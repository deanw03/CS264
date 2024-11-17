#include "Matrix.h"
#include <iostream>
#include <sstream>

/**
 * Creates a matrix with a specific number of rows and columns, initialises all elements to zero
 * Dynamically allocates memory using a 2D array
 * @param m is the number of rows in the matrix
 * @param n is the number of columns in the matrix
 */
Matrix::Matrix(unsigned int m, unsigned int n) : rows_(m), columns_(n) {
    data = new int*[rows_]; // allocating memory for the rows
    for(unsigned int i = 0; i< rows_; i++){
        data[i] = new int[columns_]; // allocating memeory for each row's columns
    }
}

/**
 * Copy constructor that makes a new matrix by duplicating an exisiting matrix
 * Dynamically allocates memory for the new matrix and copies the elements and dimensions from the existing matrix
 * @param mat is the matrix being copied 
 */
Matrix::Matrix(const Matrix& mat) : rows_(mat.rows_), columns_(mat.columns_) {
    data= new int*[rows_]; // allocating memory for the rows
    for (unsigned int i = 0; i < rows_; i++){
        data[i] = new int [columns_]; // allocating memory for each row's columns
        for(unsigned int j = 0; j< columns_; j++){
            data[i][j]=mat.data[i][j]; // copying elements from the existing matrix
        }
    }
}

/**
 * Constructor that initialises a matrix using a given 2D array
 * Dynamically allocates memory for the matrix
 * @param array is the 2D array to initialise the matrix
 * @param m is the number of rows in the matrix
 * @param n is the number of columns in the matrix
 */
Matrix::Matrix(int** array, unsigned int m,unsigned int n) :rows_(m), columns_(n){
    data = new int*[rows_]; // allocating memory for rows
    for(unsigned int i = 0; i < rows_; i++){
        data[i] = new int[columns_]; // allocating memory for each row's columns
        for(unsigned int j = 0;j<columns_; j++){
            data[i][j] = array[i][j]; // copying elements from given array
        }
    }
}

/**
 * Destructor for the Matrix class
 * Frees up the dynamically allocated memory for the matrix
 * Loops through the rows to delete the memory for the columns, then deletes the memory for the row pointers
 */
Matrix::~Matrix(){
    for(unsigned int i = 0; i < rows_; i++){
        delete[] data[i]; // freeing up memory for each row
    }
    delete[] data; // freeing up memory for the array of the row pointers
}

/**
 * Returns the number of rows in the matrix
 * Constant method, doesn't modify the matrix
 * @param The number of rows in the matrix
 */
unsigned int Matrix::rows()const{
    return rows_;
}
/**
 * Returns the number of columns in the matrix
 * Constant method, doesn't modify the matrix
 * @return The number of columns in the matrix
 */
unsigned int Matrix::columns() const{
    return columns_;
}

/**
 * Gets the value of the matrix element in a specific position
 * Constant method, doesn't modify the matrix
 * @param i The row index of the element
 * @param j The column index of the elemennt
 * @return Value of the element at the specified position
 * @throws std::out_of_range if the values provided do not exist
 */
int Matrix::get(unsigned int i,unsigned int j)const{
    if(i >= rows_ || j >= columns_){
        throw std:: out_of_range("Index out of range");
    }
    return data[i][j];
}

/**
 * Sets the value of a secific element in a specifies position
 * Method updates the matrix with the given value
 * @param i The row index of the element
 * @param j The column index of the element
 * @param value The new value of the specified element
 * @throws std::out_of_range if the values provided do not exist
 */
void Matrix::set(unsigned i, unsigned int j,int value){
    if(i >=rows_ || j >= columns_){
        throw std:: out_of_range("Index out of range");
    }
    data[i][j] = value;
}

/**
 * Performs matrix addition, adds elements of 2 matrices
 * Method checks if matrices have the same dimensions before doing the addition
 * @param mat The matrix to be added to the existing matrix
 * @return A new Matrix object which is the result of the addition of the 2 matrices
 * @throws std::out_of_range if the values provided do not exist
 */
Matrix Matrix::operator+(const Matrix& mat)const{
    if (rows_ != mat.rows_ || columns_ != mat.columns_){
        throw std::invalid_argument("Matrix dimensions mst agree");
    }
    Matrix result(rows_,columns_);
    for(unsigned int i = 0;i < rows_; i++){
        for(unsigned int j = 0;j<columns_;j++){
            result.data[i ][j] = data[i][j] + mat.data[i][j];
        }
    }
    return result;
}

/**
 * Performs matrix subtraction, subtracts elements of 2 matrices
 * Method checks if matrices have the same dimensions before doing the subtraction
 * @param mat The matrix to be subtracted from existing matrix
 * @return A new Matrix object which is the result of the matrix subtraction
 * @throws std::out_of_range if the values provided do not exist
 */
Matrix Matrix::operator-(const Matrix& mat)const{
    if(rows_ != mat.rows_ || columns_ != mat.columns_){
        throw std::invalid_argument("Matrix dimensions must agree");
    }
    Matrix result(rows_, columns_);
    for(unsigned int i = 0; i< rows_;i++){
        for(unsigned int j = 0; j < columns_; j++){
            result.data[i][j]= data[i][j] -mat.data[i][j];
        }
    }
    return result;
}

/**
 * Performs matrix multiplication, multiplies the current matrix by another matrix
 * Method checks if the number of columns in the current matrix matches the number of rows in the second matrix
 * @param mat The matrix to be multiplied with the current matrix
 * @return A new Matrix object which is the result of the matrix multiplication
 * @throws std::invalid_argument if the dimensions don't allow multiplication
 */
Matrix Matrix::operator*(const Matrix& mat)const{
    if(columns_ != mat.rows_){
        throw std::invalid_argument("Matrix dimensions must agree");
    }
    Matrix result(rows_,mat.columns_);
    for(unsigned int i=0; i < rows_; i++){
        for(unsigned int j = 0; j <mat.columns_; j++){
            result.data[i] [j] = 0;
            for(unsigned int k = 0;k <columns_; k++ ){
                result.data[i][j] += data[i][k] * mat.data[k ][j];
            }
        }
    }
    return result;
}

/**
 * For computing the transpose of the matrix, swaps the rows and columns
 * Method creates a new matrix where the rows of the current matrix become the columns and vice versa
 * @return A new matrix object that is the transpose of the current matrix
 */
Matrix Matrix::operator~() const{
    Matrix result (columns_, rows_);
    for(unsigned int i =0; i < rows_; i++){
        for(unsigned int j = 0; j < columns_; j++){
            result.data[j][i] =data[i][j];
        }
    }
    return result;
}

/**
 * Compares 2 matrices to see if they are equal, they are equal if they have the same dimensions and all elements are the same
 * @param mat The matrix to compare with the current matrix
 * @return true if both are the same, otherwise false
 */
bool Matrix::operator==(const Matrix& mat){
    if(rows_ != mat.rows_ || columns_ != mat.columns_){
        return false;
    }
    for(unsigned int i = 0; i < rows_; i++){
        for (unsigned int j = 0; j < columns_; j++){
            if(data[i][j] != mat.data[i][j])  {
                return false;
            }
        }
    }
    return true;
}

/**
 * Converts the matrix into a string
 * The matrix is represented as rows, with each element in a row being seperated by a space
 * Every row is seperated by a newline character
 * @return A string representation fo the matrix
 */
std::string Matrix::toStr() const{
    std::ostringstream oss;
    for(unsigned int i=0; i < rows_; i++){
        for(unsigned int j = 0; j < columns_; j++){
            oss << data[i][j] << " ";
        }
        oss << "\n";
    }
    return oss.str();
}