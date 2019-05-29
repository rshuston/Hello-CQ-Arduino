CC = gcc
CFLAGS = -Wall -I ../

LD = gcc
LDFLAGS = $(CFLAGS)

SRC = test_morse.c ../morse.c
OBJS = $(subst ../,,$(SRC:.c=.o))

EXE = hello-cq.exe

default: $(EXE)

force:

help: force
	@echo "default: $(EXE)"
	@echo "$(EXE): make the application image"
	@echo "clean: delete all object files and debug files"
	@echo "clobber: delete all object files, debug files, and application files"

$(EXE): $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

clean: force
	rm -f $(OBJS) $(OBJS:.o=.d)

clobber: clean
	rm -f $(EXE)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@ -MMD

%.o : ../%.c
	$(CC) -c $(CFLAGS) $< -o $@ -MMD

-include $(wildcard *.d)
