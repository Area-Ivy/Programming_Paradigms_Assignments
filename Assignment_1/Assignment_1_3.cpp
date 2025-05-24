#include <iostream>
#include <cstring>
using namespace std;

// Function to modify a string to lowercase by pointer 接受 string* 类型参数，将字符串转换为小写
void modifyStringByPointer(string* str) 
{
    for (char& c : *str) 
	{
		// Convert each character to lowercase 将每个字符转换为小写 
		if(c>='A'&&c<='Z') c=c-'A'+'a';
	}
}

// Function to modify a string to uppercase by reference 接受 string& 类型参数，将字符串转换为大写
void modifyStringByReference(string& str) 
{
    for (char& c : str) 
	{
		// Convert each character to uppercase 将每个字符转换为大写
		if(c>='a'&&c<='z')	c=c-'a'+'A';
    }
}

int main() 
{
    // Define the initial string定义初始字符串 
    string myString;
    
    // Input the initial string 输入初始字符串 
    char ch;
    while (cin.get(ch) && ch != '\n') {
        myString += ch;
    }
    
    // Print the initial string 打印初始字符串
    cout << "Initial string:" << myString << endl;

    // Pass the string to the function that takes a string* and modify it to lowercase 调用接受string*的函数，将其转换为小写
    modifyStringByPointer(&myString);
    cout << "String modified by pointer (lowercase):" << myString << endl;
    
	// Pass the string to the function that takes a string& and modify it to uppercase 调用接受string&的函数，将其转换为大写
    modifyStringByReference(myString);
    cout << "String modified by reference (uppercase): " << myString << endl;
	
	return 0;
}
