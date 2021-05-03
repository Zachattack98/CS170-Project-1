#ifndef NODE_H_
#define NODE_H_
#include <string>

#include <bits/stdc++.h>

using namespace std;

//use struct as its members are public by default
class Node {
    public:
        double cost;
        int data[3][3];                   //data found found at each state; the new 8-puzzle we acquire after each operation
        Node* parent = nullptr;
        Node* up_child = nullptr;          //the child containing the puzzle after moving tile upward
        Node* down_child = nullptr;        //the child containing the puzzle after moving tile downward
        Node* left_child = nullptr;        //the child containing the puzzle after moving tile leftward
        Node* right_child = nullptr;       //the child containing the puzzle after moving tile rightward

        // val is the value that has to be added to the data part
        Node() {
            cost = 0;
        }


        Node(char c) {
            cost = 0;
            cout << "Enter your puzzle, use a zero to represent the blank" << endl;
            cout << "Enter the first row, use space or tabs between numbers: " << endl;
            cin >> data[0][0] >> data[0][1] >> data[0][2];
            cout << "Enter the second row, use space or tabs between numbers: " << endl;
            cin >> data[1][0] >> data[1][1] >> data[1][2];
            cout << "Enter the third row, use space or tabs between numbers: " << endl;
            cin >> data[2][0] >> data[2][1] >> data[2][2];

        }


        //Initial values of puzzle, given 7 options
        Node(int val){
            cost = 0;
            if (val == 1) {
                cout << "Trivial case chosen." << endl;
                data[0][0] = 1; data[0][1] = 2; data[0][2] = 3;
                data[1][0] = 4; data[1][1] = 5; data[1][2] = 6;
                data[2][0] = 7; data[2][1] = 8; data[2][2] = 0;
            }
            if (val == 2) {
                cout << "Very Easy case chosen." << endl;
                data[0][0] = 1; data[0][1] = 2; data[0][2] = 3;
                data[1][0] = 4; data[1][1] = 5; data[1][2] = 6;
                data[2][0] = 7; data[2][1] = 0; data[2][2] = 8;
            }
            if (val == 3) {
                cout << "Easy case chosen." << endl;
                data[0][0] = 1; data[0][1] = 2; data[0][2] = 0;
                data[1][0] = 4; data[1][1] = 5; data[1][2] = 3;
                data[2][0] = 7; data[2][1] = 8; data[2][2] = 6;
            }
            if (val == 4) {
                cout << "Doable case chosen." << endl;
                data[0][0] = 0; data[0][1] = 1; data[0][2] = 2;
                data[1][0] = 4; data[1][1] = 5; data[1][2] = 3;
                data[2][0] = 7; data[2][1] = 8; data[2][2] = 6;
            }
            if (val == 5) {
                //1 2 3 - 0 6 7 - 4 5 8
                cout << "Hard case chosen." << endl;
                data[0][0] = 1; data[0][1] = 2; data[0][2] = 3;
                data[1][0] = 0; data[1][1] = 6; data[1][2] = 7;
                data[2][0] = 4; data[2][1] = 5; data[2][2] = 8;
            }
            if (val == 6) {
                cout << "Extremely Hard case chosen." << endl;
                data[0][0] = 8; data[0][1] = 7; data[0][2] = 1;
                data[1][0] = 6; data[1][1] = 0; data[1][2] = 2;
                data[2][0] = 5; data[2][1] = 4; data[2][2] = 3;
            }
            if (val == 7) {
                cout << "Impossible case chosen." << endl;
                data[0][0] = 1; data[0][1] = 2; data[0][2] = 3;
                data[1][0] = 4; data[1][1] = 5; data[1][2] = 6;
                data[2][0] = 8; data[2][1] = 7; data[2][2] = 0;
            }
        }

        void nodePrint() {
            cout << "Puzzle: " << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (this->data[i][j] == 0)
                        cout << "* ";
                    else
                        cout << this->data[i][j] << " ";
                    if (j == 2)
                        cout << endl;
                }
            }
        }
};

#endif
