#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <iso646.h>

bool scaner_x (double *x){
	printf("Enter x:\n");
    while (!(scanf("%lf",x) and fabs(*x)<1)) {
    	printf("invalid input\n");
    	scanf("%*[^\n]");
    	}
    return true;
}


bool scaner_epsilon (double *x)
{
	printf("Enter epsilon:\n");
    while (!(scanf("%lf",x) and (*x<1))) {
    	printf("invalid input\n");
    	scanf("%*[^\n]");
	    }
    return true;
}


double accuracy(double epsilon, double x, int *counter){
    double term, c, sum = 1;
    int i = 5;
    *counter = 1;
	c = x * x;
    term = 3 * c / 2;
    while (fabs(term) > epsilon){
         sum += term;
         *counter += 1;
         term = (c * term * i) / (i - 1);
         i += 2;
    }
    return sum;
}

int main()
{
	double x, epsilon, sum;
	int counter;
	scaner_x(&x);
	scaner_epsilon(&epsilon);
	sum = accuracy(epsilon, x, &counter);
	printf("value:%lf\n", sum);
	printf("amount:%d\n", counter);
	printf("%.15lf\n", (1 / ((1 - pow(x, 2))*pow(1 - pow(x, 2),0.5))));	
	return 0;
}

