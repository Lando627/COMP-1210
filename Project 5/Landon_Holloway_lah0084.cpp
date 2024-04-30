/*
* COMP 2710 Project 5 Spring 2023
* Landon Holloway (lah0084)
* Compiled in AU Terminal by g++ Landon_Holloway_lah0084.cpp
* Follow with ./a.out command which brings you to user input.
* No outside material was used. 
*/

#include <iostream> 
using namespace std;

int main (void) {
    const int max = 10;
    int tests[max];
    int test;
    int num_elems;

    cout << "How many numbers? ";
    cin >> num_elems;

    if (num_elems > max) {
        cout << "Too many numbers. Please try again." << endl;
        return 1;

    }

    /* 
    * 2.1: tests[i]: 0 <= i < max
    * 2.2: i
    * 2.4: tests[V] = test
    */
    for (int i = 0; i < num_elems; i++) {
        cout << "Please type a number: ";
        cin >> test;
        tests[i] = test;


    }
    return 0;


}