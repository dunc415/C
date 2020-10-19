// Intersession term of 2020
// Duncan Campbell
#ifndef POINT2D_H
#define POINT2D_H

typedef struct point2D{
    double x;
    double y;
} Point2D, *pPoint2D;

// a cover function for malloc()
// for a point structure
// Returns a pointer to allocated memory; NULL on fail
Point2D* mallocPoint2D();

// a cover function for free()
// for a point structure
void freePoint2D(Point2D* pThis);

// Creates a point2D object structure
Point2D* createPoint2D(double x, double y);

// Set the x and y values in a point2D structure
void setPoint2D(Point2D* pPt, double x, double y);

// Returns a copy of the point2D structure
Point2D* copyPoint2D(Point2D* pThis);

// Returns the x value stored in the point2D structure
double getXPoint2D(Point2D* pThis);

// Returns the y value stored in the point2D structure
double getYPoint2D(Point2D* pThis);

// Sets the x value in the point2D to a new value
void setXPoint2D(Point2D* pThis, double x);

// Sets the y value in the point2D to a new value
void setYPoint2D(Point2D* pThis, double y);

// Scans the value in a file and creates a Point2D out of it
// Returns the new Point2D; NULL if fail
Point2D* fscanfPoint2D(FILE* pFIn);

// Return the distance between two point2D structures
double getDistancePoint2D(Point2D* pThis, Point2D* pThat);

#endif