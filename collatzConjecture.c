#include <stdio.h>


int collatz(int n);

int main()
{
	puts("The Collatz conjecture is a conjecture in mathematics.\nTake any positive integer n. If n is even, divide it by 2 to get n / 2.\nIf n is odd, multiply it by 3 and add 1 to obtain 3n + 1. Repeat the process indefinitly.\nThe conjecture is that you will always reach at the end the following numbers \"4 2 1\".");
	puts("Now please enter the n number (integer > 0) you wish and this program will give you the number of steps to reach the conjecture's final numbers");
	int n;
	scanf("%d", &n);
	int numberOfSteps = collatz(n);
	printf("With n=%d, we need %d steps to reach the Collatz conjecture\n", n, numberOfSteps);

	return 0;
}

int collatz(int n)
{
	int steps;
	while(n != 1)
	{
		if(n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n = (n*3) + 1;
		}
		steps++;
		printf("step %d: %d\n", steps, n); 
	}
	return steps;
}
