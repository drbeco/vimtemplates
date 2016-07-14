#!/bin/bash
### BEGIN INIT INFO
# Title: <+$FILENAME$+>
# Provides:
# Required-Start:
# Required-Stop:
# Should-Start:
# Should-Stop:
# Default-Start: 2 3 4 5
# Default-Stop: 0 1 6
# Short-Description: <+#BRIEF#+>
# Description: More detailed information on how it accomplishs it.
# License: GNU GENERAL PUBLIC LICENSE Version 2
# Author: <+$AUTHOR$+> <<+$EMAIL$+>>
# Date: <+$DATE$+>
# Version: <+$VERSION$+>
# Usage: sh <+$FILENAME$+>
# Notes: Some useful notes that might be relevant goes here
# bash_version: GNU bash, version 4.2.37(1)-release (x86_64-pc-linux-gnu)
### END INIT INFO

# **************************************************************************
# * (C)opyright <+$YEAR$;R+> by <+$AUTHOR$;R++++++++++++++++++++++++++++++>*
# *                                                                        *
# * This program is free software; you can redistribute it and/or modify   *
# *  it under the terms of the GNU General Public License as published by  *
# *  the Free Software Foundation version 2 of the License.                *
# *                                                                        *
# * This program is distributed in the hope that it will be useful,        *
# *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
# *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
# *  GNU General Public License for more details.                          *
# *                                                                        *
# * You should have received a copy of the GNU General Public License      *
# *  along with this program; if not, write to the                         *
# *  Free Software Foundation, Inc.,                                       *
# *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
# *                                                                        *
# * Contact author at:                                                     *
# *  <+$AUTHOR$;R++++++++++++++++++++++++++++++++++++++++++++++++++++++++> *
# *  <+$EMAIL$;R+++++++++++++++++++++++++++++++++++++++++++++++++++++++++> *
# **************************************************************************

Help()
{
    cat << EOF
    <+$BASENAME$+> - <+#BRIEF#+>
    Usage: ${1} [-v] ( [-h|-V] | -a n -i m [-w url] )
  
    Options:
      -h, --help       Show this help.
      -V, --version    Show version.
      -v, --verbose    Turn verbose mode on (cumulative).
      -a, --max        Set max value to n.
      -i, --min        Set min value to m.
      -w, --www        Set URL to ping.
    Exit status:
       0, if ok.
       1, some error occurred.
  
    Restriction: max > min.
  
    Todo:
            Long options not implemented yet.
  
    Author:
            Written by <+$AUTHOR$+> <<+$EMAIL$+>>  

EOF
    exit 1
}
# Another usage function example
# usage() { echo "Usage: $0 [-h | -c] | [-a n -i m], being n>m" 1>&2; exit 1; }

Copyr()
{
    echo '<+$BASENAME$+> - <+$VERSION$+>'
    echo
    echo 'Copyright (C) <+$YEAR$+> <+$AUTHOR$+> <<+$EMAIL$+>>, GNU GPL version 2'
    echo '<http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and'
    echo 'redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author'
    echo 'takes no responsability to any damage this software may inflige in your data.'
    echo
    exit 1
}

# Example of a function
main()
{
    verbose=0
    #getopt example with switch/case
    while getopts "hVva:i:w:" FLAG; do
        case $FLAG in
            h)
                Help
                ;;
            V)
                Copyr
                ;;
            v)
                let verbose=verbose+1
                ;;
            w)
                www=$OPTARG
                ;;
            a)
                max=$OPTARG
                ;;
            i)
                min=$OPTARG
                ;;
            *)
                Help
                ;;
        esac
    done
  
    if [ -z "$max" ] || [ -z "$min" ]; then
        Help
    fi
    if [ "$max" -le "$min" ]; then
        echo "Restriction: Max > Min"
        exit 1
    fi
  
    echo Starting <+$FILENAME$+> script, by <+$USER$+>, version <+$VERSION$+>...
  
    echo Verbose level: $verbose
  
    #for example
    echo list of files:
    for i in $( ls ); do
        echo item: $i
    done
    echo
  
    #echo read from stdin
    backupfile=/home/$USER/$(date +%Y%m%d)-documents-backup.tgz
    echo Issuing command: tar -cZf $backupfile /home/$USER/Documents
    read Opt
    echo Your answer: $Opt
    if [ "$Opt" = "y" ]; then
        echo Just kidding\!
    else
        echo Thanks god I dont need to work today\!
    fi
    
     #while counter example
    COUNTER=2
    while [  "$COUNTER" -gt 0 ]; do
        echo The counter is $COUNTER seconds
        let COUNTER=COUNTER-1
        sleep 1 # wait 1 second
    done
    
    #Menu
    if [ -z "$www" ]; then
        echo Please chose an option number:
        OPTIONS="Google Yahoo Facebook Quit"
        select opt in $OPTIONS; do
            if [ "$opt" = "Quit" ]; then
                echo Please stop the world, I wanna get out.
                www=""
                break
            elif [ "$opt" = "Google" ]; then
                echo Make a new World
                www="www.google.com"
                break
            elif [ "$opt" = "Yahoo" ]; then
                echo 'No way! Chose another!'
            elif [ "$opt" = "Facebook" ]; then
                echo Save the World
                www="facebook.com"
                break
            else
                echo "Bad server, no donut for you"
            fi
        done
    fi
    
    echo Pinging $www
    ping -c1 $www 2>/dev/null  1>/dev/null
    pingstatus=$?
    if [[ "$pingstatus" -ne "0" ]]; then
        echo $www down
        beep
    else
        echo ping ok
    fi
    
    echo Bye main
}

#Calling main with all args
main $*
echo Bye script
exit 0

#/* -------------------------------------------------------------------------- */
#/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : SHELL config for Vim modeline */
#/* Template by Dr. Beco <rcb at beco dot cc> Version 20160714.124739          */

