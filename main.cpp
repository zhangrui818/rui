#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define RON 9
#define COL 11
char map[RON][COL+1]={
	{"*#*********"},
	{"***###*###*"},
	{"###**#****#"},
	{"*#**###**#*"},
	{"***********"},
	{"#####*##*##"},
	{"**#*****#*E"},
	{"***#*###**#"},
	{"*#*********"},
};

void print_map()
{
	for(int i=0;i<RON;i++)
	{
		puts(map[i]);
	}
}
void show_cursor(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	printf("curX=%dcurY=%d\n",x,y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int curX,curY;
int main()
{
	while(1)
	{
		system("cls");
print_map();
show_cursor(curX,curY);
char t=getch();
if(t=='w')
{
	//������
	if((curY-1)>=0&&map[curY-1][curX]=='*'||map[curY-1][curX]=='E') curY--;
}
else if(t=='s')
{
	//������
if((curY+1)<RON&&map[curY+1][curX]=='*'||map[curY+1][curX]=='E') curY++;
}
else if(t=='a')
{
	//������
if((curX-1)>=0&&map[curY][curX-1]=='*'||map[curY][curX-1]=='E') curX--;
}
else if(t=='d')
{
	//������
if((curX+1)<COL&&map[curY][curX+1]=='*'||map[curY][curX+1]=='E') curX++;
}

if(map[curX][curY]=='E')
{
	printf("oh you are so snart!\n");break;

}
	}
	return 0;
}