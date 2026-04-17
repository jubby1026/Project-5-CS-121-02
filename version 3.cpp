// Arithmetic Quiz Game
// Name: Abigale Myrick, Judson Higginbotham
// Description: multiple choice basic math quiz
// Date: 4/16/2026

#include <iostream>
using namespace std;

int main() {
    int score = 0;  // score
    char input;      // user input

    // Questions and answers 2D array (5 questions, 2 numbers each)
    int question[5][2] = {
        {2, 3},
        {5, 4},
        {7, 1},
        {6, 2},
        {9, 3}
    };
//asks 5 questions in a for loop, checks if answer is correct outputting either correct or incorrect.
    for (int i = 0; i < 5; i++) {
        int correct = question[i][0] + question[i][1];

        cout << "\nQuestion " << i + 1 << ": ";
        cout << question[i][0] << " + " << question[i][1] << " = ";
      
        
    
        //creates multiple options for answers 
        int a = correct;
        int b = correct + 1;
        int c = correct - 1;
        int d = correct + 2;

        //outputs options 
        cout << "A) " << a << endl;
        cout << "B) " << b << endl;
        cout << "C) " << c << endl;
        cout << "D) " << d << endl;

        cout << "select an answer A,B,C, or D: ";
        cin >> input;

        //check answer tells user if correct or incorrect
        if (input == 'A') {
            cout << "Correct\n";
            score++;//increases score
        } else {
            cout << "Incorrect (Correct Answer: " << correct << ")\n";
        }//Tells the user the correct answer if they are wrong

        
    }
//outputs final score of user
    cout << "\nScore: " << score << "/5\n";
// multiple score response options 
    if (score == 5) {
        cout << "A+, perfect score\n";
    } else if (score >= 3) {
        cout << "not bad!\n";
    } else {
        cout << "Better luck next time";
    }

    return 0;
}
