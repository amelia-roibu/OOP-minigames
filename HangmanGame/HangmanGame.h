//
// Created by Amelia Roibu on 4/4/2025.
//

#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <string>
#include <set>

class HangmanGame {
    private:
      std::string secretWord;
      std::set<char> guessedLetters;
      int maxAttempts;
      int remainingAttempts;
    public:
      HangmanGame(const std::string& word, int maxAttempts = 6);
      bool guessLetter(char letter);
      bool isGameOver() const;
      bool isWordGuessed() const;
      void displayProgress() const;
      int getRemainingAttempts() const;
};

#endif //HANGMANGAME_H
