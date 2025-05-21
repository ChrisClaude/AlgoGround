//
//  ConstructBinaryTree.cpp
//  AlgoGround
//
//  Created by Claude De-Tchambila on 5/16/25.
//

#include "ConstructBinaryTree.hpp"
#include <queue>
#include <iostream>

ConstructBinaryTree::TreeNode* ConstructBinaryTree::buildTreeHelper(std::vector<int>& preorder, int left, int right) {
    if (left > right) return nullptr;

    TreeNode* root = new TreeNode(preorder[preorderIndex++]);

    int rootIndex = inorderMap[root->val];

    root->left = buildTreeHelper(preorder, left, rootIndex - 1);
    root->right = buildTreeHelper(preorder, rootIndex + 1, right);

    return root;
}

ConstructBinaryTree::TreeNode* ConstructBinaryTree::buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    preorderIndex = 0;
    inorderMap.clear();

    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, 0, int(inorder.size()) - 1);
}

bool ConstructBinaryTree::traverseTree(TreeNode* root, std::vector<int>& preorder) {
    std::queue<TreeNode*> queue;
    int index = 0;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();

        if (node->val != preorder[index++]) {
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

void ConstructBinaryTree::runTests() {
    std::vector<int> preorder1 = {3,9,20,15,7};
    std::vector<int> inorder1 = {9,3,15,20,7};
    auto tree1 = buildTree(preorder1, inorder1);

    if (traverseTree(tree1, preorder1)) {
        std::cout << "Test 1 passed" << "\n";
    } else {
        std::cout << "Test 1 failed" << "\n";
    }
}


