#include <iostream>   
#include <cstdlib>    // to use rand() for random numbers
#include <ctime>      // to seed random number with current time

using namespace std;

int main() {
    int number, guess;

    // Use the current time to make the random number exactly random
    srand(time(0)); 

    // Generating between 1 to 100
    number = rand() % 100 + 1;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 to 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // Repeat the guessing process until user gets the correct number
    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > number) {
            cout << "Too high! Try again." << endl;
        } else if (guess < number) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "YEAH \nCongratulations! You guessed it right!" << endl;
        }

    } while (guess != number);  // enabling loop until guess is correct.

    return 0;
}


