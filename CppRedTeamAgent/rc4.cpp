#include "rc4.h"

#define N 256   // 2^8

void swap(unsigned char* a, unsigned char* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int KSA(char* key, unsigned char* S)
{

	int len = strlen(key);
	int j = 0;

	for (int i = 0; i < N; i++)
		S[i] = i;

	for (int i = 0; i < N; i++) {
		j = (j + S[i] + key[i % len]) % N;

		swap(&S[i], &S[j]);
	}

	return 0;
}

unsigned char* PRGA(unsigned char* S, unsigned char* plaintext, int length) {

	int i = 0;
	int j = 0;
	unsigned char* ciphertext = (unsigned char*)malloc(length + 1);
	memset(ciphertext, 0, length + 1);

	for (size_t n = 0, len = length; n < len; n++)
	{
		i = (i + 1) % N;
		j = (j + S[i]) % N;

		swap(&S[i], &S[j]);
		int rnd = S[(S[i] + S[j]) % N];

		ciphertext[n] = rnd ^ plaintext[n];

	}

	return ciphertext;
}

unsigned char* RC4(char* key, unsigned char* plaintext, int length) {

	unsigned char S[N];
	KSA(key, S);

	return PRGA(S, plaintext, length);
}