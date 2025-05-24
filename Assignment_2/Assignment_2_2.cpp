#include <iostream>
#include <cmath>
using namespace std;

// 快速幂 
long long myPow(int base, int exponent) {
    long long result = 1;
    while (exponent > 0) 
	{
        if (exponent % 2 == 1) 
		{
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

long long calculateCount(int n)
{
	int evenDigitCount=n-n/2; // 偶数位数 
	int oddDigitCount=n/2;    // 奇数位数 
	
	// 每个偶数位有5种可能值，每个奇数位有4种可能值，由此得到总个数 
	return myPow(5,evenDigitCount)*myPow(4,oddDigitCount);
}

int main()
{
	cout<<"Please enter the prompt number: ";
	int n;
	cin>>n;
	
	if(cin.fail()||n<=0)// 输入错误处理 
	{
		cout<<"Wrong input!"<<endl;
	} 
	else
	{
		cout<<calculateCount(n)<<endl;
    } 
	
	return 0;
}
