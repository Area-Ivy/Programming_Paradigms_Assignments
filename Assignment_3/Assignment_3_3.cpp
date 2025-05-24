#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
    set<int> rec;//集合用于存放数据，维护一个大小为k的滑动窗口
    for (int i = 0; i < n; i++) {
        auto iter = rec.lower_bound(max(nums[i], INT_MIN + valueDiff) - valueDiff);//找到大于等于nums[i]的最小值，同时防止下溢
        if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - valueDiff) + valueDiff) {//判断是否满足条件，同时防止上溢
            return true;
        }
        rec.insert(nums[i]);//插入数据
         if (i >= indexDiff) {
           rec.erase(nums[i - indexDiff]);//删除数据以保证窗口大小为k
        }
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
	int indexDiff,valueDiff;
	
	int inputSuccess=inputVector(nums);
    
    if(inputSuccess){
    	//输入indexDiff 
    	cout<<"Please enter indexDiff: "<<endl;
	    cin>>indexDiff;
	    if(cin.fail()||indexDiff<1||indexDiff>nums.size()){
	    	cout<<"Wrong Input!"<<endl;
			return -1;
		}
        //输入valueDiff 
     	cout<<"Please enter valueDiff: "<<endl;
	    cin>>valueDiff;
		if(cin.fail()||valueDiff<0){
	    	cout<<"Wrong Input!"<<endl;
			return -1;
		}
	    
	    if(containsNearbyAlmostDuplicate(nums,indexDiff,valueDiff))
	        cout<<"true"<<endl;
	    else
	        cout<<"false"<<endl;
	} 
	return 0;
}
