#define SIZE 100
#include <math.h>
#include <stdio.h>
#include <malloc.h>

bool prime_test(int n) {
	int int_sqrt = (int)sqrt(n);
	for (int i = 2; i <= int_sqrt; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool relt_prime(int a, int b) {
	int max = (a > b) ? a : b;
	int min = (a < b) ? a : b;

	if (max % min == 0) {
		return false;
	}
	else {
		if (prime_test(max) || prime_test(min))
			return true;

		//max랑 min이 common divisor갖는지 확인
		for (int i = 2; i < min; i++) {
			if (prime_test(i) == 0) continue;
			//왜냐면 i까지 왔다는 거는 i-1까지 다 안나눠졌다는건데
			//i가 prime이 아니라면 i의 약수로도 안나눠졌다는 것이므로 굳이 테스트 할 필요 x 
			else {
				if (max % i == 0 && min % i == 0)
					return false;
			}
		}
		return true;
	}

}

int* reltPrimeArray(int x, int* len) {
	int* arr = (int*)malloc(sizeof(int) * SIZE);
	if (arr == NULL) {
		printf("메모리 할당 오류");
	}
	int ctr = 0;
	for (int i = 2; i <= x; i++) {
		if (relt_prime(i,x)) {
			arr[ctr] = i;
			ctr++;
		}
	}
	*len = ctr; //포인터에 뭐 대입해줄 때마다 null포인터으면 안됨!! 
				//왜냐하면 주소가 없기 때문에..(컴터가 어디에 저장해야할지 모름)
	printf("%d\n", ctr);
	return arr;
}
