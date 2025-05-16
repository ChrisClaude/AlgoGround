#include "WordLadder.h"
#include <unordered_set>
#include "queue"


int ladderLength(std::string beginWord, std::string endWord,
                 std::vector<std::string> &wordList) {
    std::unordered_set<std::string> wordSet;
    for (auto word : wordList) wordSet.insert(word);

    if (!wordSet.count(endWord)) return 0;

    std::queue<std::pair<std::string, int>> queue;
    queue.emplace(beginWord, 1);

    while (!queue.empty()) {
        auto [word, level] = queue.front();
        queue.pop();

        for (int i = 0; i < word.size(); i++) {
            std::string temp = word;

            for (char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;
                if (temp == endWord) return level + 1;

                if (wordSet.count(temp)) {
                    queue.emplace(temp, level + 1);
                    wordSet.erase(temp);
                }
            }
        }
    }

    return 0;
}
