.PHONY: run

LIBS = -lwiringPi
CFLAGS = -Wall
CC = c99

SRCS = main.c \
       read.c


OBJDIR = build
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)


$(OBJDIR)/%.o : %.c
	$(CC) -o $@ $< -c $(CFLAGS)

read: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

run: read
	sudo ./read

graph: read
	@echo "Collecting ${count} samples from pin ${pin}..."
	sudo ./read ${count} ${pin} > data.dat
	./plot.gp
