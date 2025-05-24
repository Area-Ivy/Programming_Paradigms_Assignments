#include <iostream>
#include<vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen; //用哈希集合来存放数据 
    for (const int& num : nums) { //遍历数组 
        if (seen.count(num)) { //找到相同的 
            return true;
        }
        seen.insert(num); //把数据插入集合 
    }
    return false;
}

//输入函数
bool inputVector(vector<int>& nums) {
    cout << "Please enter nums (separated by spaces, end with Enter): " << endl;
    int num;
    while (true) {
	    cin >> num;//读入数据
		//输入错误处理 
		if(cin.fail()){
			cout<<"Wrong Input!"<<endl;
			return false;
		} 
        nums.push_back(num); 
        if (cin.peek() == '\n') break;//如果检测到回车则结束 
    }
	return true; 
}

int main()
{
	vector<int> nums;
	
	int inputSuccess=inputVector(nums);// 输入数据 
	
	if(inputSuccess){
		if(containsDuplicate(nums))
	        cout<<"true"<<endl;
	    else
	        cout<<"false"<<endl;
	} 
	return 0;
}
