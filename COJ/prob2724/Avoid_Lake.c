#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 100

unsigned int matriz[MAX_ROW][MAX_COL];
int N,M;

void dfs(int row, int col, unsigned int *deph)
{
    //need to check if we are not out of bounds 
    if(row < 0 || row > N ||col < 0 || col > M)
        return;
    if(!matriz[row][col]) // dry
       return ;
    (*deph)++;
    matriz[row][col] = 0; // mark as dry to avoid infinite recursion 
    dfs(row - 1, col, deph); // chek up
    dfs(row + 1, col, deph);// check down
    dfs(row, col-1, deph); // check left
    dfs(row, col+1, deph); // check right 
}


int main()
{
   int c,r,K,deph,max_deph;
   int i,j;
   scanf("%d %d %d", &N, &M, &K);
   for ( i=0; i<K ; i++)
   {
         scanf("%d %d", &r, &c);
         r--; c--;
         matriz[r][c] = 1;
   }
   
   for ( i = 0; i < N; i++)
   {
       for( j = 0; j < M; j++)
       {
            if(matriz[i][j])
             {
                 deph = 0;
                 dfs(i,j,&deph);
                 if(deph > max_deph) // check if we hace a new max deph
                     max_deph = deph;
              }
       }
    }
    printf("%d",max_deph);
}
