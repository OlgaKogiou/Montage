# Filename: Makefile

# Version  Developer        Date     Change
# -------  ---------------  -------  -----------------------
# 1.0      John Good        16Aug05  Original SunOS Makefile

.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS =	-g -O2 -I. -I../../lib/include -I../../Montage
LIBS   =	-L../../lib -lmtbl -lcoord -lwcs -lcfitsio -lm

# Define flags
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler

# Add flags to CFLAGS and LIBS
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mCatMap:	mCatMap.o
		$(CC) -o mCatMap mCatMap.o \
		../../Montage/checkHdr.o   \
		../../Montage/checkWCS.o   \
		../../Montage/debugCheck.o \
		$(LIBS)

install:
		cp mCatMap ../../bin

clean:
		rm -f mCatMap *.o
