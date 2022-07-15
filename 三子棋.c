#include<stdio.h>
#define COL 3
#define ROW 3

void menu()//�˵� 
{
	printf("**********************\n");
	printf("****1.play  0.exit****\n");
	printf("**********************\n");
}

//1.�������̣���ά�ַ�����+���̳�ʼ��
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

//2.��ӡ���� 
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

//������� ��1����ȡ���룬�ж��Ƿ�ռλ ��2��δ��ռλ�����ӣ���ռλ����һ��
void PlayerShow(char chessboard[ROW][COL],int row,int col)
{
	int r=0,c=0;
	printf("���������:>\n");
	scanf("%d%d",&r,&c);
	while(1)	
	if((r<=row&&r>0)&&(c<=col&&c>0))
	{
		if(chessboard[r-1][c-1]!=' ')
		{
			printf("�ѱ�ռ�ã�������ѡ��\n");
			scanf("%d%d",&r,&c);//�����ظ���ʱ��Ҫ����������������� 
		}
		else
		{
			chessboard[r-1][c-1]='*';
			break;
		}
	}
	else
	{
		printf("������Ч������������\n");
	}
}

//��������  ��1��ͨ�����ֵѡȡû�б�ռλ�ĸ�������  ��2�����걻ռ����������������� 
void ComputerShow(char chessboard[ROW][COL],int row,int col)
{
	int r=rand()%row;
	int c=rand()%col;
	printf("���������:>\n");
	while(1)
	{
		int r=rand()%row;
		int c=rand()%col;//�����ظ���ʱ��Ҫ�����������������
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

//�ж���Ӯ 1.��1������Ƿ���� ��2�������Ƿ���� ��3��б���Ƿ���� 
int Judge(char chessboard[ROW][COL],int row,int col)
{
	int i=0;
	for(i=0;i<row;i++)
	{
		if(chessboard[i][0]==chessboard[i][1]&&chessboard[i][1]==chessboard[i][2]&&chessboard[i][1]!=' ')
		{
			if(chessboard[i][1]=='*')
			{
				printf("���ʤ��\n");
				return 1;
			}
			else
			{
				printf("����ʤ��\n");
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
				printf("���ʤ��\n");
				return 1;
			}
			else
			{
				printf("����ʤ��\n");
				return 1;
			}
		}
	}
	if(chessboard[0][0]==chessboard[1][1]&&chessboard[1][1]==chessboard[2][2]&&chessboard[1][1]!=' ')
	{
		if(chessboard[1][1]=='*')
		{
			printf("���ʤ��\n");
			return 1;
		}
		else
		{
			printf("����ʤ��\n");
			return 1;
		}
	}
	if(chessboard[0][2]==chessboard[1][1]&&chessboard[1][1]==chessboard[2][0]&&chessboard[1][1]!=' ')
	{
		if(chessboard[1][1]=='*')
		{
			printf("���ʤ��\n");
			return 1;
		}
		else
		{
			printf("����ʤ��\n");
			return 1;
		}
	}
	if(Isfull(chessboard,row,col)==1)//�ж��Ƿ�ƽ��Ҫ�����ж��Ƿ�ʤ������ 
	{
		printf("ƽ��\n");
		return 1;
	}
	return 0;
}

//���ģ�1���������(ÿ������֮���ӡ�� ��2���������� ��3���ж���Ӯ(ÿ�����Ӻ��ӡ�� 
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
		printf("��ѡ��:>\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:printf("��Ϸ��ʼ\n"); 
				BoardInit(chessboard,ROW,COL);
				BoardPrint(chessboard,ROW,COL);
				PlayChess(chessboard,ROW,COL); 
				break;
			case 0:printf("��Ϸ����\n");
				break;
			default:printf("�����������������\n");
				break;
		}
	}while(input);
}

int main()
{
	test();
	return 0;
}
