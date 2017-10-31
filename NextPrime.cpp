// Program to fing the imediate next prime number of a given number

#include<iostream>
using namespace std;

bool isPrime(long long num) {

    if (num == 2 || num == 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    int factor = 6;

    while (factor * factor - 2 * factor + 1 <= num) {
        if (num % (factor - 1) == 0)
            return false;
        if (num % (factor + 1) == 0)
            return false;

        factor += 6;

    }

    return true;

}

int main()
{
    long long num;
    cout << "Please select a number to find the next greater prime!" << endl;
    cin >> num;
    while (!isPrime(++num)) {}
    cout << "The next prime is " << num << "!" << endl;
    return 0;
}
