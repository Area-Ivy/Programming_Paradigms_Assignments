#include <iostream>
#include <string>
using namespace std;

// 辅助函数：检查字符串是否为回文串
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

// 检测字符串是否可以通过删除一个字符后成为回文串
bool validPalindrome(const string &s) 
{
	// 原字符串为空串或只有一个字符时，不能删除
	if(s.length()<=1)  
	   return false; 
	
    int left = 0;
    int right = s.length() - 1;

    while (left < right) 
	{
        if (s[left] != s[right]) 
		{
			// 如果发现字符不匹配，尝试删除左边或右边的字符，检查是否成为回文
            return checkPalindrome(s, left + 1, right) || checkPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    
    
    // 原字符串为回文串时，则一定可以通过删除一个元素得到回文串 
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
