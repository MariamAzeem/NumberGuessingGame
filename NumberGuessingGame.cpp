#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <conio.h>

using namespace std;

int main() {
    srand(time(0));
    int rightnumber = rand() % 100 + 1;
    int guess;
    char y = 'y';
    cout << "Welcome to the Number Guessing Game!";
    cout << "\n\n            GAME RULES\n\n"
         << "1.I have selected a number between 1 and 100.You have to guess it.\n"
         << "2.You have 7 attempts to guess the right number. I will also guide you how far your guess is from the right number.\n"
         << "3.You can get upto 3 hints by pressing zero(0) at any guess.\n"
         << "4. No of attempts will be reduced by 1 with each hint, so choose wisely." << endl
         << "Press any key to start game";
    getch();
    system("CLS");
    while (y == 'y' || y == 'Y') {
        int hints = 0, attempts = 0;
        for (int i = 0; i <= 7; i++) {
            cout << "\nEnter your guess (1-100): ";
            cin >> guess;
            if (guess < 0 || guess > 100) {
                cout << "Your guess is out of range! Please enter a number between 1 and 100." << endl;
                continue;
            } else if (guess == 0) {
                if (hints < 3) {
                    hints++;
                    attempts++;
                    if (hints == 1) {
                        if (rightnumber > 50)
                            cout << "Hint 1: Right number is in range of 51 to 100";
                        else
                            cout << "Hint 1: Right number is in range of 01 to 50";
                    } else if (hints == 2) {
                        if (rightnumber % 2 == 0)
                            cout << "Hint 2: Right number is even";
                        else
                            cout << "Hint 2: Right number is odd";
                    } else if (hints == 3) {
                        cout << "Hint 3: Right number is in range of " << max(1, rightnumber - rand() % 10) << " to " << min(100, rightnumber + rand() % 10);
                    }
                } else {
                    cout << "You've used all 3 hints";
                    continue;
                }
            } else {
                attempts++;
                int difference = abs(guess - rightnumber);
                if (guess == rightnumber) {
                    cout << "Congratulations! You guessed the correct number in " << attempts << " attempts with " << hints << " hints. Want to try again?(y/n)" << endl;
                    cin >> y;
                    break;
                } else if (difference > 25) {
                    if (guess < rightnumber)
                        cout << "Too low! You're far away. Try a much higher number." << endl;
                    else
                        cout << "Too high! You're far away. Try a much lower number." << endl;
                } else if (difference > 15) {
                    if (guess < rightnumber)
                        cout << "Low! You're close. Try a higher number." << endl;
                    else
                        cout << "High! You're close. Try a lower number." << endl;
                } else if (difference <= 5) {
                    if (guess < rightnumber)
                        cout << "You're too close! Guess a little higher." << endl;
                    else
                        cout << "You're too close! Guess a little lower." << endl;
                }
                if (rightnumber % guess == 0) {
                    cout << "Hint: Your guess is a multiple of the number!" << endl;
                } else if (guess % rightnumber == 0) {
                    cout << "Hint: The number is a multiple of your guess!" << endl;
                }
            }
        }
        if (attempts >= 7) {
            cout << "Oops! You've used all 7 attempts. The correct number was " << rightnumber << ". Better luck next time! Want to try again?(y/n)";
            cin >> y;
        }
        system("CLS");
    }

    return 0;
}
