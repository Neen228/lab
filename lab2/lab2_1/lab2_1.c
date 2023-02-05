#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool scaner_x (double *x)
{
	printf("Enter x:\n");
    while (!(scanf("%lf", x) && fabs(*x) < 1)) {
   		printf("invalid input\n");
   		scanf("%*[^\n]");
    }
    return true;
}

bool scaner_n (int *x)
{
	printf("Enter amount:\n");
	char c;
    while (!(scanf("%d%c",x,&c) == 2) && (*x>0) && (c =='\n')) {
    	printf("invalid input\n");
    	scanf("%*[^\n]");
    }
    return true;
}

double amount_terms(double x, int n)
{
    double  c, term, sum = 1;
    int i = 5 ;
	c = x * x;
    if (n == 1)
        return sum;
    term = 3 * c / 2;
    for (i = 5; i < 2 * n +1; i += 2){
        sum += term;
        term = (c * term * i) / (i - 1);
    }
    return sum;   
}

int main()
{
	double x;
	int n;
	scaner_x(&x);
	scaner_n(&n);
    printf("%.15lf\n", amount_terms(x, n));
	printf("%.15lf\n", (1 / ((1 - pow(x, 2)) * pow(1 - pow(x, 2), 0.5))));
	return 0;
}
