#ifndef HEURISTIC_SEARCH_H_
#define HEURISTIC_SEARCH_H_

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>          // std::priority_queue
#include <algorithm>
#include "UCS_Alg.h"

using namespace std;

//creating a class containing the two Heuristic Search Algorithms

class Heuristic_Search {
      public:
        vector< vector<char> > curr_puzzle;   // the new/current we are comparing with the goal puzzle
        vector< vector<char> > goal_puzzle;   // the goal where each tile should be correctly positioned
      
        int temp_Heur = 0;  //temporary cost variable 
        int maxQueueNodes = 0;  //store the maximum nodes in the queue
        
        //initialize each row for the goal puzzle
        static const char arr1[] = {'1', '2', '3'};
	      static const char arr2[] = {'4', '5', '6'};
	      static const char arr3[] = {'7', '8', '*'};
        
        
	      vector<char> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
	      vector<char> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
	      vector<char> vec3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
        
        //push back each element to fill the vector
	      goal_puzzle.push_back(vec1);
	      goal_puzzle.push_back(vec2);
	      goal_puzzle.push_back(vec3);
        
        int Euclid_A_Search(curr_puzzle) {
            //A* search is similar to UCS, except using the frontier to add to sides of the graph
            //UC_search(frontier->goal_state, init_state);  //g(n) upper half
            //UC_search(goal_state, frontier->init_state);  //h(n) lower half
            
            for(int i = 0; i < 3; i++) {
			        for(int j = 0; j < 3; j++) {
				        for(int k = 0; k < 3; k++) {
					        for(int l = 0; l < 3; l++) {
                    					//check each value of the goal puzzle and locate the matching value in the current puzzle; do not check the blank square
						        if(curr_puzzle.at(k).at(l) != 0 && curr_puzzle.at(k).at(l) == goal_puzzle.at(i).at(j)) {
                    
							        temp_Heur += abs(i - k);  //comparing the positions in rows
							        temp_Heur += abs(j - l);  //comparing the positions in columns
                      
						        }
					        }
				        }
			        }
            }
            return temp_Heur;
        }
      
        int Misplaced_A_Search(curr_puzzle) {
            //UC_search(frontier->goal_state, init_state);  //g(n) upper half
            //UC_search(goal_state, frontier->init_state);  //h(n) lower half
            
            for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
                //check whether the value is in its final position; do not compare the blank square
			if(curr_puzzle.at(i).at(j) != 0 && curr_puzzle.at(i).at(j) != goal_puzzle.at(i).at(j)) {
                            temp_Heur++; //increment the total number of misplace tiles
			}
		}
            }
            return temp_Heur;
        }
};

#endif
