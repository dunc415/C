// Intersession term of 2020
// Duncan Campbell
#ifndef QUEUE_H
#define QUEUE_H
#include "Point2D.h"
#include "Stack.h"

typedef struct pt2queue{
    pPtLink head;
    pPtLink tail;
}PtQueue, *pPtQueue;

// Malloc version for a queue
pPtQueue mallocQueue();

// Malloc for a link
pPtLink mallocLink();

// Freeing the queue from its elements
void freeQueue(pPtQueue pQThis);

// Freeing the link 
void freeLink(pPtLink pLThis);

// Adding an element onto the tail
pPtLink enqueue(pPtQueue pSThis, pPtLink pLThis);

// Remove the object at the head
pPtLink dequeue(pPtQueue pSThis);

// Reporting the information of the next value that wil be dequeued
void peekQueue(pPtQueue pSThis);

// Reporting the information about all objects in the queue
void reportQueue(pPtQueue pSThis);

#endif