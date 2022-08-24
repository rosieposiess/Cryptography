/*
Transposition Cipher (전치 암호)
:평문 문자의 순서를 어떤 규칙에 따라 바꾼것!
그 규칙을 어떻게 구현하느냐가 문제
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BLOCK_SIZE 6
#include <string>


void insertKey(int key[BLOCK_SIZE]) {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		printf("Enter your key array\n (each element must be different from each other) (%d/%d) :", i + 1, BLOCK_SIZE);
		scanf("%d", &key[i]);
		for (int j = 0; j < i; j++) {
			if (key[j] == key[i]) {
				printf("Element duplicated!");
				i--;
			}
		}
	}
}

void padding(char pt[]) {
	int r = strlen(pt) % BLOCK_SIZE; //패딩 해줘야할 부분
	if (r == 0) {
	}
	else {
		for (int i = 0; i < BLOCK_SIZE - r; i++) {
			strcat(pt, "x");
		} //pt=59 r=5
	}
	printf("After Padding : %s\n", pt);
}

char* encrypt(int key[], char pt[]) {
	//int key[64] = {3,5,1,6,4,2};
	padding(pt);
	char* c=(char*)malloc(sizeof(char)*strlen(pt)+1); //null문자 자리 추가..
	int BLOCK_NUM = strlen(pt) / BLOCK_SIZE;


	for (int i = 0; i < BLOCK_NUM; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			*(c+(i * BLOCK_SIZE + j)) = pt[i * BLOCK_SIZE + (key[j]-1)];
			//key[j]에서 1을 빼준 이유? key[j]=3이면 3번째라는 뜻인데, 
			//결론적으로는 4번째가 되므로ㅜㅜ
			//i=0,j=0 -> c[0]=pt[key[0]]=pt[key[3]]
		}
	}
	c[strlen(pt)] = 0;
	return c;
}

int main() {

	int key[BLOCK_SIZE] = { 0 };
	char p_text[64];
	char* c_text=(char*)malloc(sizeof(char)*64);
	insertKey(key);
	//key array는 ct의 위치와 pt의 위치와 대응시킨것
	//ex) (1,3),(2,5) ...

	printf("Enter a plaintext:");
	scanf("%s", p_text);
	//불가능->c_text(수정 전에 배열이었음 ㅜ)=encrypt(key, p_text);(포인터를 배열에 할당할 수 없음. 이유?)
	c_text = encrypt(key,p_text);
	printf("%s",c_text);
	return 0;

}
