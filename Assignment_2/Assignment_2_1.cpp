#include <iostream>
#include <string>
using namespace std;

// ��������������ַ����Ƿ�Ϊ���Ĵ�
bool checkPalindrome(const string& s, int left, int right) 
{
    while (left < right) 
	{
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// ����ַ����Ƿ����ͨ��ɾ��һ���ַ����Ϊ���Ĵ�
bool validPalindrome(const string &s) 
{
	// ԭ�ַ���Ϊ�մ���ֻ��һ���ַ�ʱ������ɾ��
	if(s.length()<=1)  
	   return false; 
	
    int left = 0;
    int right = s.length() - 1;

    while (left < right) 
	{
        if (s[left] != s[right]) 
		{
			// ��������ַ���ƥ�䣬����ɾ����߻��ұߵ��ַ�������Ƿ��Ϊ����
            return checkPalindrome(s, left + 1, right) || checkPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    
    
    // ԭ�ַ���Ϊ���Ĵ�ʱ����һ������ͨ��ɾ��һ��Ԫ�صõ����Ĵ� 
	return true; 
}

int main() 
{
    string s;
    cout << "Please enter a string: ";
    cin >> s;

    if (validPalindrome(s)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
