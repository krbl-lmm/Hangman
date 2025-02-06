#include <iostream>
#include <string>

using namespace std;

int main() {
    int guesses = 0, correctGuesses = 0;
    char letter;
    string word, guess0 = "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
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
                
            }
        }
    }
}
