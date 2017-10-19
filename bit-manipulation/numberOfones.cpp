/* Write a function that takes an unsigned integer and returns the number of 1 bits it has. */

#include <stdio.h>

int countOnes(int n) {
	int ans = 0;
	while(n) {
		n = n&(n-1);
		ans++;
	}
	return ans;
}

int main() {
	printf("Enter a number you want to check the number of 1s in:\n");

	int key;
	scanf("%d", &key);

	int ans = countOnes(key);
	printf("%d\n", ans);
	return 0;
}