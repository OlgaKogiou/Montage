# Filename: Makefile

# Version  Developer        Date     Change
# -------  ---------------  -------  -----------------------
# 1.0      John Good        30Jul14  Original SunOS Makefile

.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS =	-g -O2 -I. -I.. -I../../lib/include -std=c99 -fPIC -Wall
LIBS   =	-L../../lib -lwcs -lcfitsio -lcoord -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mTranspose:	mTranspose.o montageTranspose.o
		$(CC) -o mTranspose mTranspose.o montageTranspose.o \
		../util/checkHdr.o   \
		../util/checkWCS.o   \
		$(LIBS)

install:
		cp mTranspose ../../bin

clean:
		rm -f mTranspose *.o
