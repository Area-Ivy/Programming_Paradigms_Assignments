#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if(k==0) return false;//k=0ʱһ��Ϊ�� 
    unordered_set<int> s; //�ù�ϣ��������Ż��������е����� 
    int length = nums.size();
    for (int i = 0; i < length; i++) {
        if (i > k) {
            s.erase(nums[i - k - 1]);//ά����СΪk�Ļ������� 
        }
        if (s.count(nums[i])) {//�ҵ����Ԫ�أ�����true 
            return true; 
        }
        s.emplace(nums[i]);//�����ݴ��뼯�� 
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
	int k;
	
	int inputSuccess=inputVector(nums);
	 
	//�������� 
	if(inputSuccess){
		cout<<"Please enter k: ";
	    cin>>k;
	    //��������� 
	    if(cin.fail()||k<0){
    	    cout << "Wrong Input"<<endl;
    	    return -1;
	    }
        //������ 
	    if(containsNearbyDuplicate(nums,k))
	        cout<<"true"<<endl;
	    else
	        cout<<"false"<<endl;
	}	
	return 0;
}
