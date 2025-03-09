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
 *   Webpage: <+$WEBPAGE$;R+++++++++++++++++++++++++++++++++++++++++++++++>*
 *   Phone: <+$PHONE$;R+++++++++++++++++++++++++++++++++++++++++++++++++++>*
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file <+$FILENAME$+>
 * \ingroup GroupUnique
 * \brief <+#BRIEF#+>
 * \details This is a CPP Header File with HPP extension
 * \version <+$VERSION$+>
 * \date <+$DATE$+>
 * \author <+$AUTHOR$+> <<<+$EMAIL$+>>>
 * \par Webpage
 * <<a href="<+$WEBPAGE$+>"><+$WEBPAGE$+></a>>
 * \copyright (c) <+$YEAR$+> GNU GPL v2
 * \note This program is free software: you can redistribute it
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
 * \todo Now that you have the template, hands on! Programme!
 * \warning Be carefull not to lose your mind in small things.
 * \bug This file right now does nothing usefull
 *
 */

#ifndef _<+$UBASENAME$+>_HPP
#define _<+$UBASENAME$+>_HPP

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

/* #include <concepts> */ /* (C++20) Fundamental library concepts */
/* #include <coroutine> */ /* (C++20) Coroutine support library */
/* #include <any> */ /* (C++17, Utilities library) std::any class */
/* #include <bitset> */ /* (Utilities library) std::bitset class template */
/* #include <chrono> */ /* (C++11, Utilities library) C++ time utilites */
/* #include <compare> */ /* (C++20, Utilities library) Three-way comparison operator support */
/* #include <csetjmp> */ /* (Utilities library) Macro (and function) that saves (and jumps) to an execution context */
/* #include <csignal> */ /* (Utilities library) Functions and macro constants for signal management */
/* #include <cstdarg> */ /* (Utilities library) Handling of variable length argument lists */
/* #include <cstddef> */ /* (Utilities library) Standard macros and typedefs */
/* #include <cstdlib> */ /* (Utilities library) General purpose utilities: program control, dynamic memory allocation, random numbers, sort and search */
/* #include <ctime> */ /* (Utilities library) C-style time/date utilites */
/* #include <expected> */ /* (C++23, Utilities library) std::expected class template */
/* #include <functional> */ /* (Utilities library) Function objects, Function invocations, Bind operations and Reference wrappers */
/* #include <initializer_list> */ /* (C++11, Utilities library) std::initializer_list class template */
/* #include <optional> */ /* (C++17, Utilities library) std::optional class template */
/* #include <source_location> */ /* (C++20, Utilities library) Supplies means to obtain source code location */
/* #include <tuple> */ /* (C++11, Utilities library) std::tuple class template */
/* #include <type_traits> */ /* (C++11, Utilities library) Compile-time type information */
/* #include <typeindex> */ /* (C++11, Utilities library) std::type_index */
/* #include <typeinfo> */ /* (Utilities library) Runtime type information utilities */
/* #include <utility> */ /* (Utilities library) Various utility components */
/* #include <variant> */ /* (C++17, Utilities library) std::variant class template */
/* #include <version> */ /* (C++20, Utilities library) Supplies implementation-dependent library information */
/* #include <memory> */ /* (Dynamic memory management) High-level memory management utilities */
/* #include <memory_resource> */ /* (C++17, Dynamic memory management) Polymorphic allocators and memory resources */
/* #include <new> */ /* (Dynamic memory management) Low-level memory management utilities */
/* #include <scoped_allocator> */ /* (C++11, Dynamic memory management) Nested allocator class */
/* #include <cfloat> */ /* (Numeric limits) Limits of floating-point types */
/* #include <cinttypes> */ /* (C++11, Numeric limits) Formatting macros, intmax_t and uintmax_t math and conversions */
/* #include <climits> */ /* (Numeric limits) Limits of integral types */
/* #include <cstdint> */ /* (C++11, Numeric limits) Fixed-width integer types and limits of other types */
/* #include <limits> */ /* (Numeric limits) Uniform way to query properties of arithmetic types */
/* #include <cerrno> */ /* (Error handling) Macro containing the last error number */
/* #include <exception> */ /* (Error handling) Exception handling utilities */
/* #include <stdexcept> */ /* (Error handling) Standard exception objects */
/* #include <system_error> */ /* (C++11, Error handling) Defines std::error_code, a platform-dependent error code */
/* #include <stacktrace> */ /* (C++23, Error handling) Stacktrace library */
/* #include <cctype> */ /* (Strings library) Functions to determine the category of narrow characters */
/* #include <charconv> */ /* (C++17, Strings library) std::to_chars and std::from_chars */
/* #include <cstring> */ /* (Strings library) Various narrow character string handling functions */
/* #include <cuchar> */ /* (C++11, Strings library) C-style Unicode character conversion functions */
/* #include <cwchar> */ /* (Strings library) Various wide and multibyte string handling functions */
/* #include <cwctype> */ /* (Strings library) Functions to determine the catagory of wide characters */
/* #include <format> */ /* (C++20, Strings library) Formatting library including std::format */
/* #include <string> */ /* (Strings library) std::basic_string class template */
/* #include <string_view> */ /* (C++17, Strings library) std::basic_string_view class template */
/* #include <array> */ /* (C++11, Containers library) std::array container */
/* #include <deque> */ /* (Containers library) std::deque container */
/* #include <forward_list> */ /* (C++11, Containers library) std::forward_list container */
/* #include <list> */ /* (Containers library) std::list container */
/* #include <map> */ /* (Containers library) std::map and std::multimap associative containers */
/* #include <queue> */ /* (Containers library) std::queue and std::priority_queue container adaptors */
/* #include <set> */ /* (Containers library) std::set and std::multiset associative containers */
/* #include <span> */ /* (C++20, Containers library) std::span view */
/* #include <stack> */ /* (Containers library) std::stack container adaptor */
/* #include <unordered_map> */ /* (C++11, Containers library) std::unordered_map and std::unordered_multimap unordered associative containers */
/* #include <unordered_set> */ /* (C++11, Containers library) std::unordered_set and std::unordered_multiset unordered associative containers */
/* #include <vector> */ /* (Containers library) std::vector container */
/* #include <iterator> */ /* (Iterators library) Range iterators */
/* #include <ranges> */ /* (C++20, Ranges library) Range access, primitives, requirements, utilities and adaptors */
/* #include <algorithm> */ /* (Algorithms library) Algorithms that operate on ranges */
/* #include <execution> */ /* (C++17, Algorithms library) Predefined execution policies for parallel versions of the algorithms */
/* #include <bit> */ /* (C++20, Numerics library) Bit manipulation functions */
/* #include <cfenv> */ /* (C++11, Numerics library) Floating-point environment access functions */
/* #include <cmath> */ /* (Numerics library) Common mathematics functions */
/* #include <complex> */ /* (Numerics library) Complex number type */
/* #include <numbers> */ /* (C++20, Numerics library) Math constants */
/* #include <numeric> */ /* (Numerics library) Numeric operations on values in ranges */
/* #include <random> */ /* (C++11, Numerics library) Random number generators and distributions */
/* #include <ratio> */ /* (C++11, Numerics library) Compile-time rational arithmetic */
/* #include <valarray> */ /* (Numerics library) Class for representing and manipulating arrays of values */
/* #include <clocale> */ /* (Localization library) C localization utilities */
/* #include <codecvt> */ /* (C++11)(deprecated in C++17, Localization library) Unicode conversion facilities */
/* #include <locale> */ /* (Localization library) Localization utilities */

/* #include <filesystem> */ /* (C++17, Filesystem library) std::path class and supporting functions */
/* #include <regex> */ /* (C++11, Regular Expressions library) Classes, algorithms and iterators to support regular expression processing */
/* #include <atomic> */ /* (C++11, Atomic Operations library) Atomic operations library */
/* #include <barrier> */ /* (C++20, Thread support library) Barriers */
/* #include <condition_variable> */ /* (C++11, Thread support library) Thread waiting conditions */
/* #include <future> */ /* (C++11, Thread support library) Primitives for asynchronous computations */
/* #include <latch> */ /* (C++20, Thread support library) Latches */
/* #include <mutex> */ /* (C++11, Thread support library) Mutual exclusion primitives */
/* #include <semaphore> */ /* (C++20, Thread support library) Semaphores */
/* #include <shared_mutex> */ /* (C++14, Thread support library) Shared mutual exclusion primitives */
/* #include <stop_token> */ /* (C++20, Thread support library) Stop tokens for std::jthread */
/* #include <thread> */ /* (C++11, Thread support library) std::thread class and supporting functions */
/* #include <stdatomic.h> */ /*(C++23, Compatibility) Defines _Atomic and provides corresponding components in the C stdlib */

/* #include "libuser.hpp" */ /* your personal user library together with libuser.cpp */
/* #include "<+$BASENAME$+>.hpp" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* g++ -DVERSION="0.1.160612.142306" */
#define VERSION "20221217.180026" /* Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* g++ -DDEBUG=1 */
#define DEBUG 0 /* Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <cassert> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */

/* Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /* string buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* classes : better located at libxxx.h */

class document
{
    public:
        void help(void); /* print some help */
        void copyr(void); /* print version and copyright information */
};

/* add more classes here */

#endif /* NOT def _<+$UBASENAME$+>_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : CPP config - Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>      Version 20250309.153530 */

