//
//  ConstructBinaryTree.hpp
//  AlgoGround
//
//  Created by Claude De-Tchambila on 5/16/25.
//

#ifndef ConstructBinaryTree_hpp
#define ConstructBinaryTree_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>

class ConstructBinaryTree {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
    void runTests();

private:
    int preorderIndex;
    std::unordered_map<int, int> inorderMap;
    TreeNode* buildTreeHelper(std::vector<int>& preorder, int left, int right);
    bool traverseTree(TreeNode* root, std::vector<int>& preorder);
};

#endif /* ConstructBinaryTree_hpp */
