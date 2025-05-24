#include <iostream>
#include <vector>
#include <cstdlib>

int main() 
{
	const int kInputSize = 25;
    std::vector<float> numbers(kInputSize);
    
    // Input data 输入数据 
    std::cout<<"Please enter 25 numbers:"<<std::endl;
    for (int i=0;i<kInputSize;i++) 
	{
        std::cin>>numbers[i];
        
        // Input error handling 输入错误处理 
		if(std::cin.fail())
		{
			std::cerr<<"wrong input!"<<std::endl;
			exit(1);
		} 
    }

    // Output the vector before squaring 输出平方前的 vector数组 
    std::cout <<"The vector before the multiplications:" << std::endl;
	for (float num : numbers) 
	{
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    
    // Square each number and store it back in the same position 对每个数平方并存回原来的位置
    for (int i=0;i<kInputSize;i++) {
        numbers[i] = numbers[i]*numbers[i]; 
    }
    
    //Output the vector after squaring 输出平方后的 vector数组 
    std::cout <<"The vector after the multiplications:" << std::endl;
    for (float num : numbers) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    
    return 0;
}
