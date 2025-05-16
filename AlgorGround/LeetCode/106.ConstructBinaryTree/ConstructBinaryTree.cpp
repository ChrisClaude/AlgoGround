//
//  ConstructBinaryTree.cpp
//  AlgorGround
//
//  Created by Claude De-Tchambila on 5/16/25.
//

#include "ConstructBinaryTree.hpp"
#include "queue"
#include <iostream>

int preorderIndex;
std::unordered_map<int, int> inorder_map;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeHelper(std::vector<int>& preorder, int left, int right) {
    if (left < right) return nullptr;
    
    TreeNode* root = new TreeNode(preorder[preorderIndex++]);
    
    root->left = buildTreeHelper(preorder, left, inorder_map[preorderIndex] + 1);
    
    root->right = buildTreeHelper(preorder, inorder_map[preorderIndex] - 1, right);
    
    return root;
};

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)  {
    preorderIndex = 0;
    
    for (int i = 0; i < inorder.size(); i++) {
        inorder_map[inorder[i]] = i;
    }
    
    return buildTreeHelper(preorder, 0, int(inorder.size()) - 1);
};

bool traverseTree(TreeNode* root, std::vector<int>& preoder) {
    std::queue<TreeNode*> queue;
    int index = 0;
    queue.push(root);
    
    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        
        if (node->val != preoder[index++]) {
            return false;
        }
        
        if (node->left != nullptr) {
            queue.push(node->left);
        }
        
        if (node->right != nullptr) {
            queue.push(node->right);
        }
    }
    
    return true;
}

void runTests() {
    std::vector<int> preoder1 = {3,9,20,15,7}; // BFS
    std::vector<int> inorder1 = {9,3,15,20,7}; // DFS
    auto tree1 = buildTree(preoder1, inorder1);
    
    if (traverseTree(tree1, preoder1)) {
        std::cout << "Test 1 passed" << "\n";
    } else {
        std::cout << "Test 1 failed" << "\n";
    }
};


