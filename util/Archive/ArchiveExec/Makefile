# Filename: Makefile.SunOS

# Version  Developer        Date     Change
# -------  ---------------  -------  -----------------
# 1.0      John Good        15Dec04  Original Makefile

.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS =	-g -O2 -I. -I../../../lib/include
LIBS   =	-L../../../lib -lwcs -lmtbl -lsvc

# Define flags
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler

# Add flags to CFLAGS and LIBS
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mArchiveExec:	mArchiveExec.o
		$(CC) -o mArchiveExec mArchiveExec.o $(LIBS)

install:
		cp mArchiveExec ../../../bin

clean:
		rm -f mArchiveExec *.o
