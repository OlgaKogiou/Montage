.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc
MPICC  =
CFLAGS =	-g -I. -I../../MontageLib -I../../lib/include \
		-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -std=c99
LIBS   =	-L../../lib -lwcs -lcfitsio -lpixbounds -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)s

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

all:		mHiPSTiles

mHiPSTiles:	mHiPSTiles.o
		$(CC) -o mHiPSTiles mHiPSTiles.o $(LIBS)

install:
		cp mHiPSTiles ../../bin
clean:
		rm -f mHiPSTiles *.o
