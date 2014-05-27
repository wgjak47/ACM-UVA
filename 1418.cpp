#include<cstdio>
#include<cstring>
main()
{
    int N;
    while (scanf("%d",&N)==1 && N)
    {
        if (N<=3)
            printf("1\n");
        else if (N==4)
            printf("2\n");
        else
            printf("%d\n",N);
    }
    return 0;
}
