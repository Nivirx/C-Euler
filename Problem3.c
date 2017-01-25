/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <stdlib.h>
#include <stdio.h>

#define NUMBER 600851475143

int main( void ) {
	long num = NUMBER ;
	long num2 = NUMBER;
	long primeFactor = 0;
 
	int counter = 2;

	while (counter * counter <= num2) {
    	if (num2 % counter == 0) {
        	num2 = num2 / counter;
        	primeFactor = counter;
    	} else {
        	counter++;
    	}
	}
	if (num2 > primeFactor) { // the remainder is a prime number
	  primeFactor = num2;
	}

	printf("Largest prime factor of %lu is %lu\n", NUMBER, primeFactor);	
return 0;
}
