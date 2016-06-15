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
 * @details This program really do a nice job as a template, and template only!
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
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Programa em C que chama uma funcao fatpl(), definida em um arquivo PROLOG cpl.pl
 * O modulo deve ser compilado junto com o codigo C
 * Para compilar use:
 *   $swipl-ld <+$BASENAME$+>.c <+$BASENAME$+>.pl -o <+$BASENAME$+>.x
 *             -Wall -Wextra -g -O0 -ansi -pedantic-errors -pl-options,-q
 * Chaves opcionais:
 *        -DDEBUG=1 : Liga o modo DEBUG
 *        -pl-options,-q : Suprime a mensagem de boas-vindas.
 *        -Wno-unused-result : Para ignorar retornos de funcoes
 *
 * ou prefira configurar o make para:
 *   make cpl o=<+$BASENAME$+>
 *
 * Caso queira compilar o fonte C para um objeto, sem linkar, usando o gcc:
 *   $gcc <+$BASENAME$+>.c -o <+$BASENAME$+>.o -c -Wall -Wextra -g -O0 -ansi
 *        -pedantic-errors -DDEBUG=1 -I/usr/lib/swi-prolog/include/
 *
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <SWI-Prolog.h> /* Prolog integration with C */

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

/** @brief If PL_func fail, exit */
#define PL_TRY(M) if(0==((int)M)){IFDEBUG("PL_fail"); exit(EXIT_FAILURE);}

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
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, <+$USER$+>!!
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
 * @warning Be careful with that axe Eugene.
 * @bug It takes about one hundred Monarch Butterflies to weigh an ounce.
 * @todo When someone knocks at the door, knock back and see how long it goes on for.
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
int main(int argc, char *argv[])
{    
    int opt; /* return from getopt() */
    int n, /* holds the value to calculate the factorial */
        f; /* will hold the factorial result of n */
    int val; /* to capture return errors from SWI-PROLOG */
    term_t ter; /* a PROLOG term */
    predicate_t pred; /* a PROLOG predicate */

    /* getopt() configured options:
     *        -h   help
     *        -V   version
     *        -v   verbose
     *        -f n fatorial
     */
    n = -1;
    opterr = 0;
    while((opt = getopt(argc, argv, "vhVf:")) != EOF)
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
            case 'f':
                n = (int)strtol(optarg, (char **)NULL, 10);
                break;
            case '?':
            default:
                printf("Type %s -h for help.\n\n", argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    if(n < 0)
    {
        printf("Type %s -h for help\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Em prolog teriamos apenas:
     * fatpl(n,f).
     */
    IFDEBUG("PROLOG setup...");
    if(!PL_initialise(argc, argv))    /* inicializa o PROLOG */
        PL_halt(EXIT_FAILURE); /* termina o PROLOG e o programa apos falha */

    pred = PL_predicate("fatpl", 2, "fatorial"); /* cria pred como predicato de fat1 */
    ter = PL_new_term_refs(2); /* cria um vetor de duas variaveis de termo ter+0 e ter+1*/

    IFDEBUG("PROLOG solving fat...\n");
    PL_TRY(PL_put_integer(ter, n)); /* coloca n em ter+0 */
    PL_call_predicate(NULL, PL_Q_NORMAL, pred, ter); /* executa o predicato */
    val = PL_get_integer(ter + 1, &f); /* recupera a resposta f = ter+1 */

    if(!val)
    {
        IFDEBUG("PROLOG failed...");
        PL_halt(EXIT_FAILURE); /* terminar o PROLOG e o programa apos falha */
    }

    printf("Prolog solved: fat(%d) = %d\n", n, f);

    PL_cleanup(EXIT_SUCCESS); /* termina o PROLOG e limpa a memoria */

    IFDEBUG("PROLOG succeed...");
    return EXIT_SUCCESS;
}

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
    printf("\nUsage: %s [-h|-v] -f n\n", "<+$BASENAME$+>");
    printf("\nOptions:\n");
    printf("\t-h,    --help\n\t\tShow this help.\n");
    printf("\t-V,    --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,    --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f n,  --fat\n\t\tCalculate fat(n)=n!\n");
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
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", <+$YEAR$+>, "<+$AUTHOR$+>", "<+$EMAIL$+>");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>      Version 20160615.002859 */
