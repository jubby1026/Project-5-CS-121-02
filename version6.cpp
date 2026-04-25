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
    cout << question << endl;

    for (int i = 0; i < 4; i++) {
        cout << options[i] << endl;
    }

    char user_answer;
    cout << "Your answer: ";
    cin >> user_answer;

    if (toupper(user_answer) == correct_answer) {  //Converts user input to uppercase
        cout << "Correct!\n\n";
        return 1;
    } else {
        cout << "Wrong! Correct answer was " << correct_answer << "\n\n";
        return 0;
    }
}

int main() {
    int score = 0;
    ifstream quiz_file("mathQuiz.txt");
    string question;
    string choices[4];
    char answer;
    
    while(getline(quiz_file, question)){
        for (int i = 0; i < 4; i++){
            getline(quiz_file, choices[i]);
        }
        
        quiz_file >> answer;
        quiz_file.ignore();
        
        score += ask_question(question, choices, answer);
        
    }

    cout << "Quiz Finished!\n";
    cout << "Your score: " << score << "/10\n";
    quiz_file.close();
    return 0;
}
