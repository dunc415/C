// Intersession term of 2020
// Duncan Campbell
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Point2D.h"
#include "Stack.c"


// Malloc version for a queue
pPtQueue mallocQueue(){
    pPtQueue pQThis = (pPtQueue)malloc(sizeof(PtQueue));
    if(pQThis == (pPtQueue)NULL){
        return pQThis;
    }
    pQThis -> head = (pPtLink)NULL;
    pQThis -> tail = (pPtLink)NULL;

    return pQThis;
}
// Freeing the queue from its elements
void freeQueue(pPtQueue pQThis){
    pPtLink working;
    working = pQThis -> tail;
    while(pQThis -> tail != (pPtLink)NULL){
        working = pQThis -> tail -> next;
        freeLink(pQThis -> tail);
        pQThis -> tail = working;
    }
    free(pQThis);
    return;
}

// Adding an element onto the tail
pPtLink enqueue(pPtQueue pQThis, pPtLink pLThis){
    
    if(pQThis -> head == (pPtLink)NULL){
        pQThis -> head = pLThis;
        pQThis -> tail = pLThis;

    }else if(pQThis -> tail == pQThis -> head){
        pQThis -> tail = pLThis;
        pQThis -> head -> next = pQThis -> tail;

    }else{
        pQThis -> tail -> next = pLThis;
        pQThis -> tail == pQThis -> tail -> next;
    }
    return pLThis;
}
    
// Remove the object at the head
pPtLink dequeue(pPtQueue pQThis){
    pPtLink temp;

    if(pQThis -> tail == (pPtLink)NULL || pQThis -> head == (pPtLink)NULL || pQThis == (pPtQueue)NULL){
        printf("No items in queue");
    }

    if(pQThis -> head -> next == (pPtLink)NULL){
        freeLink(pQThis -> head); 
        pQThis -> head = (pPtLink)NULL;
        return (pPtLink)0;
    }
    temp = pQThis -> head -> next;
    freeLink(pQThis -> head);
    pQThis -> head = temp;
    return (pPtLink)0;
}

// Reporting the information of the next value that will be dequeued
void peekQueue(pPtQueue pSThis){
    Point2D* temp = pSThis -> head -> payload;
    printf("%lf, %lf\n", getXPoint2D(temp), getYPoint2D(temp));
}

// Reporting the information about all objects in the queue
void reportQueue(pPtQueue pQThis){
    pPtLink pWorking = pQThis -> head;
    while(pWorking != (pPtLink)NULL){
        Point2D* pPoint = pWorking -> payload;
        printf("Payload: %lf, %lf\n", getXPoint2D(pPoint), getYPoint2D(pPoint));
        printf("PtLink: %p \t Payload: %p \t Next: %p \n", pWorking, pWorking -> payload, pWorking -> next);
        pWorking = pWorking -> next;
    }
}