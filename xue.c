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

void suiji(int a[40])
{
	int i,j=0,k;
	int flag;
    srand((int)time(0));
	k=studentrandom(40);
	a[0]=k;
	while(j<40)
	{       
	    flag=0;
		k=studentrandom(40);
		for(i=0;i<j+1;i++)
                   if(a[i]==k) {flag=1;break;}
		if(flag==0)   a[j++]=k;
	}
    
}
