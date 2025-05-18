//
//  MinDaysToReadBook.hpp
//  AlgorGround
//
//  Created by Claude De-Tchambila on 5/18/25.
//

#ifndef MinDaysToReadBook_hpp
#define MinDaysToReadBook_hpp

#include <stdio.h>
#include <vector>

class MinDaysToReadBookSolution {
public:
    int minDaysToReadBook(const std::vector<int>& chapters, int maxChaptersPerDay, int maxPagesPerDay);
    void runTests();
};

#endif /* MinDaysToReadBook_hpp */
