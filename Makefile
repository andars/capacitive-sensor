.PHONY: run

read: read.c
	c99 -o $@ $< -lwiringPi

run: read
	sudo ./read

graph: read
	@echo "Collecting ${count} samples from pin ${pin}..."
	sudo ./read ${count} ${pin} > data.dat
	./plot.gp
