wangaike : fun2pid.o
	cc -o wangaike fun2pid.o
fun2pid.o : fun2pid.c
	cc -c fun2pid.c
clean:
	 rm fun2pid.o

