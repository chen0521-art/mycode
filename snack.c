#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
#define maxlen 100//蛇的最大长度 
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
void GB(int x, int y);//光标位置


void GB(int x, int y)//将光标移到x,y处 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hidden()//隐藏光标，防止游戏运行时光标处在闪 
{
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=0;//光标设为不可见 
	SetConsoleCursorInfo(hOut,&cci);
}

struct //星星结构体（目标） 
{
	int x;
	int y;
}star;

struct//蛇的相关属性 
{
	int len;
	int x[maxlen];
	int y[maxlen];

}snake;

struct//用于打印墙体 
{
	int X;
	int Y;
}stone;

int dir= 72;//默认开始方向向上 
int temp = 0;//往后用来判断蛇是否吃了星星 
int score = 0;
int i; 

char *menu[]=
{
 "＊游戏介绍＊",
 "＊查看地图＊",
 "＊开始游戏＊",
 "＊历史记录＊",
 "＊退出游戏＊",
};//定义结构体

CONSOLE_CURSOR_INFO cci;  
COORD pos = {0,0};//定义默认的坐标位置  
void showmenu(HANDLE hOut ,char **menu , int size , int index) ;//显示菜单  
int  get_userinput(int *index , int size) ;//获取用户输入
int k=0;//往后在菜单用上下键选择时的判断 

void draw()//打印地图 
{
	for (i = 0; i <= W; i += 2)//打印上，下边界 
	{
		GB(i, 0);
		printf("■");
		GB(i, H);
		printf("■");
	}
	for (i = 1; i < H; i++)//打印左右边界 
	{
		GB(0, i);
		printf("■");
		GB(W, i);
		printf("■");
	}
	while (1)
	{
		srand((unsigned int)time(NULL));
		star.x = rand() % (W-4) + 2;//在4到W-2中随机产生一个数（避免star出现在墙上） 
		star.y = rand() % (H-2) + 1;
		if (star.x % 2 == 0)//每一节蛇身横向占两个格，横坐标为偶数，故star的坐标要一致 
			break;
	}
	GB(star.x, star.y);
	printf("＊");
	snake.len = 3;
	snake.x[0] = W / 2 + 1;
	snake.y[0] = H / 2;
	GB(snake.x[0], snake.y[0]);
	printf("●");//打印蛇头 
	for (i = 1; i < snake.len; i++)//打印蛇身 
	{
		snake.x[i] = snake.x[i - 1] + 2;
		snake.y[i] = snake.y[i - 1];
		GB(snake.x[i], snake.y[i]);
		printf("●");
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
		dir= _getch();//使用getch()时第二个读取的才是所要数据 
		dir= _getch();//实际数据 
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
	if (pre_dir== 77 && dir== 75)dir= 77;//控制蛇不能直接反向走 
		
		
	switch (dir)//蛇上下左右的移动 
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
	printf("●");
	GB(W - 2, 0);
	temp = 0;
	return;
}

void starplace()//蛇吃了星星后再随机出现一颗星星 
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
		printf("＊");
		snake.len++;
		score += 10;
		temp = 1;
	}
	return;
}

bool snakeStatus()//蛇状态的判断 
{
	if (snake.y[0] == 0 || snake.y[0] == H)return false;
	if (snake.x[0] == 0 || snake.x[0] == W)return false;//碰到墙判断后果 
	for (i = 1; i < snake.len; i++)
	{
		if (snake.x[i] == snake.x[0] && snake.y[i] == snake.y[0])
		return false;//碰到蛇身判断后果 
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
void save(void)//将数据保存到文件里 
{
  snake_node *p=NULL;
  if((mem=fopen("memory.txt","ab"))==NULL)//该文件可以续写 
  {
  	fprintf(stderr,"Can not open memory.txt!\n");
  	exit(1);
  }
  fprintf(mem,"%d ",snake.len);
  fprintf(mem,"%d\n",score);
  fclose(mem);
}
void load(void)//读取文件里的内容并打印出来 
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
		printf(" 蛇的长度为：%d   得分为：%d\n",ll,ss);
	}
	getchar();//敲击键盘任意键跳出页面 
	fclose(mem);
}

void showmenu(HANDLE hOut ,char **menu , int size , int index)
{
 int i ; 
 system("cls");  
 SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);//设置显示的文本的颜色  
 pos.X = 30;
 pos.Y = 0 ;//初始化控制台显示的X,Y轴的坐标
 SetConsoleCursorPosition(hOut,pos);//设置显示到控制台终端的具体位置     
 for(i = 0 ; i < size ; i++)
 {
  if(i == index)//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象
  {
   SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);//红色  
      pos.X = 30;
      pos.Y = i;
      //设置光标坐标
      SetConsoleCursorPosition(hOut,pos);    
      printf("%s",menu[i]);
  }
  else//其他显示白色 
  {
     SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
     pos.X = 30;
     pos.Y = i;
     SetConsoleCursorPosition(hOut,pos);    //设置光标坐标
     printf("%s",menu[i]);
  }//营造选择的效果 
 }
 fflush(stdout);//刷新标准输出缓冲区 
}
 
int  get_userinput(int *index , int size)//获取用户输入的接口 
{
 int ch ;
 ch = getch();
 switch(ch)
 {
  case 72: 
   if(*index > 0)  *index -= 1 ;
   k-=1;
   break;//上键 
  case 80:
  if(*index < size -1)  *index += 1 ;  
  k+=1;
  break;//下键 
  case 75: //其他键不能进行选择 
  case 97:return 0 ;
  case 77:return 0 ;
  case 13: 
  case 27: return 27 ;
 }
 return 0 ;
}




void setColor(unsigned short textColor, unsigned short backColor)//游戏时背景与字体的颜色 
{
 char command[9]="color 07";  //默认颜色 
 command[6]='0'+backColor;  //将backColor变量改为字符型 
 command[7]='0'+textColor;  //将textColor变量改为字符型 
 system(command);    //调用系统函数 
}

	
int main()
{
    int ret ,a;
    int index = 0 ;
    int c;
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); //获取当前的句柄---设置为标准输出句柄 
    GetConsoleCursorInfo(hOut, &cci); //获取光标信息  
    cci.dwSize = 1;//设置光标大小    
    cci.bVisible =  0; //设置光标不可见 FALSE 
    SetConsoleCursorInfo(hOut, &cci); //设置(应用)光标信息  
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
		       printf("游戏介绍：\n欢迎来到贪吃蛇游戏\n回车键是确定键\n菜单界面的内容选择由上下键控制\n游戏等级为1~8，数字越大难度越高\n蛇的方向由上下左右键控制\n");
		       break;
    	case 1:
		       system("cls");
		       draw();
		       Sleep(50000);
		       system("cls");
		       break;
		case 2:
		       printf("选择难度：");
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
		          printf("score:%d\n",score);//边吃的同时可以看到自己的分数 
				  Sleep(400/a);
   	           }
   	           system("cls");
	           GB(W/ 2, H / 2);
	           printf("Game Over!\n");
	           GB(W/ 2, H/ 2 + 1);
	           printf("你最终的得分为：%d\n", score);
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
