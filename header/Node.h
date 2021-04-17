#include <bits/stdc++.h>
using namespace std;

//use struct as its members are public by default
struct Node {
    int data;                   //data found found at each state; the new 8-puzzle we acquire after each operation
    struct Node* left_child;        //the left child following a parent
    struct Node* right_child;       //the right child following a parent
 
    // val is the value that has to be added to the data part
    Node(int val){
        data = val;
 
        // Left and right child are empty at the start
        left = NULL;
        right = NULL;
    }
}
