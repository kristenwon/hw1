/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main()
{
    // creates test nodes
    Node* node5 = new Node(5, NULL);
    Node* node4 = new Node(4, node5);
    Node* node3 = new Node(3, node4);
    Node* node2 = new Node(2, node3);
    Node* node1 = new Node(1, node2);
    
    Node* odds = NULL;
    Node* evens = NULL;

    split(node1, odds, evens);

    std::cout << "Evens: " << evens->value << std::endl;
    std::cout << "Evens: " << evens->next->value << std::endl;

    // deallocates the test nodes
    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete node1;

    return 0;
}