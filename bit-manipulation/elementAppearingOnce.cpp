/* Given an array of integers, every element appears twice except for one. Find that single one. */

#include <stdio.h>

int checkNum(int a[], int size) {
	int ans = 0;
	for(int i = 0; i < size; i++) {
		ans^=a[i];
	}
	return ans;
}

int main() {
	int arr[] = {1,1,2,2,3,4,4,5,5};

	printf("Element appearing once is %d\n", checkNum(arr, sizeof(arr)/sizeof(arr[0])));
	return 0;
}