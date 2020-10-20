#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<sys/time.h>

#define MAX 1000

char Cipher(char c, int key){
	if(c > 96 && c < 123)
		return ((c - 97 + key) % 26) + 97;
	else if(c > 64 && c < 91)
		return ((c - 65 + key) % 26) + 65;
	else
		return c;
}
char Plain(char c, int key){
	if(c > 96 && c < 123){
		if(c - key - 97 < 0)
			return ((c - key - 97 + 26) % 26) + 97;
		else
			return ((c - key - 97) % 26) + 97;
	}		
	else if(c > 64 && c < 91){
		if(c - key - 64 < 0)
			return ((c - key - 64 + 26) % 26) + 64;
		else
			return ((c - key - 64) % 26) + 64;
	}	
	else
		return c;
}

char *Encrypt(char *plaintext, int key){
	int len = strlen(plaintext);
	int i;
	char *ciphertext = (char *)malloc(len);
	if(ciphertext == NULL)
		return NULL;
	for(i = 0; i < len; i++)
		if(plaintext[i] != 32)
			ciphertext[i] = Cipher(plaintext[i], key);
	return ciphertext;
	
}
char *Decrypt(char *ciphertext, int key){
	int len = strlen(ciphertext);
	int i;
	char *plaintext = (char *)malloc(len);
	if(plaintext == NULL)
		return NULL;
	for(i = 0; i < len; i++){
		plaintext[i] = Plain(ciphertext[i], key);
	}
	return plaintext;
}

int main(){
	char text[MAX] = "dhfrkjsdnkasjnierhkdnkjfdjsf";
	int key = 3;
	printf("Enter text: ");
	scanf("%s", text);
	printf("Enter key: ");
	scanf("%d", &key);
	long int t1, t2;
        struct timeval tv1, tv2, tv3, tv4;

	gettimeofday(&tv1, NULL);
	char *ciphertext = Encrypt(text, key);
	gettimeofday(&tv2, NULL);
	t1 = (tv2.tv_usec) - (tv1.tv_usec);
	gettimeofday(&tv3, NULL);
	char *plaintext  = Decrypt(text, key);
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
