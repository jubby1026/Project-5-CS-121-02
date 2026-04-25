/******************************************************************************
#Project: Quiz Game
#Description: Multiple choice, ten question quiz. Standard ABCD answer choices
#Name: Untonio Evans Jr, Abigale Myrick, Judson Higginbotham
Date: 4-16-2026
*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int ask_question(string question, string options[], char correct_answer) {
    cout << question << endl;// prints out the questions 

    for (int i = 0; i < 4; i++) {
        cout << options[i] << endl;// prints out all answer options 
    }

    char user_answer;
    cout << "type selected answer here: ";
    cin >> user_answer;

    if (toupper(user_answer) == correct_answer) {  //Ensures all answers are in uppercase to match the file
        cout << "Correct! one point earned\n\n";
        return 1;
    } else {
        cout << "Wrong! Correct answer was:" << correct_answer <<"no points earned<< "\n\n";
        return 0;
    }
}

int main() {
    int score = 0;
    ifstream quiz_file("mathQuizupdated.txt");// file format includes 10 sets of questions starting with one life four the question, 4 four the answer choices one for the correct answer and a space for readability.
    string question;
    string choices[4];
    char answer;
    
    while(getline(quiz_file, question)){// reads in the question first 
        for (int i = 0; i < 4; i++){
            getline(quiz_file, choices[i]);// then the four answer choices 
        }
        
        quiz_file >> answer; // and finally the answer
        quiz_file.ignore();// skips the blank line.
        
        score += ask_question(question, choices, answer);// tracks score throught the quiz starting from 0/10
        
    }

    cout << "Quiz Finished!\n";
    cout << "Your score: " << score << "/10\n";
    quiz_file.close();
    return 0;
}
// Our code is now able to read questions from a file which is the biggest upgrade since the last milestone of this project.
