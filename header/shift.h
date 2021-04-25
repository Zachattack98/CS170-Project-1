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
        int rowBlank, colBlank;  //two variables that locate/update the blank
        vector<int> blankIndexes;
        int tempMove;  //temporary movement variable
        //int moveCost;  //variable for storing cost one the particular movement


        void Move_Up(node_pair slide, Tree* tree) {
              //Cannot push up when tile is at certain spaces
              blankIndexes = FindBlankIndex(slide.second);
              rowBlank = blankIndexes.at(0);
              colBlank = blankIndexes.at(1);

              //if the blank index isn't at the top row, proceed
              if(rowBlank != 0) {
                 Node* shift_child = new Node();
                 slide.second->up_child = shift_child;
                 copyData(slide.second, shift_child);
                 //switch tiles
                 tempMove = shift_child->data[rowBlank - 1][colBlank];
                 shift_child->data[rowBlank - 1][colBlank] = 0;      //here the value below the tile becomes the new empty space
                 shift_child->data[rowBlank][colBlank] = tempMove;
                 tree->frontier.push(make_pair(slide.first + 1, shift_child));
                 //update the column blank index to moving up
                 //colBlank +=1;
                 //add another node expanded
                 //totalExpand += 1;
              }
              //return shift_child; //return new data to up_child
        }

        Node* Move_Down(Node* slide) {
              
              if(slide->parent != data[3][1] && slide->parent != data[3][2] && slide->parent != data[3][3]) {
                FindBlankIndex(rowBlank, colBlank);

                 //switch tiles
                 tempMove = data[rowBlank + 1][colBlank];
                 data[rowBlank + 1][colBlank] = 0;
                 data[rowBlank][colBlank] = tempMove;

                 slide->shift_child = tempMove;

                 //update the column blank index to moving down
                 colBlank +=1;
                 //add another node expanded
                 totalExpand += 1;
              }
              return shift_child; //return new data to down_child
        }

        Node* Move_Left(Node* slide) {
              
              if(slide->parent != data[1][1] && slide->parent != data[2][1] && slide->parent != data[3][1]) {
                 FindBlankIndex(rowBlank, colBlank);

                 //switch tiles
                 tempMove = data[rowBlank][colBlank - 1];
                 data[rowBlank][colBlank - 1] = 0;      
                 data[rowBlank][colBlank] = tempMove;

                 slide->shift_child = tempMove;

                 //update the row blank index to moving left
                 rowBlank -=1;
                 //add another node expanded
                 totalExpand += 1;
              }
              return shift_child; //return new data to left_child
        }

        Node* Move_Right(Node* slide) {
              
              if(slide->parent != data[1][3] && slide->parent != data[2][3] && slide->parent != data[3][3]) {
                 FindBlankIndex(rowBlank, colBlank);

                 //switch tiles
                 tempMove = data[rowBlank][colBlank + 1];
                 data[rowBlank][colBlank + 1] = 0;
                 data[rowBlank][colBlank] = tempMove;

                 slide->shift_child = tempMove;

                 //update the row blank to moving right
                 rowBlank +=1;
                 //add another node expanded
                 totalExpand += 1;
              }
              return shift_child; //return new data to right_child
        }

        vector<int> FindBlankIndex(Node* node) {
            vector<int> indexes;

            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(node->data[i][j] == 0) //check for the square containing 0
                        indexes.push_back(i);
                        indexes.push_back(j);
                        return indexes;
                }
            }
            return indexes;
        }

        void copyData(Node* parent, Node* child) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    child->data[i][j] = parent->data[i][j];
                }
            }
        }
};

#endif