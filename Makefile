.PHONY: run

LIBS = -lwiringPi
CFLAGS = -Wall
CC = c99
OBJS = main.o \
       read.o

%.o : %.c
	$(CC) -o $@ $< -c $(CFLAGS)
read: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

run: read
	sudo ./read

graph: read
	@echo "Collecting ${count} samples from pin ${pin}..."
	sudo ./read ${count} ${pin} > data.dat
	./plot.gp
