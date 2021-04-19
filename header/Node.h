#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>

using namespace std;

//use struct as its members are public by default
class Node {
    public:
        int data[3][3];                   //data found found at each state; the new 8-puzzle we acquire after each operation
        Node* parent = nullptr;
        Node* up_child = nullptr;
        Node* down_child = nullptr;
        Node* left_child = nullptr;        //the left child following a parent
        Node* right_child = nullptr;       //the right child following a parent

        // val is the value that has to be added to the data part
        Node() {
            int val;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << "Insert value for row " << i << " and column " << j << ":" << endl;
                    cin >> val;
                    data[i][j] = val;
                }
            }
        }

        Node(int val){
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    data[i][j] = val;
                }
            }

            // Left and right child are empty at the start
            left_child = NULL;
            right_child = NULL;
        }

};

#endif