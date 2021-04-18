#ifndef TREE_H_
#define TREE_H_

#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

//creating a Depth-First Search Tree containing all possible states until the goal state is reached

class Tree {
  public:
    void DFS_Puzzle(struct Node* node) {
        if (node == NULL)
            return;

        /* first print data/nxn array of node */
        cout << node->data << " ";

        /* then recur on left subtree */
        DFS_Puzzle(node->left_child);

        /* now recur on right subtree */
        DFS_Puzzle(node->right_child);
    }
};

#endif
