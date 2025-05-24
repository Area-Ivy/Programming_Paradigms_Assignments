#include <iostream>
#include<vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen; //�ù�ϣ������������� 
    for (const int& num : nums) { //�������� 
        if (seen.count(num)) { //�ҵ���ͬ�� 
            return true;
        }
        seen.insert(num); //�����ݲ��뼯�� 
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
			cout<<"Wrong Input!"<<endl;
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
	
	int inputSuccess=inputVector(nums);// �������� 
	
	if(inputSuccess){
		if(containsDuplicate(nums))
	        cout<<"true"<<endl;
	    else
	        cout<<"false"<<endl;
	} 
	return 0;
}
