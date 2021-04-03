COMPILER := clang
COMPILER_PATH := $(shell pwd)/include
COMPILER_FLAGS := '-g -fPIC'
LIB_LINKER_FLAGS := -shared

ALL_OBJS := vector/*.o

all: libstlc90.so
	make clean

libstlc90.so: vectorObjs
	${COMPILER} ${ALL_OBJS} ${LIB_LINKER_FLAGS} -o bin/libstlc90.so

vectorObjs:
	COMPILER=${COMPILER} COMPILER_PATH=${COMPILER_PATH}\
		COMPILER_FLAGS=${COMPILER_FLAGS} make -C vector

clean:
	make -C vector clean

distclean: clean
	rm -f bin/libstlc90.so