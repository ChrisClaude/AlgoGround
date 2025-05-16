//
//  ConstructBinaryTree.hpp
//  AlgorGround
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
   
    struct TreeNode {};
    
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
    
    void runTests ();
};

#endif /* ConstructBinaryTree_hpp */
