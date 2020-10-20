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

int main(){
	int p, q, n, m, r;
	printf("To quit use ctrl^c.\n");
	while(1){
		printf("Enter p: ");
		scanf("%d", &p);
		printf("Enter q: ");
		scanf("%d", &q);	

		printf("GCD: %d\n", gcd(p, q));
	}
	

	return 0;
}
