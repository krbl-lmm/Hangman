#include <iostream>
#include <string>

using namespace std;

int main() {
    int guesses = 0, correctGuesses = 0;
    char letter;
    string word, guess0 = "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
    bool correct = false;
    cout << "Welcome to Hangman!\nWhat word would you like the player to guess?\n";
    cin >> word;
    int n = word.length();
    cout << "\n\n\n\n\n";
    string guess = guess0.substr(0, 2 * n);
    while (true) {
        cout << guess << endl;
        cin >> letter;
        for (int i = 0; i < n; i++) {
            if (letter == word[i]) {
                guess[2 * i] = letter;
                correctGuesses++;
                correct = true;
            }
        }
        if (!correct) guesses++;
        if (correctGuesses == n) {
            cout << word << “\nYou won!” << endl;
            break;
        }
        else if (guesses == 9) {
            cout << word << “\nYou lost!” << endl;
            break;
        }
        correct = false;
    }
}
