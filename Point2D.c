// Intersession term of 2020
// Duncan Campbell
#include <stdlib.h>
#include <stdio.h>
#include "Point2D.h"
#include <math.h>


// MALLOC
Point2D* mallocPoint2D(){
    Point2D* pPtThis;
    pPtThis = (Point2D*)malloc(sizeof(Point2D));
    return pPtThis;
}

// FREE
void freePoint2D(Point2D* pThis){
    free(pThis);
}

// CREATE
Point2D* createPoint2D(double x, double y){
    Point2D* ptThis = mallocPoint2D();

    if(ptThis != (Point2D*)NULL){
        setPoint2D(ptThis, x, y);
    }
    
    return ptThis;
}

// SETPOINT
void setPoint2D(Point2D* pPt, double x, double y){
    pPt -> x = x;
    pPt -> y = y;
}

// COPYPOINT
Point2D* copyPoint2D(Point2D* pThis){
    Point2D* copy;
    copy -> x = pThis -> x;
    copy -> y = pThis -> y;
    return copy;
}

// GET X VALUE
double getXPoint2D(Point2D* pThis){
    double num = pThis -> x;
    return num;
}

// GET Y VALUE
double getYPoint2D(Point2D* pThis){
    double num = pThis -> y;
    return num;
}

// SET X VALUE
void setXPoint2D(Point2D* pThis, double x){
    pThis -> x = x;
}

// SET Y VALUE
void setYPoint2D(Point2D* pThis, double y){
    pThis -> y = y;
}

// SCAN VALUE AND CREATE POINT2D
Point2D* fscanfPoint2D(FILE* pFIn){
    Point2D* pPtThis;
    double x;
    double y;
    int iNRead;

    iNRead = fscanf(pFIn, "%lf %lf", &x, &y);

    if(iNRead != 2){
        return (Point2D*)NULL;
    }

    pPtThis = createPoint2D(x, y);
    return pPtThis;
}

// GET DISTANCE 
double getDistancePoint2D(Point2D* pThis, Point2D* pThat){
    double diffX = abs(pThis -> x - pThat -> x);
    double diffY = abs(pThis -> y - pThat -> y);
    double dist = sqrt(pow(diffX, 2) - pow(diffY, 2));
    return dist;
}