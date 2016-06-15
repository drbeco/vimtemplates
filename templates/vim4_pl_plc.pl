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

/**
 * @file <+$FILENAME$+>
 * @ingroup GroupUnique
 * @brief <+#BRIEF#+>
 * @details Este arquivo define um modulo chamado lib<+#PREFIX#+>
 * e le uma biblioteca compartilhada lib<+#PREFIX#+>.so
 * permitindo o uso de funcoes em C de dentro do ambiente PROLOG.
 *
 * Este modulo deve ser executado com
 *   $swipl -s lib<+#PREFIX#+>.pl -q
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
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull.
 *
 */

/* ---------------------------------------------------------------------- */
/* Files, dynamic clauses, modules, etc. */
/**
 * @ingroup GroupUnique
 * @brief Creating C shared library module
 * @param[in] A The module name
 * @param[in] B List of external clauses imported
 * @retval TRUE on success.
 * @retval FALSE on fail.
 */
:- module(lib<+#PREFIX#;R+>, [<+#PREFIX#+>_fat/2,
                              <+#PREFIX#+>_help/0,
                              <+#PREFIX#+>_copyright/0,
                              <+#PREFIX#+>_get_verbose/1,
                              <+#PREFIX#+>_put_verbose/1,
                              <+#PREFIX#+>_print_item/1,
                              <+#PREFIX#+>_add_list/1]).

/**
 * @ingroup GroupUnique
 * @brief Add local path to search library ".so"
 * @param[in] A New directory to add to search path
 * @retval TRUE on success.
 * @retval FALSE on fail.
 */
:- asserta(user:file_search_path(foreign, '.')).

/**
 * @ingroup GroupUnique
 * @brief Installs shared library ".so"
 * @param[in] A The extern library name to load and install
 * @retval TRUE on success.
 * @retval FALSE on fail.
 */
:- use_foreign_library(foreign('lib<+#PREFIX#+>.so')).

/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150619.231433 */
