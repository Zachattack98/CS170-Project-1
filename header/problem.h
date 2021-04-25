#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"
#include "shift.h"

using namespace std;

class Problem {
  int intial_state[3][3];   //the state we begin with before doing any operations
  int goal_state[3][3];     //the anticipated state we hope to end the tree with
  //Node* operators;    //a pointer for all the possible moves each node can make

  bool GraphSearch() {
      Node* root = new Node();
      Tree* tree = new Tree(root);
      node_pair currTop;

      while(1) {
          currTop = tree->frontier.top();
          if (tree->frontier.empty()) {
              return false;
          }
          if (tree->frontier.top().second->data == goal_state) {
              return true;
          }
          tree->explored.push(currTop.second);
          tree->frontier.pop();
          expand(currTop, tree);
      }
  }

  void expand(node_pair node, Tree* tree) {
      Shift* shift;
      tree->frontier.push(make_pair(tree->frontier.top().first + 1, shift->Move_Left(node.second)));
      tree->frontier.push(make_pair(tree->frontier.top().first + 1, shift->Move_Right(node.second)));
      tree->frontier.push(make_pair(tree->frontier.top().first + 1, shift->Move_Up(node.second)));
      tree->frontier.push(make_pair(tree->frontier.top().first + 1, shift->Move_Down(node.second)));
  }

};

#endif