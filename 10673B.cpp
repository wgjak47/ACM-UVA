#include<stdio.h>
#include<string.h>
int main()
{
    int a, b, p, q, x, k, t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &x, &k);
        a = x / k;
        b = x / k + (x % k ? 1 : 0);
        if(a != b)
            p = -x, q = x;
        else
            p = 0, q = k;
        printf("%d %d\n", p, q);
    }
    return 0;
}
