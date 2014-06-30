.PHONY: run

read: read.c
	c99 -o $@ $< -lwiringPi

run: read
	sudo ./read

graph: read
	@echo "Collecting ${count} samples..."
	sudo ./read | sed -u '1,2d' | awk -W interactive '1; NR > ${count}{exit}' > data.dat
	./plot.gp
	
