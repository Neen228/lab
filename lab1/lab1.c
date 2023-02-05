#include <stdio.h>

 
int f(int number) {
	int out = 0, c = 1;
 	while (number != 0) {
		int reminder = number % 2;
		number = number / 2;
 		out = out + reminder * c;
 		c = c * 10;
 	}
 	return out;
 }


 int main (void){
	 int number;
	 printf("Enter number:");
	 scanf("%d", &number);
	 printf("%d\n", f(number));
	 return 0;
 }

