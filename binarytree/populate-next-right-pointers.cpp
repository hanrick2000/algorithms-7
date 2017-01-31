
/*
    Populating Next Right Pointers in Each Node

    description(leetcode:
                https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
                )

    Given a binary tree

        struct TreeLinkNode {
          TreeLinkNode *left;
          TreeLinkNode *right;
          TreeLinkNode *next;
        }
    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

    Initially, all next pointers are set to NULL.

    Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
    For example,
    Given the following perfect binary tree,
             1
           /  \
          2    3
         / \  / \
        4  5  6  7
    After calling your function, the tree should look like:
             1 -> NULL
           /  \
          2 -> 3 -> NULL
         / \  / \
        4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> connect(TreeLinkNode* root) {
        if (root == nullptr) { return {}; }
        
        vector<vector<int>> result;
        queue<pair<TreeLinkNode*,int>> nodes;
        nodes.push(make_pair(root, 1));

        while (!nodes.empty()) {
            auto node = nodes.front().first;
            auto level = nodes.front().second;
            nodes.pop();

            node->next = ( (nodes.empty() || level < nodes.front().second) ? nullptr : nodes.front().first );
            
            if (node->left != nullptr) { nodes.push(make_pair(node->left, level+1)); }
            if (node->right != nullptr) { nodes.push(make_pair(node->right, level+1)); }
        }

        return result;
    }
};

