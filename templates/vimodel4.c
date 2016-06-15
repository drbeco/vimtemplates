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
 * @details This is a shared object ".so" library with functions that can
 * be called from a PROLOG program.
 * Compile with:
 *   $swipl-ld -shared <+$BASENAME$+>.c -o <+$BASENAME$+>.so
 *             -Wall -Wextra -g -O0 -ansi -pedantic-errors
 * 
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
 * @bug This file right now does nothing usefull.
 *
 */

/*
 * Cria uma biblioteca (um modulo) em C com funcoes que podem
 * ser chamadas por um programa em PROLOG.
 * 
 * Esta biblioteca deve ser compilada para um Shared Object ".so"
 * (veja tambem ".DLL")
 * 
 * Para compilar use:
 *   $swipl-ld -shared <+$BASENAME$+>.c -o <+$BASENAME$+>.so
 *             -Wall -Wextra -g -O0 -ansi -pedantic-errors
 *             -Wno-unused-result
 *
 * ou prefira configurar o make para:
 *   make plc o=<+$BASENAME$+>
 *
 * Caso queira compilar o fonte C para um objeto, sem linkar, usando o gcc:
 *   $gcc <+$BASENAME$+>.c -o <+$BASENAME$+>.so -shared -Wall -Wextra -g -O0 -ansi
 *        -pedantic-errors -DDEBUG=1 -I/usr/lib/swi-prolog/include/
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <time.h> /* Time and date functions */
#include <SWI-Prolog.h> /* Prolog integration with C */

/* ---------------------------------------------------------------------- */
/* definitions */

#define VERSION (<+$VERSION$+>) /**< Version Number */

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/** @brief Ignore Int Return: Turn off -Wunused-result for a specific function call */
#define IGR(M) if(0==((int)M)){;}

/** @brief If PL_func fail, exit */
#define PL_TRY(M) if(0==((int)M)){IFDEBUG("PL_fail"); exit(EXIT_FAILURE);}

/* Vim template check for PROLOG: same filename and install function name */
#define INSTALL_<+$BASENAME$+> /**< Used when loading Vim Template */
#ifndef INSTALL_lib<+#PREFIX#+>
  #error "Can't compile: lib<+#PREFIX#+> (install function) different from <+$BASENAME$+> (filename)"
#endif

/* ---------------------------------------------------------------------- */
/* globals */

/** @brief context type for non-deterministic function calls */
typedef struct
{
    int d[6]; /**< dice faces: 0=available, -1=already used */
    int qtd; /**< quantity of faces available */
} context_dice_t;

int verb; /**< verbose level, global */

/* ---------------------------------------------------------------------- */
/* prototypes */

static void help(void); /* interna: mostra o help */
static void copyr(void); /* interna: mostra a versao e o copyright */
static int fat(int n); /* interna: calcula o fatorial de n */
static int s6semrepetir(context_dice_t *pc); /* interna: sorteio de 6 numeros sem repeticao */
static foreign_t <+#PREFIX#+>_fat(term_t n, term_t r); /* predicado: calcula o fatorial */
static foreign_t <+#PREFIX#+>_help(void); /* predicado: mostra o help */
static foreign_t <+#PREFIX#+>_copyright(void); /* predicado: mostra versao e copyright */
static foreign_t <+#PREFIX#+>_get_verbose(term_t t); /* predicado: pega valor verbose */
static foreign_t <+#PREFIX#+>_put_verbose(term_t t); /* predicado: ajusta valor verbose */
static foreign_t <+#PREFIX#+>_print_item(term_t l); /* predicado: imprime itens */
static foreign_t <+#PREFIX#+>_dice(term_t d, control_t ctrl); /* predicado: sorteio sem repeticao */
static foreign_t <+#PREFIX#+>_add_list(term_t l); /* predicado: soma itens de uma lista */
install_t install_lib<+#PREFIX#+>(void); /* instalacao das funcoes compartilhadas */

/* funcoes externas compartilhadas com PROLOG */
PL_extension shared_pred[] =
{
    /*{ "nomeprolog", aridade, funcaoc, PL_FA_<flags> }, */
    { "<+#PREFIX#+>_fat", 2, <+#PREFIX#+>_fat, 0 },
    { "<+#PREFIX#+>_help", 0, <+#PREFIX#+>_help, 0 },
    { "<+#PREFIX#+>_copyright", 0, <+#PREFIX#+>_copyright, 0 },
    { "<+#PREFIX#+>_get_verbose", 1, <+#PREFIX#+>_get_verbose, 0 },
    { "<+#PREFIX#+>_put_verbose", 1, <+#PREFIX#+>_put_verbose, 0 },
    { "<+#PREFIX#+>_print_item", 1, <+#PREFIX#+>_print_item, 0 },
    { "<+#PREFIX#+>_dice", 1, <+#PREFIX#+>_dice, PL_FA_NONDETERMINISTIC},
    { "<+#PREFIX#+>_add_list", 1, <+#PREFIX#+>_add_list, 0},
    { NULL, 0, NULL, 0 } /* linha final */
}; /**< Vector of registered shared functions */

/* ---------------------------------------------------------------------- */
/* funcao tem que ter o mesmo nome do arquivo */
/**
 * @ingroup GroupUnique
 * @brief Installs the shared functions in PROLOG's memory
 * @details When PROLOG executes use_foreign_library(foreign('lib<+#PREFIX#+>.so')),
 * it calls install_lib<+#PREFIX#+>() to register all shared functions
 * available.
 *
 * @warning This function must have the same name of the file its in.
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
install_t install_lib<+#PREFIX#+>(void)
{
    printf("Welcome to PROLOG calls C library template by Ruben Carlo Benante <rcb@%s>\n", "beco.cc");
    printf("%s - Version %13.6f, by <+$AUTHOR$+> <<+$EMAIL$+>>\n", "<+$BASENAME$+>", VERSION);
    printf("Installing lib<+#PREFIX#+>.\nUse <+#PREFIX#+>_help for help.\n");
    PL_register_extensions(shared_pred); /* registra as funcoes compartilhadas */
    /* PL_register_foreign("nome", aridade, func, FLAGS); */ /* outra opcao para registrar uma a uma */
    verb=0; /* verbose inicial */
    srand(time(NULL)); /* faca uma unica vez a mudanca da semente aleatoria */
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief A predicate to calculate a factorial of a number using C
 * @details This predicate can be called by PROLOG to calculate the factorial of n
 *
 * @param[in] n Predicate bounded with integer to calculate a factorial.
 * @param[out] r Predicate unbounded to return the factorial
 *
 * @retval TRUE If succeed.
 * @retval FALSE Some error occurred.
 *
 * @par Example
 * @code
 *    ?- <+#PREFIX#+>_fat(3,R).
 * @endcode
 *
 * @bug It returns 1 if asked to calculate a factorial of a negative number.
 * @todo Set it to fail if negative. Eliminate messages.
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static foreign_t <+#PREFIX#+>_fat(term_t n, term_t r)
{
    int in, ir, val;
    
    PL_TRY(PL_get_integer(n, &in)); /* pega inteiro in do termo n */
    ir=fat(in); /* calcula o fatorial */
    val = PL_unify_integer(r, ir); /* unifica o inteiro ir no termo r */
    if(!val)
    {
        printf("Some weird error in <+#PREFIX#+>_fat(_,_)\n");
        PL_fail;
    }
    printf("C solved: fat(%d)=%d\n", in, ir);
    PL_succeed;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Calculates the factorial of n
 * @details A simple and efective recursive function to
 * calculate the factorial of an integer.
 *
 * @param[in] n The number to be factorialized.
 *
 * @return Returns n!, factorial of n.
 *
 * @bug It returns 1 as result of any negative number n.
 * @warning Internal function, not to be used directly.
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static int fat(int n)
{
    if(n<=0)
        return 1;
    return n*fat(n-1);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Allows PROLOG to peek at verbose value
 * @details Gives access to verb variable that represents the ammount of messages
 * desired.
 *
 * @param[out] t Verbose value (integer)
 *
 * @retval TRUE If succeed.
 * @retval FALSE Some error occurred.
 *
 * @par Example
 * @code
 *    ?- <+#PREFIX#+>_get_verbose(T).
 * @endcode
 *
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static foreign_t <+#PREFIX#+>_get_verbose(term_t t)
{
    int val;
    /*val = PL_put_integer(t, verb); */ /* coloca verb no termo t */
    val = PL_unify_integer(t, verb); /* unifica o inteiro verb no termo t */
    if(!val)
    {
        printf("Some weird error in <+#PREFIX#+>_get_verbose(_)\n");
        PL_fail;
    }
    PL_succeed;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Allows PROLOG to set verbose value
 * @details Verbose controls the ammount of messages given by the functions.
 * This function allows PROLOG to set it to any (integer) desired value.
 *
 * @param[in] t The new verbose value
 *
 * @retval TRUE If succeed.
 * @retval FALSE Some error occurred.
 *
 * @par Example
 * @code
 *    ?- <+#PREFIX#+>_put_verbose(2).
 * @endcode
 *
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static foreign_t <+#PREFIX#+>_put_verbose(term_t t)
{
    int val;
    val = PL_get_integer(t, &verb); /* coloca o valor de t em verb */
    if(!val)
    {
        printf("Some weird error in <+#PREFIX#+>_put_verbose(_)\n");
        PL_fail;
    }
    PL_succeed;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints all given itens
 * @details A simple and efective recursive function to print all types
 * of PROLOG items.
 *
 * @param[in] t The item to be printed (any type)
 *
 * @retval TRUE If succeed.
 * @retval FALSE Some error occurred.
 *
 * @par Example
 * @code
 *    ?- <+#PREFIX#+>_print_item([a(b,"c"), 'd', 3, F, 3.14]).
 * @endcode
 * 
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static foreign_t <+#PREFIX#+>_print_item(term_t t)
{
    size_t len;
    int n;
    char *s;
    int arity;
    atom_t name;
    term_t a;
    
    switch(PL_term_type(t))
    {
        case PL_VARIABLE:
            PL_TRY(PL_get_chars(t, &s, CVT_VARIABLE));
            printf("%s", s);
            break;
        case PL_ATOM:
        case PL_INTEGER:
        case PL_FLOAT:
            PL_TRY(PL_get_chars(t, &s, CVT_ALL)); /* All but variable */
            printf("%s", s);
            break;
        case PL_STRING:
            PL_get_string_chars(t, &s, &len);
            printf("\"%s\"", s);
            break;
        case PL_TERM:
            a = PL_new_term_ref();
            PL_TRY(PL_get_name_arity(t, &name, &arity));
            printf("%s(", PL_atom_chars(name));
            for(n=1; n<=arity; n++)
            {
                PL_TRY(PL_get_arg(n, t, a));
                if(n > 1)
                    printf(", ");
                <+#PREFIX#+>_print_item(a);
            }
            printf(")");
            break;
        default:
            PL_fail; /* should never happen */
    }
    PL_succeed;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Adds all numbers (integers and floats) contained in a list
 * @details This functions follows a list to the end, ignoring non-numbers, and
 * adding all numbers, printing the result in the end
 *
 * @param[in] l The list to see through.
 *
 * @retval TRUE If succeed to the end (empty list []).
 * @retval FALSE Some error occurred.
 *
 * @par Example
 * @code
 *    ?- <+#PREFIX#+>_add_list([1, 1, [3, 4], a(5), 1.14]).
 *    Sum: 3.14
 *    true
 * @endcode
 *
 * @bug It is not recursive, meaning it will not go into another items.
 * @todo Make it recursive, adding numbers in lists inside lists.
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static foreign_t <+#PREFIX#+>_add_list(term_t l)
{
    int i;
    double a=0.0, f;
    term_t head, list;

    if(!PL_is_list(l))
    {
        printf("I need a list\n");
        PL_fail;
    }
    printf("I got a list. Let me add:\n");
    
    head = PL_new_term_ref(); /* the elements */
    list = PL_copy_term_ref(l); /* copy (we modify list) */
    
    while(PL_get_list(list, head, list))
    {
        if(PL_is_float(head))
        {
            PL_TRY(PL_get_float(head, &f)); /* pega float i do termo head */
            a+=f;
        }
        else
            if(PL_is_integer(head))
            {
                PL_TRY(PL_get_integer(head, &i)); /* pega inteiro i do termo head */
                a+=i;
            }
            /*else 
                if(PL_get_atom_chars(head, &s))
                    printf("%s\n", s);
                else
                    PL_fail;*/
    }
    printf("C solved: add_list = %.2f\n", a);
    return PL_get_nil(list); /* test end for [] */
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief A very funny function to get random numbers from 1 to 6, with no repetition
 * @details This function shows how to backtrack a C function when PROLOG asks for
 * more solutions. It will randomly chose a number from 1 to 6, without repetition,
 * until PROLOG is satisfied (prune) or run out of numbers (a failed redo).
 * 
 * @param[out] d An integer from 1 to 6
 * @param[out] ctrl Internal parameter, controled by PROLOG. Call without it (see example).
 *
 * @retval TRUE If succeed.
 * @retval FALSE If run out of numbers, or some error occurred.
 *
 * @par Example
 * @code
 *    ?- <+#PREFIX#+>_dice(X).
 *    X=3;
 *    X=1.
 *    true
 * @endcode
 *
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static foreign_t <+#PREFIX#+>_dice(term_t d, control_t ctrl)
{
    context_dice_t *ctxd=NULL;
    int i, r, val;
    switch(PL_foreign_control(ctrl))
    {
        case PL_FIRST_CALL:
            printf("First call\n");
            ctxd = malloc(sizeof(context_dice_t));
            for(i=0; i<6; i++)
                ctxd->d[i]=0;
            ctxd->qtd=6;
            r=s6semrepetir(ctxd); /* sorteia numero de 1 a 6 sem repeticao */
            val=PL_unify_integer(d, r); /* unifica o dado com o sorteio */
            if(!val)
            {
                printf("Some weird error in <+#PREFIX#+>_dice(_) FIRST_CALL\n");
                PL_fail;
            }
            PL_retry_address(ctxd); /* Succeed, mark return point */
        case PL_REDO:
            printf("Redo call\n");
            ctxd = PL_foreign_context_address(ctrl);
            if(ctxd->qtd<1)
            {
                free(ctxd);
                PL_fail;
            }
            r=s6semrepetir(ctxd); /* sorteia numero de 1 a 6 sem repeticao */
            val=PL_unify_integer(d, r); /* unifica o dado com o sorteio */
            if(!val)
            {
                printf("Some weird error in <+#PREFIX#+>_dice(_) REDO\n");
                PL_fail;
            }
            PL_retry_address(ctxd); /* Succeed, mark return point */
        case PL_PRUNED:
            printf("Prune call\n");
            ctxd = PL_foreign_context_address(ctrl);
            free(ctxd);
            PL_succeed; /* Succeed, no return point */
    }
    printf("Some weird error in <+#PREFIX#+>_dice(_) DEFAULT\n");
    PL_fail;  /* This should never happen */
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Internal function. Random choses another number from 1 to 6 without repetition.
 * @details Internal function auxiliar of <+#PREFIX#+>_dice(). It uses its context to
 * remember which numbers have being draw.
 *
 * @param[in] pc Context from <+#PREFIX#+>_dice(). Necessary because this function can
 * be safely used recursively by PROLOG.
 *
 * @return Returns r, the number draw.
 *
 * @warning Not to be used directly. It does need context. Also, it will not check if
 * there are still numbers. The caller makes sure it is safe to draw another number.
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static int s6semrepetir(context_dice_t *pc)
{
    int s, i, r;
    s = rand()%pc->qtd+1;
    i=0;
    while(s)
    {
        if(pc->d[i]==0)
        {
            r=i+1; /* sorteado de 1 a 6 */
            s--;
        }
        i++;
    }
    pc->d[r-1]=-1; /* este item ja foi sorteado */
    pc->qtd--; /* diminuiu a quantidade disponivel */
    return r;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information
 * @details Prints help information and returns
 *
 * @retval TRUE If succeed.
 *
 * @par Example
 * @code
 *    ?- <+#PREFIX#+>_help.
 * @endcode
 * 
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static foreign_t <+#PREFIX#+>_help(void)
{
    help();
    PL_succeed;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information
 * @details Prints help information and exit
 * @return Void
 * @warning Internal function, not to be used directly.
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static void help(void)
{
    IFDEBUG("help()\n");
    printf("%s - %s\n", "<+$BASENAME$+>", "<+#BRIEF#+>");
    printf("\nUsage:\n");
    printf("?- <+#PREFIX#+>_fat(N,R).\n\
                         Calculates factorial of N (bounded), returns R (unbounded).\n");
    printf("?- <+#PREFIX#+>_get_verbose(T).\n\
                         Gets current verbose value.\n");
    printf("?- <+#PREFIX#+>_put_verbose(2).\n\
                         Sets a new verbose value.\n");
    printf("?- <+#PREFIX#+>_print_item([a(b,\"c\"), 'd', 3, F, 3.14]).\n\
                         Prints a complex term.\n");
    printf("?- <+#PREFIX#+>_add_list([1, 1, [3, 4], a(5), 1.14]).\n\
                         Adds numbers in a list (only level 0).\n");
    printf("?- <+#PREFIX#+>_dice(X).\n\
                         Draws numbers from 1 to 6 in a non-repetition lottery.\n");
    printf("?- <+#PREFIX#+>_help.\n\
                         Gives this help message.\n");
    printf("?- <+#PREFIX#+>_copyright.\n\
                         Shows version and copyright information.\n");
    /* add more options here */
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "<+$AUTHOR$+>", "<+$EMAIL$+>");
    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information
 * @details Prints version and copyright information and returns
 *
 * @retval TRUE If succeed.
 *
 * @par Example
 * @code
 *    ?- <+#PREFIX#+>_copyright.
 * @endcode
 *
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static foreign_t <+#PREFIX#+>_copyright(void)
{
    copyr();
    PL_succeed;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information
 * @details Prints version and copyright information and exit
 * @return Void
 * @warning Internal function, not to be used directly.
 * @note You can read more about it at <<a href="http://<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * @author <+$AUTHOR$+>
 * @version <+$VERSION$+>
 * @date <+$DATE$+>
 *
 */
static void copyr(void)
{
    IFDEBUG("copyr()\n");
    printf("%s - Version %13.6f\n", "<+$BASENAME$+>", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>. This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", <+$YEAR$+>, "<+$AUTHOR$+>", "<+$EMAIL$+>");
    if(verb>3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    return;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>      Version 20150619.231433 */
