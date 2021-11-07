#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#define N 100
#define STU struct student

struct student
{
	int num;
	char name[20];
	int yingyu;
	int c_yuyan;
	int gaoshu;
	int pingjun;
}stu[N];

void Display();
void Re_file();
void Search();
void add();
void modify ( );
void sort(STU *s1,int n);
int Wr_file();
void menu();

int M=0;

main()
{
	int n,a;
	printf("\n\n");
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*          1：成绩显示           *\n");
	printf("*                                *\n");
	printf("*          2：成绩查找           *\n");
	printf("*                                *\n");
	printf("*          3：成绩修改           *\n");
	printf("*                                *\n");
	printf("*          4：添加学生           *\n");
	printf("*                                *\n");
	printf("*          5：成绩排序           *\n");
	printf("*                                *\n");
	printf("*          6：退出程序           *\n");
	printf("*                                *\n");
	printf("**********************************\n");
	printf("\n\n请选择功能序号：");
	scanf("%d",&n);
	Re_file();
	switch(n)
	{
	case 1:Display();break;
    case 2:Search();break;
	case 3:modify();break;
	case 4:add();break;
	case 5:sort(stu,M);break;
	case 6:exit(0);break;
	}
	printf("\n\n输入1返回菜单\n其他键退出\n");
	scanf("%d",&a);
	if(a==1)menu();
	else exit();
}



void Re_file()
{
	FILE *fp;
	fp=fopen("student.txt","r");
	while(fscanf(fp,"%d%s%d%d%d%d",&stu[M].num,&stu[M].name,&stu[M].yingyu,&stu[M].c_yuyan,&stu[M].gaoshu,&stu[M].pingjun)!=EOF)M++;
	fclose(fp);
}



void Display()
{
	int i,j;
	printf("学号 姓名 英语 C语言 高数 平均分\n");
	for(i=0,j=1;i<M;i++,j++)
	{
		printf("%-9d %-10s %-10d% -10d% -10d% -10d%\n",stu[i].num,stu[i].name,stu[i].yingyu,stu[i].c_yuyan,stu[i].gaoshu,stu[i].pingjun);
	}
	return;
}



void Search()
{
	int i,j[20]={-1},d,k,t=0;char m[20];
    printf("成绩查询:");
	printf("\n\n\n");
	printf("*********************************\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*       1：姓名     2：学号     *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*********************************\n");
	printf("请输入查询选项:");
	scanf("%d",&k);
	if(k==1)
	{
		printf("请输入姓名:");
		scanf("%s",&m);
		for(i=0;i<N;i++)
			if(strcmp(m,stu[i].name)==0)
			{
				j[t]=i;	t++;
			}
	}
	else if(k==2)
	{
		printf("请输入学号：");
		scanf("%d",&d);
		for(i=0;i<N;i++)
			if(d==stu[i].num)
			{
				j[t]=i;t++;
			}
	}
	if(t==0)
		printf("没有找到！");
	else
	{ 
		printf("学号  姓名     英语       语言      高数      平均分\n");
		for(i=0;i<t;i++)
			printf("%d   %-10s %-10d% -10d% -10d% -10d%\n",stu[j[i]].num,stu[j[i]].name,stu[j[i]].yingyu,stu[j[i]].c_yuyan,stu[j[i]].gaoshu,stu[j[i]].pingjun); 
	}
}



void add()
{
	int n,i,k,t;
	printf("请输入要添加的学生数量可输入（最多%d个）：\n",N-M);
	scanf("%d",&n);M=M+n;
	printf("请输入相关信息：\n");
	for(i=1;i<=n;i++)
	{
		printf("学号:\n");
		scanf("%d",&stu[M-n-1+i].num);
		for(k=0;k<M;k++)
		{
			if(stu[M-n-1+i].num==stu[k].num)
			{
				printf("该学号已被使用!\n输入1重新输入\n输入2返回菜单\n");
				scanf("%d",&t);
				if(t==1)
				{
					M=0;
					Re_file();
					add();
				}
				if(t==2)menu();
			}
			else break;
		}
		printf("姓名:\n");
		scanf("%s",&stu[M-n-1+i].name);
		printf("英语:\n");
		scanf("%d",&stu[M-n-1+i].yingyu);
		printf("C语言:\n");
		scanf("%d",&stu[M-n-1+i].c_yuyan);
		printf("高数:\n");
		scanf("%d",&stu[M-n-1+i].gaoshu);
		stu[M-n-1+i].pingjun=(stu[M-n-1+i].gaoshu+stu[M-n-1+i].c_yuyan+stu[M-n-1+i].yingyu)/3;
	}
	printf("请确认是否保存修改结果！");
	printf("请输入1保存修改结果！");
	scanf("%d",&k);
	if(k==1)Wr_file();
}


void modify ( )
{
	int i,k;char name[20];
	printf("成绩修改:");
	printf("\n\n\n");
	printf("*********************************\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*       1：姓名     2：学号     *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*********************************\n");
	printf("请输入修改学生的信息选项:");
	scanf("%d",&k);
	if(k==1)
	{
		printf("\t请输入学生姓名:");  
		scanf("%s",&name);
		for (i=0;i<=M;i++)           
		{
			if(strcmp(stu[i].name,name)==0)    
			{
				printf("\n\t\t\t  该学生成绩情况如下: \n");
				printf("学号  姓名  平均成绩");
				printf("英语 C语言  高等数学\n");
				printf("%d%      -6s",stu[i].num,stu[i].name);
				printf("%-6d  %-6d  %-6d  %-6d",stu[i].c_yuyan,stu[i].gaoshu,stu[i].yingyu,stu[i].pingjun);
				printf("\n\t\t 请输入该学生新的英语成绩: ");
				scanf ("%d",&stu[i].yingyu);
				printf("\n\t\t 请输入该学生新的C语言成绩: ");
				scanf ("%d",&stu[i].gaoshu);
				printf("\n\t\t 请输入该学生新的高等数学成绩: ");
				scanf ("%d",&stu[i].yingyu);	
				stu[i].pingjun=(stu[i].yingyu+stu[i].c_yuyan+stu[i].gaoshu)/3;
				printf("请确认是否保存修改结果！");
				printf("请输入1保存修改结果！");
				scanf("%d",&k);
				if(k==1)Wr_file();
			}
			else 
			{
				printf("\n\n\t\t当前还没有学生成绩记录，按任意键返回主菜单......");
				getch( );
			}
			return;
		}
	}
	if(k==2)
	{
		printf("\t请输入学生学号:");  
		scanf("%d",&k);
		for (i=0;i<=M;i++)           
		{
			if(stu[i].num==k)    
			{
				printf("\n\t\t\t  该学生成绩情况如下: \n");
				printf("学号  姓名  平均成绩");
				printf("英语 C语言  高等数学\n");
				printf("%d%      -6s",stu[i].num,stu[i].name);
				printf("%-6d  %-6d  %-6d  %-6d",stu[i].c_yuyan,stu[i].gaoshu,stu[i].yingyu,stu[i].pingjun);
				printf("\n\t\t 请输入该学生新的英语成绩: ");
				scanf ("%d",&stu[i].yingyu);
				printf("\n\t\t 请输入该学生新的C语言成绩: ");
				scanf ("%d",&stu[i].gaoshu);
				printf("\n\t\t 请输入该学生新的高等数学成绩: ");
				scanf ("%d",&stu[i].yingyu);
				stu[i].pingjun=(stu[i].yingyu+stu[i].c_yuyan+stu[i].gaoshu)/3;
				printf("请确认是否保存修改结果！");
				printf("请输入1保存修改结果！");
				scanf("%d",&k);
				if(k==1)Wr_file();
			}
			else 
			{
				printf("\n\n\t\t当前还没有学生成绩记录，按任意键返回主菜单......");
				getch( );
			}
			return;
		}
	}
}



/*void sort(int b[],int n)
{
	int i,j,k,t;
	for(i=0;i<n;i++) 
	{
		k=i;
		for(j=i+1; j<n; j++)                                                              
			if(b[j]>b[k])k=j;
		t=b[k];
		b[k]=b[i];
		b[i]=t;
	}
	for(i=0;i<N;i++)
		printf("第%d名 %s 平均分：%d",i+1,stu[i].name,stu[i].pingjun);
}



void sort(student *s,int l,int r)
{
    student x=s[l];
    if(l < r)
    {
        int i=l,j=r;x=s[l];
        while(i<j)
        {
            while(i<j&&s[j].pingjun>=x.pingjun)
                j--;
            if(i<j)
                s[i++]=s[j];

            while(i<j && s[i].pingjun<=x.pingjun)
                i++;
            if(i<j)
                s[j--]=s[i];

        }

        s[i]=x;
        sort(s,l,i-1);
        sort(s,i+1,r);
    }
}

*/

void sort(STU *s1,int n)
{
	STU *i,*j,t;
	int z=0;
	{
		for(i=s1;i<s1+n-1;i++)
		for(j=i+1;j<s1+n;j++)
			if((*i).pingjun<(*j).pingjun)
			{
				t=*i;
				*i=*j;
				*j=t;
			}
	}
		for(z=0;z<M;z++)
		printf("第 %-2d名   %-6s  平均分：%-6d  英语成绩：%-6d  C语言成绩：%-6d  高数成绩：%-6d\n",z+1,stu[z].name,stu[z].pingjun,stu[z].yingyu,stu[z].c_yuyan,stu[z].gaoshu);
}





int Wr_file()
{
	FILE *fp1;
	int i;
	if((fp1=fopen("运行结果.txt","w"))==NULL)   
	{
		printf("\nCannot open file\n");
		return 0;
	}
	for(i=0;i<M;i++)
		fprintf(fp1,"%d %s %d %d %d %d\n",stu[i].num,stu[i].name,stu[i].yingyu,stu[i].c_yuyan,stu[i].gaoshu,stu[i].pingjun);
	fclose(fp1);
	return 1;
}


void menu()
{
	int n,a;
	printf("\n\n");
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*          1：成绩显示           *\n");
	printf("*                                *\n");
	printf("*          2：成绩查找           *\n");
	printf("*                                *\n");
	printf("*          3：成绩修改           *\n");
	printf("*                                *\n");
	printf("*          4：添加学生           *\n");
	printf("*                                *\n");
	printf("*          5：成绩排序           *\n");
	printf("*                                *\n");
	printf("*          6：退出程序           *\n");
	printf("*                                *\n");
	printf("**********************************\n");
	printf("\n\n请选择功能序号：");
	scanf("%d",&n);
	switch(n)
	{
	case 1:Display();break;
    case 2:Search();break;
	case 3:modify();break;
	case 4:add();break;
	case 5:sort(stu,M);break;
	case 6:exit(0);break;
	}
	printf("\n\n输入1返回菜单\n其他键退出\n");
	scanf("%d",&a);
	if(a==1)menu();
	else exit();
}
