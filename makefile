list: enlist.c
	gcc enlist.c -o list

clean:
	rm *~

run: list
	./list
