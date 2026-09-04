
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
	int n_array[] = {2500, 5000, 10000, 20000, 40000, 80000};
	size_t lengthOfSizes = sizeof(n_array) / sizeof(n_array[0]);

    	for (int s = 0; s < lengthOfSizes; s++) {
        	int n = n_array[s];
        	int trials = 50000;
        	
        	printf("===== n = %d =====\n", n);

			// Method 1
			clock_t start = clock();
			for (int i = 0; i < trials; i++) {
			    Method1(x, n);
			}
			clock_t end = clock();
			double avg_time = ((double)(end - start) / CLOCKS_PER_SEC) / trials;
			printf("Method 1; n = %d, time = %.12f seconds\n", n, avg_time);


			// Method 2
			start = clock();
     		for (int i = 0; i < trials; i++) {
    			Method2(x, n);
    		}
    		end = clock();
    		avg_time = ((double)(end - start) / CLOCKS_PER_SEC) / trials;
    		printf("Method 2; n = %d, time = %.12f seconds\n", n, avg_time);
        	
			// Method 3
			start = clock();
     		for (int i = 0; i < trials; i++) {
    			Method3(x, n);
    		}
    		end = clock();
    		avg_time = ((double)(end - start) / CLOCKS_PER_SEC) / trials;
    		printf("Method 3; n = %d, time = %.12f seconds\n", n, avg_time);
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

