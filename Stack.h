// Intersession term of 2020
// Duncan Campbell
#ifndef STACK_H
#define STACK_H
#include "Point2D.h"


typedef struct pt2link{
    Point2D* payload;
    struct pt2link* next;
}PtLink, *pPtLink;

typedef struct pt2stack{
    pPtLink head;
}PtStack, *pPtStack;

// Malloc version for a stack
pPtStack mallocStack();

// Malloc for a link
pPtLink mallocLink();

// Freeing the stack from its elements
void freeStack(pPtStack pSThis);

// Freeing the link 
void freeLink(pPtLink pLThis);

// Pushing an element onto the tail
pPtLink pushStack(pPtStack pSThis, pPtLink pLThis);

// Popping an element oof the head
pPtLink popStack(pPtStack pSThis);

// Reporting the information on the top of the stack (head)
void peekStack(pPtStack pSThis);

// Reporting the information about all objects in the stack
void reportStack(pPtStack pSThis);

#endif