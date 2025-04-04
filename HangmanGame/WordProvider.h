//
// Created by Amelia Roibu on 4/4/2025.
//

#ifndef WORDPROVIDER_H
#define WORDPROVIDER_H

#include <string>
#include <vector>

class WordProvider{
      std::vector<std::string> words;
public:
      WordProvider();
      std::string getRandomWord() const;
};

#endif //WORDPROVIDER_H
