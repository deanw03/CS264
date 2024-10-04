/*
This program reads an integer from the user and checks if it is a palindrome.

This will be done by:
1) Storing the original input to compare it later.
2) Reversing the digits of the input by:
    - Using the modulo operation(%) to isolate the last digit of the input(num).
    - Adding these isolated digits to a variable(reversedNum) by shifting them to the left(*10) for each iteration of the loop.
    - Removing the last digit from the input(num) after each iteration of the loop(/=10).
    - Once "num" = 0 the process will be complete and "reversedNum" will be printed for the user.
3) Comparing the reversed number to the original input to check if they are the same.
4) If the reversed number is equal to the original, the number is a palindrome. Otherwise, it is not.

Example:
Input:  1221
Output: True
*/
#include <iostream> 
using namespace std;

int main() {
    int num; //variable for the inputed number
    int reversedNum = 0; //variable for the final reversed number
    int originalNum; //variable for the original number which will be compared to the reverse
    int remainder; //variable which will be continuously be added onto each iteration of the loop
    originalNum = num; //storing original number to compare later

    cout << "Please enter an Integer: "; //asks the user to enter an integer
    cin >> num; //stores the input in the variable "num"

    //loop for reversing the inputed integer
    while (num != 0) { //loop is finished once "num" is 0
        remainder = num % 10; //gets the last digit of the input
        reversedNum = reversedNum * 10 + remainder; //adds the last digit to "reversedNum" and adds the remainder to it's right
        num /= 10; //removes the last digit from "num" as it has already been added to the front
    }

    //check if the reversed number is the same as the original number
    if (originalNum == reversedNum) {
        cout << "True" << endl; //if true then the number is a palindrome
    } else {
        cout << "False" << endl; //if false then the number is not a palindrome
    }
    return 0;
}