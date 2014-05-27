#include<stdio.h>
#include<string.h>
int main()
{
    int N, t = 0;
    while(scanf("%d", &N)==1)
    {
        int i;
        for(i = 16; (N & 1 << i) == 0; i --);
        printf("Case %d: %d\n", ++ t, i + (N - (1 << i) != 0));
    }
    return 0;
}
