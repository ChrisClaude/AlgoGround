//
//  315CountSmallerSolution.h
//  AlgorGround
//
//  Created by Claude De-Tchambila on 5/5/25.
//

#ifndef CountSmallerSolution_h
#define CountSmallerSolution_h

#include <vector>

class CountSmallerSolution {
private:
    void mergeSort(std::vector<std::pair<int, int>>& nums, int left, int right, std::vector<int>& result);

public:
    std::vector<int> countSmaller(std::vector<int>& nums);
    void runTests();
};

#endif /* CountSmallerSolution_h */
