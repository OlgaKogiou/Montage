.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc
MPICC  =
CFLAGS =	-g -O2 -I. -I.. -I../../lib/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -std=c99 -fPIC -Wall

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

all:		filePath.o debugCheck.o checkFile.o checkHdr.o checkWCS.o version.o

clean:
			rm -f *.o
