/***************************************************************************
 *   <+$FILENAME$;R+++++++++++++++++++++++++> Version <+$VERSION$;R+++++++>*
 *                                                                         *
 *   <+#BRIEF#;R++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>*
 *   Copyright (C) <+$YEAR$;R+> by <+$AUTHOR$;R+++++++++++++++++++++++++++>*
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
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

/* ---------------------------------------------------------------------- */
/**
 * @file <+$FILENAME$+>
 * @ingroup GroupUnique
 * @brief <+#BRIEF#+>
 * @details This is an example of a minimum Allegro program with some preprogrammed
 * functions as skeleton.
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 * @author <+$AUTHOR$+> <<<+$EMAIL$+>>>
 * @par Webpage
 * <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @copyright (c) <+$YEAR$+> GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Transform this template in something useful.
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/* Template para Allegro
 * com abertura de tela grafica
 *
 * Para compilar use:
 *  $gcc <+$BASENAME$+>.c -o <+$BASENAME$+>.x `allegro-config --cflags --libs` -Wall
 *       -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DHAVE_CONFIG_H
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */

/* #define ALLEGRO_USE_CONSOLE / *doxygen*< Console app. Need to be before allegro.h */
#include <allegro.h> /* A game library for graphics, sounds, etc. */

#include <assert.h> /* Verify assumptions with assert */
/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno for system calls */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "<+$BASENAME$+>.h" */ /* To be created for this template if needed */

#ifdef HAVE_CONFIG_H
#include <config.h> /**< Usually from auto-tools and -DHAVE_CONFIG_H key */
#endif

/* ---------------------------------------------------------------------- */
/* definitions */

#define VERSION (<+$VERSION$+>) /**< Version Number */

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/** Ignore Int Return: Turn off -Wunused-result for a specific function call */
#define IGR(M) if(0==((int)M)){;}

/* limits */
#define BUFF_WIDTH 800 /**< Standard buffer width */
#define BUFF_HEIGHT 600 /**< Standard buffer height */
#define BUFF_WIDTH_MAX 1280 /**< Maximum buffer width */
#define BUFF_WIDTH_MIN 320 /**< Minimum buffer width */
#define BUFF_HEIGHT_MAX 1024 /**< Maximum buffer height */
#define BUFF_HEIGHT_MIN 200 /**< Minimum buffer height */
#define RADIUS_MAX 1280 /**< Maximum radius of a circle */

/* colors and names */
#define CORBRANCO (makecol(255,255,255)) /**< Allegro white color */
#define CORPRETO 1 /**< Allegro black color */
#define CORCINZA (makecol(160,160,160)) /**< Allegro gray color */
#define CORAZUL (makecol(0, 0, 255)) /**< Allegro blue color */
#define CORVERDE (makecol(0, 255, 0)) /**< Allegro green color */
#define CORAMARELO (makecol(255,255,100)) /**< Allegro yellow color */
#define CORVERMELHO (makecol(255, 0, 0)) /**< Allegro red color */
#define CORLARANJA (makecol(255, 155, 0)) /**< Allegro orange color */
#define CORROSA (makecol(255, 0, 255)) /**< Allegro pinky color */
#define CORROXO (makecol(200, 0, 255)) /**< Allegro purple color */
#define CORCIANO (makecol(0, 255, 255)) /**< Allegro cyan color */

/* You can also use for Allegro 5:
 * al_color_name("gray");
 * #define GRAYCOLOR = al_map_rgb(160, 160, 160);
 */

#define IMAGENAME "circle.bmp" /**< Image file name */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */
volatile int close_button_pressed = 0; /**< clicked on close window button? */

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
float version(void); /* returns the version float number YYMMDD.hhmmss */
void <+$BASENAME$+>_init(int *bw, int *bh, int *vw, int *vh, int *cx, int *cy, int *cr); /* global initialization function */
void close_button_handler(void); /* a close button handler to handle close button */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./<+$BASENAME$+> -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo New key -o filename
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    BITMAP *buff; /* image buffer pointer */
    PALETTE pal; /* color palette */
    int bw = 0, bh = 0; /* buffer width, height, and window resolution */
    int vw = 0, vh = 0; /* virtual window size */
    int cx = 0, cy = 0, cr = 0; /* circle pos (x, y) and radius (r) */

    /* getopt() configured options:
     *        -h       --help
     *        -V       --version
     *        -v       --verbose
     *        -r W:H   --resolution
     *        -w W:H   --window size (defaults to zero, "couldn't care less")
     *        -c X:Y:R --circle position (x, y) and radius (R)
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhVr:w:c:")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'V':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case 'r':
                sscanf(optarg, "%d:%d", &bw, &bh);
                break;
            case 'w':
                sscanf(optarg, "%d:%d", &vw, &vh);
                break;
            case 'c':
                sscanf(optarg, "%d:%d:%d", &cx, &cy, &cr);
                break;
            case '?':
            default:
                printf("Type\n\t$%s -h\nfor help.\n\n", argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    <+$BASENAME$+>_init(&bw, &bh, &vw, &vh, &cx, &cy, &cr); /* inicializa definicoes */

    /* O mesmo que:
     * install_allegro(SYSTEM_AUTODETECT, &errno, atexit) */
    if(allegro_init() != 0)
        exit(EXIT_FAILURE);

    /* A memory lock for callback functions.
     * It starts in the function name, and end in the
     * END_OF_FUNCTION(close_button_handler) MACRO
     */
    LOCK_FUNCTION(close_button_handler);
    set_close_button_callback(close_button_handler); /* set the callback */

    /* a neat message box with a ok button */
    allegro_message("Allegro ID: %s (data: %d)\n", allegro_id, ALLEGRO_DATE);

    /* set_color_depth(16); Need to set it before set_gfx_mode() */
    set_color_depth(desktop_color_depth());
    /* Paleta de cores */
    get_palette(pal);
    /* Installing the keyboard handler. */
    install_keyboard();
    /* Turning on graphic mode. Problem? Try GFX_SAFE */
    IFDEBUG("[ok] Color/Palette/Keyboard");
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, bw, bh, vw, vh) < 0)
    {
        allegro_message("Could not initialize graphic mode!\n");
        exit(EXIT_FAILURE);
    }
    IFDEBUG("[ok] set_gfx_mode");
    /* Window title */
    set_window_title("Allegro Test - By <+$USER$+>");
    /* Installing the timer (needed for mouse functions) */
    install_timer();
    /* Installing the mouse handler. */
    install_mouse();
    /* para habilitar o tipo de cursor do mouse use */
    enable_hardware_cursor();
    select_mouse_cursor(MOUSE_CURSOR_BUSY);
    show_mouse(screen);

    /* Create a buffer for smooth animation. */
    buff = create_bitmap(bw, bh);
    if(buff == NULL)
    {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Could not create buffer!");
        IFDEBUG("Could not create buffer!");
        exit(EXIT_FAILURE);
    }

    circle(buff, cx, cy, cr, CORAMARELO);
    textprintf_ex(buff, font, 50, 50, CORVERDE, CORPRETO, "Circle test");
    textprintf_ex(buff, font, 50, 70, CORVERDE, CORPRETO, "Press <space bar>.");

    acquire_screen();
    blit(buff, screen, 0, 0, 0, 0, buff->w, buff->h);
    release_screen();

    IFDEBUG("[ok] release_screen");
    rest(2000); /* A timer function: sleep for 2 secs (2000 ms) */
    IFDEBUG("[ok] rest");

    select_mouse_cursor(MOUSE_CURSOR_ARROW);
    show_mouse(screen);
    IFDEBUG("[ok] mouse ARROW");
    while(!key[KEY_SPACE] && !close_button_pressed)
    {
        rest(10); /* A timer function: sleep for 10 ms*/
        if(mouse_b & 1) /* left button */
        {
            textprintf_ex(buff, font, 50, 90, CORVERDE, CORPRETO, "mouse=(%d, %d)", mouse_x, mouse_y);
            acquire_screen();
            blit(buff, screen, 0, 0, 0, 0, buff->w, buff->h);
            release_screen();
        }
    }
    IFDEBUG("[ok] loop");

    /* save image to disk */
    save_bitmap(IMAGENAME, buff, pal);
    IFDEBUG("[ok] saved");

    if(close_button_pressed)
    {
        textprintf_ex(buff, font, 50, 110, CORVERDE, CORPRETO, "Close button pressed. I'm gonna go now...");
        acquire_screen();
        blit(buff, screen, 0, 0, 0, 0, buff->w, buff->h);
        release_screen();
        rest(2000); /* A timer function: sleep for 2 secs */
    }

    destroy_bitmap(buff);
    return EXIT_SUCCESS;
}
/** @brief Allegro magic (Allegro 5 doesn't need it anymore) */
END_OF_MAIN()

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "<+$BASENAME$+>", "<+#BRIEF#+>");
    printf("\nUsage: %s [-h|-v]\n", "<+$BASENAME$+>");
    printf("\nOptions:\n");
    printf("\t-h,       --help\n\t\tShow this help.\n");
    printf("\t-V,       --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,       --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-r W:H,   --resolution\n\t\tSet resolution width to be W (range: [%d, %d]) and height H (range: [%d, %d])\n", BUFF_WIDTH_MIN, BUFF_WIDTH_MAX, BUFF_HEIGHT_MIN, BUFF_HEIGHT_MAX);
    printf("\t-w W:H,   --window size (defaults to zero \"couldn't care less\").\n");
    printf("\t-c X:Y:R, --circle position (x, y) and radius (R).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "<+$AUTHOR$+>", "<+$EMAIL$+>");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "<+$BASENAME$+>", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", <+$YEAR$+>, "<+$AUTHOR$+>", "<+$EMAIL$+>");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
void <+$BASENAME$+>_init(int *bw, int *bh, int *vw, int *vh, int *cx, int *cy, int *cr)
{
    IFDEBUG("<+$BASENAME$+>_init()");
    if(DEBUG) fprintf(stderr, "BEFORE: bw=%d, bh=%d, vw=%d, vh=%d, cx=%d, cy=%d, cr=%d\n", *bw, *bh, *vw, *vh, *cx, *cy, *cr);

    /* initialization */
    if(*bw < BUFF_WIDTH_MIN || *bw > BUFF_WIDTH_MAX)
    {
        *bw = BUFF_WIDTH;
        if(verb)
            printf("Buffer Width out of range. Using %d instead.\n", *bw);
    }
    if(*bh < BUFF_HEIGHT_MIN || *bh > BUFF_HEIGHT_MAX)
    {
        *bh = BUFF_HEIGHT;
        if(verb)
            printf("Buffer Height out of range. Using %d instead.\n", *bh);
    }
    if(*vw != 0 && (*vw < BUFF_WIDTH_MIN || *vw > BUFF_WIDTH_MAX))
    {
        *vw = BUFF_WIDTH;
        if(verb)
            printf("Virtual Window Width out of range. Using %d instead.\n", *vw);
    }
    if(*vh != 0 && (*vh < BUFF_HEIGHT_MIN || *vh > BUFF_HEIGHT_MAX))
    {
        *vh = BUFF_HEIGHT;
        if(verb)
            printf("Virtual Window Height out of range. Using %d instead.\n", *vh);
    }
    if(*cx < 1 || *cx > *bw)
    {
        *cx = (*bw) / 2;
        if(verb)
            printf("Circle X out of range. Using %d instead.\n", *cx);
    }
    if(*cy < 1 || *cy > *bh)
    {
        *cy = (*bh) / 2;
        if(verb)
            printf("Circle Y out of range. Using %d instead.\n", *cy);
    }
    if(*cr < 1 || *cr > RADIUS_MAX)
    {
        *cr = (((*bw) < (*bh)) ? (*bw) / 2 : (*bh) / 2);
        if(verb)
            printf("Circle R out of range. Using %d instead.\n", *cr);
    }
    if(DEBUG) fprintf(stderr, "AFTER: bw=%d, bh=%d, vw=%d, vh=%d, cx=%d, cy=%d, cr=%d\n", *bw, *bh, *vw, *vh, *cx, *cy, *cr);

    /* DEBUG: Defensive programming: make sure of your assumptions */
    /* Use only for DEBUG. Its terrible to maintain codes like this */
    assert(*bw >= BUFF_WIDTH_MIN && *bw <= BUFF_WIDTH_MAX);
    assert(*bh >= BUFF_HEIGHT_MIN && *bh <= BUFF_HEIGHT_MAX);
    assert(*vw == 0 || (*vw >= BUFF_WIDTH_MIN && *vw <= BUFF_WIDTH_MAX));
    assert(*vh == 0 || (*vh >= BUFF_HEIGHT_MIN && *vh <= BUFF_HEIGHT_MAX));
    assert(*cx >= 1 && *cx <= *bw);
    assert(*cy >= 1 && *cy <= *bh);
    assert(*cr >= 1 && *cr <= RADIUS_MAX);
    /* End of DEBUG */
    /* Delete those lines after you are sure the program works */
    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Handle the Close Window click
 * @details This function is a callback for the event of a mouse click on the
 * close button ico. (Remember: all callback functions must be very fast and small, and never
 * calls system functions or others. Do what you got to do, and return! Use this rule:
 * Set flags and return. Nothing more.)
 * @return Void
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
void close_button_handler(void)
{
    close_button_pressed = 1;
}
/** @brief Allegro magic for callback functions (lock memory and data) */
END_OF_FUNCTION(close_button_handler)

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.013719      */
