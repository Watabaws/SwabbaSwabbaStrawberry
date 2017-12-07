sephora: sephora.o
	gcc -o sephora sephora.c

sephora.o: sephora.c
	gcc -c sephora.c

run: all
	./sephora -tag
	./sephora -tag num
