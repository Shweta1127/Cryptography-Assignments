#include <stdio.h>
#define MAX 100

int multi_inverse(int n, int m){
	int i = 1;
	while((n * i) % m != 1)
		i += 1;
	return i;
}
int main(){
	int n[MAX];
	int b[MAX];
	int N[MAX];
	int y[MAX];
	int no;	
	int No = 1;
	scanf("%d", &no);
	int i, j;
	printf("Enter n values: ");
	for(i = 0; i < no; i++){
		scanf("%d", &n[i]);
		No *= n[i];
	}
	printf("Enter b values: ");
	for(i = 0; i < no; i++){
		scanf("%d", &b[i]);
	}
	for(i = 0; i < no; i++){
		N[i] = No / n[i];
		y[i] = multi_inverse(N[i], n[i]);
	}
	int ans = 0;
	for(i = 0; i < no; i++){
		ans += b[i] * N[i] * y[i];
	}
	printf("P : %d\n", ans % No);

	return 0;
}
