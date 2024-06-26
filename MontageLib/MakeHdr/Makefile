.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc
CFLAGS =	-g -O2 -I. -I.. -I../../lib/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -std=c99 -fPIC -Wall
LIBS   =	-L../../lib -lwcs -lboundaries -lmtbl -lcoord -lcfitsio -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mMakeHdr:	mMakeHdr.o montageMakeHdr.o
				$(CC) -o mMakeHdr mMakeHdr.o montageMakeHdr.o ../util/debugCheck.o ../util/checkFile.o ../util/checkHdr.o ../util/checkWCS.o $(LIBS)

install:
		cp mMakeHdr ../../bin

clean:
		rm -f mMakeHdr *.o
