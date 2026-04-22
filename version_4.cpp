#include <iostream>
#include <string>
using namespace std;

int askQuestion(string question, string options[], char correctAnswer) {
    cout << question << endl;

    for (int i = 0; i < 4; i++) {
        cout << options[i] << endl;
    }

    char userAnswer;
    cout << "Your answer: ";
    cin >> userAnswer;

    if (toupper(userAnswer) == correctAnswer) {  //Converts user input to uppercase
        cout << "Correct!\n\n";
        return 1;
    } else {
        cout << "Wrong! Correct answer was " << correctAnswer << "\n\n";
        return 0;
    }
}

int main() {
    int score = 0;

    // Questions array
    string questions[10] = {
        "1. What is 2 + 2?",
        "2. What is the square root of 25",
        "3. What is 5 + 7?",
        "4. What are the first five digits of pi?",
        "5. How many inches are on a standard ruler?",
        "6. How many pints are in a gallon?",
        "7. What is the square root of 324?",
        "8. What is 360 divided by 90?",
        "9. Which answer is a prime number?",
        "10. What is 5 to the power of 0?"
    };

    // 2D options array
    string options[10][4] = {
        {"A. 2", "B. 4", "C. 9", "D. 1984"},
        {"A. 5", "B. 6", "C. 5.5", "D. 4"},
        {"A. 10", "B. 11", "C. 12", "D. 13"},
        {"A. 3.3333", "B. 3.1315", "C. 4.1415", "D. 3.1415"},
        {"A. 13", "B. 11", "C. 12", "D. 11.5"},
        {"A. 8", "B. 4", "C. 6", "D. 9"},
        {"A. 18", "B. 17", "C. 16", "D. 19"},
        {"A. 4", "B. 4.5", "C. 5", "D. 0"},
        {"A. 4", "B. 99", "C. 29", "D. 12"},
        {"A. 5", "B. 10", "C. 25", "D. 1"}
    };

    // Correct answer array
    char answers[10] = {'B','A','C','D','C','A','A','A','C','D'};

    // Loop through questions, and cycles through the arrays
    for (int i = 0; i < 10; i++) {
        score += askQuestion(questions[i], options[i], answers[i]);
    }

    cout << "Quiz Finished!\n";
    cout << "Your score: " << score << "/10\n";

    return 0;
}
