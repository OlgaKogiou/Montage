.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc
CFLAGS =	-g -O2 -I. -I.. -I../../lib/include -fPIC
LIBS   =	 -L../../lib -lbz2

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mArchiveGet:	mArchiveGet.o montageArchiveGet.o
		$(CC) -o mArchiveGet mArchiveGet.o montageArchiveGet.o $(LIBS)

install:
		cp mArchiveGet ../../bin

clean:
		rm -f mArchiveGet *.o
