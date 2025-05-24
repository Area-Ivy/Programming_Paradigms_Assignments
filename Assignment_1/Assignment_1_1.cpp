#include <iostream>
#include <fstream>
#include <cstdlib>

int main() 
{
    // File name 输入要读取的文件名 
    std::string fileName;
    std::cout << "Enter the file name(Please make sure the text file is in the same directory as your program or provide the full path to the file) : ";
    std::cin >> fileName;

    // Open the file 检测是否成功打开文件 
    std::ifstream file(fileName);
    if (!file.is_open()) 
	{
        std::cerr << "Error opening file!" << std::endl;
        exit(1);
    }

    // Variables to keep track of the word and count 定义变量word用于逐个读取 
    std::string word;
    const std::string targetWord = "that";
    int wordCount = 0;

    // Read words from the file and count occurrences of "that" 读取文件并统计'that'出现的次数 
    while (file >> word) 
	{
        std::string cleanWord;
        for (char c : word) 
		{
			// Filter non letter symbols to avoid the influence of punctuation 过滤非字母符号，避免标点的影响 
            if (isalnum(c)) 
			{
                cleanWord += c;
            }
        }
        if (cleanWord == targetWord) 
        {
            wordCount++;
        }
    }

    // Close the file 关闭文件 
    file.close();

    // Output the result 输出结果 
    std::cout << "The word 'that' appears " << wordCount << " times in the file." << std::endl;

    return 0;
}
