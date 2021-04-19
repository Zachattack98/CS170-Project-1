#ifndef TREE_H_
#define TREE_H_

#include <bits/stdc++.h>
#include "Node.h"
#define N 3

using namespace std;

//creating a Depth-First Search Tree containing all possible states until the goal state is reached

class Tree {
  public:
    Node* root;
    stack<Node*> frontier;

    //initialize the tree
    Tree(Node* input_root) {
        if (input_root == NULL)
            return;
        this->root = input_root;
        frontier.push(this->root);
    }

    void TreeTraversal() {
        PrintPuzzle(root);
        frontier.pop();

        if (root->up_child != nullptr) {
            frontier.push(root->up_child);
        }
        if (root->down_child != nullptr) {
            frontier.push(root->down_child);
        }
        if (root->left_child != nullptr) {
            frontier.push(root->left_child);
        }
        if (root->right_child != nullptr) {
            frontier.push(root->right_child);
        }

        if (frontier.top() != nullptr) {
            TreeTraversal(frontier.top());
        }
    }

    void TreeTraversal(Node* node) {
        PrintPuzzle(node);
        frontier.pop();

        if (node->up_child != nullptr) {
            frontier.push(node->up_child);
        }
        if (node->down_child != nullptr) {
            frontier.push(node->down_child);
        }
        if (node->left_child != nullptr) {
            frontier.push(node->left_child);
        }
        if (node->right_child != nullptr) {
            frontier.push(node->right_child);
        }

        if (frontier.top() != nullptr) {
            TreeTraversal(frontier.top());
        }
    }

    /*
    //Locate the square that does not contain a tile; this is the square to shift tiles to
    const int FindBlankIndex {
      int blankIndex[N]{N];    //index of blank square
      
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
              if(node->data[i][j] == 0) //check for the square containing 0
                return blankIndex[i][j];
        }
      }
    }
     
    void ShiftAdjacentTile {
    
    }
    */
    void DFS_Puzzle(Node* node) {
        if (node == nullptr)
            return;
        /* first print data/nxn array of node */
        PrintPuzzle(node);

        /* then recur on left subtree */
        DFS_Puzzle(node->left_child);

        /* now recur on right subtree */
        DFS_Puzzle(node->right_child);
    }

    void PrintPuzzle(Node* node) {
        cout << "Puzzle: " << endl << node->data[0][0] << " " << node->data[0][1] << " " << node->data[0][2] << " "
             << endl << node->data[1][0] << " " << node->data[1][1] << " " << node->data[1][2] << " " << endl
             << node->data[2][0] << " " << node->data[2][1] << " " << node->data[2][2] << " " << endl << endl;
    }
};

#endif
