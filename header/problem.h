#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"
#include "shift.h"

using namespace std;

class Problem {
public:
    int expanded = 1;
  //int intial_state[3][3];   //the state we begin with before doing any operations
  int goal_state[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };     //the anticipated state we hope to end the tree with
  //Node* operators;    //a pointer for all the possible moves each node can make

  bool GraphSearch(Node* root) {
      //Node* root = new Node();
      Tree* tree = new Tree(root);
      node_pair currTop;

      while(1) {
          if (tree->frontier.empty()) {
              return false;
          }
          tree->frontier.top().second->nodePrint();
          currTop = tree->frontier.top();
          if (checkGoal(currTop.second)) {
              return true;
          }
          tree->explored.push(currTop.second);
          expand(currTop, tree);
          tree->frontier.pop();
          tree->explore.push_back(currTop.second);
      }
  }

  void expand(node_pair node, Tree* tree) {
      expanded++;
      Shift* shift;
       shift->Move_Up(node, tree);
       shift->Move_Down(node, tree);
       shift->Move_Left(node, tree);
       shift->Move_Right(node, tree);
  }

  bool checkGoal(Node* node) {
      for (int i = 0; i < 3; i++) {
          for (int j = 0; i < 3; i++) {
              if (node->data[i][j] != goal_state[i][j]) {
                  return false;
              }
          }
      }
      return true;
  }

};

#endif