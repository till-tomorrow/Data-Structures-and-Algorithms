// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1

#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l)/2;
		if (arr[mid] == x) return mid;
		if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
		return binarySearch(arr, mid+1, r, x);
	}

	return -1;
}

int main(void)
{
	int arr[] = {2, 3, 4, 10, 40};
	int n = sizeof(arr)/ sizeof(arr[0]);

	printf("Check if a particular key is present\n");
	int key;
	scanf("%d", &key);

	int result = binarySearch(arr, 0, n-1, key);
	if (result == -1) {
		printf("Element is not present in array\n");
	}
	else {
		 printf("Element is present at index %d\n", result);
	}
	return 0;
}
