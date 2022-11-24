#include <math.h>
#include "NumClass.h"

int isArmstrong(int n) {
	int temp=n, digits=0;
	while (temp>0) {
		digits++;
		temp/=10;
	}
	int sum=0;
	temp=n;
	while(temp>0) {
		sum+=pow(temp%10,digits);
		temp/=10;
	}
	if (n==sum)
	{
		return 1;
	}
	return 0;
}

int isPalindrome(int n) {
	int temp=n;
	int sum=0;
	while(temp>0) {
		sum=(temp%10)+(sum*10);
		temp/=10;
	}
	if (n==sum)
	{
		return 1;
	}
	return 0;
}