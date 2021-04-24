#include<stdio.h>
#include<time.h>
int main()
{
	char *wday[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	time_t timep;
	struct tm *p;
	time(&timep);
	p=gmtime(&timep);
	printf("%d\\%d\\%d\n",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);//->不能换成成员符
	printf(wday[p->tm_wday]);
	printf("\n%d:%d:%d\n",p->tm_hour+8,p->tm_min,p->tm_sec);//加8是因为Windows下获取的小时数相差8小时
	return 0;
}
