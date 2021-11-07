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
	printf("*          1���ɼ���ʾ           *\n");
	printf("*                                *\n");
	printf("*          2���ɼ�����           *\n");
	printf("*                                *\n");
	printf("*          3���ɼ��޸�           *\n");
	printf("*                                *\n");
	printf("*          4�����ѧ��           *\n");
	printf("*                                *\n");
	printf("*          5���ɼ�����           *\n");
	printf("*                                *\n");
	printf("*          6���˳�����           *\n");
	printf("*                                *\n");
	printf("**********************************\n");
	printf("\n\n��ѡ������ţ�");
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
	printf("\n\n����1���ز˵�\n�������˳�\n");
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
	printf("ѧ�� ���� Ӣ�� C���� ���� ƽ����\n");
	for(i=0,j=1;i<M;i++,j++)
	{
		printf("%-9d %-10s %-10d% -10d% -10d% -10d%\n",stu[i].num,stu[i].name,stu[i].yingyu,stu[i].c_yuyan,stu[i].gaoshu,stu[i].pingjun);
	}
	return;
}



void Search()
{
	int i,j[20]={-1},d,k,t=0;char m[20];
    printf("�ɼ���ѯ:");
	printf("\n\n\n");
	printf("*********************************\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*       1������     2��ѧ��     *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*********************************\n");
	printf("�������ѯѡ��:");
	scanf("%d",&k);
	if(k==1)
	{
		printf("����������:");
		scanf("%s",&m);
		for(i=0;i<N;i++)
			if(strcmp(m,stu[i].name)==0)
			{
				j[t]=i;	t++;
			}
	}
	else if(k==2)
	{
		printf("������ѧ�ţ�");
		scanf("%d",&d);
		for(i=0;i<N;i++)
			if(d==stu[i].num)
			{
				j[t]=i;t++;
			}
	}
	if(t==0)
		printf("û���ҵ���");
	else
	{ 
		printf("ѧ��  ����     Ӣ��       ����      ����      ƽ����\n");
		for(i=0;i<t;i++)
			printf("%d   %-10s %-10d% -10d% -10d% -10d%\n",stu[j[i]].num,stu[j[i]].name,stu[j[i]].yingyu,stu[j[i]].c_yuyan,stu[j[i]].gaoshu,stu[j[i]].pingjun); 
	}
}



void add()
{
	int n,i,k,t;
	printf("������Ҫ��ӵ�ѧ�����������루���%d������\n",N-M);
	scanf("%d",&n);M=M+n;
	printf("�����������Ϣ��\n");
	for(i=1;i<=n;i++)
	{
		printf("ѧ��:\n");
		scanf("%d",&stu[M-n-1+i].num);
		for(k=0;k<M;k++)
		{
			if(stu[M-n-1+i].num==stu[k].num)
			{
				printf("��ѧ���ѱ�ʹ��!\n����1��������\n����2���ز˵�\n");
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
		printf("����:\n");
		scanf("%s",&stu[M-n-1+i].name);
		printf("Ӣ��:\n");
		scanf("%d",&stu[M-n-1+i].yingyu);
		printf("C����:\n");
		scanf("%d",&stu[M-n-1+i].c_yuyan);
		printf("����:\n");
		scanf("%d",&stu[M-n-1+i].gaoshu);
		stu[M-n-1+i].pingjun=(stu[M-n-1+i].gaoshu+stu[M-n-1+i].c_yuyan+stu[M-n-1+i].yingyu)/3;
	}
	printf("��ȷ���Ƿ񱣴��޸Ľ����");
	printf("������1�����޸Ľ����");
	scanf("%d",&k);
	if(k==1)Wr_file();
}


void modify ( )
{
	int i,k;char name[20];
	printf("�ɼ��޸�:");
	printf("\n\n\n");
	printf("*********************************\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*       1������     2��ѧ��     *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*                               *\n");
	printf("*********************************\n");
	printf("�������޸�ѧ������Ϣѡ��:");
	scanf("%d",&k);
	if(k==1)
	{
		printf("\t������ѧ������:");  
		scanf("%s",&name);
		for (i=0;i<=M;i++)           
		{
			if(strcmp(stu[i].name,name)==0)    
			{
				printf("\n\t\t\t  ��ѧ���ɼ��������: \n");
				printf("ѧ��  ����  ƽ���ɼ�");
				printf("Ӣ�� C����  �ߵ���ѧ\n");
				printf("%d%      -6s",stu[i].num,stu[i].name);
				printf("%-6d  %-6d  %-6d  %-6d",stu[i].c_yuyan,stu[i].gaoshu,stu[i].yingyu,stu[i].pingjun);
				printf("\n\t\t �������ѧ���µ�Ӣ��ɼ�: ");
				scanf ("%d",&stu[i].yingyu);
				printf("\n\t\t �������ѧ���µ�C���Գɼ�: ");
				scanf ("%d",&stu[i].gaoshu);
				printf("\n\t\t �������ѧ���µĸߵ���ѧ�ɼ�: ");
				scanf ("%d",&stu[i].yingyu);	
				stu[i].pingjun=(stu[i].yingyu+stu[i].c_yuyan+stu[i].gaoshu)/3;
				printf("��ȷ���Ƿ񱣴��޸Ľ����");
				printf("������1�����޸Ľ����");
				scanf("%d",&k);
				if(k==1)Wr_file();
			}
			else 
			{
				printf("\n\n\t\t��ǰ��û��ѧ���ɼ���¼����������������˵�......");
				getch( );
			}
			return;
		}
	}
	if(k==2)
	{
		printf("\t������ѧ��ѧ��:");  
		scanf("%d",&k);
		for (i=0;i<=M;i++)           
		{
			if(stu[i].num==k)    
			{
				printf("\n\t\t\t  ��ѧ���ɼ��������: \n");
				printf("ѧ��  ����  ƽ���ɼ�");
				printf("Ӣ�� C����  �ߵ���ѧ\n");
				printf("%d%      -6s",stu[i].num,stu[i].name);
				printf("%-6d  %-6d  %-6d  %-6d",stu[i].c_yuyan,stu[i].gaoshu,stu[i].yingyu,stu[i].pingjun);
				printf("\n\t\t �������ѧ���µ�Ӣ��ɼ�: ");
				scanf ("%d",&stu[i].yingyu);
				printf("\n\t\t �������ѧ���µ�C���Գɼ�: ");
				scanf ("%d",&stu[i].gaoshu);
				printf("\n\t\t �������ѧ���µĸߵ���ѧ�ɼ�: ");
				scanf ("%d",&stu[i].yingyu);
				stu[i].pingjun=(stu[i].yingyu+stu[i].c_yuyan+stu[i].gaoshu)/3;
				printf("��ȷ���Ƿ񱣴��޸Ľ����");
				printf("������1�����޸Ľ����");
				scanf("%d",&k);
				if(k==1)Wr_file();
			}
			else 
			{
				printf("\n\n\t\t��ǰ��û��ѧ���ɼ���¼����������������˵�......");
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
		printf("��%d�� %s ƽ���֣�%d",i+1,stu[i].name,stu[i].pingjun);
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
		printf("�� %-2d��   %-6s  ƽ���֣�%-6d  Ӣ��ɼ���%-6d  C���Գɼ���%-6d  �����ɼ���%-6d\n",z+1,stu[z].name,stu[z].pingjun,stu[z].yingyu,stu[z].c_yuyan,stu[z].gaoshu);
}





int Wr_file()
{
	FILE *fp1;
	int i;
	if((fp1=fopen("���н��.txt","w"))==NULL)   
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
	printf("*          1���ɼ���ʾ           *\n");
	printf("*                                *\n");
	printf("*          2���ɼ�����           *\n");
	printf("*                                *\n");
	printf("*          3���ɼ��޸�           *\n");
	printf("*                                *\n");
	printf("*          4�����ѧ��           *\n");
	printf("*                                *\n");
	printf("*          5���ɼ�����           *\n");
	printf("*                                *\n");
	printf("*          6���˳�����           *\n");
	printf("*                                *\n");
	printf("**********************************\n");
	printf("\n\n��ѡ������ţ�");
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
	printf("\n\n����1���ز˵�\n�������˳�\n");
	scanf("%d",&a);
	if(a==1)menu();
	else exit();
}
