#ifndef UCS_ALG_H_
#define UCS_ALG_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>          // std::priority_queue
#include <algorithm>
#include "Node.h"
#include "Tree.h"
#include "problem.h"

using namespace std;

//creating a Uniforn Cost Search class

class UCS_Alg {

// graph
vector<vector<int> > graph;
 
// map to store cost of edges
map<pair<int, int>, int> cost;
 
// returns the minimum cost in a vector(if there are multiple goal states)
vector<int> UC_search(vector<int> goal, int start) {
    // minimum cost of starting state to goal state
    vector<int> answer;
 
    // create a priority queue
    priority_queue<pair<int, int> > my_queue;
 
    // set the answer vector to max value
    for (int i = 0; i < goal.size(); i++)
        answer.push_back(INT_MAX);
 
    // push the starting index into the queue
    my_queue.push(make_pair(0, start));
 
    // map to store nodes that have ben previously visited
    map<int, int> visited;
 
    int count = 0;
 
    // while the queue is not empty
    while (queue.size() > 0) {
 
        // get the top element of the
        // priority queue
        pair<int, int> p = queue.top();
 
        // pop the element
        queue.pop();
 
        // get the original value
        p.first *= -1;
 
        // check if the element is part of
        // the goal list
        if (find(goal.begin(), goal.end(), p.second) != goal.end()) {
 
            // get the position
            int index = find(goal.begin(), goal.end(),
                             p.second) - goal.begin();
 
            // if a new goal is reached
            if (answer[index] == INT_MAX)
                count++;
 
            // if the cost is less
            if (answer[index] > p.first)
                answer[index] = p.first;
 
            // pop the element
            queue.pop();
 
            // if all goals are reached
            if (count == goal.size())
                return answer;
        }
 
        // check for the non visited nodes
        // which are adjacent to present node
        if (visited[p.second] == 0)
            for (int i = 0; i < graph[p.second].size(); i++) {
 
                // value is multiplied by -1 so that
                // least priority is at the top
                queue.push(make_pair((p.first +
                  cost[make_pair(p.second, graph[p.second][i])]) * -1,
                  graph[p.second][i]));
            }
 
        // mark as visited
        visited[p.second] = 1;
    }
 
    return answer;
}
};

#endif
