#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int euclidgcd(int num1, int num2) {
	if (num1 == 0) return num2;
	else if (num2 == 0) return num1;
	euclidgcd(num2, num1 % num2);
}

int main(void) {
	int num1, num2, num, gcd;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &num1, &num2);
		gcd = euclidgcd(num1, num2);
		printf("%d\n", (num1 / gcd) * (num2 / gcd) * gcd);
	}
	return 0;
}