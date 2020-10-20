#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<sys/time.h>

#define MAX 1000
char securitykeyAZ[26]="QSCFTHMLPOKNGRDZAWEUIJVXYB";
char securitykeyaz[26] = "qscfthmlpokngrdzaweuijvxyb";

/*
void PrepareSecurityKey(){
	int i, key;
	while(i < 26){
		key = rand()%26;
		if(CheckKey(key, i)){
			securitykeyAZ[i] = key + 65;
			securitykeyaz[i] = key + 97;
			i += 1;
		}
	}
}
*/

char Cipher(char c){
	if(c > 96 && c < 123)
		return securitykeyaz[c - 97];
	else if(c > 64 && c < 91)
		return securitykeyAZ[c - 65];
	else
		return c;
}
char Plain(char c){
	int i;
	if(c > 96 && c < 123){
		for(i = 0; i < 26; i++){
			if(securitykeyaz[i] == c)
				return i + 97;
		}	
	}
	else if(c > 64 && c < 91){
		for(i = 0; i < 26; i++){
			if(securitykeyAZ[i] == c)
				return i + 65;
		}
	}
	else
		return c;
}

char *Encrypt(char *plaintext){
	int len = strlen(plaintext);
	int i;
	char *ciphertext = (char *)malloc(len);
	if(ciphertext == NULL)
		return NULL;
	for(i = 0; i < len; i++)
		if(plaintext[i] != 32)
			ciphertext[i] = Cipher(plaintext[i]);
	return ciphertext;
	
}
char *Decrypt(char *ciphertext){
	int len = strlen(ciphertext);
	int i;
	char *plaintext = (char *)malloc(len);
	if(plaintext == NULL)
		return NULL;
	for(i = 0; i < len; i++){
		plaintext[i] = Plain(ciphertext[i]);
	}
	return plaintext;
}

int main(){
	char text[MAX];
	printf("Enter text: ");
	scanf("%s", text);

	long int t1, t2, t3;
        struct timeval tv1, tv2, tv3, tv4, tv5, tv6;

	/*
	gettimeofday(&tv5, NULL);
	PrepareSecurityKey();
	gettimeofday(&tv6, NULL);
	t3 = (tv6.tv_usec) - (tv5.tv_usec);
	printf("Time required for creating keys: %ld usecs\n", t3);
	*/
	gettimeofday(&tv1, NULL);
	char *ciphertext = Encrypt(text);
	gettimeofday(&tv2, NULL);
	t1 = (tv2.tv_usec) - (tv1.tv_usec);

	gettimeofday(&tv3, NULL);
	char *plaintext  = Decrypt(text);
	gettimeofday(&tv4, NULL);
	t2 = (tv4.tv_usec) - (tv3.tv_usec);
	
	printf("\nplaintext: %s\nciphertext: %s\n", text, ciphertext);
    	printf("\nTime required: %ld usec\n", t1);

	printf("\nciphertext: %s\nplaintext: %s\n", text, plaintext);
    	printf("\nTime required: %ld usec\n", t2);

	free(ciphertext);
	free(plaintext);

	return 0;
}
