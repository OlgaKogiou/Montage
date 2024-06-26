.SUFFIXES:
.SUFFIXES: .c .o

CC     = gcc -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -std=c99 -fPIC
CFLAGS = -g -O2 -I. -I.. -I../../lib/include -Wall
LIBS   = -L../../lib -lsvc -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

all: mHdrWWT mHdrWWTExec mProjWWTExec mPNGWWTExec

mHdrWWT:	mHdrWWT.o
		$(CC) -o mHdrWWT mHdrWWT.o $(LIBS)

mHdrWWTExec:	mHdrWWTExec.o
		$(CC) -o mHdrWWTExec mHdrWWTExec.o $(LIBS)

mProjWWTExec:	mProjWWTExec.o
		$(CC) -o mProjWWTExec mProjWWTExec.o $(LIBS)

mPNGWWTExec:	mPNGWWTExec.o
		$(CC) -o mPNGWWTExec mPNGWWTExec.o $(LIBS)

install:
		cp mHdrWWT mHdrWWTExec mProjWWTExec mPNGWWTExec ../../bin

clean:
		rm -f mHdrWWT mHdrWWTExec mProjWWTExec mPNGWWTExec *.o
