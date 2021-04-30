#ifndef SHIFT_H_
#define SHIFT_H_

#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"
#include "heuristic_search.h"

using namespace std;

//create a class that stores all the movements of the blank tile
class Shift {
    public:
        double HeuristicCost;
        int algorithm;
        int tempMove;  //temporary movement variable
        //Heuristic_Search heuristic;

        void Move_Up(node_pair slide, Tree* tree) {
            tree->expanded++;
            //Cannot push up when tile is at certain spaces
            int rowBlank, colBlank;
                if (!isValidMove(slide.second, tree)) {
                    return;
                }
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(slide.second->data[i][j] == 0) { //check for the square containing 0
                            rowBlank = i;
                            colBlank = j;
                        }
                    }
                }

              //if the blank index isn't at the top row, proceed
              if(rowBlank != 0) {
                 Node* shift_child = new Node();
                 slide.second->up_child = shift_child;
                 copyData(slide.second, shift_child);
                 //switch tiles
                 tempMove = shift_child->data[rowBlank - 1][colBlank];
                 shift_child->data[rowBlank - 1][colBlank] = 0;      //here the value below the tile becomes the new empty space
                 shift_child->data[rowBlank][colBlank] = tempMove;
                  
                 //calculating new move cost
                 HeuristicCost = 0.0;
                 if (algorithm == 2) {
                     HeuristicCost = Misplaced_A_Search(shift_child);
                 }
                 else if (algorithm == 3) {
                     HeuristicCost = Euclid_A_Search(shift_child);
                 }
                 shift_child->cost = slide.first + 1 + HeuristicCost;
                 tree->frontier.push(make_pair(slide.first + 1 + HeuristicCost, shift_child)); //ERROR WHEN PUSHING TO FRONTIER
                 return;
              }
        }

        void Move_Down(node_pair slide, Tree* tree) {
            tree->expanded++;
            //Cannot push up when tile is at certain spaces
            int rowBlank, colBlank;
            if (!isValidMove(slide.second, tree)) {
                return;
            }
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(slide.second->data[i][j] == 0) { //check for the square containing 0
                        rowBlank = i;
                        colBlank = j;
                    }
                }
            }

            //if the blank index isn't at the top row, proceed
            if(rowBlank != 2) {
                Node* shift_child = new Node();
                slide.second->down_child = shift_child;
                copyData(slide.second, shift_child);
                //switch tiles
                tempMove = shift_child->data[rowBlank + 1][colBlank];
                shift_child->data[rowBlank + 1][colBlank] = 0;      //here the value below the tile becomes the new empty space
                shift_child->data[rowBlank][colBlank] = tempMove;
                
                //calculating new move cost
                HeuristicCost = 0.0;
                if (algorithm == 2) {
                    HeuristicCost = Misplaced_A_Search(shift_child);
                }
                else if (algorithm == 3) {
                    HeuristicCost = Euclid_A_Search(shift_child);
                }
                shift_child->cost = slide.first + 1 + HeuristicCost;
                tree->frontier.push(make_pair(slide.first + 1 + HeuristicCost, shift_child)); //ERROR WHEN PUSHING TO FRONTIER
                return;

            }
        }

        void Move_Left(node_pair slide, Tree* tree) {
            tree->expanded++;
            //Cannot push up when tile is at certain spaces
            int rowBlank, colBlank;
            if (!isValidMove(slide.second, tree)) {
                return;
            }
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(slide.second->data[i][j] == 0) { //check for the square containing 0
                        rowBlank = i;
                        colBlank = j;
                    }
                }
            }

            //if the blank index isn't at the top row, proceed
            if(colBlank != 0) {
                Node* shift_child = new Node();
                slide.second->left_child = shift_child;
                copyData(slide.second, shift_child);
                //switch tiles
                tempMove = shift_child->data[rowBlank][colBlank - 1];
                shift_child->data[rowBlank][colBlank - 1] = 0;      //here the value below the tile becomes the new empty space
                shift_child->data[rowBlank][colBlank] = tempMove;
                
                //calculating new move cost
                HeuristicCost = 0.0;
                if (algorithm == 2) {
                    HeuristicCost = Misplaced_A_Search(shift_child);
                }
                else if (algorithm == 3) {
                    HeuristicCost = Euclid_A_Search(shift_child);
                }
                shift_child->cost = slide.first + 1 + HeuristicCost;
                tree->frontier.push(make_pair(slide.first + 1 + HeuristicCost, shift_child)); //ERROR WHEN PUSHING TO FRONTIER
                return;
            }
        }

        void Move_Right(node_pair slide, Tree* tree) {
            tree->expanded++;
            //Cannot push up when tile is at certain spaces
            int rowBlank, colBlank;
            if (!isValidMove(slide.second, tree)) {
                return;
            }
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(slide.second->data[i][j] == 0) { //check for the square containing 0
                        rowBlank = i;
                        colBlank = j;
                    }
                }
            }

            //if the blank index isn't at the top row, proceed
            if(colBlank != 2) {
                Node* shift_child = new Node();
                slide.second->right_child = shift_child;
                copyData(slide.second, shift_child);
                //switch tiles
                tempMove = shift_child->data[rowBlank][colBlank + 1];
                shift_child->data[rowBlank][colBlank + 1] = 0;      //here the value below the tile becomes the new empty space
                shift_child->data[rowBlank][colBlank] = tempMove;
                
                //calculating new move cost
                HeuristicCost = 0.0;
                if (algorithm == 2) {
                    HeuristicCost = Misplaced_A_Search(shift_child);
                }
                else if (algorithm == 3) {
                    HeuristicCost = Euclid_A_Search(shift_child);
                }
                shift_child->cost = slide.first + 1 + HeuristicCost;
                tree->frontier.push(make_pair(slide.first + 1 + HeuristicCost, shift_child)); //ERROR WHEN PUSHING TO FRONTIER
                return;

            }
        }

        void copyData(Node* parent, Node* child) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    child->data[i][j] = parent->data[i][j];
                }
            }
        }

        bool isValidMove(Node* node, Tree* tree) {
            for (int i = 0; i < tree->explore.size(); i++) {
                if (tree->explore.at(i)->data[0][0] == node->data[0][0] && tree->explore.at(i)->data[0][1] == node->data[0][1] && tree->explore.at(i)->data[0][2] == node->data[0][2] &&
                tree->explore.at(i)->data[1][0] == node->data[1][0] && tree->explore.at(i)->data[1][1] == node->data[1][1] && tree->explore.at(i)->data[1][2] == node->data[1][2] &&
                tree->explore.at(i)->data[2][0] == node->data[2][0] && tree->explore.at(i)->data[2][1] == node->data[2][1] && tree->explore.at(i)->data[2][2] == node->data[2][2] )
                {
                    return false;
                }
            }
            return true;
        }

        double Misplaced_A_Search(Node* node) {
            double heuristic = 0;
            if (node->data[0][0] != 1) {heuristic++;} if (node->data[0][1] != 2) {heuristic++;} if (node->data[0][2] != 3) {heuristic++;}
            if (node->data[1][0] != 4) {heuristic++;} if (node->data[1][1] != 5) {heuristic++;} if (node->data[1][2] != 6) {heuristic++;}
            if (node->data[2][0] != 7) {heuristic++;} if (node->data[2][1] != 8) {heuristic++;} if (node->data[2][2] != 0) {heuristic++;}
            return heuristic;
        }

        double Euclid_A_Search(Node* node) {
            double heuristic = 0.0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    heuristic += tileDistance(node->data[i][j], i, j);
                }
            }
            return heuristic;
        }

        double tileDistance(int tile, int x, int y) {
            double distance = 0.0;
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
