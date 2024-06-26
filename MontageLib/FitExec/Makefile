.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc
CFLAGS =	-g -O2 -I. -I.. -I../../lib/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -std=c99 -fPIC -Wall
LIBS   =	-L../../lib -lwcs -lmtbl -lpixbounds -lcfitsio -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mFitExec:		mFitExec.o montageFitExec.o
		$(CC) -o mFitExec mFitExec.o montageFitExec.o ../Fitplane/montageFitplane.o \
                        ../util/checkHdr.o ../util/checkWCS.o ../util/filePath.o ../util/checkFile.o $(LIBS)

install:
		cp mFitExec ../../bin

clean:
		rm -f mFitExec *.o
