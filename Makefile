objects = main.o

a.out:$(objects)
	g++ $(objects) -o a.out


.PHONY:clean

clean:
	rm a.out $(objects)
