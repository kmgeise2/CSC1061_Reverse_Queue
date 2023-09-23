/*
File: CSC1061_Reverse_Queue.cpp
Author: Ram Longman
Revised: 9/22/23 by Kathy Geise
Description: This file reverses the elements in a 
Linked List queue. It uses a stack to hold the queue
elements as it reverses them. 

The queueLinked header defines several functions:
   isEmptyQueue()
   isFullQueue()
   initializeQueue();
   addQueue(const Type& newElement);
   front() const;
   back() const;
   deleteQueue();

The local function reverseQueue() is defined in this file
*/

#include <iostream>
#include "queueLinked.h"
#include "myStack.h"

using namespace std;

void reverseQueue(linkedQueueType<char>& q);

int main()
{
    // Create a Linked List queue that contains characters
    linkedQueueType<char> queue;
    queue.initializeQueue(); // From queueLinked header

    for (char c = 'A'; c <= 'Z'; c++) {
        queue.addQueue(c);
    }

    cout << "Original queue: ";
    queue.print();
    cout << endl;

    reverseQueue(queue); //queue is passed by reference

    cout << "Reversed queue: ";
    queue.print();
    cout << endl;
}

// reverseQueue receives a pointer to the queue &q

void reverseQueue(linkedQueueType<char>& q) {

    // Create a stack to hold the queue elements
    stackType<char> stk;
    char f;

    while (!q.isEmptyQueue()) {
        // Take the front queue element and 
        // add it to the back of the stack
        f = q.front();
        q.deleteQueue();
        stk.push(f);
    }

    while (!stk.isEmptyStack()) {
        // Take the back stack element and
        // add it to the top of the queue
        f = stk.top();
        stk.pop();
        q.addQueue(f);
    }
}