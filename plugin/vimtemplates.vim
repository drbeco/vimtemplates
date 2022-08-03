" -----------------------------------------------------------------
" Copyright GNU GPL v2 - Ruben Carlo Benante <rcb@beco.cc>
"
" file: vimtemplates.vim
" Ruben Carlo Benante <rcb@beco.cc> 2016-06-12, 2017-07-08
" http://github.com/drbeco/vimtemplates
"
" Based originally on the script file-templates.vim
" by Alan Budden <abudden@gmail.com> 2009-05-21
" http://lucumr.pocoo.org/cogitations/2007/08/03/vim-file-templates/
" https://sites.google.com/site/abudden/contents/Vim-Scripts/file-templates
"
" -----------------------------------------------------------------
" Search for a tag of the form: <+$TAG$+>
" 
" With possible keys inside including the name (for simple things)
" or special keys like $BASENAME$ or $YEAR$.
" If the pattern ends with ';R' the field is justified.
"
" System variables:
" $FILENAME$
" $BASENAME$
" $UBASENAME$
" $LBASENAME$
" $YEAR$
" $DATE$
"
" Automatic valued:
" $VERSION$ => float number formatted as YMD.HMS (year, month, day, hour, min, sec)
" $USER$ => user login
" $AUTHOR$ => author's name (automatically get from DoxygenToolkit_authorName)
" $EMAIL$ => email
" $WEBPAGE$ => web page
" $PHONE$ => phone number
"
" Asked in the prompt, with a default value set:
" #BRIEF# => a brief explanation of what the program do (used by DoxyGen)
" #PROGRAM# => the name of the binary program to compile (makefile)
" #MAJOR# => the major version number (default to 0)
" #MINOR# => the minor version number (default to 1)
" #DDEBUG# => the DEBUG flag (0 or 1, default to 1)
" #CFLAGS# => the compiler C flags (gcc) (default to -Wall -Wextra -g -O0 -c -std=gnu99)
" #LDLIBS# => the linker flags (default to -lm -lncurses -lpthread -lgmp)
"
" -----------------------------------------------------------------
" ~/.vimrc configuration:
"
" Template Configuration
"let g:author="Your Name Here"
"let g:email="your@email.here"
"let g:webpage="www.yoursite.com"
"let g:phone="+55 (11) 12345-4321"
"
" OPTIONAL: the file path is configurated by:
"let g:vimtemplates_dir="dir/where/vimtemplates/are"
" Don't need to configure it, it will find itself automatically
"
" And if you have doxygen installed, you can author as:
"let g:DoxygenToolkit_authorName=g:author
"
" -----------------------------------------------------------------
"
" This file vimtemplates.vim
" should be installed in the paths: 
" a) Manually: 
"   * ~/.vim/plugin
"   * ~/.vim/templates
" b) Using plugin manager vim-plug (preferred method)
" (available at https://github.com/junegunn/vim-plug)
" Add to your .vimrc vim-plug session:
" " Vimtemplates - templates for diverse files
" Plug 'drbeco/vimtemplates'
"
" The file templates have a name pattern vimodelX.extension
" where:
"   X is a number
"   extension is some file extension (.c, .cpp, .txt, .md, etc.)
" 
" The file templates model should be put in one of the paths:
"   * ~/.vim/templates (for manually installed) or
"   * ~/.vim/plugged/vimtemplates/templates (installed with plug-vim)
"
" -----------------------------------------------------------------
" Usage:
"   Command to use, just type
"       :LoadTemplate vimodelX.ext
"   with the vimodel of your choice
"   TIP: double <TAB> key will show all models available
"   
" TODO:
"  <TAB> auto-complete

let s:TagMatch = '<+\(.\{-1,}\)\(;R\)\?+\+>'
let s:VarTagMatch = '<+\(\$[A-Z]\+\$\)\(;R\)\?+\+>'
let s:AskTagMatch = '#[A-Z_]\{-1,}#'
let s:searchSpecial = '$^*[]\:'

let s:AskTagDefault = {}
let s:AskTagDefault["BRIEF"] = "Brief description"
let s:AskTagDefault["PROGRAM"] = "a_out"
let s:AskTagDefault["MAJOR"] = "0"
let s:AskTagDefault["MINOR"] = "1"
let s:AskTagDefault["DDEBUG"] = "1"
let s:AskTagDefault["CFLAGS"] = "-Wall -Wextra -g -O0 -c -std=gnu99"
let s:AskTagDefault["LDLIBS"] = "-lm -lncurses -lpthread -lgmp"
let g:file_template_default={}
let g:file_template_default["default"]="default"

" To choose a different location, add to your .vimrc file:
" let g:vimtemplates_dir="dir/where/vimtemplates/are"
if !exists("g:vimtemplates_dir")
    let g:vimtemplates_dir=expand('<sfile>:p:h:h')
endif
 
command! -complete=customlist,ListAvailableTemplates -nargs=? 
			\ LoadTemplate call LoadFileTemplate("<args>")

command! -complete=customlist,ListAvailableTemplates -nargs=? 
			\ AddTemplate call AddTemplate("<args>")

function! ListAvailableTemplates(A,L,P)
	let s:bufferFileName = expand('%:t')
	let result = []
	let resultDict = {}
	if len(s:bufferFileName) > 0
		let extension = expand('%:e')
		if len(extension) > 0
			let files = split(globpath(g:vimtemplates_dir."/templates/", '*.'.extension), '\n')

			for f in files
				let root = fnamemodify(f, ':t:r')
				let resultDict[root] = ''
			endfor
		else
			let files = split(globpath(g:vimtemplates_dir."/templates/", s:bufferFileName.'*'), '\n')
			for f in files
				let root = fnamemodify(f, ':t:r')
				let resultDict[root] = ''
			endfor
		endif

		let result = keys(resultDict)
	endif
	return result
endfunction

function! LoadFileTemplate(name)
	let s:bufferFileName = expand('%:t')
	if len(a:name) == 0
		if exists('g:file_template_default')
			if has_key(g:file_template_default, expand('%:e'))
				let template_name = g:file_template_default[expand('%:e')]
			elseif has_key(g:file_template_default, 'default')
				let template_name = g:file_template_default['default']
			else
				throw "No default template configured for this file"
			endif
		else
			throw "Invalid or Unspecified Template"
		endif
	else
		let template_name = a:name
	endif

	if len(s:bufferFileName) > 0
		if(len(expand('%:e'))) != 0
			execute "silent! 0r ".g:vimtemplates_dir."/templates/".tolower(template_name).".".expand('%:e')
		else
			execute "silent! 0r ".g:vimtemplates_dir."/templates/".template_name
		endif

		syn match vimTemplateMarker "<+.++>" containedin=ALL
		call ExpandTemplateNames()
		call AskForOtherNames()
	endif
endfunction

function! AddTemplate(name)
	let s:bufferFileName = expand('%:t')
	let template_name = a:name

	if len(s:bufferFileName) > 0
		if(len(expand('%:e'))) != 0
			execute "silent! r ".g:vimtemplates_dir."/templates/".tolower(template_name).".".expand('%:e')
		else
			execute "silent! r ".g:vimtemplates_dir."/templates/".template_name
		endif
		syn match vimTemplateMarker "<+.++>" containedin=ALL
		call ExpandTemplateNames()
		call AskForOtherNames()
	endif
endfunction

function! AskForOtherNames()
	let winstate = winsaveview()
	let old_query = getreg('/')
	let NameDict = {}
	normal gg
	let [lnum, cnum] = searchpos(s:TagMatch)
	while lnum != 0
		let matches = matchlist(getline(lnum), '^'.s:TagMatch, cnum-1)
		if len(matches) > 0
			" We have matches of tags, now search within those tags
			" for 'NAMES' (tags are in matches[1])
			let FullTag = matches[1]
			let NewTag = FullTag
			let askMatch = match(NewTag, s:AskTagMatch)
			while askMatch != -1
				" Check for the match in NameDict
				let askString = matchstr(NewTag, s:AskTagMatch)
				" Strip the #s
				let askString = askString[1:len(askString)-2]
				if index(keys(NameDict), askString) == -1
					" Look for a default value
					if index(keys(s:AskTagDefault), askString) == -1
						let defaultText = ""
					else
						let defaultText = s:AskTagDefault[askString]
					endif

					let newText = inputdialog('Details for tag ' . askString . '? ',
								\ defaultText,
								\ FullTag)

					" Only run if cancel wasn't pressed
					if newText != FullTag
						let s:AskTagDefault[askString] = newText
					else
						let newText = askString
					endif
					let NameDict[askString] = newText
				else
					let newText = NameDict[askString]
				endif

				" Now replace all instances of #askString# with newText
				let NewTag = substitute(NewTag, '#'.askString.'#', newText, "")

				let askMatch = match(NewTag, s:AskTagMatch)
			endwhile

			" Now update the text according to whether or not there was a ';R'
			if matches[2] == ";R"
				" We have to maintain the current width
				let width = len(matches[0])
				if len(NewTag) > width
					echoerr "Expanded variables are too long"
				else
					let fillVariable = NewTag
					let fillVariable .= repeat(' ', width-len(NewTag))
					execute lnum.'s:^.\{'.(cnum-1).'}\zs'.escape(matches[0], s:searchSpecial).':'.expand(fillVariable, s:searchSpecial).':'
				endif
			else
				" We don't have to maintain the width
				execute lnum.'s:^.\{'.(cnum-1).'}\zs'.escape(matches[0],s:searchSpecial).':'.expand(NewTag, s:searchSpecial).':'
			endif

		endif

		let [lnum, cnum] = searchpos(s:TagMatch)
	endwhile

	call setreg('/', old_query)
	call winrestview(winstate)
endfunction

function! ExpandTemplateNames()
	let winstate = winsaveview()
	let old_query = getreg('/')
	normal gg
	let l:hostn = hostname()
	let l:user = exists("g:user") ? g:user : $USER
	let variablesDict =
				\ {
				\     '$FILENAME$':   expand('%:t'),
				\     '$BASENAME$':   expand('%:t:r'),
				\     '$UBASENAME$':  toupper(expand('%:t:r')),
				\     '$LBASENAME$':  tolower(expand('%:t:r')),
				\     '$YEAR$':       strftime("%Y"),
				\     '$DATE$':       strftime('%Y-%m-%d'),
				\     '$VERSION$':    strftime('%Y%m%d.%H%M%S'),
				\     '$USER$':       expand('$USER'),
				\     '$AUTHOR$':     exists("g:author") ? g:author : (exists("g:DoxygenToolkit_authorName") ? g:DoxygenToolkit_authorName : (exists("g:username") ? g:username : l:user)),
				\     '$EMAIL$':      exists("g:email") ? g:email : (l:user . "@" . l:hostn),
				\     '$WEBPAGE$':    exists("g:webpage") ? g:webpage."~".l:user : g:DoxygenToolkit_authorName,
				\     '$PHONE$':      exists("g:phone") ? g:phone : '(**) *****-****',
				\ }

	let [lnum, cnum] = searchpos(s:VarTagMatch)
	while lnum != 0
		let matches = matchlist(getline(lnum), '^'.s:VarTagMatch, cnum-1)
		if len(matches) > 0
			" We have matches
			if index(keys(variablesDict), matches[1]) != -1
				let expandedVariable = variablesDict[matches[1]]
				if matches[2] == ";R"
					" We have to maintain the current width
					let width = len(matches[0])
					if len(expandedVariable) > width
						" The variable is too long!
						echoerr "Expanded Variable is Too Long"
					else
						let fillVariable = expandedVariable
						let fillVariable .= repeat(' ', width-len(expandedVariable))
						execute lnum.'s:^.\{'.(cnum-1).'}\zs'.escape(matches[0],s:searchSpecial).':'.expand(fillVariable, s:searchSpecial).':'
					endif
				else
					" We don't have to maintain the width
					execute lnum.'s:^.\{'.(cnum-1).'}\zs'.escape(matches[0],s:searchSpecial).':'.expand(expandedVariable, s:searchSpecial).':'
				endif
			else
				" Leave this one and let the user fill it in manually
			endif
		endif
		let [lnum, cnum] = searchpos(s:VarTagMatch)
	endwhile
	call setreg('/', old_query)
	call winrestview(winstate)
endfunction

command! TemplateJumpCmd echo ""

function! JumpToNextPlaceholder()
	" Save the old query
	let old_query = getreg('/')
	let [lnum, cnum] = searchpos(s:TagMatch)
	let matches = matchlist(getline(lnum), '^'.s:TagMatch, cnum-1)
	command! TemplateJumpCmd echo ""
	if len(matches) > 0
		" We have matches
		echomsg matches[1]
		if matches[2] == ";R"
			" Fixed width
			" Change the entire string to spaces
			execute lnum.'s:^.\{'.(cnum-1).'}\zs'.escape(matches[0],s:searchSpecial).':'.repeat(' ', len(matches[0])).':'
			exec "norm! ".(cnum)."|"
			command! TemplateJumpCmd startreplace
		else
			" Nice and simple
			exec "norm! ".(cnum)."|"
			if (len(matches[0])+cnum) >= len(getline(lnum))
				exec "norm! d$"
				command! TemplateJumpCmd startinsert!
			else
				exec "norm! d".len(matches[0])."l"
				command! TemplateJumpCmd startinsert
			endif
		endif
	endif
	call setreg('/', old_query)
endfunction

nnoremap <C-J> :call JumpToNextPlaceholder()<CR>:TemplateJumpCmd<CR>
inoremap <C-J> <ESC>:call JumpToNextPlaceholder()<CR>:TemplateJumpCmd<CR>

