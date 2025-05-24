#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

string addLargeNumbers(string &a, string &b, int m, int n) {
    string result = "";  // 保存结果
    int carry = 0;       // 进位
    int i = m - 1, j = n - 1;  // 从最后一位开始相加

    // 逐位相加
    while (i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0) ? a[i] - '0' : 0;  // 当前a的位数，超出则为0
        int digitB = (j >= 0) ? b[j] - '0' : 0;  // 当前b的位数，超出则为0

        int sum = digitA + digitB + carry;  // 两位相加并加上进位
        carry = sum / 10;  // 更新进位
        result += (sum % 10) + '0';  // 保存当前位

        i--;  // 移动到下一位
        j--;  // 移动到下一位
    }

    // 由于我们是从低位到高位进行相加，结果需要反转
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int m, n;
    string a, b;

    // 输入四行：a的位数m，a，b的位数n，b
    cout<<"Please enter the length of string a: ";
    cin >> m;
    cout<<"Please enter the string a: " ;
    cin >> a;
    cout<<"Please enter the length of string b: ";
    cin >> n;
    cout<<"Please enter the string b: ";
    cin >> b;
    
    // 检查给定的长度是否与实际长度匹配 
    if(m!=a.length()||n!=b.length())
	{
    	cout<<"Wrong input"<<endl;
	}
	else
	{
		// 调用相加函数
        string result = addLargeNumbers(a, b, m, n);

        // 输出结果
        cout << result << endl;
	}

    return 0;
}



