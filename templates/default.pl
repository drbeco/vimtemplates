%#!/usr/bin/swipl -q -G64m -L64m -t main -f none -s
%  Uncomment the live above to run as executable prolog script
%  -q : Operate silently
%  -G : Set global stack
%  -L : Set local stack
%  -t main : Set goal to main
%  -f none : Do not use an initialization file
%  -s : Turn this file into an executable
%       prolog script (use chmod +x <+$FILENAME$+>)
%

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

/**
 * @file <+$FILENAME$+>
 * @ingroup GroupUnique
 * @brief <+#BRIEF#+>
 * @details A simple example of PROLOG source documented with doxygen.
 *
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
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull.
 *
 */

/* ---------------------------------------------------------------------- */
/* Files, dynamic clauses, modules, etc. */
/**
 * @ingroup GroupUnique
 * @brief Defining dynamic clauses
 * @param[in] A List of clauses
 * @retval TRUE on success.
 * @retval FALSE on fail.
 */
:- dynamic([verbosecounter/1]).

/* ---------------------------------------------------------------------- */
/* Facts and Rules */
/**
 * @ingroup GroupUnique
 * @brief main is det
 * @details Initializes memory and other tasks
 * @retval TRUE If it can prove main.
 * @retval FALSE If main can't be proven.
 */
main :-
    writeln('Initializing...').

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief help is det
 * @details Shows a help message on how to use <+$BASENAME$+>
 * @return TRUE always.
 */
help :-
    writeln('<+$BASENAME$+> - <+#BRIEF#+>'),
    writeln('Usage:'),
    writeln('$swipl -s <+$BASENAME$+>'),
    /* Stand alone scripts, invert: comment above, uncomment bellow. */
    /* writeln('$./<+$BASENAME$+>'), */
    writeln('Clauses:'),
    writeln('  main.       Starts the main program.'),
    writeln('  copyright.  Shows version and copyright information.'),
    writeln('  version.    Returns version number.'),
    writeln('  help.       Shows this help message.'),
    writeln('  verbose.    Sets verbose level (cumulative).'),
    /* add more options here */
    writeln('  Exit status:'),
    writeln('    TRUE if ok'),
    writeln('    FALSE if some error occurred.'),
    writeln('  Todo:'),
    writeln('    Read options from OS'),
    writeln('  Author:'),
    writeln('    Written by <+$AUTHOR$+> <<+$EMAIL$+>>').

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief copyright is det
 * @details Shows version and copyright information.
 * @return TRUE always.
 */
copyright :-
    writeln('<+$BASENAME$+> - Version <+$VERSION$+>'),
    writeln('Copyright (C) <+$YEAR$+> <+$AUTHOR$+> <<+$EMAIL$+>>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.').

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief verbose is det
 * @details Increases verbose level by one.
 * @return TRUE always.
 */
verbose :-
    verbosecounter(X),
    retractall(verbosecounter(_)),
    Y is X + 1,
    assert(verbosecounter(Y)).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief verbose0 is det
 * @details Sets verbose level to zero.
 * @return TRUE always.
 */
verbose0 :-
    retractall(verbosecounter(_)),
    assert(verbosecounter(0)).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief version is a fact
 * @details It will return the version number of program <+$BASENAME$+>.
 * @param[out] A It's a string with the version number.
 * @return TRUE always.
 */
version('<+$VERSION$+>').

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief pai(?NomePai, ?NomeFilho) is det
 * @details O predicado pai indica quem eh o pai de determinado filho(a)
 *
 * @param[in,out] A is the father's name
 * @param[in,out] B is the son's (daughter's) name
 * @retval TRUE In pai(NomePai, NomeFilho) if NomePai is father of NomeFilho.
 * @retval FALSE otherwise.
*/
pai(joao,pedro).
pai(joao,clara).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief mae(?NomeMae, ?NomeFilho) is det
 * @details O predicado mae indica quem eh a mae de determinado filho(a)
 *
 * @param[in,out] A Mother's name.
 * @param[in,out] B Son's (daughter's) name.
 * @retval TRUE In mae(NomeMae, NomeFilho) if NomeMae is mother of NomeFilho.
 * @retval FALSE otherwise.
*/
mae(maria,pedro).
mae(maria,manoel).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief homem(?NomeHomem)
 * @details Indica que o nome apontado eh homem
 *
 * @param[in,out] A name of a masculine person.
 * @retval TRUE If homem(NomeHomem) is man.
 * @retval FALSE otherwise.
*/
homem(joao).
homem(pedro).
homem(manoel).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief mulher(+NomeMulher)
 * @details Indica que o nome apontado eh mulher
 *
 * @param[in,out] A is a feminine person.
 * @retval TRUE If mulher(NomeMulher) is woman.
 * @retval FALSE otherwise.
*/
mulher(maria).
mulher(clara).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief pais(?NomePais, ?NomeFilho)
 * @details Indica que NomePais eh o pai ou a mae do(a) NomeFilho(a)
 *
 * @param[in,out] A Father's or mother's name (parent).
 * @param[in,out] B B the son's (daughter's) name.
 * @retval TRUE In pais(NomePais, NomeFilho) if NomePais is father or mother of Nomefilho.
 * @retval FALSE otherwise.
*/
pais(X,Y) :-
    pai(X,Y).
pais(X,Y) :-
    mae(X,Y).

/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */
