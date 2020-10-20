#include <stdio.h>

int multi_inverse(int n, int m){
	int i = 1;
	while((n * i) % m != 1)
		i += 1;
	return i;
}

int main(){
	int i, n, m;
	printf("To quit use ctrl^c.\nn*multi_inverse mod m = 1\n");
	while(1){
		printf("Enter n: ");
		scanf("%d", &n);
		printf("Enter m: ");
		scanf("%d", &m);
		
		printf("Multiplicative inverse: %d\n", multi_inverse(n, m));
			
	}

	return 0;
}
