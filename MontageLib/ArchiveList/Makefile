# Filename: Makefile

# Version  Developer        Date     Change
# -------  ---------------  -------  -----------------------
# 1.0      John Good        14Dec04  Original Darwin Makefile

.SUFFIXES:
.SUFFIXES: .c .o

CC     =	cc -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS =	-g -O2 -I. -I.. -I../../lib/include -fPIC
LIBS   =	-L../../lib -lwcs -lcfitsio -lcoord  -lboundaries -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mArchiveList:	mArchiveList.o montageArchiveList.o
		$(CC) -o mArchiveList mArchiveList.o montageArchiveList.o $(LIBS)

install:
		cp mArchiveList ../../bin

clean:
		rm -f mArchiveList *.o
