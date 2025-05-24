#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

string addLargeNumbers(string &a, string &b, int m, int n) {
    string result = "";  // ������
    int carry = 0;       // ��λ
    int i = m - 1, j = n - 1;  // �����һλ��ʼ���

    // ��λ���
    while (i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0) ? a[i] - '0' : 0;  // ��ǰa��λ����������Ϊ0
        int digitB = (j >= 0) ? b[j] - '0' : 0;  // ��ǰb��λ����������Ϊ0

        int sum = digitA + digitB + carry;  // ��λ��Ӳ����Ͻ�λ
        carry = sum / 10;  // ���½�λ
        result += (sum % 10) + '0';  // ���浱ǰλ

        i--;  // �ƶ�����һλ
        j--;  // �ƶ�����һλ
    }

    // ���������Ǵӵ�λ����λ������ӣ������Ҫ��ת
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int m, n;
    string a, b;

    // �������У�a��λ��m��a��b��λ��n��b
    cout<<"Please enter the length of string a: ";
    cin >> m;
    cout<<"Please enter the string a: " ;
    cin >> a;
    cout<<"Please enter the length of string b: ";
    cin >> n;
    cout<<"Please enter the string b: ";
    cin >> b;
    
    // �������ĳ����Ƿ���ʵ�ʳ���ƥ�� 
    if(m!=a.length()||n!=b.length())
	{
    	cout<<"Wrong input"<<endl;
	}
	else
	{
		// ������Ӻ���
        string result = addLargeNumbers(a, b, m, n);

        // ������
        cout << result << endl;
	}

    return 0;
}



