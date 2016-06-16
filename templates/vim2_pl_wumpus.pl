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
 * @details Write details of the program here
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
 * @brief Loading wumpus module
 * @param[in] A List of files
 * @retval TRUE on success.
 * @retval FALSE on fail.
 */
:- load_files([wumpus1]).
/**
 * @ingroup GroupUnique
 * @brief Defining dynamic clauses
 * @param[in] A List of clauses
 * @retval TRUE on success.
 * @retval FALSE on fail.
*/
:- dynamic([verbosecounter/1, estou/2, direcao/1, flecha/1, ouro/1, andei/1, andarei/1, seguras/1]).

/* ---------------------------------------------------------------------- */
/* Facts and Rules */
/**
 * @ingroup GroupUnique
 * @brief main is det
 * @details Inicializa memoria e inicia o programa
 * @retval TRUE If it can prove main.
 * @retval FALSE If main can't be proven.
 */
main :-
  writeln('Initializing...'),
  start. /*  from Wumpus module. */

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
/*
 * Bellow a skeleton of a simple agent to run the Wumpus World
 *
 * To define:
 *   init_agent
 *   restart_agent
 *   run_agent
 *
 * Perception order:
 * [Stench, Breeze, Glitter, Bump,     Scream]
 * [Fedor,  Vento,  Brilho,  Trombada, Grito]
 * initialize([F,V,B,T,G])
 *
 * Actions:
 * goforward - avançar
 * turnright - girar 90 graus para direita
 * turnleft - girar 90 graus para esquerda
 * grab - pegar o ouro
 * climb - escalar para fora da caverna (na casa 1,1)
 * shoot - atirar a flecha
 */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief init_agent is det
 * @details This predicate is called by Wumpus Simulator and is the starting
 *          point of the simulation. Used to initialize the agent.
 * @return TRUE always.
 */
init_agent :-
  verbose0.

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief restart_agent is det
 * @details Used in case of many simulations in a trial. This restarts the agent.
 *          Usually it calls init_agent, but can be used also to free memory.
 * @return TRUE always.
 */
restart_agent :-
 init_agent.

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief run_agent(+Percepcao, -Acao) is det
 * @details It is called in every step of the simulation. The agent receives
 *          perceptions from the world and must return an action.
 *          Here it is set to call cabeca_dura() to chose an action.
 *
 * @param[in] A Receives a list in the form:
 *                        [Stench, Breeze, Glitter, Bump,     Scream]
 *           (portuguese) [Fedor,  Vento,  Brilho,  Trombada, Grito]
 * @param[out] B Returns an action to performe. Must be one of the valid options:
 *        goforward, turnright, turnleft, grab, climb, shoot
 * @return TRUE always.
 */
run_agent(Percepcao, Acao) :-
 cabeca_dura(Percepcao, Acao).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief cabeca_dura(?Percepcao, -Acao) is det
 * @details It is called in every step of the simulation, by run_agent.
 *          This predicate calculates the action. In the example bellow,
 *          it ignores all perceived items of the list, and simply
 *          walks forward.
 *
 * @param[in] A The perception of the world, as list. This simple program
 *            ignores it using an anonymous ('_') variable.
 * @param[out] B An action to execute in this particular step.
 *               This stronghead always return action goforward!
 * @return TRUE always.
 */
cabeca_dura(_,goforward).

/*
 * Abaixo mais exemplos de uso:
 *
 * Percepcoes: P eh lista = [Stench,Breeze,Glitter,Bump,Scream]
 * atualizamodelo(P) :-
 *    atualizacheiro(P),
 *    atualizabrisa(P),
 *    atualizabrilho(P),
 *    atualizabatida(P),
 *    atualizagrito(P).
 *
 * Agente fixo na Figura 62 do livro de Russel e Norvig
 *
 *  * @ingroup GroupUnique
 *  * @brief init_agent is det
 *  * @details This predicate is called by Wumpus Simulator and is the starting
 *  *          point of the simulation. Used to initialize the agent.
 *  *          This example uses assert/retract to keep track of things.
 *  * @return TRUE always.
 * init_agent :-
 *  inicia_fig62.
 *
 *  * @ingroup GroupUnique
 *  * @brief restart_agent is det
 *  * @details Simply call inicia_fig62
 *  * @return TRUE always.
 * restart_agent :-
 *  inicia_fig62.
 *
 *  * @ingroup GroupUnique
 *  * @brief inicia_fig62 is det
 *  * @details This predicate makes sure the memory is clean and ready
 *  *          for a new start.
 *  *          It keeps a list of pre-determined actions to follow to
 *  *          solve, in an ad-hoc way, the Russel & Norvig famous figure 62.
 *  * @return TRUE always.
 * inicia_fig62 :-
 *   retractall(fig62acts(_)),
 *   assert(fig62acts([goforward,turnleft,goforward,goforward,grab,
 *                     turnleft,turnleft,goforward,goforward,turnright,
 *                     goforward,climb])).
 *
 *  * @ingroup GroupUnique
 *  * @brief run_agent is det
 *  * @details It passes along Perception and Action to fig62_agent,
 *  *          Also prints action taken and the current world.
 *  * @return TRUE always.
 * run_agent(Percept,Action) :-
 *   fig62_agent(Percept,Action),
 *   format('~nacao do agente: (~w)~n',Action),
 *   display_world.
 *
 *  * @ingroup GroupUnique
 *  * @brief fig62_agent is det
 *  * @details It ignores perception, grab the first (head) item of the
 *  *          action list to bound to Action and returns.
 *  *          Before returning, makes sure to remember that the list is
 *  *          one action short.
 *  * @param[in] A The perception (ignored by anonymous variable).
 *  * @param[out] B The new action from the list.
 *  * @return TRUE always.
 * fig62_agent(_,Action) :-
 *   retract(fig62acts([Action|Actions])),
 *   assert(fig62acts(Actions)).
 *
 *  * @ingroup GroupUnique
 *  * @brief random_agent is det
 *  * @details It ignores perception, and grab a aleatory item from the list.
 *  * @param[in] A The perception, ignored.
 *  * @param[out] B The action, an aleatory item from the list of possibilities.
 *  * @return TRUE always.
 * random_agent(_,Action) :-
 *   random_member(Action,[goforward,turnleft,turnright,grab,shoot,climb]).
 */

/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */
