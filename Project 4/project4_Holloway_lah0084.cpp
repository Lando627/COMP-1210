/* project4_Holloway_lah0084.cpp
 * AUTHOR: Landon Holloway
 * Compiled in AU Terminal by g++ project4_Holloway_lah0084.cpp
 * Follow with ./a.out command which brings you to user input.
 * I used websites like geeksforgeeks.org and stackoverflow.com to grasp C++ concepts better
 * so I could complete this project efficiently. 
 * I used Li's hints and the lecture briefings.
 * I moved the order of some things around compared to the template as well 
 * because it made more sense and was easier for me. 
*/

//library imports
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <sstream>
using namespace std;

// Structue for creating a linked list that holds a trivia question, answer, and point amount. 
struct trivia_node 
{
    string question;
    string answer;
    int point;
    
    //pointer to other trivia node
    trivia_node* next;
};

//initialized list for trivia_node 
trivia_node* trivia_list();
trivia_node* node_add(string question, string answer, int point, trivia_node* node); //ques is question, ans is answer

int ask_ques(trivia_node* node, int number);

trivia_node* Triviagame = trivia_list();
int final_score = 0;

//Returns three questions below with answer and point value no matter how many questions the user creates
trivia_node* trivia_list() 
{
    trivia_node* question1 = new trivia_node;
    trivia_node* question2 = new trivia_node;
    trivia_node* question3 = new trivia_node;
    
    //Q1 the highest point value
    question1->question = "How long was the shortest war on record? (Hint: how many minutes)";
    question1->answer = "38";
    question1->point = 100;
    question1->next = question2;
    
    //Q2 with second highest point value
    question2->question = "What was the Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    question2->answer = "Bank of Italy";
    question2->point = 50;
    question2->next = question3;
    
    //Q3 with third highest point value
    question3->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
    question3->answer = "Wii Sports";
    question3->point = 20;
    question3->next = NULL;
    return question1;
}

//adds node using same layout
trivia_node* addNode(string ques, string ans, int point, trivia_node* node) 
{
    //new node for trivia
    trivia_node* tail = new trivia_node;
    tail->question = ques;
    tail->answer = ans;
    tail->point = point;
    tail->next = NULL;
    trivia_node* temp = node;
    
    //moves node to the end
    while (temp->next != NULL) 
	{
        temp = temp->next;
    }
    temp->next = tail;
    return(0);
}

//places data in node
int ask_ques(trivia_node* node, int number) 
{
    trivia_node* temp = node;
    int count = 1;
    while (temp->next != NULL) 
	{
        temp = temp->next;
        count++;
    }
    
    //empty list
    if (number < 1) 
	{
        cout << "Warning - The number of trivia to be asked must be equal to or larger than 1.\n";
        return 1;
    }
    
    else if (number > count) 
	{
        cout << "Warning - There are only " << count << " trivia in the list.\n";
        return 1;
    }
    
    //checks if answers to questions are right
    for (int i = 1; i <= number; i++) 
	{
        string in;
        cout << "Question: " << node->question << "\nAnswer: ";
        getline(cin, in);
        
        if (node->answer == in) 
		{
            cout << "Your answer is correct. You recieve " << node->point << " points.\n";
            final_score += node->point;
        }
        
        else 
		{
            cout << "Your answer is wrong. The correct answer is: " << node->answer << "\n";
        }
        
        node = node->next;
        cout << "Your total points: " << final_score << "\n\n";
    }
    return 0;
}

/* ******************************** TESTING *********************************** */
#ifdef UNIT_TESTING
int main() 
{
    int x;
    cout << "\n*** This is a debug version ***\n";
    
    cout << "Unit Test Case 1: Ask no questions. The program should give a warning message.\n";
    x = ask_ques(Triviagame, 0);
    if (x == 0) 
	{
        cout << "Case 1 passed...\n\n";
    } 
	else 
	{
        cout << "\n";
    }
    
    
    
    cout << "Unit Test Case 2.1: Ask 1 question in the list. The tester enters an incorrect answer.\n";
    x = ask_ques(Triviagame, 1);
    if (x == 0) 
	{
        cout << "Case 2.1 passed...\n\n";
    } 
	else 
	{
        cout << "\n";
    }

    cout << "Unit Test Case 2.2: Ask 1 question in the list. The tester enters right answer.\n";
    x = ask_ques(Triviagame, 1);
    if (x == 0) 
	{
        cout << "Case 2.2 passed...\n\n";
    } 
	else 
	{
        cout << "\n";
    }
    
    cout << "Unit Test Case 3.1: Ask 3 questions from list with right answers.\n";
    x = ask_ques(Triviagame, 3);
    if (x == 0) 
	{
        cout << "Case 3.1 passed...\n\n";
    } 
	else 
	{
        cout << "\n";
    }
    
    cout << "Unit Test Case 3.2: Ask 3 questions from list with wrong answers.\n";
    x = ask_ques(Triviagame, 3);
    if (x == 0) 
	{
        cout << "Case 3.2 passed...\n\n";
    } 
	else 
	{
        cout << "\n";
    }
    
    cout << "Unit Test Case 4: Ask 5 questions in the list.\n";
    x = ask_ques(Triviagame, 5);
    if (x == 0) 
	{
        cout << "Case 4 passed...\n\n";
    } 
	else 
	{
        cout << "\n";
    }
    
    cout << "\n*** End of the Debug Version ***\n";
    
    /* ***************************** ENDS TESTING *************************************** */
}
#else
int main() 
{
    int num = 3;
    string cont;
    cout << "\n*** Welcome to Landon's trivia quiz game ***\n";
    
    //data added to linkedlist
    do  
	{
        string question;
        string answer;
        string score;
        
        cout << "Enter a question: ";
        getline(cin, question);
        
        cout << "Enter an answer: ";
        getline(cin, answer);
        
        cout << "Enter award points: ";
        getline(cin, score);
        
        stringstream geek(score);
        int sc = 0;
        geek >> sc;
        
        //continue?
        cout << "Continue? (Yes/No): ";
        getline(cin, cont);
        addNode(question, answer, sc, Triviagame);
        num++;
    }
    
    while (cont == "Yes");
    cout << "\n";
    ask_ques(Triviagame, num);
    cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
    return(0);
}
#endif