#include<stdio.h>


//�Ǻ���ġ �ݺ���
int fibonacci(int n) {
	int current = 1;
	int before = 0;
	int temp;

	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		for (int i = 1; n > i; i++) {
			temp = current;
			current = before + temp;
			before = temp;

		}
		return current;
	}
}


int main() {

	printf("%d\n", fibonacci(6));

}




//factorial �ݺ���
int factorial(int n) {
	int i = 0;
	int result = 1;

	for (i = n; n > 0; i--) {

		result *= i;

	}
	return result;
}

int main() {

	printf("%d", factorial(3));

}





//�ŵ����� ��������
int O_power(int base, int exponent) {
	if (exponent == 0) {
		return 1;
	}

	int n = pow(base, exponent / 2);
	int temp = n * n;

	if (exponent % 2 == 0) { // exponent�� ¦���� ��
		return temp;
	}
	else { // exponent�� Ȧ���� ��
		return base * temp;
	}
}

int main() {
	printf("%d\n", O_power(2, 3));
	return 0;
}

