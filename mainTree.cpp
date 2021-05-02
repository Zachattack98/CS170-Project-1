#include <bits/stdc++.h>
#include "Tree.h"
#include "problem.h"
#include <iostream>

using namespace std;

int puzzlePrompt();

int main() {
    int proceed = 1;
    
    cout << "Welcome to 862041797 and 862130859 8 puzzle solver." << endl;

    while(proceed) {
        Node *root;
        int Algorithm;
        int decision;

        cout << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl;
        cin >> decision;

        while (decision != 1 && decision != 2) {
            cout >> "\nNot a valid response! Please re-enter your choice." << endl;
            cin >> decision;
        }
        
        if (decision == 1) {
            int difficulty;
            cout << "\nChoose puzzle Complexity (1-6): ";
            cin >> difficulty;
            
            while (difficulty != 1 && difficulty != 2 && difficulty != 3 && difficulty != 4 && difficulty != 5 && difficulty != 6) {
                cout >> "\nThat is not one of the puzzles! Please re-enter your choice." << endl;
                cin >> difficulty;
            }
            root = new Node(difficulty);
        }
            
        } else {
            root = new Node('c');
        }

        cout << "\nEnter your choice of algorithm\n"
             << "1. Uniform Cost Search\n2. A* with the Misplaced Tile heuristic.\n3. A* with the Eucledian distance heuristic."
             << endl;
        cin >> Algorithm;

        while (Algorithm != 1 && Algorithm != 2 && Algorithm != 3) {
            cout >> "\nThat is not one of the algorithms! Please re-enter your choice." << endl;
            cin >> Algorithm;
        }
    
        Problem problem;
        problem.algorithmchoice = Algorithm;

        if (problem.GraphSearch(root)) {
            cout << "Solution Found!" << endl;
            cout << problem.expanded << " nodes expanded." << endl;
        } else {
            cout << "Solution Failed!" << endl;
            cout << problem.expanded << " nodes expanded." << endl;
        }
    
        cout << "\nDo you wish to solve another puzzle? Y or N." << endl;
        cin >> proceed;
    }
 
    return 0;
}
