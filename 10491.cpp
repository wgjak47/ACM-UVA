#include<cstdio>
#include<cstring>
main()
{
	int cows,cars,doors;
	while (scanf("%d%d%d",&cows,&cars,&doors)==3)
		printf("%.5f\n",1.0*cows/(cows+cars)*cars/(cows+cars-doors-1)+1.0*cars/(cows+cars)*(cars-1)/(cows+cars-doors-1));
	return 0;
}
