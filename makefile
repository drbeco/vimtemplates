#***************************************************************************
#*   makefile Autoversion                    Version 20160614.151147       *
#*                                                                         *
#*   This makefile template sets BUILD and VERSION and gives options       *
#*   to compile a diverse set of programs                                  *
#*   Copyright (C) 2016 by Ruben Carlo Benante                             *
#***************************************************************************
#*   This program is free software; you can redistribute it and/or modify  *
#*   it under the terms of the GNU General Public License as published by  *
#*   the Free Software Foundation; version 2 of the License.               *
#*                                                                         *
#*   This program is distributed in the hope that it will be useful,       *
#*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
#*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
#*   GNU General Public License for more details.                          *
#*                                                                         *
#*   You should have received a copy of the GNU General Public License     *
#*   along with this program; if not, write to the                         *
#*   Free Software Foundation, Inc.,                                       *
#*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
#***************************************************************************
#*   To contact the author, please write to:                               *
#*   Ruben Carlo Benante                                                   *
#*   Email: rcb@beco.cc                                                    *
#*   Webpage: http://drbeco.github.io/                                     *
#***************************************************************************

.PHONY: clean cleanall
.PRECIOUS: %.o
SHELL=/bin/bash -o pipefail

MAJOR = <+#MAJOR#+>
MINOR = <+#MINOR#+>
BUILD = $(shell date +"%g%m%d.%H%M%S")
DEFSYM = $(subst .,_,$(BUILD))
VERSION = "\"$(MAJOR).$(MINOR).$(BUILD)\""
CC = gcc
# Some gcc flags:
# 	-S -masm=att -masm=intel -E -x lang
CFLAGS = <+#CFLAGS#+>
#more CFLAGS: 
#	-Wall -Wextra -g -O0 -c -std=gnu99
#	-std=gnu89 -std=gnu99 -std=gnu11 -std=c89 -std=c99 -std=c11
# 	-Werror -ansi -Wpedantic -pedantic-error
# 	-g0 -g3 -s -Og -Os -O1 -O3 -pg -Ofast
# 	-Wchar-subscripts -Wshadow
# 	-Wno-unused-variable -Wno-unused-function -Wno-unused
# 	-Wpointer-arith -Wmissing-prototypes -Wwrite-strings
# 	-Wformat-security -Wmissing-format-attribute -Wstrict-prototypes 
#	-fsave-memoized -fmemoize-lookups -fPIC -fpic -fno-inline -fomit-frame-pointer 
#	-finstrument-functions -fstack-check -fvisibility=hidden -fwhole-program -flto
#	-m486 -m64 -m32 -march=i586 -mtune=i586 -mtune=generic
#	-mw32 -mwindows -mconsole -mthread -mdll
# 	`allegro-config --cflags`
CPPFLAGS = -DVERSION=$(VERSION) -DBUILD="\"$(BUILD)\"" -DDEBUG=<+#DDEBUG#+>
#more CPPFLAGS:
#	-DQT_THREAD_SUPPORT -D_REENTRANT -D_BSD_SOURCE 
# 	-D_XOPEN_SOURCE=500 -D_XOPEN_SOURCE=700
LDLIBS = -Wl,--defsym,BUILD_$(DEFSYM)=0 <+#LDLIBS#+>
#more LDLIBS:
#	-lm -lncurses -lgmp -lpthread 
#	`allegro-config --libs` -lalleg -lstdc++
#	-static -shared -ll -lfl -ldl -ly
#	-shared-libgcc -static-libgcc
o = <+#PROGRAM#+>

#object
%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ |& tee errors.err

#binary
$(o) : % : %.o $(OBJ)
	$(CC) $(LDLIBS) $^ -o $@ |& tee errors.err
	echo $(o) version $(VERSION) > VERSION

clean:
	rm -f *.o errors.err

cleanall:
	rm -i $(o) *.x *.o errors.err

#* ------------------------------------------------------------------- *
#* makefile config for Vim modeline                                    *
#* vi: set ai noet ts=4 sw=4 tw=72 wm=0 fo=croqlt :                    *
#* Template by Dr. Beco <rcb at beco dot cc> Version 20160614.152950   *
