#include "Matrix.h"
#include <iostream>

// Testing the default constructor and get() method
void test_constructor_and_get(){
    Matrix mat(2,3);
    std::cout << "Test Constructor and Get: ";
    std::cout << ((mat.get(0,0)== 0) ? "Passed" : "Failed")<<std::endl;
}
// Testing the copy constructor
void test_copy_constructor(){
    Matrix mat1(2,3);
    mat1.set(0,0,5);
    Matrix mat2 = mat1;
    std::cout << "Test Copy Constructor: ";
    std::cout << ((mat2.get(0,0) == 5) ? "Passed" : "Failed") << std::endl;
}
// Testing the addition of 2 matrices
void test_addition(){
    Matrix mat1 (2,2);
    mat1.set(0,0,1);
    Matrix mat2 (2,2);
    mat2.set(0,0,2);
    Matrix result = mat1 + mat2;
    std::cout << "Test Addition: ";
    std::cout << ((result.get(0,0) == 3) ? "Passed" : "Failed") << std::endl;
}
// Testing the subtraction of 2 matrices
void test_subtraction(){
    Matrix mat1 (2,2);
    mat1.set(0,0,5);
    Matrix mat2 (2,2);
    mat2.set(0,0,3);
    Matrix result = mat1 - mat2;
    std::cout << "Test Subtraction: ";
    std::cout << ((result.get(0,0) == 2) ? "Passed" : "Failed") << std::endl;
}
// Testing the multiplication of 2 matrices
void test_multiplication(){
    Matrix mat1(2,3);
    mat1.set(0,0,1);
    mat1.set(0,1,2);
    mat1.set(0, 2,3);
    Matrix mat2(3,2);
    mat2.set(0, 0,4);
    mat2.set(1,0,5);
    mat2.set(2,0,6);
    Matrix result = mat1 * mat2;
    std::cout << "Test Multiplication: ";
    std::cout << ((result.get(0, 0) == 32) ? "Passed" : "Failed") << std::endl;
}
// Testing the transpose operation
void test_transpose(){
    Matrix mat(2, 3);
    mat.set(0,1,5);
    Matrix result = ~mat;
    std::cout << "Test Transpose: ";
    std::cout << ((result.get(1,0) ==5) ? "Passed" : "Failed") << std::endl;
}
// Testing the equality operator
void test_equality(){
    Matrix mat1(2,2);
    mat1.set(0,0,1);
    mat1.set(0,1,2);
    Matrix mat2(2, 2);
    mat2.set(0,0,1);
    mat2.set(0,1,2);
    std::cout << "Test Equality: ";
    std::cout << ((mat1 == mat2) ? "Passed" : "Failed") << std::endl;
}
// Testing the toStr method
void test_toStr() {
    Matrix mat(2,2);
    mat.set(0,0,1);
    mat.set(0,1,2);
    mat.set(1,0,3);
    mat.set(1,1,4);
    std::string expected_output = "1 2 \n3 4 \n";
    std::cout << "Test toStr: ";
    std::cout << ((mat.toStr() == expected_output) ? "Passed" : "Failed") << std::endl;

}
// Testing addition with incompatible matrices to ensure exception is thrown
void test_invalid_dimensions_addition(){
    Matrix mat1(2, 2);
    Matrix mat2(3, 2);
    try{
        Matrix result = mat1+mat2;
        std::cout << "Test Invalid Addition: Failed" << std::endl;
    }catch (const std::invalid_argument){
        std::cout << "Test Invalid Addition: Passed" << std::endl;
    }
}
// Testing multiplication with incompatible matrices to ensure exception is thrown
void test_invalid_dimensions_multiplication(){
    Matrix mat1(2,3);
    Matrix mat2(2,2);
    try{
        Matrix result = mat1 * mat2;
        std::cout << "Test Invalid Multiplication: Failed" << std::endl;
    }catch (const std::invalid_argument){
        std::cout << "Test Invalid Multiplication: Passed" << std::endl;
    }
}

int main(){
    test_constructor_and_get();
    test_copy_constructor();
    test_addition();
    test_subtraction();
    test_multiplication();
    test_transpose();
    test_equality();
    test_toStr();
    test_invalid_dimensions_addition();
    test_invalid_dimensions_multiplication();
    return 0;
}