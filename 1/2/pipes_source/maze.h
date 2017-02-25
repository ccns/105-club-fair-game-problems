#ifndef _MAZE_
#define _MAZE_

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include"cursor.h"

const int dir_r[] = {0, 0, -1, 1};
const int dir_c[] = {-1, 1, 0, 0};

struct coordinate {
	int r, c;
}start, end;

const int maze_cols = 100;
int maze_rows, vis[maze_cols][maze_cols];

void mazeInit(char maze[][maze_cols])
{
	memset(vis, 0, sizeof(vis));

	for(int i = 0;; i++) {
		if(strlen(maze[i]) < 1) {
			maze_rows = i+1;
			break;
		}
	}

	for(int i = 0; i < maze_rows; i++) {
		for(int j = 0; j < maze_cols; j++) {
			if(maze[i][j] == 'S') { start.r = i; start.c = j; }
			if(maze[i][j] == 'E') { end.r = i; end.c = j; }
		}
	}
}

void printMaze(char maze[][maze_cols])
{
	for(int i = 0; i < maze_rows; i++) printf("%s\n", maze[i]);
}

bool dfs(char maze[][maze_cols], int r, int c)
{
	if(r == end.r && c == end.c) return true;
	if(vis[r][c] || maze[r][c] != ' ' || r < 0 || c < 0 || r >= maze_rows || c >= maze_cols) return false;
	//maze[r][c] = '%';
	//clear();
	//printMaze(maze);
	vis[r][c] = 1;
	for(int i = 0; i < 4; i++) if(dfs(maze, r+dir_r[i], c+dir_c[i])) return true;
}

bool is_solve(char maze[][maze_cols])
{
	for(int i = 0; i < 4; i++) if(dfs(maze, start.r+dir_r[i], start.c+dir_c[i])) {
		clear();
		printf(\
				"************************************************\n"\
				"*CHICKEN:*******************************:ATTACK*\n"\
				"************************************************\n");
		return true;
	}
	memset(vis, 0, sizeof(vis));
	return false;
}

#endif
