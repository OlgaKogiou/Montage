.SUFFIXES:
.SUFFIXES: .c .o

CC     =	cc -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -std=c99 -fPIC -Wall
CFLAGS =	-g -O2 -I. -I.. -I../../lib/include
LIBS   =	-L../../lib -lwcs -lcfitsio -lcoord -lmtbl \
		-lboundaries -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mHdr:	mHdr.o montageHdr.o
		$(CC) -o mHdr mHdr.o montageHdr.o $(LIBS)

install:
		cp mHdr ../../bin

clean:
		rm -f mHdr *.o
