.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc
MPICC  =
CFLAGS =	-g -I. -I../../lib/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -std=c99
LIBS   =	-L../../lib -lmtbl -lwcs -lsvc -lcfitsio -lm

# DLIO FLAGS
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

all:		mHPXPlateHist mHPXPlateComboHist mHPXPlatePNG mHiPSPNGs

mHPXPlateHist:	mHPXPlateHist.o
		$(CC) -o mHPXPlateHist mHPXPlateHist.o $(LIBS)

mHPXPlateComboHist:	mHPXPlateComboHist.o
		$(CC) -o mHPXPlateComboHist mHPXPlateComboHist.o $(LIBS)

mHPXPlatePNG:	mHPXPlatePNG.o
		$(CC) -o mHPXPlatePNG mHPXPlatePNG.o $(LIBS)

mHiPSPNGs:	mHiPSPNGs.o
		$(CC) -o mHiPSPNGs mHiPSPNGs.o $(LIBS)

install:
		cp mHPXPlateHist mHPXPlateComboHist mHPXPlatePNG mHiPSPNGs ../../bin

clean:
		rm -f mHPXPlateHist mHPXPlateComboHist mHPXPlatePNG mHiPSPNGs *.o
