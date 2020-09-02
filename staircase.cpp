#include <stdio.h>
using namespace std;

int main()
{
    int n, i, j, s = 0, pattern = 0;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        s = n - (i+1);
        for(j = 0; j < s; j++)
        {
            printf(" ");
        }
  
        pattern = i + 1;
  
        for(j = 0; j < pattern; j++)
        {
            printf("#");
        }
  
        printf("\n");
    }
}
