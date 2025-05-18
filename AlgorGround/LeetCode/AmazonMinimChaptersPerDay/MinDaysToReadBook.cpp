//
//  MinDaysToReadBook.cpp
//  AlgorGround
//
//  Created by Claude De-Tchambila on 5/18/25.
//

#include "MinDaysToReadBook.hpp"
#include <iostream>
#include <cassert>

int MinDaysToReadBookSolution::minDaysToReadBook(const std::vector<int>& chapters, int maxChaptersPerDay, int maxPagesPerDay) {
    int days = 0;
    int chapterIndex = 0;
    int n = int(chapters.size());
    int remainingPages = chapters.empty() ? 0 : chapters[0];
    
    while (chapterIndex < n) {
        int pagesReadToday = 0;
        int chaptersReadToday = 0;
        
        // Try to read up to maxChaptersPerDay and maxPagesPerDay
        while (chapterIndex < n &&
               chaptersReadToday < maxChaptersPerDay &&
               pagesReadToday < maxPagesPerDay) {
            
            int pagesCanRead = std::min(remainingPages, maxPagesPerDay - pagesReadToday);
            pagesReadToday += pagesCanRead;
            remainingPages -= pagesCanRead;
            
            if (remainingPages == 0) {
                // Finished this chapter
                chapterIndex++;
                if (chapterIndex < n)
                    remainingPages = chapters[chapterIndex];
                chaptersReadToday++;
            } else {
                // Didn't finish the current chapter, so can't start a new one today
                break;
            }
        }
        
        days++;
    }
    
    return days;
};

void MinDaysToReadBookSolution::runTests() {
    std::cout << "Min Days To Read Book Solution" << "\n\n";
    
    std::vector<int> test1 = {3, 1, 4};
    assert(MinDaysToReadBookSolution::minDaysToReadBook(test1, 2, 2) == 4);
    std::cout << "Test 1 passed" << "\n";
    
    
    std::vector<int> test2 = {6, 2, 8, 3, 1, 7};
    assert(MinDaysToReadBookSolution::minDaysToReadBook(test2, 2, 4) == 7);
    std::cout << "Test 2 passed" << "\n";
    
    std::vector<int> test3 = {1, 2, 8, 3, 1, 2};
    assert(MinDaysToReadBookSolution::minDaysToReadBook(test3, 2, 4) == 5);
    std::cout << "Test 3 passed" << "\n";
};
