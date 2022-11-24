#include <math.h>
#include "NumClass.h"

int fact(int x) {
	if (x==0) return 1;
	return x*fact(x-1);
}

int isPrime(int x) {
	if(x==0) return 0;
	int i, prime=1;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			prime=0;
			break;
		}
	}

	return prime;
}

int isStrong(int x) {
	int y=x,sum=0;
	if (x==0) return 0;
	while(y>0){
		sum+=fact(y%10);
		y/=10;
	}

	if(sum==x)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}