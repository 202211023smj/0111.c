#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 5
#define WID 5
#define LEN 5

int NUM=5;
int number;
void in_bingo(int a[ROWS][COLS], int b[WID][LEN]);
void init_bingo(int a[ROWS][COLS]);
void print_bingo(int a[ROWS][COLS]);
void win_bingo(int a[ROWS][COLS]);
int main(void)
{
	int a[ROWS][COLS]={0};
	int b[WID][LEN]={0};
	init_bingo(a);
	in_bingo(a, b);
	printf("\n");
	print_bingo(a);
	print_bingo(b);
	printf("3 빙고\n");
	return 0;
}
void in_bingo(int a[ROWS][COLS], int b[WID][LEN])
{
	int number, d, c, i, j;
	int bingocnt, sum=0;
	srand((unsigned)time(NULL));
	
	while(bingocnt<3)
	{
		int x=rand()%5;
		int y=rand()%5;
		d=x;
		c=y;
		bingocnt=0;
		printf("(x,y)=(%d, %d)\n", d, c);
		number=rand()%25+1;
		printf("number=%d\n", number);
		
		for(i=0;i<NUM;i++)
		{
			for(j=0;j<NUM;j++){
				if(b[i][j]==0)
				{
					if(a[i][j]==number)
					b[i][j]=1;
				}
					sum+=b[i][j];
				if(sum>=5)
					bingocnt++;
			}
			sum=0;
		}
		for(i=0;i<NUM;i++)
			{
			sum+=b[i][i];
			if(sum>=5)
				bingocnt++;
			sum=0;
			}
		for(i=4;i>-1;i--)
			{
			sum+=b[i][j];
			if(sum>=5)
				bingocnt++;
			sum=0;
			}
		}
	}
void init_bingo(int a[ROWS][COLS]){
	int count=0;
	while(count<25){
		int x=rand()%5;
		int y=rand()%5;
		if(a[x][y]==0){
			a[x][y]=count+1;
			count++;
		}
	}
}
void print_bingo(int a[ROWS][COLS]){
	for(int i=0;i<NUM;i++)
	{
		for(int j=0;j<NUM;j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}