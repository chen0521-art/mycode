#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
#define maxlen 100//�ߵ���󳤶� 
#define W 50
#define H 20
typedef char bool;
#define false 0
#define true  1
void draw();
void starplace();
void dirDown();
bool snakeStatus();
void save();
void load();
void GB(int x, int y);//���λ��


void GB(int x, int y)//������Ƶ�x,y�� 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hidden()//���ع�꣬��ֹ��Ϸ����ʱ��괦���� 
{
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=0;//�����Ϊ���ɼ� 
	SetConsoleCursorInfo(hOut,&cci);
}

struct //���ǽṹ�壨Ŀ�꣩ 
{
	int x;
	int y;
}star;

struct//�ߵ�������� 
{
	int len;
	int x[maxlen];
	int y[maxlen];

}snake;

struct//���ڴ�ӡǽ�� 
{
	int X;
	int Y;
}stone;

int dir= 72;//Ĭ�Ͽ�ʼ�������� 
int temp = 0;//���������ж����Ƿ�������� 
int score = 0;
int i; 

char *menu[]=
{
 "����Ϸ���ܣ�",
 "���鿴��ͼ��",
 "����ʼ��Ϸ��",
 "����ʷ��¼��",
 "���˳���Ϸ��",
};//����ṹ��

CONSOLE_CURSOR_INFO cci;  
COORD pos = {0,0};//����Ĭ�ϵ�����λ��  
void showmenu(HANDLE hOut ,char **menu , int size , int index) ;//��ʾ�˵�  
int  get_userinput(int *index , int size) ;//��ȡ�û�����
int k=0;//�����ڲ˵������¼�ѡ��ʱ���ж� 

void draw()//��ӡ��ͼ 
{
	for (i = 0; i <= W; i += 2)//��ӡ�ϣ��±߽� 
	{
		GB(i, 0);
		printf("��");
		GB(i, H);
		printf("��");
	}
	for (i = 1; i < H; i++)//��ӡ���ұ߽� 
	{
		GB(0, i);
		printf("��");
		GB(W, i);
		printf("��");
	}
	while (1)
	{
		srand((unsigned int)time(NULL));
		star.x = rand() % (W-4) + 2;//��4��W-2���������һ����������star������ǽ�ϣ� 
		star.y = rand() % (H-2) + 1;
		if (star.x % 2 == 0)//ÿһ���������ռ�����񣬺�����Ϊż������star������Ҫһ�� 
			break;
	}
	GB(star.x, star.y);
	printf("��");
	snake.len = 3;
	snake.x[0] = W / 2 + 1;
	snake.y[0] = H / 2;
	GB(snake.x[0], snake.y[0]);
	printf("��");//��ӡ��ͷ 
	for (i = 1; i < snake.len; i++)//��ӡ���� 
	{
		snake.x[i] = snake.x[i - 1] + 2;
		snake.y[i] = snake.y[i - 1];
		GB(snake.x[i], snake.y[i]);
		printf("��");
	}
	GB(W- 2, 0);
	return;
}

void dirDown()
{
	int pre_dir= dir;
	if (_kbhit())
	{
		fflush(stdin);
		dir= _getch();//ʹ��getch()ʱ�ڶ�����ȡ�Ĳ�����Ҫ���� 
		dir= _getch();//ʵ������ 
	}
	if (temp == 0)
	{
		GB(snake.x[snake.len - 1], snake.y[snake.len - 1]);
		printf("  ");
	}

	for (i = snake.len - 1; i > 0; i--)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}

	if (pre_dir== 72 && dir== 80)dir= 72;
	if (pre_dir== 80 && dir== 72)dir= 80;
	if (pre_dir== 75 && dir== 77)dir= 75;
	if (pre_dir== 77 && dir== 75)dir= 77;//�����߲���ֱ�ӷ����� 
		
		
	switch (dir)//���������ҵ��ƶ� 
	{
	case 75:
		snake.x[0] -= 2;
		break;
	case 77:
		snake.x[0] += 2;
		break;
	case 72:
		snake.y[0]--;
		break;
	case 80:
		snake.y[0]++;
		break;
	}
	GB(snake.x[0], snake.y[0]);
	printf("��");
	GB(W - 2, 0);
	temp = 0;
	return;
}

void starplace()//�߳������Ǻ����������һ������ 
{
	if (snake.x[0] == star.x && snake.y[0] == star.y)
	{
		while (1)
		{
			int flag = 1;
			srand((unsigned int)time(NULL));
			star.x = rand() % (W- 4) + 2;
			star.y = rand() % (H- 2) + 1;
			for (i = 0; i < snake.len; i++)
			{
				if (snake.x[i] == star.x && snake.y[i] == star.y)
				{
					flag = 0;
					break;
				}
			}
			if (flag && star.x % 2 == 0)
				break;
		}
		GB(star.x, star.y);
		printf("��");
		snake.len++;
		score += 10;
		temp = 1;
	}
	return;
}

bool snakeStatus()//��״̬���ж� 
{
	if (snake.y[0] == 0 || snake.y[0] == H)return false;
	if (snake.x[0] == 0 || snake.x[0] == W)return false;//����ǽ�жϺ�� 
	for (i = 1; i < snake.len; i++)
	{
		if (snake.x[i] == snake.x[0] && snake.y[i] == snake.y[0])
		return false;//���������жϺ�� 
	}
	return true;
}
FILE *mem;
void save(void);
void load(void);
typedef struct node
{
	COORD cor;
	struct node *next;
}snake_node;
void save(void)//�����ݱ��浽�ļ��� 
{
  snake_node *p=NULL;
  if((mem=fopen("memory.txt","ab"))==NULL)//���ļ�������д 
  {
  	fprintf(stderr,"Can not open memory.txt!\n");
  	exit(1);
  }
  fprintf(mem,"%d ",snake.len);
  fprintf(mem,"%d\n",score);
  fclose(mem);
}
void load(void)//��ȡ�ļ�������ݲ���ӡ���� 
{
	int m=1,ss,ll;
	if((mem=fopen("memory.txt","r"))==NULL)
	{
		fprintf(stderr,"No Game Cache Here!\n");
		exit(2);
	}
	int n=1;
	while(n==1)
	{
		n=fscanf(mem,"%d ",&ll);
		fscanf(mem,"%d\n",&ss);
		if(n!=1) break;
		printf(" �ߵĳ���Ϊ��%d   �÷�Ϊ��%d\n",ll,ss);
	}
	getchar();//�û��������������ҳ�� 
	fclose(mem);
}

void showmenu(HANDLE hOut ,char **menu , int size , int index)
{
 int i ; 
 system("cls");  
 SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);//������ʾ���ı�����ɫ  
 pos.X = 30;
 pos.Y = 0 ;//��ʼ������̨��ʾ��X,Y�������
 SetConsoleCursorPosition(hOut,pos);//������ʾ������̨�ն˵ľ���λ��     
 for(i = 0 ; i < size ; i++)
 {
  if(i == index)//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ�����������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ�������
  {
   SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);//��ɫ  
      pos.X = 30;
      pos.Y = i;
      //���ù������
      SetConsoleCursorPosition(hOut,pos);    
      printf("%s",menu[i]);
  }
  else//������ʾ��ɫ 
  {
     SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//��ɫ 
     pos.X = 30;
     pos.Y = i;
     SetConsoleCursorPosition(hOut,pos);    //���ù������
     printf("%s",menu[i]);
  }//Ӫ��ѡ���Ч�� 
 }
 fflush(stdout);//ˢ�±�׼��������� 
}
 
int  get_userinput(int *index , int size)//��ȡ�û�����Ľӿ� 
{
 int ch ;
 ch = getch();
 switch(ch)
 {
  case 72: 
   if(*index > 0)  *index -= 1 ;
   k-=1;
   break;//�ϼ� 
  case 80:
  if(*index < size -1)  *index += 1 ;  
  k+=1;
  break;//�¼� 
  case 75: //���������ܽ���ѡ�� 
  case 97:return 0 ;
  case 77:return 0 ;
  case 13: 
  case 27: return 27 ;
 }
 return 0 ;
}




void setColor(unsigned short textColor, unsigned short backColor)//��Ϸʱ�������������ɫ 
{
 char command[9]="color 07";  //Ĭ����ɫ 
 command[6]='0'+backColor;  //��backColor������Ϊ�ַ��� 
 command[7]='0'+textColor;  //��textColor������Ϊ�ַ��� 
 system(command);    //����ϵͳ���� 
}

	
int main()
{
    int ret ,a;
    int index = 0 ;
    int c;
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��ǰ�ľ��---����Ϊ��׼������ 
    GetConsoleCursorInfo(hOut, &cci); //��ȡ�����Ϣ  
    cci.dwSize = 1;//���ù���С    
    cci.bVisible =  0; //���ù�겻�ɼ� FALSE 
    SetConsoleCursorInfo(hOut, &cci); //����(Ӧ��)�����Ϣ  
    while(1)
    {
     showmenu(hOut , menu , NR(menu) , index);
     ret = get_userinput(&index , NR(menu));
     if(ret == 27) break ;
     if(ret == 13)
     {
          switch(index)
            {
              case 0:           break ;   
              case 1:           break ;  
              case 2:           break ;  
              case 3:           break ;   
              case 4:           return 0 ;
            }
     }
    }
    printf("\n");
   switch(k)
    {
    	case 0:
		       system("cls");
		       printf("��Ϸ���ܣ�\n��ӭ����̰������Ϸ\n�س�����ȷ����\n�˵����������ѡ�������¼�����\n��Ϸ�ȼ�Ϊ1~8������Խ���Ѷ�Խ��\n�ߵķ������������Ҽ�����\n");
		       break;
    	case 1:
		       system("cls");
		       draw();
		       Sleep(50000);
		       system("cls");
		       break;
		case 2:
		       printf("ѡ���Ѷȣ�");
	           scanf("%d",&a);
			   system("cls");
		       hidden();
		       setColor(0,7);
	           draw();
	           while (1)
	           {
		          dirDown();
		          if (!snakeStatus())break;
		          starplace();
		          GB(0,H+1);
		          printf("score:%d\n",score);//�߳Ե�ͬʱ���Կ����Լ��ķ��� 
				  Sleep(400/a);
   	           }
   	           system("cls");
	           GB(W/ 2, H / 2);
	           printf("Game Over!\n");
	           GB(W/ 2, H/ 2 + 1);
	           printf("�����յĵ÷�Ϊ��%d\n", score);
	           Sleep(3000);
	           save();
	           system("cls");
	           break;
	    case 3:
			system("cls");
			load();
			break;
	    case 4:
	    	   system("cls");
	           GB(W/ 2, H / 2);
	           printf("SEE YOU!!!\n");
	           break;
	}
    return 0;
}
