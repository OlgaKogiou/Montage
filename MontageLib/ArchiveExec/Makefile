# Filename: Makefile.SunOS

# Version  Developer        Date     Change
# -------  ---------------  -------  -----------------
# 1.0      John Good        15Dec04  Original Makefile

.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS =	-g -O2 -I. -I.. -I../../lib/include -fPIC
LIBS   =	-L../../lib -lwcs -lmtbl -lbz2

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mArchiveExec:	mArchiveExec.o montageArchiveExec.o ../ArchiveGet/montageArchiveGet.o
		$(CC) -o mArchiveExec mArchiveExec.o montageArchiveExec.o ../ArchiveGet/montageArchiveGet.o $(LIBS)

install:
		cp mArchiveExec ../../bin

clean:
		rm -f mArchiveExec *.o
