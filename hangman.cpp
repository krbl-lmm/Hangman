#include <iostream>
#include <string>

using namespace std;

int wrongGuesses, correctGuesses;

void displayHangman() {
    switch (wrongGuesses) {
        case 0:
        cout << endl;
        break;
        case 1:
        cout << "\n"
             << "|\n"
             << "|\n"
             << "|\n"
             << "|\n"
             << "|\n"
             << "|\n";
        break;
        case 2:
        cout << " ____\n"
             << "|\n"
             << "|\n"
             << "|\n"
             << "|\n"
             << "|\n"
             << "|\n";
        break;
        case 3:
        cout << " ____\n"
             << "|    |\n"
             << "|\n"
             << "|\n"
             << "|\n"
             << "|\n"
             << "|\n";
        break;
        case 4:
        cout << " ____\n"
             << "|    |\n"
             << "|    o\n"
             << "|\n"
             << "|\n"
             << "|\n"
             << "|\n";
        break;
        case 5:
        cout << " ____\n"
             << "|    |\n"
             << "|    o\n"
             << "|    |\n"
             << "|\n"
             << "|\n"
             << "|\n";
        break;
        case 6:
        cout << " ____\n"
             << "|    |\n"
             << "|    o\n"
             << "|    |\\\n"
             << "|\n"
             << "|\n"
             << "|\n";
        break;
        case 7:
        cout << " ____\n"
             << "|    |\n"
             << "|    o\n"
             << "|   /|\\\n"
             << "|\n"
             << "|\n"
             << "|\n";
        break;
        case 8:
        cout << " ____\n"
             << "|    |\n"
             << "|    o\n"
             << "|   /|\\\n"
             << "|   /\n"
             << "|\n"
             << "|\n";
        break;
        case 9:
        cout << " ____\n"
             << "|    |\n"
             << "|    o\n"
             << "|   /|\\\n"
             << "|   / \\\n"
             << "|\n"
             << "|\n";
        break;
    }
}

int main() {
    int alpha[26], menu;
    char letter;
    string word, guess0 = "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ", 
    words[13] = {"ketchup", "mustard", "tortilla", "pizza", "spaghetti", "pasta", "sandwich", "pancake", "candy", "chocolate", "bread", "cupcake", "dumpling"};
    bool correct = false;
    cout << "Welcome to Hangman!";
    z:
    wrongGuesses = 0;
    correctGuesses = 0;
    for (int i = 0; i < 26; i++) {
        alpha[i] = 0;
    }
    cout << "\n1. Play\n2. Make a friend guess\n0. Exit\n";
    cin >> menu;
    switch (menu) {
        case 1:
        goto a;
        break;
        case 2:
        goto b;
        break;
        case 0:
        return 0;
        default:
        return 1;
        break;
    }
    a:
    srand(time(0));
    word = words[rand() % 13];
    cout << "\nTheme: Food\n";
    goto c;
    b:
    cout << "What word would you like the player to guess: ";
    cin >> word;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    c:
    int n = word.length();
    for (int i = 0; i < n; i++) {
        word[i] = tolower(word[i]);
    }
    string guess = guess0.substr(0, 2 * n);
    while (true) {
        cout << guess << endl;
        cin >> letter;
        letter = tolower(letter);
        if (alpha[letter - 97] != 0) {
            cout << "Letter already guessed." << endl;
            continue;
        }
        alpha[letter - 97]++;
        for (int i = 0; i < n; i++) {
            if (letter == word[i]) {
                guess[2 * i] = letter;
                correctGuesses++;
                correct = true;
            }
        }
        if (!correct) wrongGuesses++;
        displayHangman();
        cout << endl;
        if (correctGuesses == n) {
            cout << "The word was: " << word << "\nYou won!" << endl;
            break;
        }
        else if (wrongGuesses == 9) {
            cout << "The word was: " << word << "\nYou lost!" << endl;
            break;
        }
        correct = false;
    }
    goto z;
}
