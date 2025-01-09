.PHONY: all run clean
head := $(wildcard *.h)
src := $(wildcard *.c)
obj := $(src:%.h=%.o)


all: launch

run:
	./lab3.exe

clean:
	cmd /C del /Q *.exe *.o

%.o: %.c $(head)
	gcc -c -o $@ $<

launch: $(obj)
	gcc -o lab3 $^