#define SIZE 50
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


int main() {
	void caesarEncrypt(char a[], char* ct, int key);
	void caesarDecrypt(char a[], char* pt, int key);

	char s[SIZE];
	printf("Enter plaintext you want to encrypt(A~z):");
	gets_s(s, SIZE);

	char* ct = (char*)malloc(sizeof(char) * SIZE);
	char* pt = (char*)malloc(sizeof(char) * SIZE);
	int key = 3;

	caesarEncrypt(s, ct, key);
	printf("Ciphertext : %s\n", ct);
	caesarDecrypt(ct, pt, key);
	printf("Plaintext : %s\n", pt);
	
	free(ct);
	free(pt);
	
	return 0;
}

void caesarEncrypt(char a[], char* ct, int key) {
	//a는 plaintext 이고 key만큼 각 문자를 이동시킬 것임
	int i;
	for (i = 0; a[i] != 0; i++) {
		
		if (isupper(a[i])) {
			a[i]=tolower(a[i]);
			ct[i] = (a[i] + key - 97) % 26 + 97;
			ct[i]=toupper(ct[i]);
			a[i]=toupper(a[i]);
		}

		else if (!isalpha(a[i])) {
			ct[i] = a[i];
		}
			
		//a[i]=0 는 문자열의 끝을 의미함 이때까지 반복
		else {
			ct[i] = (a[i] + key - 97) % 26 + 97; // 모듈러 연산 
			//97 넣어주는 이유는 'a'의 아스키코드가 97이어서.
		}
	}

	ct[i] = 0;
	return;
}

void caesarDecrypt(char c[], char*pt, int key) {
	//그냥 반대로 해주면 됨 
	int i;
	key = 26 - key; //언제나 양수
	//key가 음수가 되면 모듈러 연산에서 이상한 값이 나올 수 있어서 조정하는 것
	
	
	for (i = 0; c[i] != 0; i++) {
		if (isupper(c[i])) {
			c[i]=tolower(c[i]);
			pt[i] = (c[i] + key - 97) % 26 + 97;
			pt[i]=toupper(pt[i]);
			c[i] = toupper(c[i]); //caesarDecrypt 함수를 한 번 돌리면 상관이없는데 만약 이 함수를 여러번 돌린다면 문제가 생김
		}

		else if (!isalpha(c[i])) {
			pt[i] = c[i];
		}

		else {
			pt[i] = (c[i] + key - 97) % 26 + 97;
		}
	}
	pt[i] = 0;
	return;
}
