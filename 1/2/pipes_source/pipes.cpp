#include<stdio.h>
#include"maze.h"
#include"getch.h"
#include"cursor.h"

char maze[][maze_cols] = {
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@S               @@ @@@       @",
	"@@@@@@@@@ @@  @@ @@@@ @ @ @ @ @",
	"@@     @@   @@ @ @@@@@@@  @ @ @",
	"@@ @@@ @@@ @@ @ @@       @ @  @",
	"@@ @@ @ @@ @@ @ @@@@  @ @@ @  @",
	"@@ @ @ @ @  @@ @ @E@@@ @@ @ @ @",
	"@@ @ @ @ @@ @@@@@@@@@@ @@@@ @ @",
	"@@ @ @ @         @          @ @",
	"@@ @ @ @@@@@@ @@@@@@@@@@@@@@@ @",
	"@@ @   @   @@                 @",
	"@@ @@@@@@@@@@ @@@@@@@@@@@@@@@@@",
	"@@                           @@",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};
int row, col, rCnt = 3;

int main()
{
	mazeInit(maze);
	clear();
	printMaze(maze);
	move(maze_rows-1, 0);
	printf("r = %d", --rCnt);

	row = 1; col = 1;
	move(row, col);

	char cmd;
	while(cmd = getch()) {
		switch(cmd) {
			case 'h':
				if(col-1-1 >= 0) col--;
				break;
			case 'j':
				if(row+1-1 < maze_rows-1) row++;
				break;
			case 'k':
				if(row-1-1 >= 0) row--;
				break;
			case 'l':
				if(col+1-1 < maze_cols-1) col++;
				break;
			case 'r':
				int r = getch();
				maze[row-1][col-1] = r;
				clear();
				printMaze(maze);
				if(is_solve(maze)) return 0;
				move(maze_rows-1, 0);
				printf("r = %d", --rCnt);
				if(!rCnt) {
					clear();
					printf("You lost!\n");
					return 0;
				}
				break;
		}
		move(row, col);
	}
}

