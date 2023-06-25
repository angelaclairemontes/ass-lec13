#include <stdio.h>
#include <stdlib.h> // for abs()
#include <math.h>

struct line
{
    struct point
    {
		float x;
		float y;
	} point1, point2;
	float *midpoint;
	float slope;
	float distance;
};

float solveSlope(struct line line1);
float *solveMidpoint(struct line line1);
float solveDistance(struct line line1);
void getSlopeInterceptForm(struct line line1);

int main()
{
	struct line line1;

	// ask for x and y of point 1
	printf("Enter the x and y for point1: ");
	scanf("%f %f", &line1.point1.x, &line1.point1.y);

	// ask for x and y of point 2
	printf("Enter the x and y for point2: ");
	scanf("%f %f", &line1.point2.x, &line1.point2.y);

	// m = (y2 - y1)/(x2 - x1)
	if ((line1.point1.y - line1.point2.y) == 0){			// if the numerator equates to 0, then the slope will be 0
		printf("\nSlope = %f", abs(solveSlope(line1)));	// the code will return -0, thus the usage of abs() 
	} else if ((line1.point2.x - line1.point1.x) == 0){		// if the denominator equates to 0, the slope will be undefined
		printf("\nSlope = Slope is undefined.");
	} else {
		printf("\nSlope: %f", solveSlope(line1));
	}

	solveMidpoint(line1);	// retrive the values of midpoint
	printf("\nMidpoint: %f %f", line1.midpoint[0], line1.midpoint[1]); // print the values of midpoints
	printf("\nDistance: %f", solveDistance(line1));
	getSlopeInterceptForm(line1);

	return 0;
}

float solveSlope(struct line line1){
    
    line1.slope = ((line1.point2.y - line1.point1.y) / (line1.point2.x - line1.point1.x));
    
    return line1.slope;

}

float *solveMidpoint(struct line line1){

	// create array to store values for the midpoint
	line1.midpoint[2]; 

	line1.midpoint[0] = ((line1.point1.x + line1.point2.x)/2);  // solve for the x-value of the midpoint
	line1.midpoint[1] = ((line1.point1.y + line1.point2.y)/2);	// solve for the y-value of the midpoint

	return line1.midpoint; 

}

float solveDistance(struct line line1){

	line1.distance = sqrt(((line1.point1.x - line1.point2.x)*(line1.point1.x - line1.point2.x)) + ((line1.point1.y - line1.point2.y)*(line1.point1.y - line1.point2.y)));

	return line1.distance;
}

void getSlopeInterceptForm(struct line line1){

	float b = line1.point1.y - ((line1.slope)*(line1.point1.x)); // get the b constants

	if ((line1.point1.y - line1.point2.y) == 0){		// if m = 0, then the slope-intercept form is y = b
		printf("\ny = %f", b);
	} else if ((line1.point2.x - line1.point1.x) == 0){ // if m = undefined, then no slope intercept form
		printf("\nSlope is undefined. No slope-intercept form.");	
	} else {
		printf("\ny = %fx + %f", line1.slope, b); 		// unfortunately this is not working, i haven't figured out how to fix it 
	}

}