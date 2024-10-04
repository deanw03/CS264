/*
This program implements a power function Pow(x, y) to calculate x raised to the power y without using the built-in c++ power function. 
The function uses the method of exponentiation by squaring, which has a time complexity of O(log n) where n is the exponent (y). 

Why is it O(log n)?
1) The algorithm reduces the problem size by half in each recursive call.
   - If y is even, we can compute x^(y/2) and then square the result.
   - If y is odd, we compute x^(y-1) and then multiply by x.
2) This halving of the exponent leads to a logarithmic number of steps since each step reduces the exponent significantly.

Example:
Input:  x = 2, y = 10
Output: 1024 
*/
#include <iostream> 
using namespace std; 

//function to calculate x to the power of y
double Power(double x, int y) {
   if (y == 0) { //any number to the power of 0 is 1
      return 1;
   }
   if (y < 0) { //if y is negative, we take the reciprocal
      x = 1 / x; //inverting the base
      y = -y; //making y positive
   }
   double result = 1;

   //loop to implement exponention by squaring
   while (y > 0) { //goes until y becomes 0
      if (y % 2 == 1) { //checking if y is odd
         result *= x; //multiplying result by the base
      }
      x *= x; //squaring the base
      y /= 2; //dividing the exponent by 2
   }
   return result; //returning the final result
}

int main() {
   double x; //variable for the base
   int y; //variable for the exponent

   cout << "Please enter the Base (x): "; // asks the user to input a base
   cin >> x; // saves the base as "x"
   cout << "Please enter the Exponent (y): "; // asks the user to input an exponent
   cin >> y; // saves the exponent as "y"

   cout << Power(x,y) << endl; //calculating and outputing the result for x^y

   return 0;
}