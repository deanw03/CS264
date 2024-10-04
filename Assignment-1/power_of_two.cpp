/*
This function checks whether a given integer is a power of two.

This will be done by:
1) Checking if the input is positive, powers of 2 must be greater than 0.
2) If the number can be divided by 2, we keep dividing it by 2.
3) At the end of the loop, if the number remaining is a 1, it means that the number is a power of 2.
4) If the number is not a 1, it means the number is not a power of 2.

Example:
Input:  8
Output: True
*/
#include <iostream> 
using namespace std;

bool powerOfTwo(int num) {
    if (num <= 0) return false; //powers of 2 must be greater than 0
    //loop to divide num by 2 until it is no longer divisible by 2
    while (num % 2 == 0) { //if num is divisible by 2, continue dividing
        num /= 2; //dividing the number by 2
    }
    //if num has been reduced to 1, it is a power of 2
    return num == 1; //return true if num is 1, otherwise false
}

int main() {
    int num;
    //asks the user to enter a non-negative integer
    cout << "Please enter a non-negative integer: ";
    cin >> num; //saves that integer as "num"

    //letting the user know if their input is a power of two
    if (powerOfTwo(num)) { //checking the "powerOfTwo" function to produce an output based on the results
        cout << "True" << endl; //"True" is printed if the function returns a 1
    } else {
        cout << "False" << endl; //"False" is printed if the function returns a number other than 
    }
    return 0;
}