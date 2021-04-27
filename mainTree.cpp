#include <bits/stdc++.h>
#include "Tree.h"
#include "problem.h"
#include <iostream>

using namespace std;
 
int main() {
 
    int squares;  //total number of squares (including the blank square) in the puzzle
    int n;    //variable used for nxn array

 
    /*create root; just practice*/
    Node* root = new Node();
    Problem problem;
    if (problem.GraphSearch(root)) {
        cout << "Solution found!" << endl;
        cout << problem.expanded << " nodes expanded." << endl;
    }
    else {
        cout << "Solution Failed!" << endl;
    }

 
    return 0;
};
