#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/time.h>

#define MAX 128
#define greater(a, b) a > b ? a : b
#define lesser(a, b) b > a ? a : b

//check prime number
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

//find gcd
int gcd(int p, int q) {
	int m, n, r;
	n = greater(p, q);
	m = lesser(p, q);

	while(m > 0){
		r = n % m;
		n = m;
		m = r;
	}
	return n;
}

//multiplicative inverse
int multi_inverse(int n, int m){
	int i = 5;
	while((n * i) % m != 1)
		i += 1;
	return i;
}

//mod => x^y mod n
int pow_mod( int x, int y, int n) {
	int a = x % n;
	int t = 1;
	while( y > 0 ) {
		// Y is odd
		if( y & 1 )
			t = (t * a) % n;
		y >>= 1;
		a = (a * a) % n;
	}
	return(t);
}

int main(int argc, char* argv[]) {
	int p, q;
	int n, phn;

	int cipher[MAX];
	char plaintext[MAX], decrypt[MAX];

	int len, i;
	long int t1, t2, t3;
        struct timeval tv1, tv2, tv3, tv4, tv5, tv6;

	printf("To quit use ctrl^c.\n");
	while(1){
		while (1) {
			printf("Enter p: ");
			scanf("%d", &p);

			printf("Enter q: ");
			scanf("%d", &q);

			if (!(check_prime(p) && check_prime(q)))
				printf("Please enter prime numbers only...\n");
			else
				break;
		}
		printf("Enter plaintext: ");
		scanf("%s", plaintext);
		len = strlen(plaintext);

		// public key = {e, n}
		// private key = {d, n}
		n = p * q;
		phn = (p - 1) * (q - 1);
		int e = 0;
		for (e = 5; e <= 100; e++) {
			if (gcd(phn, e) == 1)
				break;
		}
		int d = multi_inverse(e, phn);

		//Encryption
		gettimeofday(&tv1, NULL);
		for(i = 0; i < len; i++)
			cipher[i] = pow_mod(plaintext[i], e, n);
		gettimeofday(&tv2, NULL);
		t1 = (tv2.tv_usec) - (tv1.tv_usec);

		//Decryption
		gettimeofday(&tv3, NULL);
		for(i = 0; i < len; i++)
			decrypt[i] = pow_mod(cipher[i], d, n);
		gettimeofday(&tv4, NULL);
		t2 = (tv4.tv_usec) - (tv3.tv_usec);
		
		printf("\nValue of e: %d\nValue of d: %d\n\n", e, d);

		printf("Plaintext ascii values: \n");
		for(i = 0; i < len; i++)
			printf("%d ", plaintext[i]);
		printf("\n\n");


		printf("Cipher values: \n");
		for(i = 0; i < len; i++)
			printf("%d ", cipher[i]);
		printf("\n");
		printf("Time required for encryption: %ld usec\n\n", t1);

		decrypt[i] = '\0';
		printf("The decrypted text is: %s\n", decrypt);
		printf("Time required for decryption: %ld usec\n\n", t2);
	}

	return 0;
}
