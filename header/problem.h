#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"
#include "shift.h"

using namespace std;

class Problem {
public:
  //int intial_state[3][3];   //the state we begin with before doing any operations
  int goal_state[3][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };     //the anticipated state we hope to end the tree with
  //Node* operators;    //a pointer for all the possible moves each node can make

  bool GraphSearch(Node* root) {
      //Node* root = new Node();
      Tree* tree = new Tree(root);
      node_pair currTop;

      while(1) {
          if (tree->frontier.empty()) {
              return false;
          }

          currTop = tree->frontier.top();
          if (checkGoal(currTop.second)) {
              currTop.second->nodePrint();
              return true;
          }
          tree->explored.push(currTop.second);
          tree->frontier.pop();
          expand(currTop, tree);
      }
  }

  void expand(node_pair node, Tree* tree) {
      Shift* shift;
      shift->Move_Up(node, tree);
      node.second->up_child->nodePrint();
//      tree->frontier.push(make_pair(tree->frontier.top().first + 1, shift->Move_Left(node.second)));
//      tree->frontier.push(make_pair(tree->frontier.top().first + 1, shift->Move_Right(node.second)));
//      tree->frontier.push(make_pair(tree->frontier.top().first + 1, shift->Move_Up(node.second)));
//      tree->frontier.push(make_pair(tree->frontier.top().first + 1, shift->Move_Down(node.second)));
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