#include <iostream>
#include <vector>
#include <cstdlib>

int main() 
{
	const int kInputSize = 25;
    std::vector<float> numbers(kInputSize);
    
    // Input data �������� 
    std::cout<<"Please enter 25 numbers:"<<std::endl;
    for (int i=0;i<kInputSize;i++) 
	{
        std::cin>>numbers[i];
        
        // Input error handling ��������� 
		if(std::cin.fail())
		{
			std::cerr<<"wrong input!"<<std::endl;
			exit(1);
		} 
    }

    // Output the vector before squaring ���ƽ��ǰ�� vector���� 
    std::cout <<"The vector before the multiplications:" << std::endl;
	for (float num : numbers) 
	{
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    
    // Square each number and store it back in the same position ��ÿ����ƽ�������ԭ����λ��
    for (int i=0;i<kInputSize;i++) {
        numbers[i] = numbers[i]*numbers[i]; 
    }
    
    //Output the vector after squaring ���ƽ����� vector���� 
    std::cout <<"The vector after the multiplications:" << std::endl;
    for (float num : numbers) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    
    return 0;
}
