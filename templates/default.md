## <+#TITLE#+>
### <+#SUBTITLE#+>

#### Summary

This example shows how to use markdown to integrate your doxygen __mainpage__ with the github __mainpage__.

#### Description

Here a more detailed description of the theme.

The markdown bellow are compatible with _doxygen_ and _github_.

If you are planning to integrate those two, better not use header level 1, because doxygen already have a big title and they are going to be duplicated.

##### Paragraph

Just jump a blank line.

Like this.

##### Headers (this one is level 5)

Use as many # as you like from 1 to 6

###### This is a header level 6

Level 6 fonts looks smaller than normal text in doxygen, and the same size but gray in doxygen.

Thats the last level.

##### Block quotes

Use > to start them:

> Test block quotes.
> Another line in the block.
> > Can be nested.
> > Another nested.
> Back to level 1

##### Lists

###### Numbered lists

1. item 1
2. See? Just enumerate them
3. And so on

###### Bullet lists

- Start with an hifen
- And keep going
  * You can use also an asterisk, but better not!
  - Doxygen doesn't like asterisks in the begin of a line
  - It strips them off!
  - And nest them
    + And a plus sign
  - Thats it
- The end

##### Emphasis

One _ (underline) or one * (asterisk) then a word or sentence, then another of the same symbol to close it.

You should prefer using _underlines_ because, you know, __doxygen__ don't like too much the asterisks.

##### Code

This is trick! Both _doxygen_ and _github_ have source code definitions, but they don't agree how to mark. So you probably need to choose.

Well, choose __doxygen__ because __github__ can understand most of it! (Yep! Han!)

Code block:

    if (chose(you)) doxygen
       then "start your code indented" by 4 spaces.
       Its the same as the Q/A site stackoverflow.
    else
       Then you chose(github), you start with 3 backticks `
       in a line, the code, and end with another line
       with ```
    endif


Fancy (fenced) code block

You can syntax highlight a source code using 3 tildes. Just state the language extension (if supported):

Prolog:

~~~{.prolog}
head(X) -:
    body(X),
    not(foot(X)).
~~~

C:

~~~{.c}
#ifdef LESS
  if(x<Y)
#else
  if(x>=y)
#endif
  printf("%d\n", x);
  return 1;
~~~

Not mentioned what language:

~~~
if(x==y)
  sprintf(str, "%d is %d\n", x, y);
~~~

At least both agree `one back tick` is for `inline code` (or `monospaced font`).

##### Links

You can link using brackets for the text and parenthesis for the link:

[Github Markdown](https://help.github.com/articles/markdown-basics/)

[Doxygen Markdown](http://www.stack.nl/~dimitri/doxygen/manual/markdown.html)

For email, it works if you wrap in < and >: <test@example.com>

You can also put an email in a link:

[test email](test@example.com)

If you like when they have the < and > around, you need to use 2.
<<test@example.com>>

or

<[test email](test@example.com)>

And you can use it also in the URL link just like this: <[text](www.example.com)>

##### Horizontal rules

Type 3 or more underlines in the begin of a line:

___

That will do. You can type more than 3.

##### Tables

Type as you would in text. Separate the coluns with pipes | and
the first line from the others wit some hifens -.

See this | second | column 3
---------|--------|---------
here     | it     | goes
third    | line   | here

Alignment can be done with a colon positionated as:

|left     | center | right   |
|:--------|:------:|--------:|
|here     | it     | goes    |
|third    | line   | here    |



Now, how to do that? Easy. Just take a look at this example. It has all you need to start. Source is available.

Use it as a skeleton for your work.

__In appreciation__

__<+$AUTHOR$+>__
_________________________________________________________________

####Program details

* Version <+$VERSION$+>
* Date <+$DATE$+>
* Author <+$AUTHOR$+> <<<+$EMAIL$+>>> (<+$USER$+>)
* Webpage <[<+$WEBPAGE$+>](http://<+$WEBPAGE$+>)>

_________________________________________________________________

####Copyright, License and Warranty

__copyright (c) <+$YEAR$+> GNU GPL v2__

This program is free software: you can redistribute it
and/or modify it under the terms of the
GNU General Public License as published by
the Free Software Foundation version 2 of the License.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.
If not, write to the Free Software Foundation, Inc.,
59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
Or read it online at <<http://www.gnu.org/licenses/>>.

_________________________________________________________________

_Template by Dr. Beco < rcb at beco dot cc > Version 20160714.115030_

