#include <iostream>
#include <cstring>
using namespace std;

// Function to modify a string to lowercase by pointer ���� string* ���Ͳ��������ַ���ת��ΪСд
void modifyStringByPointer(string* str) 
{
    for (char& c : *str) 
	{
		// Convert each character to lowercase ��ÿ���ַ�ת��ΪСд 
		if(c>='A'&&c<='Z') c=c-'A'+'a';
	}
}

// Function to modify a string to uppercase by reference ���� string& ���Ͳ��������ַ���ת��Ϊ��д
void modifyStringByReference(string& str) 
{
    for (char& c : str) 
	{
		// Convert each character to uppercase ��ÿ���ַ�ת��Ϊ��д
		if(c>='a'&&c<='z')	c=c-'a'+'A';
    }
}

int main() 
{
    // Define the initial string�����ʼ�ַ��� 
    string myString;
    
    // Input the initial string �����ʼ�ַ��� 
    char ch;
    while (cin.get(ch) && ch != '\n') {
        myString += ch;
    }
    
    // Print the initial string ��ӡ��ʼ�ַ���
    cout << "Initial string:" << myString << endl;

    // Pass the string to the function that takes a string* and modify it to lowercase ���ý���string*�ĺ���������ת��ΪСд
    modifyStringByPointer(&myString);
    cout << "String modified by pointer (lowercase):" << myString << endl;
    
	// Pass the string to the function that takes a string& and modify it to uppercase ���ý���string&�ĺ���������ת��Ϊ��д
    modifyStringByReference(myString);
    cout << "String modified by reference (uppercase): " << myString << endl;
	
	return 0;
}
