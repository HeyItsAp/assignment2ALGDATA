
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double Method1(double x, int n);
double Method2(double x, int n);
double Method3(double x, int n);


int main(){
	float x = 5.0;
	int exponent = 11;
	printf("Method1: %f\n", Method1(x, exponent));
	printf("Method2: %f\n", Method2(x, exponent));
	printf("Method3: %f\n", Method3(x, exponent));

}


double Method1(double x, int n){
	if (n = 1){
		return x;
	} else {
		return x * Method1(x, n-1);
	}
}
double Method2(double x, int n){
	if (n = 1){
		return x;
	} 

	if (n & 1.0){
		double new_x = x*x;
		double new_n = (n-1)/2;
		return x*Method2(new_x,new_n);
	}
}

double Method3(double x, int n){
	return pow(x, n);
}

