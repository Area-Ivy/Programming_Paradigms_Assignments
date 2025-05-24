#include <iostream>
#include <string>

// Define the struct 定义结构体
struct MyStruct
{
    std::string str_first;
    std::string str_second;
    int number;
};

// Using typedef for the struct name 使用typedef定义新类型名
typedef MyStruct MyStructType; 

int main() 
{
    // Create an instance of MyStruct and initialize its values 创建结构体实例并初始化
    MyStructType instance = {"Hello", "World", 114514};
    
    // Print the original values 打印初始值
    std::cout << "Original values: " << instance.str_first << ", " << instance.str_second << ", " << instance.number << std::endl; 
    
    // Take the address of the instance and assign it to a pointer 获取实例的地址并将其赋值给一个指向MyStruct的指针
    MyStructType* ptr = &instance;

    // Change the values using the pointer 修改值
    ptr->str_first = "Tongji";
    ptr->str_second = "University";
    ptr->number = 1919810;

    // Print the updated values using the pointer 打印修改后的值
    std::cout << "Updated values using the pointer: " << ptr->str_first << ", " << ptr->str_second << ", " << ptr->number << std::endl;

    return 0;
}
