#include <iostream>
#include "WordProvider.h"
#include "HangmanGame.h"

int main() {
    std::string word;

    std::cout << "Welcome to my Hangman game!\n";
    std::cout << "Do you want to set a custom word (1), or to use a standard one (2)?\n";
    int option;
    std::cin >> option;
    if (option == 1){
        std::cout << "Enter your custom word: ";
        std::cin >> word;
    }
    else {
        WordProvider provider;
        word = provider.getRandomWord();
    }
    HangmanGame game(word);

    while (!game.isGameOver()) {
        char l;
        game.displayProgress();
        std::cout << "Try a new letter: \n";
        std::cin >> l;
        if (!game.guessLetter(l)) {
            std::cout << "Oops! The letter '" << l << "' is wrong!\n";
        }
        else {
            std::cout << "Correct!";
        }
        std::cout << "Remaning attempts: " << game.getRemainingAttempts() << '\n';
    }

    if (game.isWordGuessed()) {
        std::cout << "Congratulations! You guessed correctly the word " << word << "!\n";
    }
    else {
        game.displayProgress();
        std::cout << "Better luck next time! The word was " << word << "!\nTry again?";
    }

    return 0;
}