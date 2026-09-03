
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float Method1(float x, float n);
float Method2(float x, float n);
float Method3(float x, int n);


int main(){
	float x = 5.0;
	int exponent = 11;
}


float Method1(float x, float n){
	if (n = 1){
		return x;
	} else {
		return x * Method1(x, n-1);
	}
}
float Method2(float x, float n){
	if (n = 1){
		return x;
	} 

	if (n & 1){
		float n,, new_x = x*x
		float new_n = (n-1)/2
		return x*Method2(new_x,new_n);
	}
}
float Method3(float x, int n){
	return pow(x, n);
}

