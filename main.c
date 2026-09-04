
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double Method1(double x, int n);
double Method2(double x, int n);
double Method3(double x, int n);


int main(){
	float x = 5.0;
	int exponent = 11;
	printf("Method1: %lf\n", Method1(x, exponent));
	printf("Method2: %lf\n", Method2(x, exponent));
	printf("Method3: %lf\n", Method3(x, exponent));

}


double Method1(double x, int n){
	if (n == 1){
		return x;
	} else {
		return x * Method1(x, n-1);
	}
}
double Method2(double x, int n){
	if (n == 1){
		return x;
	} 

	double new_x = x*x;
	double new_n = (n-1)/2;
	if (n & 1){
		return x*Method2(new_x,new_n);
	} else {
		return Method2(new_x,new_n);
	}
}

double Method3(double x, int n){
	return pow(x,n);
}

