# Filename: Makefile.Darwin

# Version  Developer        Date     Change
# -------  ---------------  -------  -----------------------
# 1.0      John Good        04Oct05  Original SunOS Makefile

.SUFFIXES:
.SUFFIXES: .c .o

CC     =	gcc -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS =	-g -O2 -I. -I../../../lib/include -I../../../Montage
LIBS   =	-L../../../lib -lsvc -lmtbl -lwcs -lcfitsio -lcoord -lm

# Define flags
DLIO_CFLAGS = -I/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/include
DLIO_LDFLAGS = -L/usr/workspace/iopp/kogiou1/venvs/pegasus-env/lib/python3.9/site-packages/dlio_profiler/lib64 -ldlio_profiler

# Add flags to CFLAGS and LIBS
CFLAGS += $(DLIO_CFLAGS)
LIBS += $(DLIO_LDFLAGS)

.c.o:
		$(CC) $(CFLAGS)  -c  $*.c

mNotifyTG:	mNotifyTG.o
		$(CC) -o mNotifyTG mNotifyTG.o \
		$(LIBS)

install:
		cp mNotifyTG ../../../bin

clean:
		rm -f mNotifyTG *.o
