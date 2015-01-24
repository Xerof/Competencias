#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef unsigned char boolean;

char *createPalindromo(const char *str);
void fill(const char *origen, char *dest, unsigned int ban);
boolean isPalindromo(char *str);
int main()
{
   char palindromo[MAX_SIZE];
   scanf("%s",palindromo);
   char *result = createPalindromo(palindromo);
   printf("%s\n", result);

   return 0;
}

char *createPalindromo(const char *str)
{
    size_t len = strlen(str);
    size_t possiblePositions = len+1;
    size_t i;
    char *Palindromo = (char *) malloc(sizeof(char) * possiblePositions + 1);
    memset(Palindromo, '\0',sizeof(char) * possiblePositions + 1);

    for(i = 0; i < possiblePositions ; i++)
    {
        fill(str,Palindromo,i);
        if(isPalindromo(Palindromo))
           return Palindromo;
    }
    return "NA";
            
}

void fill(const char *origen, char *dest, unsigned int ban)
{
    size_t i;
    size_t j;
    size_t len = strlen(origen)+1;

    for( i = j = 0; origen[j] != '\0'; i++)
        if(i != ban)
            dest[i] = origen[j++];

   dest[ban] = dest[len - 1 - ban];
}

boolean isPalindromo(char *str)
{
    size_t i;
    size_t j= strlen(str) - 1;

    for( i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != str[j--])
            return 0;
    }
    return 1;
}
