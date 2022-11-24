#include <math.h>
#include "NumClass.h"

int ArmStrongRecursive(int num,int d) {
    if (num==0) return 0;
    return ArmStrongRecursive((num/10),d)+pow((num%10),d);
}

int CountDigits(int num) {
    if (num==0) return 0;
    return 1+CountDigits(num/10);
}

int PalindromeRecursive(int num,int sum) {
    if (num==0) return sum;
    return PalindromeRecursive((num/10),((sum*10)+(num%10)));
}

int isArmstrong(int num) {
	int d;
	d=CountDigits(num);

	if (num==ArmStrongRecursive(num,d))
	{
		return 1;
	}

	return 0;
}

int isPalindrome(int num)  {
	if (num==PalindromeRecursive(num,0))
	{
		return 1;
	}

	return 0;
}