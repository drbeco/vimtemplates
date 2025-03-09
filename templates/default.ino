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
 * Instrucoes para compilar o sketch do Arduino:
 *
 * $ arduino-cli compile --fqbn arduino:avr:uno <+$BASENAME$+>
 * $ arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno <+$BASENAME$+>
 *
 */

/* ---------------------------------------------------------------------- */
/* includes */

/* #include "<+$BASENAME$+>.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142306" */
#define VERSION "<+$VERSION$+>" /* Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /* Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */

/* Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /* string buffer */

/* pins */
#define LED 13

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */

/* ---------------------------------------------------------------------- */
/* the setup function runs once when you press reset or power the board
 */
void setup()
{
    pinMode(LED, OUTPUT); // set pin LED (13) to Output
    Serial.begin(9600); // open the serial port at 9600 bps:
}

/* ---------------------------------------------------------------------- */
/* This function is the main loop
 */
void loop()
{
    /* local declarations */
    int i; /* general index */
    char s[SBUFF]; /* a string to hold ... */

    /* code */
    digitalWrite(LED, HIGH);  // turn the LED on (HIGH is the voltage level)
    Serial.println("Red on");
    delay(1000);              // wait for a second
    digitalWrite(LED, LOW);   // turn the LED off by making the voltage LOW
    Serial.println("Red off");
    delay(1000);              // wait for a second

    /* ...and more code */
}

/* add more functions here */

/* ---------------------------------------------------------------------- */
/* Prints help information on Serial Comm
 *  usually called by opt -h or --help
 */
void help(void)
{
    IFDEBUG("help()");
    Serial.println("<+$BASENAME$+> - <+#BRIEF#+>");
    Serial.println("Usage: <+$BASENAME$+>");
    Serial.println("This program does...");
    /* add more stuff here */
    Serial.println("Exit status:");
    Serial.println("0 if ok.");
    Serial.println("1 some error occurred.");
    Serial.println();
    Serial.println("Todo: Long options not implemented yet.");
    Serial.println("Author: Written by <+$AUTHOR$+>, <+$EMAIL$+>");
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints version and copyright information on Serial Comm
 *  usually called by opt -V
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    Serial.print("<+$BASENAME$+> Version: ");
    Serial.println(VERSION);
    Serial.print("Copyright (C) ");
    Serial.print(<+$YEAR$+>)
    Serial.print(" <+$AUTHOR$+>, ");
    Serial.println("<+$EMAIL$+>");
    Serial.println("GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.");
    return;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>      Version 20250309.153530 */

