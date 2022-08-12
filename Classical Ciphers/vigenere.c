#define SIZE 50
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


int main() {
	void vigenereEncrypt(char pt[], char* ct, char key[]);
	void vigenereDecrypt(char ct[], char* pt, char key[]);

	char s[SIZE];
	char key[SIZE];
	printf("Enter plaintext you want to encrypt(A~z):");
	gets_s(s, SIZE);
	printf("Enter your encryption key(a~z):");
	gets_s(key, SIZE);
	

	char* ct = (char*)malloc(sizeof(char) * SIZE);
	char* pt = (char*)malloc(sizeof(char) * SIZE);
	

	vigenereEncrypt(s, ct, key);
	printf("Ciphertext : %s\n", ct);
	vigenereDecrypt(ct, pt, key);
	printf("Plaintext : %s\n", pt);

	free(ct);
	free(pt);

	return 0;
}

void vigenereEncrypt(char pt[], char* ct, char key[]) {
	int i;
	int keyLength;

	for (keyLength = 0; key[keyLength] != 0; keyLength++) {
	}

	for (i = 0; pt[i] != 0; i++) {
		if (isupper(pt[i])) {
			pt[i] = tolower(pt[i]);
			ct[i] = (pt[i] - 97 + (key[i % keyLength]-97+1)) % 26+97;
			ct[i] = toupper(ct[i]);
		}

		else if (!isalpha(pt[i])) {
			ct[i] = pt[i];
		}

		else {
			ct[i] = (pt[i] - 97 + (key[i % keyLength]-97+1)) % 26 +97;
		}
		
	}
	ct[i] = 0;
}


void vigenereDecrypt(char ct[], char* pt, char key[]) {
	int i;
	int keyLength;

	for (keyLength = 0; key[keyLength] != 0; keyLength++) {
	}

	for (i = 0;  ct[i] != 0; i++) {
		if (isupper(ct[i])) {
			ct[i] = tolower(ct[i]);
			pt[i] = (ct[i] - 97 + 26 - (key[i % keyLength]- 97 + 1)) % 26 + 97;
			pt[i] = toupper(pt[i]);
		}

		else if (!isalpha(ct[i])) {
			pt[i] = ct[i];
		}

		else {
			pt[i] = (ct[i] - 97 + 26 - (key[i % keyLength] - 97 +1)) % 26 + 97;
		}
	}
	pt[i] = 0;
}
