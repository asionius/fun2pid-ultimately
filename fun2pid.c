#include<dirent.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char*argv[])
{
	if(argc != 2)
	{
			printf("wrong input!，please input only one name of pid!\n");
			exit(1);
	}
	DIR *dir;
	int i=0,j=0,k,l=0;
	 struct dirent *ptr;
	 FILE *fp;
	 char filepath[50];//大小随意，能装下cmdline文件的路径即可
	 char filetext[50];//大小随意，能装下要识别的命令行文本即可
	 char filename[50];//用来截取文件名
	 dir = opendir("/proc"); //打开路径
	 if (NULL != dir)
	 {
			 while ((ptr = readdir(dir)) != NULL) //循环读取路径下的每一个文件/文件夹
			 {
					 //如果读取到的是"."或者".."则跳过，读取到的不是文件夹名字也跳过
					 if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0)) continue;
					 if (DT_DIR != ptr->d_type) continue;			
					 sprintf(filepath, "/proc/%s/status", ptr->d_name);//生成要读取的文件的路径
					 fp = fopen(filepath, "r");//打开文件
					 if (NULL != fp)
					 {
							 fgets(filetext,50,fp);//读取文件
							filetext[49] = '\0';//给读出的内容加上字符串结束符
	//						 printf("%s\n",filetext);
							while(filetext[++i] != '\0');
							j = i;
	//						printf("%d\n",i);
							while(filetext[--i] != '	');	//经测试该处为tab键
	//						printf("%d\n",i);				//测试用，此处知道filetext中没有空格键
							for(k=i+1;k<j;k++){
								filename[l++] = filetext[k];//filetext里面内容为 (Name:	"进程名称")该段代码将"进程名称"提取出来。 
							}
							filename[l] = '\0';
							l=0;
							i=j=0;
	//						printf("%s\n",filename);
	//						printf("%d\n",(int)strlen(filetext));
							 //如果文件内容满足要求则打印路径的名字（即进程的PID）
							 if (filename == strstr(filename, argv[1])) 
									 printf("PID:  %s\n", ptr->d_name);						 
							 fclose(fp);
					 }

			 }
			 closedir(dir);//关闭路径
																		    }
}
