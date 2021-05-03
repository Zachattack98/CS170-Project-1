//#include <bits/stdc++.h>
#include "Tree.h"
#include "problem.h"
#include <iostream>

using namespace std;

int main() {

    cout << "Welcome to 862041797 and 862130859 8 puzzle solver." << endl;

    while(1) {
        Node *root;
        int Algorithm;
        int decision;

        cout << endl << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl;
        cin >> decision;

        if (decision == 1) {
            int difficulty;
            cout << "Choose puzzle Complexity (1-7): ";
            cin >> difficulty;
            root = new Node(difficulty);
        } else {
            root = new Node('c');
        }

        cout << "Enter your choice of algorithm\n"
             << "1. Uniform Cost Search\n2. A* with the Misplaced Tile heuristic.\n3. A* with the Eucledian distance heuristic."
             << endl;
        cin >> Algorithm;

        Problem problem;
        problem.algorithmchoice = Algorithm;

        if (problem.GraphSearch(root)) {
            cout << "Solution Found!" << endl;
            cout << problem.expanded << " nodes expanded." << endl;
        } else {
            cout << "Solution Failed!" << endl;
            cout << problem.expanded << " nodes expanded." << endl;
        }

        cout << "Proceed? (Y/N):" << endl;
        char proceed;
        cin >> proceed;
        if (proceed != 'Y')
            exit(0);
    }

}
