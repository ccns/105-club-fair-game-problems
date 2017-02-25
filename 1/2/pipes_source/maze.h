#ifndef _MAZE_
#define _MAZE_

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<unistd.h>
#include"cursor.h"
using std::queue;

const int dir_r[] = {0, 0, -1, 1};
const int dir_c[] = {-1, 1, 0, 0};

struct coordinate {
	int r, c;
	coordinate(int r=0, int c=0):r(r), c(c){}
}start;

const int MAX_SIZE = 100;
int maze_rows, maze_cols, vis[MAX_SIZE][MAX_SIZE];
int endCnt = 0;

void mazeInit(char maze[][MAX_SIZE])
{
	memset(vis, 0, sizeof(vis));

	maze_cols = strlen(maze[0]);
	for(int i = 0;; i++) {
		if(strlen(maze[i]) == 0) {
			maze_rows = i;
			break;
		}
	}

	for(int i = 0; i < maze_rows; i++)
		for(int j = 0; j < maze_cols; j++) {
			if(maze[i][j] == 'S') { start.r = i; start.c = j; }
			if(maze[i][j] == 'E') endCnt++;
		}
}

void printMaze(char maze[][MAX_SIZE])
{
	for(int i = 0; i < maze_rows-1; i++) printf("%s\n", maze[i]);
}

bool floodfill(char maze[][MAX_SIZE], bool solved)
{
	memset(vis, 0, sizeof(vis));
	int endCntdown = endCnt;

	queue<coordinate> Q;
	Q.push(coordinate(start.r, start.c));
	vis[start.r][start.c] = 1;

	bool ok = false;
	while(!Q.empty()) {
		coordinate u = Q.front(); Q.pop();
		for(int i = 0; i < 4 && !ok; i++) {
			coordinate v(u.r+dir_r[i], u.c+dir_c[i]);
			if(vis[v.r][v.c] || v.r >= maze_rows || v.r < 0 || v.c >= maze_cols || v.c < 0) continue;
			if(maze[v.r][v.c] == 'E' && !vis[v.r][v.c] && !(--endCntdown)) { ok = true; break; }
			vis[v.r][v.c] = 1;
			if(maze[v.r][v.c] != ' ' && maze[v.r][v.c] != 'E') continue;
			Q.push(v);
			if(solved) {
				if(maze[v.r][v.c] != 'E') maze[v.r][v.c] = '.';
				clear();
				printMaze(maze);
			}
		}
		if(solved) usleep(50000);
	}

	if(ok) return true;
	return false;
}

bool is_solve(char maze[][MAX_SIZE])
{
	if(floodfill(maze, false)) {
		floodfill(maze, true);
		clear();
		printf(\
				"************************************************\n"\
				"*CHICKEN:*******************************:ATTACK*\n"\
				"************************************************\n");
		return true;
	}
	return false;
}

#endif
