#include<stdio.h>
#define COL 3
#define ROW 3

void menu()//菜单 
{
	printf("**********************\n");
	printf("****1.play  0.exit****\n");
	printf("**********************\n");
}

//1.制作棋盘，二维字符数组+棋盘初始化
void BoardInit(char chessboard[ROW][COL],int row,int col)
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			chessboard[i][j]=' ';
		}
	}
}

//2.打印棋盘 
void BoardPrint(char chessboard[ROW][COL],int row,int col)
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %c ",chessboard[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if(i<row-1)
		{
			for(j=0;j<col;j++)
			{
				printf("---");
				if(j<col-1)
				printf("|");
			}
			printf("\n");
		}
	}
}

//玩家落子 （1）读取输入，判断是否被占位 （2）未被占位则落子，被占位再来一次
void PlayerShow(char chessboard[ROW][COL],int row,int col)
{
	int r=0,c=0;
	printf("请玩家下棋:>\n");
	scanf("%d%d",&r,&c);
	while(1)	
	if((r<=row&&r>0)&&(c<=col&&c>0))
	{
		if(chessboard[r-1][c-1]!=' ')
		{
			printf("已被占用，请重新选择\n");
			scanf("%d%d",&r,&c);//发生重复的时候不要忘记让玩家重新输入 
		}
		else
		{
			chessboard[r-1][c-1]='*';
			break;
		}
	}
	else
	{
		printf("输入无效，请重新输入\n");
	}
}

//电脑落子  （1）通过随机值选取没有被占位的格子落子  （2）坐标被占用则重新生成随机数 
void ComputerShow(char chessboard[ROW][COL],int row,int col)
{
	int r=rand()%row;
	int c=rand()%col;
	printf("请电脑下棋:>\n");
	while(1)
	{
		int r=rand()%row;
		int c=rand()%col;//发生重复的时候不要忘记重新生成随机数
		if((r<row&&r>=0)&&(c<row&&c>=0)&&chessboard[r][c]==' ')
		{
			chessboard[r][c]='#';
			break;
		}
		else
		{
			continue;
		}
	}
}

int Isfull(char chessboard[ROW][COL],int row,int col)
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(chessboard[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//判断输赢 1.（1）横的是否相等 （2）竖的是否相等 （3）斜的是否相等 
int Judge(char chessboard[ROW][COL],int row,int col)
{
	int i=0;
	for(i=0;i<row;i++)
	{
		if(chessboard[i][0]==chessboard[i][1]&&chessboard[i][1]==chessboard[i][2]&&chessboard[i][1]!=' ')
		{
			if(chessboard[i][1]=='*')
			{
				printf("玩家胜！\n");
				return 1;
			}
			else
			{
				printf("电脑胜！\n");
				return 1;
			}
		}
	}
	for(i=0;i<col;i++)
	{
		if(chessboard[0][i]==chessboard[1][i]&&chessboard[1][i]==chessboard[2][i]&&chessboard[1][i]!=' ')
		{
			if(chessboard[1][i]=='*')
			{
				printf("玩家胜！\n");
				return 1;
			}
			else
			{
				printf("电脑胜！\n");
				return 1;
			}
		}
	}
	if(chessboard[0][0]==chessboard[1][1]&&chessboard[1][1]==chessboard[2][2]&&chessboard[1][1]!=' ')
	{
		if(chessboard[1][1]=='*')
		{
			printf("玩家胜！\n");
			return 1;
		}
		else
		{
			printf("电脑胜！\n");
			return 1;
		}
	}
	if(chessboard[0][2]==chessboard[1][1]&&chessboard[1][1]==chessboard[2][0]&&chessboard[1][1]!=' ')
	{
		if(chessboard[1][1]=='*')
		{
			printf("玩家胜！\n");
			return 1;
		}
		else
		{
			printf("电脑胜！\n");
			return 1;
		}
	}
	if(Isfull(chessboard,row,col)==1)//判断是否平局要放在判断是否胜利后面 
	{
		printf("平局\n");
		return 1;
	}
	return 0;
}

//对弈（1）玩家落子(每次落子之后打印） （2）电脑落子 （3）判断输赢(每次落子后打印） 
void PlayChess(char chessboard[ROW][COL],int row,int col)
{
	int ret=0;
	while(1)
	{
		PlayerShow(chessboard,row,col);
		BoardPrint(chessboard,row,col);
		ret=Judge(chessboard,row,col);
		if(ret)
		break;
		ComputerShow(chessboard,row,col);
		BoardPrint(chessboard,row,col);
		ret=Judge(chessboard,row,col);
		if(ret)
		break;
	}
}

void test()
{
	int input=0;
	char chessboard[ROW][COL]={0};
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:printf("游戏开始\n"); 
				BoardInit(chessboard,ROW,COL);
				BoardPrint(chessboard,ROW,COL);
				PlayChess(chessboard,ROW,COL); 
				break;
			case 0:printf("游戏结束\n");
				break;
			default:printf("输入错误！请重新输入\n");
				break;
		}
	}while(input);
}

int main()
{
	test();
	return 0;
}
