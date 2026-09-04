
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

double Method1(double x, int n);
double Method2(double x, int n);
double Method3(double x, int n);


int main(){

	double x = 1.003;
	// Different n sizes and test it
	int n_array[] = {2500, 5000, 10000, 20000, 40000, 80000, 160000};
	size_t lengthOfSizes = sizeof(n_array) / sizeof(n_array[0]);

    	for (int s = 0; s < lengthOfSizes; s++) {
        	int n = n_array[s];
        	printf("===== n = %d =====\n", n);

			// Method 1
        	clock_t start = clock();
			Method1(x, n);
        	clock_t end = clock();

        	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        	printf("Method 1; n = %d, time = %f seconds\n", n, seconds);

			// Method 2
			clock_t start2 = clock();
			Method2(x, n);
        	clock_t end2 = clock();

        	double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
        	printf("Method 2; n = %d, time = %f seconds\n", n, seconds2);
        	
			// Method 3
			clock_t start3 = clock();
			Method3(x, n);
        	clock_t end3 = clock();

        	double seconds3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
        	printf("Method 3; n = %d, time = %f seconds\n", n, seconds3);
    	}

}


double Method1(double x, int n){
	if (n == 1){
		return x;
	} else {
		return x * Method1(x, n-1);
	}
}
double Method2(double x, int n){
	if (n == 0){
		return 1;
	}
	if (n == 1){
		return x;
	} 


	double new_x = x*x;
	if (n & 1){
		int new_n = (n-1)/2;
		return x*Method2(new_x,new_n);
	} else {
		int new_n = n/2;
		return Method2(new_x,new_n);
	}
}

double Method3(double x, int n){
	return pow(x,n);
}

