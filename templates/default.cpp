/***************************************************************************
 *   <+$FILENAME$;R+++++++++++++++++++++++++> Version <+$VERSION$;R+++++++>*
 *                                                                         *
 *   <+#BRIEF#;R++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>*
 *   Copyright (C) <+$YEAR$;R+> by <+$AUTHOR$;R+++++++++++++++++++++++++++>*
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   <+$AUTHOR$;R+++++++++++++++++++++++++++++++++++++++++++++++++++++++++>*
 *   Email: <+$EMAIL$;R+++++++++++++++++++++++++++++++++++++++++++++++++++>*
 *   Webpage: http://<+$WEBPAGE$;R++++++++++++++++++++++++++++++++++++++++>*
 *   Phone: <+$PHONE$;R+++++++++++++++++++++++++++++++++++++++++++++++++++>*
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 *   $ make <+$BASENAME$+>.xpp
 * ou
 *   $ g++ <+$BASENAME$+>.c -o <+$BASENAME$+>.xpp -Wall -Wextra -g -O0 -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */
#include <iostream> /* (Input/output library) Several standard stream objects */
using namespace std;
/* #include <cstdio> */ /* (Input/output library) C-style input-output functions */
/* #include <fstream> */ /* (Input/output library) std::basic_fstream, std::basic_ifstream, std::basic_ofstream class templates and several typedefs */
/* #include <iomanip> */ /* (Input/output library) Helper functions to control the format of input and output */
/* #include <ios> */ /* (Input/output library) std::ios_base class, std::basic_ios class template and several typedefs */
/* #include <iosfwd> */ /* (Input/output library) Forward declarations of all classes in the input/output library */
/* #include <istream> */ /* (Input/output library) std::basic_istream class template and several typedefs */
/* #include <ostream> */ /* (Input/output library) std::basic_ostream, std::basic_iostream class templates and several typedefs */
/* #include <spanstream> */ /* (C++23, Input/output library) std::basic_spanstream, std::basic_ispanstream, std::basic_ospanstream class templates and typedefs */
/* #include <sstream> */ /* (Input/output library) std::basic_stringstream, std::basic_istringstream, std::basic_ostringstream class templates and several typedefs */
/* #include <streambuf> */ /* (Input/output library) std::basic_streambuf class template */
/* #include <strstream> */ /* (deprecated in C++98, Input/output library) std::strstream, std::istrstream, std::ostrstream */
/* #include <syncstream> */ /* (C++20, Input/output library) std::basic_osyncstream, std::basic_syncbuf, and typedefs */

/* #include "libuser.hpp" */ /* your personal user library together with libuser.cpp */
/* #include "<+$BASENAME$+>.hpp" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* g++ -DVERSION="0.1.160612.142306" */
#define VERSION "<+$VERSION$+>" /* Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* g++ -DDEBUG=1 */
#define DEBUG 0 /* Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <cassert> */ /* (Error handling) Conditionally compiled macro that compares its argument to zero */

/* Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /* string buffer */

/* ---------------------------------------------------------------------- */
/* classes : better located at libxxx.h */

class document
{
    public:
        void help(void); /* print some help */
        void copyr(void); /* print version and copyright information */
};

/* ---------------------------------------------------------------------- */
/* methods */

/* ---------------------------------------------------------------------- */
/* Prints help information 
 *  usually called by opt -h or --help
 */
void document::help(void)
{
    IFDEBUG("help()");
    /* printf("%s - %s\n", "<+$BASENAME$+>", "<+#BRIEF#+>"); */
    cout << "<+$BASENAME$+> - <+#BRIEF#+>\n";
    cout << "\nUsage: <+$BASENAME$+>\n\n";
    cout << "This program does...\n";
    /* add more stuff here */
    cout << "\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n";
    cout << "\nTodo:\n\tLong options not implemented yet.\n";
    cout << "\nAuthor:\n\tWritten by <+$AUTHOR$+> <<+$EMAIL$+>>\n\n";
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints version and copyright information 
 *  usually called by opt -V
 */
void document::copyr(void)
{
    IFDEBUG("copyr()");
    cout << "<+$BASENAME$+> - Version " << VERSION << "\n";
    cout << "\nCopyright (C) <+$YEAR$+> <+$AUTHOR$+> <<+$EMAIL$+>>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n";
    return;
}

/* ---------------------------------------------------------------------- */
/* This function does ...
 * 
 * It receives as input ... 
 *
 * It returns ...
 */
int main(void)
{
    /* local declarations */
    document doc; /* create an object of a class */
    int i; /* general index */
    char s[SBUFF]; /* a string to hold ... */

    /* code */
    doc.help();
    doc.copyr();
  
    /* ...and we are done */
    return 0;
}

/* add more functions here */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : CPP config - Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20220718.172615      */

