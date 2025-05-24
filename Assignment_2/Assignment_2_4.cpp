#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// 只针对整数的幂函数，节约性能 
int myPow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;  
    }
    return result;
}

// 将六进制转换为十进制 
int base6ToDecimal(int number) 
{
	//如果传入值为负数，返回-1 
	if(number<0)
	    return -1;
	
    int decimal = 0;
    int power = 0;

    while (number > 0) 
	{
        int digit = number % 10;  // 取出六进制数的最后一位
        
		if (digit < 0 || digit > 5) 
            return -1;  // 如果出现非法的六进制位，返回-1
        
		decimal += digit * myPow(6, power);  // 将这一位的值乘以6的相应次幂
        number /= 10;  // 移除最后一位
        power++;  // 更新次幂
    }

    return decimal;
}

// 将十进制数转换为x进制
string decimalToBase(int decimal, int base) 
{
    string result = "";
    const string digits = "0123456789ABCDEFGHIJ";  // 用于表示0-9以及A-J

    do{
        result = digits[decimal % base] + result;  // 取余数并将对应字符加到结果前面
        decimal /= base; // 对原数据进行除法运算 
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
    
    // 将六进制数转换为十进制数 
    decimal=base6ToDecimal(number);
    
    // 输入错误处理 
    if(base<2||base>20||decimal<0||decimal>1000000)
	{
    	cout<<"Wrong input!"<<endl;
	}
	else{
		// 输入数据正确，输出结果 
		cout<<decimalToBase(decimal, base)<<endl;
	}
       
	return 0;
}
