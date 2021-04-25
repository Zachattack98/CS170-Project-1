#include <bits/stdc++.h>
#include "Tree.h"
#include "problem.h"
#include <iostream>

using namespace std;
 
int main() {
 
    int squares;  //total number of squares (including the blank square) in the puzzle
    int n;    //variable used for nxn array
 
    /*cout << "How squares are in the puzzle?" << endl;
    cin >> squares;
 
    if (sqrt(squares) == n) { //check if there is a valid number of squares for an nxn array
     cout << " Invalid number! Enter again" << endl;
     cin >> squares;
    }*/
 
    /*create root; just practice*/
    Node* root = new Node();
    root->nodePrint();
    Problem problem;
    if (problem.GraphSearch(root)) {
        cout << "Solution found!" << endl;
    }
    else {
        cout << "Solution Failed!" << endl;
    }
//    root->left_child = new Node(2);
//    root->right_child = new Node(3);
//    root->left_child->left_child = new Node(4);
//    root->left_child->right_child = new Node(5);


    //cout << "\n" << squares << "-Puzzle Solution of binary tree is \n";
    //Tree* tree = new Tree(root);
    //tree->TreeTraversal();

    //tree->DFS_Puzzle(root);
 
    return 0;
};
