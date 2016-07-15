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

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Hunt The Wumpus - World Simulator
%
%   Author: 
%     - Ruben Carlo Benante (rcb@beco.cc)
%   Copyright: 2012 - 2016
%   License: GNU GPL Version 2.0
%
%   Special thanks to:
%     - Original by Gregory Yob (1972)
%     - Larry Holder (accessed version Oct/2005)
%     - Walter Nauber 09/02/2001
%     - An Anonymous version of Hunt The Wumpus with menus (aeric? 2012?)
%
% A Prolog implementation of the Wumpus world invented by Gregory Yob
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% To define an agent you will need:
%   use module wumpus.pl to load the simulator
%   init_agent called once at start
%   run_agent called each turn, gives perceptions to agent and waits an action
%   world_setup([Size, Type, Move, Gold, Pit, Bat, [RandS, RandA]]) to setup once
%
%       +--------+-----------+
%       |  Type  |    Size   |
%       +--------+-----------+
%       | fig62  | 4 (fixed) |
%       | grid   | 2 ... 9   |
%       | dodeca | 20 (fixed)|
%       +--------+-----------+
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Lista de Percepcao: [Stench, Breeze, Glitter, Bump, Scream, Rustle]
% Traducao: [Fedor, Vento, Brilho, Trombada, Grito, Ruido]
% Acoes possiveis (abreviacoes para jogo no modo manual apenas):
% goforward (go)                - andar
% turnright (turn, turnr ou tr) - girar sentido horario
% turnleft (turnl ou tl)        - girar sentido anti-horario
% grab (gr)                     - pegar o ouro
% climb (cl)                    - sair da caverna
% shoot (sh)                    - atirar a flecha
% sit (si)                      - sentar (nao faz nada, passa a vez)
%
% Custos:
% Andar/Girar/Pegar/Sair/Atirar/Sentar: -1
% Morrer: -1000 (buraco, wumpus ou fadiga)
% Matar Wumpus: +1000
% Sair com ouro: +500 para cada pepita
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* ---------------------------------------------------------------------- */
/* Files, dynamic clauses, modules, etc. */
/**
 * @ingroup GroupUnique
 * @brief Loading wumpus module
 * @param[in] A List of files
 * @retval TRUE on success.
 * @retval FALSE on fail.
 */

:- use_module(wumpus, [start/0]). % agente usa modulo simulador

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% world_setup([Size, Type, Move, Gold, Pit, Bat, Adv])
%
% Size and Type: - fig62, 4
%                - grid, [2-9] (default 4)
%                - dodeca, 20
%
% Configuration:
%    1.   Size: 0,2..9,20, where: grid is [2-9] or 0 for random, dodeca is 20, fig62 is 4.
%    2.   Type: fig62, grid or dodeca
%    3.   Move: stander, walker, runner (wumpus movement)
%    4.   Gold: Integer is deterministic number, float from 0.0<G<1.0 is probabilistic
%    5.   Pits: Idem, 0 is no pits.
%    6.   Bats: Idem, 0 is no bats.
%    7.   Adv: a list with advanced configuration in the form [RandS, RandA]:
%       - RandS - yes or no, random agent start position
%       - RandA - yes or no, random agent start angle of orientation
%
% examples: 
% world_setup([4, grid, stander, 0.1, 0.2, 0.1, [no, no]]). % default
% world_setup([5, grid, stander, 1, 3, 0.1, [yes]]). % size 5, 1 gold, 3 pits, some bats prob. 0.1, agent randomly positioned
%
%   Types of Wumpus Movement
%       walker    : original: moves when it hears a shoot, or you enter its cave
%       runner    : go forward and turn left or right on bumps, maybe on pits
%       wanderer  : arbitrarily choses an action from [sit,turnleft,turnright,goforward]
%       spinner   : goforward, turnright, repeat.
%       hoarder   : go to one of the golds and sit
%       spelunker : go to a pit and sit
%       stander   : do not move (default)
%       trapper   : goes hunting agent as soon as it leaves [1,1]; goes home otherwise
%       bulldozer : hunt the agent as soon as it smells him
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Mundo: 
%    4x4, quadrado, wumpus anda quando atira ou quando entra na casa dele
%    probabilidade de ouro 0.1, de buracos 0.2, um unico morcego
%    agente inicia em casa aleatoria [yes]
%    Maximo de acoes antes de morrer de fome: Size^2x4 = 4x4x4 = 64

/**
 * @ingroup GroupUnique
 * @brief World setup 
 * @param[in] A List of configurations
 * @retval Always TRUE (it is a fact).
*/
world_setup([4, grid, walker, 0.1, 0.2, 1, [yes]]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Start coding from here

/**
 * @ingroup GroupUnique
 * @brief Defining dynamic clauses
 * @param[in] A List of clauses
 * @retval TRUE on success.
 * @retval FALSE on fail.
*/
:- dynamic([
    verbosecounter/1,   % contador verbose 
    flecha/1]).         % contador de flechas

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
 *------------------------------------------------------------------------------
 * Ideia para atualizar modelo de mundo 
 *
 * Percepcoes: P eh lista = [Stench,Breeze,Glitter,Bump,Scream,Rustle]
 * atualizamodelo(P) :-
 *     atualizacheiro(P),
 *     atualizabrisa(P),
 *     atualizabrilho(P),
 *     atualizabatida(P),
 *     atualizagrito(P),
 *     atualizaruido(P).
 *
 *------------------------------------------------------------------------------
 * Agente fixo na Figura 62 do livro de Russel e Norvig
 *
 *  * @ingroup GroupUnique
 *  * @brief init_agent is det
 *  * @details This predicate is called by Wumpus Simulator and is the starting
 *  *          point of the simulation. Used to initialize the agent.
 *  *          This example uses assert/retract to keep track of things.
 *  * @return TRUE always.
 * init_agent :-
 *     inicia_fig62.
 *
 *  * @ingroup GroupUnique
 *  * @brief inicia_fig62 is det
 *  * @details This predicate makes sure the memory is clean and ready
 *  *          for a new start.
 *  *          It keeps a list of pre-determined actions to follow to
 *  *          solve, in an ad-hoc way, the Russel & Norvig famous figure 62.
 *  * @return TRUE always.
 * inicia_fig62 :-
 *     retractall(fig62acts(_)),
 *     assert(fig62acts([goforward,turnleft,goforward,goforward,grab,
 *                     turnleft,turnleft,goforward,goforward,turnright,
 *                     goforward,climb])).
 *
 *  * @ingroup GroupUnique
 *  * @brief run_agent is det
 *  * @details It passes along Perception and Action to fig62_agent,
 *  *          Also prints action taken and the current world.
 *  * @return TRUE always.
 * run_agent(Percept,Action) :-
 *     fig62_agent(Percept,Action),
 *     format('~nacao do agente: (~w)~n',Action).
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
 *     retract(fig62acts([Action|Actions])),
 *     assert(fig62acts(Actions)).
 *
 *------------------------------------------------------------------------------
 * Exemplo de agente aleatorio
 *
 *  * @ingroup GroupUnique
 *  * @brief random_agent is det
 *  * @details It ignores perception, and grab a aleatory item from the list.
 *  * @param[in] A The perception, ignored.
 *  * @param[out] B The action, an aleatory item from the list of possibilities.
 *  * @return TRUE always.
 * random_agent(_,Action) :-
 *     random_member(Action,[goforward,turnleft,turnright,grab,shoot,climb]).
 */

/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */
