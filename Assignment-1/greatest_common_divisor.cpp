/*
This program reads two integers from the user and calculates their Greatest Common Divisor.

This will be done by:
1) Using the Euclidean algorithm to find the GCD of the two input integers.
2) In each iteration of the loop, the second number (b) will be replaced by the remainder of the division of the first number (a) by the second number (b) using the modulo operation(a % b).
3) The first number (a) will be updated to the value of the second number (b) from the previous iteration.
4) Once the second number (b) becomes 0, the process is complete, and the first number (a) will hold the GCD.

Example:
Input:  56 and 24
Output: 8
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) { 
    //loop for calculating the gcd using euclidean algorithm
    while (b != 0) { //loop ends once "b" = 0
        int temp = b; //storing "b" temporarily
        b = a % b; //"b" updated to the remainder of "a" divided by "b"
        a = temp; //"a" updated to the inital value of "b"
    }
    return a; //when "b" = 0, "a" hold the gcd
}
int main() {
    int num1, num2; //declaring input variables for the two inputed numbers

    cout << "Please enter Two Integers: "; //asks the user for two integer inputs
    cin >> num1 >> num2; //stores the inputs into the variables "num1" and "num2"
    
    //calculate and output gcd
    cout << gcd(num1, num2) << endl; //prints the gcd for the user

    return 0; 
}