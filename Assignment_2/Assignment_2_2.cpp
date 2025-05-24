#include <iostream>
#include <cmath>
using namespace std;

// ������ 
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
	int evenDigitCount=n-n/2; // ż��λ�� 
	int oddDigitCount=n/2;    // ����λ�� 
	
	// ÿ��ż��λ��5�ֿ���ֵ��ÿ������λ��4�ֿ���ֵ���ɴ˵õ��ܸ��� 
	return myPow(5,evenDigitCount)*myPow(4,oddDigitCount);
}

int main()
{
	cout<<"Please enter the prompt number: ";
	int n;
	cin>>n;
	
	if(cin.fail()||n<=0)// ��������� 
	{
		cout<<"Wrong input!"<<endl;
	} 
	else
	{
		cout<<calculateCount(n)<<endl;
    } 
	
	return 0;
}
