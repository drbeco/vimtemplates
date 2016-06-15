/***************************************************************************
 *   <+$FILENAME$;R+++++++++++++++++++++++++> Version <+$VERSION$;R+++++++>*
 *                                                                         *
 *   <+#BRIEF#;R++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>*
 *   Copyright (C) <+$YEAR$;R+> by <+$AUTHOR$;R+++++++++++++++++++++++++++>*
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
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
 * @details This program is a template for a minimum Allegro in Text Mode
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 * @author <+$AUTHOR$+> <<<+$EMAIL$+>>>
 * @par Webpage
 * <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @copyright (c) <+$YEAR$+> GNU GPL v3
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 3 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/* Template para programa basico Allegro
 * que salva uma imagem em arquivo
 *
 * Para compilar use:
 *   $gcc <+$BASENAME$+>.c -o <+$BASENAME$+>.x `allegro-config --cflags --libs` -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */

#define ALLEGRO_USE_CONSOLE /**< Console app. Need to be before allegro.h */
#include <allegro.h> /* A game library for graphics, sounds, etc. */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <assert.h> */ /* Verify assumptions with assert */
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

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "<+$VERSION$+>" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/** @brief Ignore Int Return: Turn off -Wunused-result for a specific function call */
#define IGR(M) if(0==((int)M)){;}

/* limits */
#define BUFF_WIDTH 320 /**< Standard buffer width */
#define BUFF_HEIGHT 240 /**< Standard buffer height */
#define BUFF_WIDTH_MAX 1280 /**< Maximum buffer width */
#define BUFF_WIDTH_MIN 320 /**< Minimum buffer width */
#define BUFF_HEIGHT_MAX 1024 /**< Maximum buffer height */
#define BUFF_HEIGHT_MIN 200 /**< Minimum buffer height */

/* colors and names */
#define CORBRANCO (makecol(255,255,255)) /**< Allegro white color */
#define CORPRETO 1 /**< Allegro black color */
#define CORCINZA (makecol(160,160,160)) /**< Allegro gray color */
#define CORAZUL (makecol(0, 0, 255)) /**< Allegro blue color */
#define CORVERDE (makecol(0, 255, 0)) /**< Allegro green color */
#define CORAMARELO (makecol(255,255,100)) /**< Allegro yellow color */
#define CORVERMELHO (makecol(255, 0, 0)) /**< Allegro red color */

#define IMAGENAME "teste.bmp" /**< Image file name */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */

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
 * @todo Need to do...
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
    int bw, bh; /* buffer width and buffer height */

    /* getopt() configured options:
     *        -h     --help
     *        -V     --version
     *        -v     --verbose
     *        -r W:H --resolution
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhVr:")) != EOF)
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
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);
    /* ...and we are done */

    if(bw < BUFF_WIDTH_MIN || bw > BUFF_WIDTH_MAX)
    {
        bw = BUFF_WIDTH;
        if(verb)
            printf("Width out of range. Using %d instead.\n", BUFF_WIDTH);
    }
    if(bh < BUFF_HEIGHT_MIN || bh > BUFF_HEIGHT_MAX)
    {
        bh = BUFF_HEIGHT;
        if(verb)
            printf("Height out of range. Using %d instead.\n", BUFF_HEIGHT);
    }

    /* instead of allegro_init() */
    if(install_allegro(SYSTEM_NONE, &errno, atexit) != 0)
    {
        IFDEBUG("Cannot install allegro.");
        exit(EXIT_FAILURE);
    }

    set_color_depth(16);
    get_palette(pal);

    /* Create a buffer for saving the image, size Width x Height pixels. */
    buff = create_bitmap(bw, bh);
    if(buff == NULL)
    {
        IFDEBUG("Could not create buffer!");
        exit(EXIT_FAILURE);
    }

    circle(buff, 160, 120, 100, CORAMARELO);
    textprintf_ex(buff, font, 50, 50, CORVERDE, CORPRETO, "Teste do circulo.");

    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    if(verb)
        printf("Successfully saved image %s.\n", IMAGENAME);

    return EXIT_SUCCESS;
}

/** @brief Allegro magic */
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
    printf("\t-h,      --help\n\t\tShow this help.\n");
    printf("\t-V,      --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,      --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-r W:H,  --resolution\n\t\tSet resolution width to be W (range: [%d, %d]) and height H (range: [%d, %d])\n", BUFF_WIDTH_MIN, BUFF_WIDTH_MAX, BUFF_HEIGHT_MIN, BUFF_HEIGHT_MAX);
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
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>. This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", <+$YEAR$+>, "<+$AUTHOR$+>", "<+$EMAIL$+>");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.012749      */
