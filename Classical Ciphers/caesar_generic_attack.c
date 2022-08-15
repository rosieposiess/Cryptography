//brute force attack 코드

#include <stdio.h>
#include <malloc.h>
#define SIZE 100

void caesarDecrypt(char ct[], char* pt, int key);

int main() {
	char ct[] = "T estyv ncjaezrclasj td dfns ly leeclnetgp dfmupne.";

	for (int i = 0; i < 26; i++) {
		char* pt = (char*)malloc(sizeof(char) * SIZE); 
		//pt를 null로 원래 접근했었을 때 읽기 엑세스 오류 났었음 
		//접근할 곳이 없어서였던듯

		caesarDecrypt(ct, pt, i);
		printf("%c | Plaintext : %s\n", i + 65, pt);
		free(pt);
	}

	return 0;
}
