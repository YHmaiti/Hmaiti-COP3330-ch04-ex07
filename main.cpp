/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Yohan Hmaiti
 */

// include the header file that has all the imports and prototypes needed
#include "std_lib_facilities.h"

// use the standard namespace
using namespace std;

// create a vector that will hold the string of the name reflecting a digit
// if i = 5 then the vector called numbers at index 5 will hold the string "five"
vector<string> numbers; 

// function used to gather the input from the user when appropriate
int input() {

    // set a variable to hold the limit possible which is 10
    // create a variable val to be set to 10, then changed later if a valid value of a digit was found
    // set a String to be a helper in order to siplify working with String related digits when the user enters
    // the digit as a word
    int novalid = numbers.size(); 
    int val = 10;
    string helper;

    // conditional that handles the case when the user enters a digit as a number and not a string
    if (cin >> val) {
        
        // if the value entered is a digit we work with it by returning it, otherwise throw an error
        if(val < 10 && val >= 0)
            return val; 

        else {
            error("----The entered number is invalid, please only enter single digits!!-----");
            exit(0);
        }

    }

    // use the .clear command to clear any error flag on cin
    cin.clear();
    
    // get the digit that the user entered as a String
    cin >> helper;

    // loop to check if the String matches any digit
    // if so then set value to the index where the string is stored
    for (int i = 0; i < numbers.size(); i++) 
        if (numbers[i] == helper) {
            val = i;
            return val;
        }
    
    // return the val
    return 10;
}

// main driver function
int main(void){

    // add the appropriate string values for each digit from 0 up to 9 inclusive
    // in a ascending order in order to set the ground for iterative solutions later
    numbers.push_back("zero");
    numbers.push_back("one");
    numbers.push_back("two");
    numbers.push_back("three");
    numbers.push_back("four");
    numbers.push_back("five");
    numbers.push_back("six");
    numbers.push_back("seven");
    numbers.push_back("eight");
    numbers.push_back("nine");

    // prompt the user for input
    cout << "Enter two digit values either number or string separated with spaces and operator in between that can be: (+ - * / ) ";

    // create a helper string to help in the printing process
    // create a double variable to handle the result after the appropriate processing
    string helper;
    double result;
    // get the first digit from the user
    int val1 = input();
    // declare a variable to store the operator inputted by the user
    char operation = 0;
    cin >> operation; 
    // get the second digit from the user
    int val2 = input();

    // switch used to determine the helper string content along with the result based on what the user
    // inputs as operator stored within operation
    switch (operation) {

        // handle the case of addition
        case '+':
            helper = "The result of the sum of ";
            if (val1 >= 10 || val1 < 0 || val2 >= 10 || val2 < 0)
            {
                error("The entered number is not a digit from 0 to 9 inclusive, try again!!: ", helper);
                exit(0);
            }
            result = val1 + val2;
            break;

        // handle the case of subtraction
        case '-':
            if (val1 >= 10 || val1 < 0 || val2 >= 10 || val2 < 0)
            {
                error("The entered number is not a digit from 0 to 9 inclusive, try again!!: ", helper);
                exit(0);
            }
            helper = "The subtraction of ";
            result = val1 - val2;
            break;

        // handel the case of multiplication
        case '*':
            if (val1 >= 10 || val1 < 0 || val2 >= 10 || val2 < 0)
            {
                error("The entered number is not a digit from 0 to 9 inclusive, try again!!: ", helper);
                exit(0);
            }
            helper = "The result of the product of ";
            result = val1 * val2;
            break;

        // handle the case of division
        case '/':
            if (val1 >= 10 || val1 < 0 || val2 >= 10 || val2 < 0)
            {
                error("The entered number is not a digit from 0 to 9 inclusive, try again!!: ", helper);
                exit(0);
            }
            helper = "The result of the division of ";
            if (val2 == 0)
                error("Attention!!! Division by 0 is invalid, try again");
            result = val1 / val2;
            break;

        // handle any casualty with the presence of an invalid operator
        default:
            error("The entered operator is invalid, please try again!");

        }
        
        // print the result to the user
        cout << helper << val1 << " and " << val2 << " -> " << result << '\n';

    
    return 0; // end of the main function
}
