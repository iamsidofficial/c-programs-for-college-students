#include <math.h>
#include <stdio.h>

// Function to calculate distance
float distance(int x1, int y1, int x2, int y2)
{
	// Calculating distance
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

// Drivers Code
int main()
{
	printf("%f", distance(3, 4, 4, 3));
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
