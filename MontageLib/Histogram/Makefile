.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc
CFLAGS =	-g -I. -I.. -I../../lib/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -std=c99 -fPIC -Wall
LIBS   =	-L../../lib -lcfitsio -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

all:		mHistogram mCombineHist

mHistogram:	mHistogram.o montageHistogram.o
		$(CC) -o mHistogram mHistogram.o montageHistogram.o $(LIBS)

mCombineHist:	mCombineHist.o montageCombineHist.o
		$(CC) -o mCombineHist mCombineHist.o montageCombineHist.o $(LIBS)

install:
		cp mHistogram mCombineHist ../../bin

clean:
		rm -f mHistogram mCombineHist *.o
