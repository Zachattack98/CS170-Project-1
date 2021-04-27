#ifndef SHIFT_H_
#define SHIFT_H_

#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"

using namespace std;

//create a class that stores all the movements of the blank tile
class Shift {
    public:
        //child node to store the shift after it occurs
        int tempMove;  //temporary movement variable
        int depth;
        //int moveCost;  //variable for storing cost one the particular movement


        void Move_Up(node_pair slide, Tree* tree) {
            //Cannot push up when tile is at certain spaces
            int rowBlank, colBlank;
            //FindBlankIndex(slide.second, rowBlank, colBlank);

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
                 shift_child->cost = slide.first + 1;

                 depth++;
                 
                  tree->frontier.push(make_pair(slide.first + 1, shift_child)); //ERROR WHEN PUSHING TO FRONTIER
                  return;

              }
        }

        void Move_Down(node_pair slide, Tree* tree) {
            //Cannot push up when tile is at certain spaces
            int rowBlank, colBlank;
            //FindBlankIndex(slide.second, rowBlank, colBlank);

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
                shift_child->cost = slide.first + 1;

                tree->frontier.push(make_pair(slide.first + 1, shift_child)); //ERROR WHEN PUSHING TO FRONTIER
                return;

            }
        }

        void Move_Left(node_pair slide, Tree* tree) {
            //Cannot push up when tile is at certain spaces
            int rowBlank, colBlank;
            //FindBlankIndex(slide.second, rowBlank, colBlank);

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
                shift_child->cost = slide.first + 1;

                tree->frontier.push(make_pair(slide.first + 1, shift_child)); //ERROR WHEN PUSHING TO FRONTIER
                return;

            }
        }

        void Move_Right(node_pair slide, Tree* tree) {
            //Cannot push up when tile is at certain spaces
            int rowBlank, colBlank;
            //FindBlankIndex(slide.second, rowBlank, colBlank);

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
                shift_child->cost = slide.first + 1;

                tree->frontier.push(make_pair(slide.first + 1, shift_child)); //ERROR WHEN PUSHING TO FRONTIER
                return;

            }
        }

        void FindBlankIndex(Node* node, int row, int col) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(node->data[i][j] == 0) { //check for the square containing 0
                        row = i;
                        col = j;
                        return;
                    }
                }
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


};

#endif
