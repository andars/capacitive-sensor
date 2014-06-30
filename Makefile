.PHONY: run graph

read: read.c
    c99 -o $@ $<

run: read
    sudo ./read

graph: read
    sudo ./read | sed -u '1,2d' > samples.data
    ./plot.gp
    
