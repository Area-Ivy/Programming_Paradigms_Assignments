#include<iostream>
#include<cmath>
#include<vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;
using std::min;

// Input data and handle input errors �������ݲ�������������� 
void getInput(vector<int>& prices)
{
	
	// value stores the raw input data, temp stores each read price value ���ԭʼ�������ݣ�temp���ÿ�ζ�ȡ�ļ۸� 
	string value;
	int temp=0;
	
	cin>>value;
	
	int n=value.length();
	
	// If n < 2, it is an incorrect ���n<2����Ϊ��������
	if(n<2)
	{
		cerr<<"wrong input!";
		exit(1);
	}
	
	// Check the beginning of the input, if it's not '[', then it's an error ������Ŀ�ͷ���м�飬�����뿪ͷ��Ϊ'['����ֱ���ж�Ϊ�������� 
	if(value[0]!='[')
	{
		cerr<<"wrong input!";
		exit(1);
	}
	else
	{
		// Process the data �����ݽ��д���
		for(int i=1;i<n-1;i++){
			
		    // When reading a digit, add it to temp ��������������ʱ�������ŵ�temp�� 
			if(value[i]>='0'&&value[i]<='9')
			{
                temp=temp*10+value[i]-'0';
		    }
		    
		    else if(value[i]==',')
			{
		    	
		        // Check for consecutive ',' ����Ƿ���ڶ��','�������ֵ���� 
		    	if(value[i-1]<'0'||value[i-1]>'9')
				{
		    		cerr<<"wrong input!";
		            exit(1);
				}
				
				else
				{
					// If no error, store the current number in prices ��������ǰ���ֵĶ�ȡ����ɣ������ŵ�prices�� 
					prices.push_back(temp);
					temp=0;
				}
				
		    }
		    else 
			{
				// If the input is neither a digit nor a ',' , it's an error������ļȲ�������Ҳ����','ʱ���ж�Ϊ������� 
		    	cerr<<"wrong input!";
		        exit(1);
			}
		}
		
		// Check the end of the input. If the end of the input is not ']', or if it is','before']', it is judged as incorrect input   
		// ������Ľ�β���м�飬�������β��Ϊ']'����']'֮ǰ��','�����ж�Ϊ�������� 
		if(value[n-1]==']'&&value[n-2]!=',')
		{
			// Correct input, add the last number to prices ��ȷ���룬�����һ�����ַ���prices�� 
			prices.push_back(temp);
		}
		else
		{
		    cerr<<"wrong input!";
		    exit(1);	
		}
	}
	return;
} 
 

int maxProfit(vector<int>& prices) 
{
	if (prices.empty())
	{
		return 0;
	} 
	
	//min_price tracks the lowest stock price seen so far  min_price��¼����ǰ����Ϊֹ���ֵ���͹ɼ�
    int minprice = INT_MAX;
    //max_profit tracks the maximum profit so far, initial profit is 0  max_price��¼��ǰ����Ϊֹ�ɻ�õ��������,��ʼ����Ϊ0
	int maxprofit = 0; 
	
	// Iterate through the prices array ��������prices
    for (int price: prices) 
	{
		// Update the maximum profit �����������ֵ 
        maxprofit = max(maxprofit, price - minprice); 
        // Update the minimum price ���¼۸���Сֵ 
        minprice = min(price, minprice);
    }
    
    return maxprofit;
}	

int main()
{
	vector<int> prices;
	cout<<"Please enter prices, starting with '[' and ending with ']', separated by ',' (e.g., [7,1,5,3,6,4]):"<<endl; 
	getInput(prices);
	cout<<maxProfit(prices);
	return 0;
}
