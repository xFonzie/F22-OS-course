#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Point {
    double x;
    double y;
} POINT;

double distance(POINT a, POINT b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double area(POINT p1, POINT p2, POINT p3) {
    return fabs(p1.x * p2.y - p2.x * p1.y +
               p2.x * p3.y - p3.x * p2.y +
               p3.x * p1.y - p1.x * p3.y) / 2.0;
}

int main() {
    POINT A = {2.5 , 6}, B = {1 , 2.2}, C = {10 , 6};
    printf("Distance between A and B: %f\n", distance(A, B));
    printf("Area of triangle ABC: %f\n", area(A, B, C));
}
