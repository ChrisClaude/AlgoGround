//
//  MinimumSwaps.cpp
//  AlgoGround
//
//  Created by Claude De-Tchambila on 5/21/25.
//

#include "MinimumSwaps.hpp"
#include <numeric>
#include <cassert>
#include <iostream>

int MinimumSwaps::minSwaps(std::vector<int> &nums) {
    int minimumSwaps = INT_MAX;
    int totalOnes = std::accumulate(nums.begin(), nums.end(), 0);
    int end = 0;
    int onesCount = nums[0];
    int n = int(nums.size());
    
    for (int start = 0; start < n; start++) {
        if (start != 0) {
            onesCount -= nums[start - 1];
        }
        
        while (end - start + 1 < totalOnes) {
            end++;
            onesCount += nums[end % n];
        }
        
        minimumSwaps = std::min(minimumSwaps, totalOnes - onesCount);
    }
    
    return minimumSwaps;
}

void MinimumSwaps::runTests() {
    // Test 1
    std::vector<int> data1 = {0,1,0,1,1,0,0};
    assert(MinimumSwaps::minSwaps(data1) == 1);
    
    std::cout << "test 1 passed" << "\n";
    
    // Test 2
    std::vector<int> data2 = {0,1,1,1,0,0,1,1,0};
    assert(MinimumSwaps::minSwaps(data2) == 2);
    
    std::cout << "test 2 passed" << "\n";
    
    // Test 3
    std::vector<int> data3 = {1,1,0,0,1};
    assert(MinimumSwaps::minSwaps(data3) == 0);
    
    std::cout << "test 3 passed" << "\n";
}
