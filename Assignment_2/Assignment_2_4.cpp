#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// ֻ����������ݺ�������Լ���� 
int myPow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;  
    }
    return result;
}

// ��������ת��Ϊʮ���� 
int base6ToDecimal(int number) 
{
	//�������ֵΪ����������-1 
	if(number<0)
	    return -1;
	
    int decimal = 0;
    int power = 0;

    while (number > 0) 
	{
        int digit = number % 10;  // ȡ���������������һλ
        
		if (digit < 0 || digit > 5) 
            return -1;  // ������ַǷ���������λ������-1
        
		decimal += digit * myPow(6, power);  // ����һλ��ֵ����6����Ӧ����
        number /= 10;  // �Ƴ����һλ
        power++;  // ���´���
    }

    return decimal;
}

// ��ʮ������ת��Ϊx����
string decimalToBase(int decimal, int base) 
{
    string result = "";
    const string digits = "0123456789ABCDEFGHIJ";  // ���ڱ�ʾ0-9�Լ�A-J

    do{
        result = digits[decimal % base] + result;  // ȡ����������Ӧ�ַ��ӵ����ǰ��
        decimal /= base; // ��ԭ���ݽ��г������� 
    } while (decimal > 0);

    return result;
}

int main() 
{
    int number,decimal, base;
   
    cout << "Enter the base (2 to 20): ";
    cin >> base;
    
    cout << "Enter the number : ";
    cin >> number;
    
    // ����������ת��Ϊʮ������ 
    decimal=base6ToDecimal(number);
    
    // ��������� 
    if(base<2||base>20||decimal<0||decimal>1000000)
	{
    	cout<<"Wrong input!"<<endl;
	}
	else{
		// ����������ȷ�������� 
		cout<<decimalToBase(decimal, base)<<endl;
	}
       
	return 0;
}
