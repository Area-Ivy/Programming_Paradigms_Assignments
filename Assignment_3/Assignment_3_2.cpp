#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if(k==0) return false;//k=0时一定为假 
    unordered_set<int> s; //用哈希集合来存放滑动窗口中的数据 
    int length = nums.size();
    for (int i = 0; i < length; i++) {
        if (i > k) {
            s.erase(nums[i - k - 1]);//维护大小为k的滑动窗口 
        }
        if (s.count(nums[i])) {//找到相等元素，返回true 
            return true; 
        }
        s.emplace(nums[i]);//将数据存入集合 
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
			cout<<"Wrong Input"<<endl;
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
	int k;
	
	int inputSuccess=inputVector(nums);
	 
	//输入数据 
	if(inputSuccess){
		cout<<"Please enter k: ";
	    cin>>k;
	    //输入错误处理 
	    if(cin.fail()||k<0){
    	    cout << "Wrong Input"<<endl;
    	    return -1;
	    }
        //输出结果 
	    if(containsNearbyDuplicate(nums,k))
	        cout<<"true"<<endl;
	    else
	        cout<<"false"<<endl;
	}	
	return 0;
}
