// Arithmetic Quiz Game
// Name: Abigale Myrick, Judson Higginbotham
// Description: multiple choice basic math quiz
// Date: 4/16/2026

#include <iostream>
using namespace std;

int main() {
    int score = 0;  // score
    int input;      // user input

    // Questions and answers
    int question[5][2] = {
        {2, 3},
        {5, 4},
        {7, 1},
        {6, 2},
        {9, 3}
    };

    for (int i = 0; i < 5; i++) {
        cout << "\nQuestion " << i + 1 << ": ";
        cout << question[i][0] << " + " << question[i][1] << " = ";
        cin >> input;

        if (input == question[i][0] + question[i][1]) {
            cout << "Correct\n";
            score++;
        } else {
            cout << "incorrect (Correct Answer: " << question[i][0] + question[i][1] << ")\n";
        }
    }

    cout << "\nScore: " << score << "/5\n";

    if (score == 5) {
        cout << "A+\n";
    } else if (score >= 3) {
        cout << "Good job\n";
    } else {
        cout << "try againn";
    }

    return 0;
}
