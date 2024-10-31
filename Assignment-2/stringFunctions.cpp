#include <iostream>
#include <cstring>

using namespace std;

// Function to calculate the lenght of a string
unsigned int length(const char* str){
    unsigned int len = 0; // counter to track the length of the string
    while (str[len] != '\0') { // loop through each character in "str" until the null terminator is encountered
        len++; // increment the counter for every character encountered
    }
    return len; // return the total length
}

// Function to copy a source string (src) into a destination string (dest)
char* copy(char* dest, const char* src){
    int i = 0; // index to keep track of the current character position
    while (src[i] != '\0') { // loop through each character in "src" until the null terminator is encountered
        dest[i] = src[i]; // copy each charcater from "src" to the correct postition in "dest"
        i++; // increment the counter for every character encountered
    }
    dest[i] = '\0'; // adding a null terminator to the end of "dest"
    return dest; // return the destination pointer
}

// Function to find the index of a specific characters first occurrence
int indexOf(char c, const char* str){
    for (int i = 0; str[i] != '\0'; i++) { // loop through each character in "str" until the null terminator is encountered
        if (str[i] == c) { // check if the current character is the same as the seach character "c"
            return i; // if a match is found we return the index i
        }
    }
    return -1; // if the loop completes with no match found we return -1 to show there was no "c"
}

// Function to make a substring from a given string (str) between the indicies "i" and "j"
char* substring(int i, int j, const char* str){
    if (i < 0 || j <= i || j > length(str)) { // checking if the values for "i" and "j" are valid, "i" should be non-negative,"j" should be greate than "i", "j" should be less than "str"
        return NULL; // return NULL if they are invalid
    }
    char* subStr = new char [j - i + 1]; // new substring of length (j - i) + 1 to include the null terminator
    int k = 0; // index for "subStr"
    for (int index = i; index < j; index++) { // copying characters from "str" within the range [i,j] into "subStr"
        subStr[k++] = str[index]; // copy characters from "str" to "subStr" and increment "k"
    }
    subStr[k] = '\0'; // adding null terminator to mark the end of "subStr"
    return subStr; // return the substring
}

// Function to replace all occurrences of a specified character in a string
char* replace(char c, char p, const char* str){
    int len = length(str); // get the length of the original string
    char* newStr = new char[len + 1]; // new string with replaces letters, includes space for the null terminator
    for (int i = 0; i < len; i++) { // loop through each character of the original string
        if(str[i] == c) { // if the character at "i" matches "c"
            newStr[i] = p; // replace it with "p"
        } else {
            newStr[i] = str[i]; // otherwise we keep the original character
        }
    }
    newStr[len] = '\0'; // adding the null terminator to the end of "newStr"
    return newStr; // return the new string
}

// Test Cases

// Length function
void length_test_case_1() {
    const char* testStr = "string";
    unsigned int expected = 6;
    unsigned int result = length(testStr);
    if (result == expected) {
        cout << "length_test_case_1 PASSED" << endl;
    } else {
        cout << "length_test_case_1 FAILED" << endl;
    }
}
// Copy function
void copy_test_case_1() {
    char dest[10];
    const char* src = "string";
    char* result = copy(dest, src);
    if(result && string(dest) == "string") {
        cout << "copy_test_case_1 PASSED" << endl;
    } else {
        cout << "copy_test_case_1 FAILED" << endl;
    }
}
// IndexOf function
void indexOf_test_case_1() {
    const char* testStr = "string";
    int expected = 3;
    int result = indexOf('i', testStr);
    if(result == expected) {
        cout << "indexOf_test_case_1 PASSED" << endl;
    } else {
        cout << "indexOf_test_case_1 FAILED" << endl;
    }
}
// Substring function
void substring_test_case_1() {
    const char* testStr = "string";
    char* result = substring(0, 3, testStr);
    string expected = "str";
    if(result && string(result) == expected) {
        cout << "substring_test_case_1 PASSED" << endl;
    } else {
        cout << "substring_test_case_1 FAILED" << endl;
    }
    delete[] result; 
}
// Replace function
void replace_test_case_1() {
    const char* testStr = "string";
    char* result = replace('s', 'x', testStr);
    string expected = "xtring";
    if(result && string(result) == expected) {
        cout << "replace_test_case_1 PASSED" << endl;
    } else {
        cout << "replace_test_case_1 FAILED" << endl;
    }
    delete[] result;
}
// Calling the test functions
int main(){
    length_test_case_1();
    copy_test_case_1();
    indexOf_test_case_1();
    substring_test_case_1();
    replace_test_case_1();
    return 0;
}