.SUFFIXES:
.SUFFIXES: .c .o

CC     = gcc -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS = -g -O2 -I. -I../../lib/include
LIBS   = -L../../lib -lwcs -lboundaries -lmtbl -lsvc -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
			$(CC) $(CFLAGS)  -c  $*.c


all:      mHPXHdr mHiPSHdr 

mHPXHdr: mHPXHdr.o
			gcc -o mHPXHdr mHPXHdr.c $(LIBS)

mHiPSHdr: mHiPSHdr.o
			gcc -o mHiPSHdr mHiPSHdr.o $(LIBS)

install:
			cp mHPXHdr mHiPSHdr ../../bin

clean:
			rm -f mHPXHdr mHiPSHdr *.o
