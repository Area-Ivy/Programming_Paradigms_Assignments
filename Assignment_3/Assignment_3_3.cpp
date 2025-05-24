#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
    set<int> rec;//�������ڴ�����ݣ�ά��һ����СΪk�Ļ�������
    for (int i = 0; i < n; i++) {
        auto iter = rec.lower_bound(max(nums[i], INT_MIN + valueDiff) - valueDiff);//�ҵ����ڵ���nums[i]����Сֵ��ͬʱ��ֹ����
        if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - valueDiff) + valueDiff) {//�ж��Ƿ�����������ͬʱ��ֹ����
            return true;
        }
        rec.insert(nums[i]);//��������
         if (i >= indexDiff) {
           rec.erase(nums[i - indexDiff]);//ɾ�������Ա�֤���ڴ�СΪk
        }
    }
        return false;
}

//���뺯��
bool inputVector(vector<int>& nums) {
    cout << "Please enter nums (separated by spaces, end with Enter): " << endl;
    int num;
    while (true) {
	    cin >> num;//��������
		//��������� 
		if(cin.fail()){
			cout<<"Wrong Input"<<endl;
			return false;
		} 
        nums.push_back(num); 
        if (cin.peek() == '\n') break;//�����⵽�س������ 
    }
	return true; 
}

int main()
{
	vector<int> nums;
	int indexDiff,valueDiff;
	
	int inputSuccess=inputVector(nums);
    
    if(inputSuccess){
    	//����indexDiff 
    	cout<<"Please enter indexDiff: "<<endl;
	    cin>>indexDiff;
	    if(cin.fail()||indexDiff<1||indexDiff>nums.size()){
	    	cout<<"Wrong Input!"<<endl;
			return -1;
		}
        //����valueDiff 
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
