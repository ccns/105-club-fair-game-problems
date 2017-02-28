#ifndef _MAZE_
#define _MAZE_

#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include"cursor.h"
using std::vector;

struct coordinate {
	int r, c;
	coordinate(int r, int c):r(r), c(c){}
};

const int maze_cols = 100;
int keyCnt, totalKey, maze_rows;
vector<coordinate> portal;

void mazeInit(char maze[][maze_cols])
{
	keyCnt = 0; totalKey = 0;

	for(int i = 0;; i++) {
		if(strlen(maze[i]) < 1) {
			maze_rows = i+1;
			break;
		}
	}

	for(int i = 0; i < maze_rows; i++) {
		int len = strlen(maze[i]);
		for(int j = 0; j < len; j++) {
			if(maze[i][j] == '@') portal.push_back(coordinate(i, j));
			if(maze[i][j] == 'K') totalKey++;
		}
	}
}

void printMaze(char maze[][maze_cols])
{
	for(int i = 0; i < maze_rows; i++) {
		int len = strlen(maze[i]);
		for(int j = 0; j < len; j++) {
			if(maze[i][j] == '@') printf("%s", "\033[33m@\033[0m");
			else if(maze[i][j] == 'K') printf("%s", "\033[36mK\033[0m");
			else putchar(maze[i][j]);
		}
		putchar('\n');
	}
}

void teleport(int& row, int& col)
{
	//find protal number
	int portal_num;
	for(int i = 0; i < portal.size(); i++) {
		if(portal[i].r == row-1 && portal[i].c == col-1) {
			portal_num = i;
			break;
		}
	}

	int nxt;
	do { nxt = rand()%(portal.size()); } while(nxt == portal_num);

	move(row = portal[nxt].r+1, col = portal[nxt].c+1);
}

bool getKey(char maze[][maze_cols], int row, int col)
{
	maze[row-1][col-1] = ' ';
	keyCnt++;

	if(keyCnt == totalKey) {
		clear();
		printf(\
				"************************************************\n"\
				"*CHICKEN:*******************************:ATTACK*\n"\
				"************************************************\n");
		return true;
	} else {
		clear();
		printMaze(maze);
		move(row, col);
		return false;
	}
}

#endif
