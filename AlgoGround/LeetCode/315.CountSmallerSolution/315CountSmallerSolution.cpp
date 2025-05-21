//
//  315CountSmallerSolution.cpp
//  AlgoGround
//
//  Created by Claude De-Tchambila on 5/5/25.
//

#include "315CountSmallerSolution.h"
#include <iostream>

void CountSmallerSolution::mergeSort(std::vector<std::pair<int, int>>& nums, int left, int right, std::vector<int>& result) {
    if (right - left <= 1) return;
    int mid = (left + right) / 2;
    mergeSort(nums, left, mid, result);
    mergeSort(nums, mid, right, result);
    int j = mid;

    for (int i = left; i < mid; i++) {
        while (j < right && nums[j].first < nums[i].first)
            j++;

        result[nums[i].second] += j - mid;
    }

    std::inplace_merge(nums.begin() + left, nums.begin() + mid, nums.begin() + right);
}

std::vector<int> CountSmallerSolution::countSmaller(std::vector<int>& nums) {
    int n = int(nums.size());
    std::vector<int> result(n, 0);
    std::vector<std::pair<int, int>> indexedNums;
    for (int i = 0; i < n; i++)
        indexedNums.emplace_back(nums[i], i);

    mergeSort(indexedNums, 0, n, result);

    return result;
}

void CountSmallerSolution::runTests() {
    std::cout << "Running test for 315. Count Smaller Solution" << "\n";
    // Test 1
    std::vector<int> testData1 = {5,2,6,1};
    std::vector<int> expectedResult1 = {2,1,1,0};

    if (countSmaller(testData1) == expectedResult1) {
        std::cout << "Test 1 passed" << "\n";
    } else {
        std::cout << "Test 1 failed" << "\n";
    }

    // Test 2
    std::vector<int> testData2 = {-1,-1};
    std::vector<int> expectedResult2 = {0,0};

    if (countSmaller(testData2) == expectedResult2) {
        std::cout << "Test 2 passed" << "\n";
    } else {
        std::cout << "Test 2 failed" << "\n";
    }

    // Test 3
    std::vector<int> testData3 = {-1,-1};
    std::vector<int> expectedResult3 = {0,0};

    if (countSmaller(testData3) == expectedResult3) {
        std::cout << "Test 3 passed" << "\n";
    } else {
        std::cout << "Test 3 failed" << "\n";
    }
}
