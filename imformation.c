#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define len sizeof(struct member)
struct member *creat();
void gotoxy(int x, int y);
void gettime();
void out(struct member *head);
struct member *del(struct member *head,int num);
struct member *add(struct member *head,struct member *Add);

struct member
{
	int num;
	//float grade;
	float math;
	float chinese;
	float english;
	struct member *next; 
};
int n;
struct member *creat()
{
	struct member *head;
	struct member *p1,*p2;
	n=0;
	p1=p2=(struct member *)malloc(len);
	printf("enter num：");
	scanf("%d",&p1->num);
	printf("enter math grade：");//
	scanf("%f",&p1->math);
	printf("enter chinese grade:");
	scanf("%f",&p1->chinese);
	printf("enter english grade:");
	scanf("%f",&p1->english);
	
	head=NULL;
	while(p1->num!=0)//p1->num!=0
	{
		n+=1;
		if(n==1)head=p1;
		else
		{
			p2->next=p1;
		}
		//p2->next=p1;
		p2=p1;
		p1=(struct member *)malloc(len);
		printf("\nenter num：");
		scanf("%d",&p1->num);
		printf("enter math grade：");
		scanf("%f",&p1->math);
		printf("enter chinese grade:");
		scanf("%f",&p1->chinese);
		printf("enter english grade:");
		scanf("%f",&p1->english);
	}
	p2->next=NULL;
	return (head);
}

struct member *del(struct member *head,int num)
{
	struct member *p1,*p2;
	if(head==NULL)
	{
		printf("\nThe list is not exist!\n");
		return NULL;
	}
	p1=head;
	while(num!=p1->num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(num==p1->num)
	{
		if(p1==head)
			head=p1->next;
		else
		 p2->next=p1->next;	
		printf("\ndelate No:%d succeed!\n",num);
		n=n-1;//n作为全局变量，用来记录链表的数据个数 
	}
	else
		printf("%d not been found!\n",num);	
	return head;
}


struct member *add(struct member *head,struct member *Add)
{
	struct member *p0,*p1,*p2;
	Add=(struct member *)malloc(len);
	printf("\nenter the num you want to add:");
	scanf("%d",&Add->num);
	printf("enter math grade：");
	scanf("%f",&Add->math);
	printf("enter chinese grade:");
	scanf("%f",&Add->chinese);
	printf("enter english grade:");
	scanf("%f",&Add->english);
	p1=head;
	p0=Add;
	if(head==NULL)
	{
		head=p0;
		p0->next=NULL;
	}
	else
	{
		while((p0->num>p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->num<=p1->num)
		{
			if(head==p1)
			{
				head=p0;
			}
			else p2->next=p0;
			p0->next=p1;
		}
		else
		{
			p1->next=p0;
			p0->next=NULL;
		}
	}
	n=n+1;
	return head;
}


void out(struct member *head)
{
	struct member *p;
	int j=2;
	//printf("\n\n");
	p=head;
	//sleep(1000);
	system("cls");
	printf("There are %d records!\n",n);
	printf("studynumber  Math    Chinese    English");
	if(head!=NULL)
	  do//这里的数据打印形式不够灵活，还要改 
	  {
	  	gotoxy(0,j);
	  	printf("%d",p->num);
	  	gotoxy(13,j);
	  	printf("%0.2f",p->math);
	  	gotoxy(21,j);
	  	printf("%0.2f",p->chinese);
	  	gotoxy(32,j);
	  	printf("%0.2f",p->english);
	  	p=p->next;
	  	j++;
	  }while(p!=NULL);
	   
}



void gotoxy(int x, int y)//获取光标位置进行打印 
{
    CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;                            
    HANDLE    hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.X = x;                                    
    csbiInfo.dwCursorPosition.Y = y;                                    
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition); 
}


void gettime()//获取系统时间 
{
	char *wday[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};//指针数组 ，周日是每周的开始，不能更改 
	time_t timep;//“箱子” 
	struct tm *p;
	time(&timep);
	p=gmtime(&timep);
	printf("\n%d\\%d\\%d\t",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
	printf(wday[p->tm_wday]);
	printf("\t%d:%d:%d\n",p->tm_hour+8,p->tm_min,p->tm_sec);//windows系统下的时间慢8小时 
	
}

int main()//仅仅数单个数据的删减或增加，还没改善 
{
		struct member *pt,*ad,*pT,*Add;
		int num;
		pt=creat();
		out(pt);
		printf("\nyou want to delate the data of No:\n ");
		scanf("%d",&num);
		ad=del(pt,num);
		out(ad);
		pT=add(ad,Add);
		out(pT);
		gettime();
		return 0;
}
 
