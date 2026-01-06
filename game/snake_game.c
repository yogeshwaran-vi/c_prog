#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/types.h>

int foody,foodx;
int x=10,y=10;
int score=0;
int gameover=0;
char dir='R';

char getch()
{
	char ch;
	struct termios old,new;

	tcgetattr(STDIN_FILENO,&old);
	new=old;
	new.c_lflag &=~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO,TCSANOW,&new);
	ch=getchar();
	tcsetattr(STDIN_FILENO,TCSANOW,&old);
	return ch;
}
void draw()
{
    	int i,j;
    	system("clear");
    	for(i = 0; i < 40; i++)
    	{
        	for(j = 0; j < 80; j++)
        	{
            		if(i == 0 || i == 39 || j == 0 || j == 79)
                		printf("#");
            		else if(i == y && j == x)
                		printf(">");
            		else if(i == foody && j == foodx)
               		 	printf("F");
            		else
                		printf(" ");
        	}
        		printf("\n");
    	}
    	printf("Score: %d\n", score);
}
void input()
{
	char c;
	c=getch();

	if(c=='w')
		dir='U';
	else if(c=='s')
		dir='D';
	else if(c=='a')
		dir='L';
	else if(c=='d')
		dir='R';
}
void food()
{
    foodx=rand()%38+1;
    if(foodx==0)
    {
	    foodx !=0;
    }
    foody=rand()%78+1;
    if(foody==0)
    {
	    foody !=0;
    }
}
void logic()
{
    if(dir == 'U') y--;
    else if(dir == 'D') y++;
    else if(dir == 'L') x--;
    else if(dir == 'R') x++;

    // collision with wall
    if(x <= 0 || x >= 79 || y <= 0 || y >= 39)
        gameover = 1;

    // eat food
    if(x == foodx && y == foody)
    {
        score += 10;
        food();
    }
}

int main()
{
    srand(time(0));
    food();

    while(!gameover)
    {
        draw();
        input();
        logic();
        usleep(10000);
    }

    printf("Game Over! Final Score: %d\n", score);
    return 0;
}

