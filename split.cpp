/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void helper_split(Node*& in, Node*& odds, Node*& evens, Node*& oddsTail, Node*& evensTail);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  Node *oddtemp = nullptr, *eventemp = nullptr;
  helper_split(in, odds, evens, oddtemp, eventemp);
  in = nullptr;
  
}

/* If you needed a helper function, write it here */
void helper_split(Node*& in, Node*& odds, Node*& evens, Node*& oddtemp, Node*& eventemp) {
  if(in == nullptr) {
    // base case
    return;
  }

  Node* nextNode = in->next;

  // reset next pointer of current node
  in->next = nullptr;

  // append current node
  if(in->value % 2 == 0) {
    if(eventemp) {
      eventemp->next = in;
    }
    else {
      evens = in;
    }
    eventemp = in;
  }
  else {
    if(oddtemp) {
      oddtemp->next = in;
    }
    else {
      odds = in;
    }
    oddtemp = in;
  }

  helper_split(nextNode, odds, evens, oddtemp, eventemp);
}