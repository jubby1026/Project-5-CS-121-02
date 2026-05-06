/******************************************************************************
#Project: Quiz Game
#Description: Multiple choice, ten question general quiz. Standard ABCD answer choices. Reads questions and answers from a file.
#Name: Untonio Evans Jr, Abigale Myrick, Judson Higginbotham
Date: 5-1-2026
*******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

// This functions holds all of the question logic including printing it to the console, checking if the provided input is correct, and returning a point (Everything besides the while loop is done by Untonio and Abigale).
int ask_question(string question, string options[], char correct_answer) {
    cout << question << endl; // prints out the questions

    for (int i = 0; i < 4; i++) {
        cout << options[i] << endl; // prints out all answer options 
    }
    
    int correctBool;
    //The while loop is only here to allow multiple attempts after messing up an input (The while loop, breaks, continue, and correctBool variable created by Burke)
    while (true){
        char user_answer;
        cout << "Enter your answer: ";
        cin >> user_answer;
        char uaUpper = toupper(user_answer);
        int tries = 3;
        

        if (uaUpper == correct_answer) {  //Ensures all answers are in uppercase to match the file (Made by Untonio)
            cout << "Correct!\n\n";
            correctBool = 1; // Tracks the score
            break;
        } else if ((uaUpper == 'A' or uaUpper == 'B') or (uaUpper == 'C' or uaUpper == 'D')) { // Additional qurstion logic (Made by Untonio)
            cout << "Wrong! Try again. \nTries remaining: "<<tries<<".\n\n";
            tries -= 1;
            if (tries >= 0){
                correctBool = 0;
                cout << "Wrong! Correct answer was " << correct_answer << "\n\n";
                break;
            }
            continue;
        } else{ // handles invalid inputs (Untonio)
            cout<<"Invalid input. Try again"<<endl;
            continue;
        }
        
    }
    return correctBool;
}

// Handles most of the general logic that would be printed to the console. It was put here for better modular design (While loop section created by Judson, everything else is made by Untonio and Abigale.).
double outputManager(ifstream& quiz_file, string question,string choices[4],char answer){
    double score = 0;
    while(getline(quiz_file, question)){ // reads in the question first
        for (int i = 0; i < 4; i++){
            getline(quiz_file, choices[i]); // then the four answer choices
        }
        
        quiz_file >> answer; // and finally the answer
        quiz_file.ignore(); // skips the blank line.
        
        score += ask_question(question, choices, answer); // tracks score throught the quiz starting from 0/10
        quiz_file.ignore();
    }

    cout << "Quiz Finished!\n";
    cout << "Your score: " << (score/10) * 100 << "%\n";
    quiz_file.close();
    return (score/10) * 100;
}

// Reads the file and puts specific lines into specific variables to be used inside the outputManager function (Made by Judson debugged by Abigale )
double fileRead(string file){
    ifstream quiz_file(file); // file format includes 10 sets of questions starting with the question, four answer choices, the correct answer, and a space for readability.(file ,made and formatteed by Abigale)
    if (!quiz_file){
        cout<<"Invalid File Input"<<endl;
        return 0;
    }
    string question;
    string choices[4];
    char answer;
    return outputManager(quiz_file, question, choices, answer);
}

int main() {
    // Allows for any file to be easily inputted into the program, increasing modularity.
    string fileInput;
    int highScore = 0;
    do {
    cout<<"Menu: \n Press 1 to enter file name. \n Press 0 to exit the program. \n Input here: "<<endl;
    cin>>fileInput;
    if (fileInput == "1") {
        cout<<"Enter file name: "<<endl;
        cin>>fileInput;
        int frOutput = fileRead(fileInput);
        if (frOutput >= highScore){
            highScore = frOutput;
        }
    }
    cout<<"Your highscore is "<< highScore <<"%.\n\n"<<endl;
    } while(fileInput != "0");
    return 0;
}
// Our code is now able to read questions from a file which is the biggest upgrade since the last milestone of this project. Judson did most of the fixes based off the comments provided to his final project submission.
