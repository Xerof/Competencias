#include <stdio.h>

int main()
{
    int n;
    int m;
    int i,j;
    char pos = 1;

    scanf("%d", &n);
    scanf("%d", &m);

    for(i = 0; i < n; i++)
    {
        if( i % 2 == 0)
            for(j = 0; j < m; j++)
                putchar('#');
        else
            if(pos)
            {
                for(j = 0; j < m-1 ; j++)
                    putchar('.');
                putchar('#');
                pos = 0;
            }else
            {
                putchar('#');
                for(j = 0; j < m-1; j++)
                    putchar('.');
                pos = 1;
            }
        printf("\n");
    }
}
