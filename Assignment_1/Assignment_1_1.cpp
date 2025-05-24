#include <iostream>
#include <fstream>
#include <cstdlib>

int main() 
{
    // File name ����Ҫ��ȡ���ļ��� 
    std::string fileName;
    std::cout << "Enter the file name(Please make sure the text file is in the same directory as your program or provide the full path to the file) : ";
    std::cin >> fileName;

    // Open the file ����Ƿ�ɹ����ļ� 
    std::ifstream file(fileName);
    if (!file.is_open()) 
	{
        std::cerr << "Error opening file!" << std::endl;
        exit(1);
    }

    // Variables to keep track of the word and count �������word���������ȡ 
    std::string word;
    const std::string targetWord = "that";
    int wordCount = 0;

    // Read words from the file and count occurrences of "that" ��ȡ�ļ���ͳ��'that'���ֵĴ��� 
    while (file >> word) 
	{
        std::string cleanWord;
        for (char c : word) 
		{
			// Filter non letter symbols to avoid the influence of punctuation ���˷���ĸ���ţ��������Ӱ�� 
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

    // Close the file �ر��ļ� 
    file.close();

    // Output the result ������ 
    std::cout << "The word 'that' appears " << wordCount << " times in the file." << std::endl;

    return 0;
}
