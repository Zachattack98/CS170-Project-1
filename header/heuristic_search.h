#ifndef HEURISTIC_SEARCH_H_
#define HEURISTIC_SEARCH_H_

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>          // std::priority_queue
#include <algorithm>

using namespace std;

//creating a class containing the two Heuristic Search Algorithms

class Heuristic_Search {
      public:
        int goal_state[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };
        double heuristic = 0;  //temporary cost variable

        int Euclid_A_Search(Node* node) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    heuristic += tileDistance(node->data[i][j], i, j);
                }
            }

            return heuristic;
        }

        int tileDistance(int tile, int x, int y) {
            double distance = 0;
            switch(tile) {
                case 1:
                    distance = sqrt( pow(0 - x,2) + pow(0 - y,2));
                    break;
                case 2:
                    distance = sqrt( pow(0 - x,2) + pow(1 - y,2));
                    break;
                case 3:
                    distance = sqrt( pow(0 - x,2) + pow(2 - y,2));
                    break;
                case 4:
                    distance = sqrt( pow(1 - x,2) + pow(0 - y,2));
                    break;
                case 5:
                    distance = sqrt( pow(1 - x,2) + pow(1 - y,2));
                    break;
                case 6:
                    distance = sqrt( pow(1 - x,2) + pow(2 - y,2));
                    break;
                case 7:
                    distance = sqrt( pow(2 - x,2) + pow(0 - y,2));
                    break;
                case 8:
                    distance = sqrt( pow(2 - x,2) + pow(1 - y,2));
                    break;
                case 0:
                    distance = sqrt( pow(2 - x,2) + pow(2 - y,2));
                    break;
                default:
                    distance = 0;
                    cout << "Error with tileDistance" << endl;
                    break;
            }
            return distance;
        }

};



#endif
