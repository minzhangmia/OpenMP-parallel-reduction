
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int main()
{
	double a[1000];
    double sum = 0;
    
	for(int i = 0;i < 1000;i++)
	{
		a[i] = drand48();
	}
	
    #pragma omp parallel for reduction(+:sum) 
    for(int i = 0;i < 1000; i++)
	{
		sum += a[i];
	}
	double average = sum/1000;
	printf("Average of the array values = %lf\n",average);
	return 0;
}