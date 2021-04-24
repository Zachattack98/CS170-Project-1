#include <bits/stdc++.h>
#include "Tree.h"
#include "problem.h"
#include <iostream>

using namespace std;
 
int main() {
 
    //int squares;  //total number of squares (including the blank square) in the puzzle
    //int n;    //variable used for nxn array
 
 
    int dft_puzzle[3][3] = { {1, 5, 2},
                             {0, 4, 3},
                             {7, 8, 6}};  //default puzzle; 5 moves to soluton
    int make_puzzle[3][3]; //user created puzzle
    int pz_choice;   //user's choice of puzzle to implement
    int alg_choice;  //user's choice of the three possible search algorithms
    char proceed = 'Y';   //continuation of the game; set to yes by default
    
  while(proceed == 'Y') {
    //Enter which type of puzzle you want to solve
    cout << "Enter '1' for a default puzzle, or '2' to create your own 8-square puzzle: " << endl;
    cin >> pz_choice;
  
    while(pz_choice != 1 && pz_choice != 2) {
         cout << "\n\nThat is not a valid choice! Please re-enter your choice: ";
         cin >> pz_choice;
    }
 
    if(pz_choice == 1) {
     init_state -> dft_puzzle;  //default puzzle set as initial puzzle
    }
    else if(ppz_choice == 2) {
      cout << "\n\n Now enter a puzzle numbered '1'-'8' with '0' as the blank, three separate rows and 3 numbers each!\n\n" << endl;
     
      for(int i=0; i<=2; i++) {
        cout << "Enter numbers in row " << i << ": ";
        for(int j=0; j<=2; j++) {
          cin >> make_puzzle[i][j]; //inputting each individual tile
        }
      }
     
     //Invalid numbers
     //while()
     
     init_puzzle -> makepuzzle; //personal puzzle set as as initial puzzle
    }
 
 
    cout << "Here is a list of algorithms to choose from." << endl;
    cout << "\n--------------------------------------------\n\n";
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A* Search with Misplaced Tiles" << endl;
    cout << "3. A* Search Using Euclidean Distance" << endl << endl;
 
    //Enter the algorithm to solve the 8 puzzle
    cout << "Choose which algorithm you wish to implement from the list above: ";
    cin >> alg_choice;
 
    //
    //
    //
    //
 
    cout << "\n\n!!!!GOAL REACHED!!!!" << endl << endl;
 
    //Display number of nodes expanded
    cout << "To solve this problem the search algorithm expanded a total of " << node << "nodes." << endl << endl;
 
    //Display maximum queue size
    cout << "The maximum number of nodes in the queue at any one time is " << queue_nodes << " nodes." << endl << endl;
 
    cout << "Do you wish to solve another puzzle? Y or N" << endl;
    cin >> proceed;
     
    cout << "\n\n\n\n";
  }
 
 
    /*cout << "How squares are in the puzzle?" << endl;
    cin >> squares;
 
    if (sqrt(squares) == n) { //check if there is a valid number of squares for an nxn array
     cout << " Invalid number! Enter again" << endl;
     cin >> squares;
    }*/
 
    /*create root; just practice*/
    /*Node* root = new Node(1);
    root->left_child = new Node(2);
    root->right_child = new Node(3);
    root->left_child->left_child = new Node(4);
    root->left_child->right_child = new Node(5);*/


    //cout << "\n" << squares << "-Puzzle Solution of binary tree is \n";
    Tree* tree = new Tree(root);
    tree->TreeTraversal();

    //tree->DFS_Puzzle(root);
 
    return 0;
};
