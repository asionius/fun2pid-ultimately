#include<stdio.h>
#include"student_info.h"
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)
int studentrandom(int a)
{
	int i;
	srand((int)time(NULL));
	i=random(a);
	return i;
}
