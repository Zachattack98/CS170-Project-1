#include <bits/stdc++.h>
#include "problem.h"
#include "Node.h"
#include "Tree.h"
using namespace std;
 
int main() {
 
    int squares;  //total number of squares (including the blank square) in the puzzle
    int n;    //variable used for nxn array
 
    cout << "How squares are in the puzzle?" << endl;
    cin >> squares;
 
    if (sqrt(squares) == n) { //check if there is a valid number of squares for an nxn array
     cout << " Invalid number! Enter again" << endl;
     cin >> squares;
    }
 
    /*create root; just practice*/
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    cout << "\n" << squares << "-Puzzle Solution of binary tree is \n";
    DFS_Puzzle(root);
 
    return 0;
}
