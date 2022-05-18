CFLAGS=-I./include

SRC=$(wildcard src/*.c)
OBJS=$(addprefix build/,$(patsubst %.c, %.o, $(SRC)))

ASM_SRC=$(wildcard asm/*.c)
ASM_OBJS=$(addprefix build/,$(patsubst %.c, %.o, $(ASM_SRC)))

all: check vmz asm

.PHONY: check
check:
	if [ ! -d ./build ] ; then mkdir -p build; fi
	if [ ! -d ./build/src ] ; then mkdir -p build/src; fi
	if [ ! -d ./build/asm ] ; then mkdir -p build/asm; fi

vmz: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o build/vmz
	
build/src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
asm: $(ASM_OBJS)
	$(CC) $(CFLAGS) $(ASM_OBJS) -o build/vmzasm
	
build/asm/%.o: asm/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean	
clean:
	rm build/vmz; \
	rm build/vmzasm; \
	rm build/src/*.o; \
	rm build/asm/*.o
	
