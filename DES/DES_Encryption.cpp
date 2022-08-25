#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


/*상수 정의*/
#define BLOCK_SIZE 8 //DES 블록 사이즈 (64bit니까 8byte라는 뜻인가..?)
#define DES_ROUND 16 //DES 라운드 수

/*타입 정의*/
typedef unsigned char BYTE; //char는 256가지이므로 1byte크기와 동일
typedef unsigned int UINT;


/*사용되는 함수*/
void key_expansion(BYTE* key, BYTE round_key[16][6]); 
//64bit key를 48bit 라운드키 16개로 확장하는 함수
void IP(BYTE* in, BYTE* out); 
//in에 있는 애들을 substitution해서 out로 보냄
void BtoW(BYTE* in, UINT* x, UINT* y); //byte(8bit)->word(32bit)
void WtoB(UINT l, UINT r, BYTE* out); //word(32bit)->byte(8bit)
void In_IP(BYTE* in, BYTE* out); //역초기 순열
void swap(UINT* x, UINT* y);
UINT f(UINT in, BYTE* rkey); //파이스텔 한 라운드에 나오는 f 함수

/*암호화 함수*/
void DES_Encryption(BYTE* p_text, BYTE* result, BYTE* key) {
	//아마 p_text(바이트배열(?))이 인자로 들어오는 듯 하다..
	
	BYTE data[BLOCK_SIZE] = { 0, }; 
	BYTE round_key[16][6] = { 0, };
	UINT L = 0, R = 0;

	key_expansion(key, round_key);
	IP(p_text, data); //p_text를 이리저리 바꾼 결과를 data에 담음

	//64bit 블록을 32bit짜리 2개로 나눔
	BtoW(data, &L, &R);

	//DES Roudn 1~16
	for (int i = 0; i < DES_ROUND; i++) {
		L = L ^ f(R, round_key[i]);
		//마지막 라운드는 swap 안함
		if (i != DES_ROUND - 1) {
			swap(&L, &R); 
		}
	}
	WtoB(L, R, data); //32bit로 나눠진 블록을 다시 64bit로 변환
	In_IP(data,result);//역초기 순열
}
