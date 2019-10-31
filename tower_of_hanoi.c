// Implementation of Tower of Hanoi puzzle in C
//The task is basically to arrange n number of discs using 3 rods in such a way that
// 1. No disk may be placed on top of a smaller disk.
// 2. Only one disc can be moved at a time
#include <stdio.h>

// recursive function for finding tower of hanoi
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n; // Number of disks
    printf("\nEnter the number of discs: ") ;
    scanf("%d", &n) ;
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}
