/**************************************************************************************************
 * PROBLEM: 
 *			Weed Invasion
 *
 * PROBLEM NUMBER:
 *			1385
 *
 * WEB SITE:
 *			http://coj.uci.cu/24h/problem.xhtml?pid=1385
 *
 * AUTOR:
 *			Xerof - 06/03/2014
 **************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_X 101
#define MAX_Y 101
#define INF -1
#define STEP 1
#define MAX_MOVES 8

struct Coordinates
{
	int x;
	int y;
};

/**************************************************************************************************
 * FUNCTION: BFS
 * PARAMETERS:
 * 	@graph  - Matrix that contains the position of the pasture and the rocks
 * 	@X      - X Coordinate
 * 	@Y      - Y Coordinate
 * 	@MovesX - Valid moves in X Coordinate
 * 	@MovesY - Valid moves in Y Coordinate
 * 	@Mx     - X coordinate of the weed 
 *  @My     - Y coordinate of the weed
 *  @MaxMoves - Maximum number of movements for the weed
 * DESCRIPTION:
 * This function is used to calculate how long the weep will last until it spreads over all the 
 * squares
 * RETURN
 * 		The number of weeks that the weed has took to complete the invasion
 **************************************************************************************************/
int bfs(char (*graph)[MAX_X], int X, int Y, int *MovesX, int *MovesY, int Mx, int My, int MaxMoves)
{
	int dist[MAX_Y][MAX_X];
	struct Coordinates CoorQueue[ MAX_X * MAX_Y] = {};
	int front = 0;
	int back = 0;
	int i,j;
	for(i = 0; i < Y; i++)
		for(j = 0; j < X; j++)
			dist[i][j] = INF;
	
	dist[My][Mx] = 0;
	CoorQueue[back].x = Mx;
	CoorQueue[back].y = My;
	back++;
	while(front < back)
	{
		struct Coordinates tmp = CoorQueue[front++];
		
		for( i = 0; i < MaxMoves; i++)
		{
			int x = tmp.x + MovesX[i];
			int y = tmp.y + MovesY[i];
			
			if(x < 0 || x >= X && y < 0 || y >= Y)
				continue;
			
			if(graph[y][x] != '*' && dist[y][x] == INF)
			{
				graph[y][x] = 'M';
				dist[y][x] = dist[tmp.y][tmp.x] + STEP;
				CoorQueue[back].x = x;
				CoorQueue[back].y = y;
				back++;
			}
		}
	}
	front--;
	return dist[CoorQueue[front].y][CoorQueue[front].x];
}

int main(int argc, char **argv)
{
	char graph[MAX_Y][MAX_X] = {};
	int validMovesX[]= {-1,-1,-1,0,0,1,1,1};
	int validMovesY[]= {1,0,-1,1,-1,1,0,-1};
	int x,y, Mx, My;
	char *str;
	int i,j;
	int DEBUG;
	
	DEBUG = argc > 1 ? atoi(argv[1]) : 0;
	
	scanf("%d %d %d %d",&x,&y,&Mx,&My);
	fflush( stdin );

	str = malloc(sizeof(char)*x);
	if(!str){
		printf("Malloc Failed couldn't allocate memory");
		return 1;
	}
	/* Get User's input string where . is pasture and * is a rock*/
	for (i = 0; i < y; i++)
	{
		scanf("%s", str);
		char *c = str;

		for(j = 0; c[j] != '\0'; j++)
			graph[i][j] = c[j];
	}
	// print how many weeks the weeb will last until it spreads over all the squares
	int result = bfs(graph, x, y, validMovesX, validMovesY, Mx-1, y-My, MAX_MOVES);
	printf("%d", result ? result : 1);
	free(str);
	if(DEBUG)
	{
		for(i = 0; i < y ; i++)
		{
			for ( j = 0 ; j < x; j++)
			{
				printf("%c ",graph[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
