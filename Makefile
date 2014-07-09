.PHONY: run

LIBS = -lwiringPi
CFLAGS = -Wall
CC = c99

SRCS = main.c \
       read.c


OBJDIR = build
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

read: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

collect: collect.o read.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(OBJDIR)/%.o : %.c %.h
	$(CC) -o $@ $< -c $(CFLAGS)


run: read
	sudo ./read

graph: collect
	@echo "Collecting ${count} samples from pin ${pin}..."
	sudo ./collect ${count} ${pin} > data.dat
	./plot.gp
