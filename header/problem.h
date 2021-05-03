#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"
#include "shift.h"

using namespace std;

class Problem {
public:
  int expanded;
  int algorithmchoice;
  int goal_state[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };     //the anticipated state we hope to end the tree with

  bool GraphSearch(Node* root) {
      Tree* tree = new Tree(root);
      node_pair currTop;

      while(1) {
          if (tree->frontier.empty() || tree->expanded == 300000) {
              return false;
          }

          tree->frontier.top().second->nodePrint();
          currTop = tree->frontier.top();
          if (checkGoal(currTop.second)) {
              expanded = tree->expanded;
              return true;
          }
          cout << "The best state to expand with cost: " << tree->frontier.top().second->cost << " is..." << endl;
          tree->explored.push(nullptr);
          expand(currTop, tree);
          tree->frontier.pop();
          tree->explore.push_back(currTop.second);
      }
  }

  void expand(node_pair node, Tree* tree) {
      Shift* shift;
      shift->algorithm = algorithmchoice;
        shift->Move_Up(node, tree);
        shift->Move_Down(node, tree);
        shift->Move_Left(node, tree);
        shift->Move_Right(node, tree);
  }

  bool checkGoal(Node* node) {
      if (node->data[0][0] == goal_state[0][0] && node->data[0][1] == goal_state[0][1] && goal_state[0][2] == node->data[0][2] &&
          goal_state[1][0] == node->data[1][0] && goal_state[1][1] == node->data[1][1] && goal_state[1][2] == node->data[1][2] &&
          goal_state[2][0] == node->data[2][0] && goal_state[2][1] == node->data[2][1] && goal_state[2][2] == node->data[2][2])
      {
          return true;
      }
      return false;
  }

};

#endif