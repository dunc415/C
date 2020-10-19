// Intersession term of 2020
// Duncan Campbell
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Point2D.c"

// Malloc version for a stack
pPtStack mallocStack(){
    pPtStack pSThis = (pPtStack)malloc(sizeof(PtStack));
    if(pSThis == (pPtStack)NULL){
        return pSThis;
    }
    pSThis -> head = (pPtLink)NULL;
    return pSThis;
}

// Malloc for a link
pPtLink mallocLink(){
    pPtLink pLThis = (pPtLink)malloc(sizeof(PtLink));
    if(pLThis ==(pPtLink)NULL){
        return pLThis;
    }
    pLThis -> next = (pPtLink)NULL;
    pLThis -> payload = (Point2D*)mallocPoint2D();

    return pLThis;
    
}
// Freeing the link 
void freeLink(pPtLink pLThis){
    freePoint2D(pLThis -> payload);
    free(pLThis);
}

// Freeing the stack from its elements
void freeStack(pPtStack pSThis){
    pPtLink working;
    working = pSThis -> head;
    while(pSThis -> head != (pPtLink)NULL){
        working = pSThis -> head -> next;
        freeLink(pSThis -> head);
        pSThis -> head = working;
    }
    free(pSThis);
    return;
}

// Pushing an element onto the head
pPtLink pushStack(pPtStack pSThis, pPtLink pLThis){
    pPtLink working = pSThis -> head;
    if(working == (pPtLink)NULL){
        pSThis -> head = pLThis;
        return pLThis;
    }

    pSThis -> head = pLThis;
    pSThis -> head -> next = working;
    
    return pLThis;
}
// Popping an element of the head
pPtLink popStack(pPtStack pSThis){
    pPtLink temp = (pPtLink)mallocLink();
    if(pSThis -> head == (pPtLink)NULL){
        printf("Can't Pop");
        return (pPtLink)0;
    }
    temp = pSThis -> head -> next;
    freeLink(pSThis -> head);
    pSThis -> head = temp;
    return (pPtLink)0;
}

// Reporting the information on the top of the stack (head)
void peekStack(pPtStack pSThis){
    Point2D* temp = pSThis -> head -> payload;
    printf("%lf, %lf\n", getXPoint2D(temp), getYPoint2D(temp));
}

// Reporting the information about all objects in the stack
void reportStack(pPtStack pSThis){
    pPtLink pWorking = pSThis -> head;
    while(pWorking != (pPtLink)NULL){
        Point2D* pPoint = pWorking -> payload;
        printf("Payload: %lf, %lf\n", getXPoint2D(pPoint), getYPoint2D(pPoint));
        printf("PtLink: %p \t Payload: %p \t Next: %p \n", pWorking, pWorking -> payload, pWorking -> next);
        pWorking = pWorking -> next;
    }
}