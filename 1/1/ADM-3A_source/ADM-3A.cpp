#include<stdio.h>
#include"maze.h"
#include"getch.h"
#include"cursor.h"

char maze[][maze_cols] = {
	"*******************************",
	"*                K** ***      *",
	"********* **  ** **** * * * * *",
	"**     **   ** * ******** * * *",
	"** *** *K** ** * *@       * * *",
	"** *@* * ** ** * ***** * ** * *",
	"** * * * ** ** * * * * ** * * *",
	"** * * * ** **** ***** **** * *",
	"** * * *         *          * *",
	"** * * ****** *************** *",
	"** *   *   ** *K              *",
	"** ********** *****************",
	"**            **             **",
	"*******************************"
};
int row, col;

int main()
{
	mazeInit(maze);
	clear();
	printMaze(maze);
	row = 2; col = 2;
	move(row, col);

	char cmd;
	while(cmd = getch()) {
		switch(cmd) {
			case 'h':
				if(maze[row-1][col-1-1] != '*') col--;
				break;
			case 'j':
				if(maze[row+1-1][col-1] != '*') row++;
				break;
			case 'k':
				if(maze[row-1-1][col-1] != '*') row--;
				break;
			case 'l':
				if(maze[row-1][col+1-1] != '*') col++;
				break;
		}
		move(row, col);

		if(maze[row-1][col-1] == '@') teleport(row, col);
		if(maze[row-1][col-1] == 'K') if(getKey(maze, row, col)) return 0;
	}
}


