.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc
CFLAGS =	-g -I. -I.. -I../../lib/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -std=c99 -fPIC -Wall
LIBS   =	-L../../lib -lpixbounds -lwcs -lmtbl -lcfitsio -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

all:		mHPXGap mHPXGapDiff mHPXGapCombine

mHPXGap:	mHPXGapScripts.o
		$(CC) -o mHPXGapScripts mHPXGapScripts.o ../../MontageLib/util/debugCheck.o $(LIBS)

mHPXGapDiff:	mHPXGapDiff.o montageHPXGapDiff.o
		$(CC) -o mHPXGapDiff mHPXGapDiff.o montageHPXGapDiff.o ../../MontageLib/util/debugCheck.o $(LIBS)

mHPXGapCombine:	mHPXGapCombine.o
		$(CC) -o mHPXGapCombine mHPXGapCombine.o ../../MontageLib/util/debugCheck.o $(LIBS)

install:
		cp mHPXGapScripts mHPXGapDiff mHPXGapCombine ../../bin

clean:
		rm -f mHPXGapScripts mHPXGapDiff mHPXGapCombine *.o
