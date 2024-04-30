/* project3_Holloway_lah0084.cpp
 * AUTHOR: Landon Holloway
 * Compiled in AU Terminal by g++ project3_Holloway_lah0084.cpp
 * Follow with ./a.out command which brings you to user input.
 * I did not use any outside resources for this Project. 
 * The only resources I used were Li's hints and the lecture briefings.
 * I would ask that some grace is used on this project if at all possible. I've been under the weather and have tried to produce the best work with what time I have. 
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
/* declare your user-defined functions */
bool check_file(string);
/* do not forget to describe each function */
vector<int> read_file(string);
void write_file(string, vector<int>);
vector<int> merge(vector<int>, vector<int>);
/*
* Display the values of a given vector.
*
* Param: file Name of file to display. (string)
* Param: v Vector containing values to display. (vector<int>)
*/
void to_string(string, vector<int>);
/*
* Merge the numbers in two specified files and write all the numbers
* to a specified third file sorted in ascending order.
*
* Return: 1 Program completed successfully. (int)
*/
int main() {
/* declare your variables */
string file1, file2, file3;
vector<int> numbers1, numbers2, numbers3;
/* Get name of file one. */

cout << "*** Welcome to Landon's sorting program ***\n";

do {
    cout << "Enter the first input file name: ";
    cin >> file1;
} while (cin.fail() || !check_file(file1));

/* Get and display numbers from file one. */
numbers1 = read_file(file1);
to_string(file1, numbers1);
cout << "The list of " << numbers1.size() << " numbers in file " << file1 << " is:\n";
for (int num : numbers1) {
    cout << num << endl;

}

/* Get name of file two. */
do {
    cout << "Enter the second input file name: ";
    cin >> file2;
} while (cin.fail() || !check_file(file2));

/* Get and display numbers from file two. */
numbers2 = read_file(file2);
to_string(file2, numbers2);
cout << "The list of " << numbers2.size() << " numbers in file " << file2 << " is;\n";
for (int num : numbers2) {
    cout << num << endl;
}


/* Combine vectors and display the sorted result. */
numbers3 = merge(numbers1, numbers2);
to_string("output.txt", numbers3);
cout << "The sorted list of " << numbers3.size() << " numbers is:";
for (int num : numbers3) {
    cout << " " << num;
}
cout << endl;

/* Get name of output file. */
do {
    cout << "Enter the output file name: ";
    cin >> file3;
} while (cin.fail());

/* Write combined vector to output file. */
write_file(file3, numbers3);
cout << "*** Please check the new file - " << file3 << " " << endl;
cout << "*** Goodbye. ***" << endl;
return 1;
}

bool check_file(string file) {
/* Input file stream. (ifstream) */
ifstream stream;
/* Check whether file exists. */
stream.open(file.c_str());
if (stream.fail()) {
    cout << "Error opening file: " << strerror(errno) << endl;
    stream.close();
    return false;
}
stream.close();
return true;
}
vector<int> read_file(string file) {
/* Input file stream. (ifstream) */
ifstream stream;
/* Vector containing numbers from file. (vector<int>) */
vector<int> v;
/* Integer read from file. (int) */
int i;
/* Add each number in the file to a vector. */
stream.open(file.c_str(), ios::binary);
if (!stream.is_open()) {
    cout << "Cannot open " << file << "!" << endl;
    return v;

}
while (stream.read((char*)&i, sizeof(int))) {
 v.push_back(i);
}
stream.close();
return v;
}
void write_file(string file, vector<int> v) {
/* Output file stream. (ofstream) */
 ofstream stream;
 stream.open(file.c_str(), ios::binary);
 if (!stream.is_open()) {
    cout << "Cannot open " << file << "!" << endl;
    return; 
 }

 for (int num : v) {
    stream.write((char*)&num, sizeof(int));
 }
 stream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {
vector<int> merged;
int i = 0, j = 0;

/* Compare both vectors. */
while (i < v1.size() && j < v2.size()) {
if (v1[i] > v2[j]) {
    merged.push_back(v2[j]);

} 
else {
    merged.push_back(v1[i]);
    i++;
}
}

/* Add any remaining numbers from vector one. */
while (i < v1.size()) {
merged.push_back(v1[i]);
i++;
}


/* Add any remaining numbers from vector two. */
while (j < v2.size()) {
merged.push_back(v2[j]);
j++;
}
return merged; 
}

void to_string(string file, vector<int> v) {
/* Vector interator number. (unsigned short) */
unsigned short i;
/* Display the numbers contained in a vector. */
cout << "The list of " << v.size() << " numbers in file " << file << " is:\n";
for (int num : v) {
cout << num << endl;

} 
}
