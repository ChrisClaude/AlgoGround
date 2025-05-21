#ifndef WordLadder_h
#define WordLadder_h

#include <vector>
#include <string>

class WordLadder
{
public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string> &wordList);
};
#endif
