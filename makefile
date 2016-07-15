# vimtemplates makefile
# (C) 2016, Ruben Carlo Benante <rcb@beco.cc>
# A helper to install / uninstall vimtemplates
#
# After running
#      $ make install
# please edit ~/.vimrc and configure your personal data
# in the corresponding variables:
#	* g:author
#	* g:email
#	* g:webpage
#	* g:phone

.PHONY: uninstall install uninstallvimrc installvimrc

install : ./plugin/vimtemplates.vim ./templates/default.c
	@echo --- installing vimtemplates
	mkdir -p ~/.vim/plugin/
	mkdir -p ~/.vim/templates/
	cp ./plugin/vimtemplates.vim ~/.vim/plugin/
	cp ./templates/* ~/.vim/templates/

installvimrc :
	echo '" -------------------------------------------------' >> ~/.vimrc
	echo '" vimtemplates ~/.vimrc configuration, by Dr. Beco:' >> ~/.vimrc
	echo '"' >> ~/.vimrc
	echo '"	The file path is configurated by:' >> ~/.vimrc
	echo 'let g:VIMFILESDIR="~/.vim/" "_vimtemplates_' >> ~/.vimrc
	echo '"' >> ~/.vimrc
	echo '" Template Configuration' >> ~/.vimrc
	echo 'let g:author="Your Name Here" "_vimtemplates_' >> ~/.vimrc
	echo 'let g:email="your@email.here" "_vimtemplates_' >> ~/.vimrc
	echo 'let g:webpage="www.yoursite.com" "_vimtemplates_' >> ~/.vimrc
	echo 'let g:phone="+55 (11) 12345-4321" "_vimtemplates_' >> ~/.vimrc
	echo '"' >> ~/.vimrc
	echo '" If doxygen plugin is installed, you can use:' >> ~/.vimrc
	echo '"let g:DoxygenToolkit_authorName=g:author "_vimtemplates_' >> ~/.vimrc
	echo '"' >> ~/.vimrc
	echo '" -------------------------------------------------' >> ~/.vimrc
	echo >> ~/.vimrc

uninstall :
	rm -f ~/.vim/plugin/vimtemplates.vim
	rm -rf ~/.vim/templates/

uninstallvimrc :
	sed -i 's/.*_vimtemplates_/"&/' ~/.vimrc

