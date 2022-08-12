#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#include <stdio.h>
#include <ctype.h>
#include <string>

//빈도수 체크 코드

int main() {
	void onlyAlpha(char s[], int leng);
	void alphaFrequency(char s[], int leng);
	char s[SIZE];
	int leng = 0;

	printf("Enter your string : ");
	gets_s(s,SIZE);
	for (; s[leng] != 0; leng++) {}
	onlyAlpha(s, leng);
	alphaFrequency(s, strlen(s)); //알파벳 빈도수 분석 함수
	return 0;
}


void onlyAlpha(char s[],int leng) { //알파벳 빼고 다 지움
	char temp[SIZE] = { 0 }; //임시 문자열
	int j = 0;
	
	for (int i = 0; i < leng; i++) {
		if (isalpha((s[i]))) {
			temp[j] = s[i];
			j++;
		}
	}
	temp[j] = 0;
	strcpy(s, temp);
	printf("%s\n", s);	
}


void alphaFrequency(char s[], int leng) { // s는 입력받을 문자열, leng은 s의 길이
	
	int f[26] = { 0 };

	for (int i = 0; i < leng; i++) {
		if (islower(s[i])) {
			s[i] = toupper(s[i]);
		}
		int n = s[i] - 65; 
		f[n]++;
	}

	//결과물 출력
	for (int j = 0; j < 26; j++) {
		printf("%c : %d (%2.2f)\t", j + 65, f[j], (float)f[j] / leng);
	}
}
