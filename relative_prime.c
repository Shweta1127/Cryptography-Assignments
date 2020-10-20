#include <stdio.h>
#define greater(a, b) a > b ? a : b
#define lesser(a, b) b > a ? a : b

int gcd(int p, int q) {
	int n, m, r;
	n = greater(p, q);
	m = lesser(p, q);

	while(m > 0){
		r = n % m;
		n = m;
		m = r;
	}
	return n;
}

//if gcd(n, m) == 1 Relative prime	
int main() {
   	int n, m, i, flag = 0;
	printf("To quit use ctrl^c.\n");
	while(1){
	   	printf("Enter n: ");
	   	scanf("%d", &n);
	   	printf("Enter m: ");
	   	scanf("%d", &m);

		if (gcd(n, m) == 1)
			printf("Relative prime numbers.\n");
		else
			printf("Not relative prime numbers.\n");
	}

    return 0;
}
