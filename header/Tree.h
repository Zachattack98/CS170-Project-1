#ifndef TREE_H_
#define TREE_H_

#include <bits/stdc++.h>
#include "Node.h"

using namespace std;

//creating a Depth-First Search Tree containing all possible states until the goal state is reached
typedef pair<int, Node*> node_pair;

//struct CompareCost {
//    bool operator()(Node const& n1, Node const& n2)
//    {
//        // return "true" if "p1" is ordered
//        // before "p2", for example:
//        return n1.cost < n2.cost;
//    }
//};

class Tree {
  public:
    Node* root;
    //priority_queue<Node*> frontier;

    priority_queue<node_pair, vector<node_pair>, greater<node_pair>> frontier;
    stack<Node*> explored;
    vector<Node*> explore;

    int totalExpand;     //total number of nodes expanded

    //initialize the tree
    Tree(Node* input_root) {
        Node * test = new Node();
        test->cost = 1000;
        if (input_root == NULL)
            return;
        this->root = input_root;
        root->cost = 0;

        frontier.push(make_pair(0, root));
        frontier.push(make_pair(1000000, root));
    }

    void PrintPuzzle(Node* node) {
        cout << "Puzzle: " << endl << node->data[0][0] << " " << node->data[0][1] << " " << node->data[0][2] << " "
             << endl << node->data[1][0] << " " << node->data[1][1] << " " << node->data[1][2] << " " << endl
             << node->data[2][0] << " " << node->data[2][1] << " " << node->data[2][2] << " " << endl << endl;
    }
};

#endif
