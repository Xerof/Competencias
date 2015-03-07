#include <stdio.h>
#define MAX_CHAMBERS 51
#define MAX_BROKERS 501
#define STEP 1

int queue[MAX_CHAMBERS];

void clean (int (*graph)[MAX_CHAMBERS], int N)
{
	int i, j;
	
	for(i = 0; i < N ; i++)
		for(j = 0 ; j < N; j++)
			graph[i][j] = 0;
}
/* BFS */

void findChamberTime(int (*graph)[MAX_CHAMBERS], int N ,int *distancias)
{
	int i,j;
	int first = 0;
	int last  = 0;
	distancias[1] = 1;
	int v = 1;
	queue[last++] = v;
	
	while(first < last)
	{
		v = queue[first++];
		for (i = 1; i <= N ; i++)
			if(graph[v][i] && !distancias[i])
			{
				distancias[i] = distancias[v] + STEP;
				queue[last++] = i;
			}
	}
}

int main ()
{
   int T; // Castles
   int N; // Number of Chambers
   int L; // Number of Brokers
   int Q; // Numero of Querries 
   int graph[MAX_CHAMBERS][MAX_CHAMBERS] = {};
   int distancias[MAX_CHAMBERS] = {};
   int i,j;
	
	scanf("%d",&T);
	
    while(T--)
	{
		scanf("%d %d %d",&N,&L,&Q);
		while(L--)
		{
			int src, dest;
			scanf("%d %d", &src, &dest);
			graph[src][dest] = 1;
		}
		
		findChamberTime(graph, N , distancias);
		
		while (Q--)
		{
			int chamber;
			scanf("%d", &chamber);
			printf("%d\n",distancias[chamber] != 0 ? distancias[chamber] : -1 );
		}
		
		clean(graph, MAX_CHAMBERS);
		
		for(i = 0; i < MAX_CHAMBERS; i++)
			distancias[i] = 0;
	}		
	
	return 0;
}