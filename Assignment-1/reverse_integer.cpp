/*
This program reads an integer from the user and reverses its digits.

This will be done by:
1) Using the modulo operation(%) to isolate the last digit of the input(num).
2) Adding these isolated digits to a variable(reversedNum) by shifting them to the left(*10) for each iteration of the loop.
3) Removing the last digit from the input(num) after each iteration of the loop(/=10).
4) Once "num" = 0 the process will be complete and "reversedNum" will be printed for the user.

Example:
Input:  123
Output: 321
*/
#include <iostream>
using namespace std;

int main() {
    int num; //variable for the inputed number
    int remainder; //variable for the result of the modulo operation which will be moved to the front
    int reversedNum = 0;  //variable which will be continuously be added onto each iteration of the loop
    cout << "Please enter an Integer: "; //asks the user for an integer input
    cin >> num; //stores that input in the variable "num"

    //loop for reversing the inputed integer
    while (num != 0) { //loop is finished once "num" is 0
        remainder = num % 10; //gets the last digit of the input
        reversedNum = reversedNum * 10 + remainder; //adds the last digit to "reversedNum" and adds the remainder to it's right
        num /= 10; //removes the last digit from "num" as it has already been added to the front
    }
    //output for the reversed number
    cout <<  reversedNum << endl; //shows the user the final iteration of "reversedNum" which is the fully reversed number

    return 0;
}