#ifndef SHIFT_H_
#define SHIFT_H_

#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"

using namespace std;

//create a class that stores all the movements of the blank tile
class Shift {
    public:
        Node* shift_child;     //child node to store the shift after it occurs
        int rowBlank, colBlank;  //two variables that locate/update the blank 
        int tempMove;  //temporary movement variable
        //int moveCost;  //variable for storing cost one the particular movement
        

        Node* Move_Up(Node* slide) {
              //Cannot push up when tile is at certain spaces
              if(slide->parent != data[1][1] && slide->parent != data[1][2] && slide->parent != data[1][3]) {
                 FindBlankIndex(rowBlank, colBlank);

                 //switch tiles
                 tempMove = data[rowBlank - 1][colBlank];
                 data[rowBlank - 1][colBlank] = 0;      //here the value below the tile becomes the new empty space
                 data[rowBlank][colBlank] = tempMove;

                 slide->shift_child = tempMove;   //store data in child node

                 //update the column blank index to moving up
                 colBlank +=1;
                 //add another node expanded
                 totalExpand += 1;
              }
              return shift_child; //return new data to up_child
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
};