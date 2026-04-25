
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int askQuestion(string question, string options[], char correctAnswer) {
    cout << question << endl; // prints out the questions

    for (int i = 0; i < 4; i++) {
        cout << options[i] << endl; // prints out all answer options 
    }

    char userAnswer;
    cout << "Your answer: ";
    cin >> userAnswer;

    if (toupper(userAnswer) == correctAnswer) {  //Ensures all answers are in uppercase to match the file
        cout << "Correct!\n\n";
        return 1;
    } else {
        cout << "Wrong! Correct answer was " << correctAnswer << "\n\n";
        return 0;
    }
}

int main() {
    int score = 0;
    ifstream quizFile("mathQuizupdated.txt"); // file format includes 10 sets of questions starting with the question, four answer choices, the correct answer, and a space for readability.
    string question;
    string choices[4];
    char answer;
    
    while(getline(quizFile, question)){ // reads in the question first
        for (int i = 0; i < 4; i++){
            getline(quizFile, choices[i]); // then the four answer choices
        }
        
        quizFile >> answer; // and finally the answer
        quizFile.ignore(); // skips the blank line.
        
        score += askQuestion(question, choices, answer); // tracks score throught the quiz starting from 0/10
        quizFile.ignore();
    }

    cout << "Quiz Finished!\n";
    cout << "Your score: " << score << "/10\n";
    quizFile.close();
    return 0;
}
// Our code is now able to read questions from a file which is the biggest upgrade since the last milestone of this project.
