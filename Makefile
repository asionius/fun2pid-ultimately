all:wangaike Stu
wangaike : fun2pid.o
	cc -o wangaike fun2pid.o
Stu:Stu_Rand4_Group.o
	cc -o Stu Stu_Rand4_Group.o
fun2pid.o : fun2pid.c
	cc -c fun2pid.c
Stu_Rand4_Group.o:Stu_Rand4_Group.c
	cc -c Stu_Rand4_Group.c
clean:
	rm Stu_Rand4_Group.o fun2pid.o

