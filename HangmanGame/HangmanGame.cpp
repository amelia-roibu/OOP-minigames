//
// Created by Amelia Roibu on 4/4/2025.
//
#include "HangmanGame.h"
#include <iostream>

HangmanGame::HangmanGame(const std::string& word, int maxAttempts) : secretWord(word), maxAttempts(maxAttempts), remainingAttempts(maxAttempts){}

bool HangmanGame::guessLetter(char letter){
  guessedLetters.insert(letter);
  if (secretWord.find(letter) == std::string::npos) {
    // npos este o constanta speciala din C++, folosita cu string-uri
    // pentru a semnala o valoare invalida sau imposibila in contextul
    // cautarii intr-un string
    remainingAttempts--;
    return false;
  }
  return true;
}

bool HangmanGame::isGameOver() const{
  return remainingAttempts == 0 || isWordGuessed();
}

bool HangmanGame::isWordGuessed() const{
  for (char c : secretWord) // fiecare litera din secretWord intr-un parametru "c"
    if (!guessedLetters.count(c))
      return false;
  return true;
}

void HangmanGame::displayProgress() const{
  std::cout << " +------+ \n";
  std::cout << " |      | \n";

  switch(remainingAttempts) {
    case 6:
      std::cout << " |\n |\n |\n |\n";
      break;
    case 5:
      std::cout << " |      0\n |\n |\n |\n";
      break;
    case 4:
      std::cout << " |      0\n |      |\n |\n |\n";
      break;
    case 3:
      std::cout << " |      0\n |      |\n |     / \n |\n";
      break;
    case 2:
      std::cout << " |      0\n |      |\n |     / \\\n |\n";
      break;
    case 1:
      std::cout << " |      0\n |     /|\n |     / \\\n |\n";
      break;
    case 0:
      std::cout << " |      0\n |     /|\\\n |     / \\\n |\n";
      break;
  }
  std::cout << " +------- \n";

  for (char c : secretWord){
    if (guessedLetters.count(c))
      std::cout << c << " ";
     else std::cout << "_" << " ";
  }
  std::cout << "\n";
}

int HangmanGame::getRemainingAttempts() const{
  return remainingAttempts;
}
