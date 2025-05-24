#include <iostream>
#include <string>

// Define the struct ����ṹ��
struct MyStruct
{
    std::string str_first;
    std::string str_second;
    int number;
};

// Using typedef for the struct name ʹ��typedef������������
typedef MyStruct MyStructType; 

int main() 
{
    // Create an instance of MyStruct and initialize its values �����ṹ��ʵ������ʼ��
    MyStructType instance = {"Hello", "World", 114514};
    
    // Print the original values ��ӡ��ʼֵ
    std::cout << "Original values: " << instance.str_first << ", " << instance.str_second << ", " << instance.number << std::endl; 
    
    // Take the address of the instance and assign it to a pointer ��ȡʵ���ĵ�ַ�����丳ֵ��һ��ָ��MyStruct��ָ��
    MyStructType* ptr = &instance;

    // Change the values using the pointer �޸�ֵ
    ptr->str_first = "Tongji";
    ptr->str_second = "University";
    ptr->number = 1919810;

    // Print the updated values using the pointer ��ӡ�޸ĺ��ֵ
    std::cout << "Updated values using the pointer: " << ptr->str_first << ", " << ptr->str_second << ", " << ptr->number << std::endl;

    return 0;
}
