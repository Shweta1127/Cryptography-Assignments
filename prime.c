#include <stdio.h>

int check_prime(int n) {
	int i;
	int m = n / 2;
	
	for (i = 2; i <= m; i++) {
		if (n % i == 0) {
			return 0; // Not Prime
		}
	}

	return 1; // Prime
}

int main() {
  	int n, i, flag = 0;
	printf("To quit use ctrl^c.\n");
	while(1){
	   	printf("Enter a positive integer: ");
	    	scanf("%d", &n);
	    	if (n == 1) {
			printf("1 is neither prime nor composite.");
	    	}
	    	else {
			if (check_prime(n))
		    		printf("%d is a prime number.\n", n);
			else
		    		printf("%d is not a prime number.\n", n);
	    	}
	}

    return 0;
}
