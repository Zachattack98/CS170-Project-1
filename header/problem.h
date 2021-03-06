#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <bits/stdc++.h>
#include "Node.h"

using namespace std;

class Problem {
  int intial_state[3][3];   //the state we begin with before doing any operations
  int goal_state[3][3];     //the anticipated state we hope to end the tree with
  Node* operators;    //a pointer for all the possible moves each node can make
};

#endif