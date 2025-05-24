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

// Input data and handle input errors 输入数据并进行输入错误处理 
void getInput(vector<int>& prices)
{
	
	// value stores the raw input data, temp stores each read price value 存放原始输入数据，temp存放每次读取的价格 
	string value;
	int temp=0;
	
	cin>>value;
	
	int n=value.length();
	
	// If n < 2, it is an incorrect 如果n<2，则为错误输入
	if(n<2)
	{
		cerr<<"wrong input!";
		exit(1);
	}
	
	// Check the beginning of the input, if it's not '[', then it's an error 对输入的开头进行检查，若输入开头不为'['，则直接判定为错误输入 
	if(value[0]!='[')
	{
		cerr<<"wrong input!";
		exit(1);
	}
	else
	{
		// Process the data 对数据进行处理
		for(int i=1;i<n-1;i++){
			
		    // When reading a digit, add it to temp 当读到的是数字时，将其存放到temp中 
			if(value[i]>='0'&&value[i]<='9')
			{
                temp=temp*10+value[i]-'0';
		    }
		    
		    else if(value[i]==',')
			{
		    	
		        // Check for consecutive ',' 检测是否存在多个','连续出现的情况 
		    	if(value[i-1]<'0'||value[i-1]>'9')
				{
		    		cerr<<"wrong input!";
		            exit(1);
				}
				
				else
				{
					// If no error, store the current number in prices 若无误，则当前数字的读取已完成，将其存放到prices中 
					prices.push_back(temp);
					temp=0;
				}
				
		    }
		    else 
			{
				// If the input is neither a digit nor a ',' , it's an error当输入的既不是数字也不是','时，判定为输入错误 
		    	cerr<<"wrong input!";
		        exit(1);
			}
		}
		
		// Check the end of the input. If the end of the input is not ']', or if it is','before']', it is judged as incorrect input   
		// 对输入的结尾进行检查，若输入结尾不为']'，或']'之前是','，则判定为错误输入 
		if(value[n-1]==']'&&value[n-2]!=',')
		{
			// Correct input, add the last number to prices 正确输入，将最后一个数字放入prices中 
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
	
	//min_price tracks the lowest stock price seen so far  min_price记录到当前日期为止出现的最低股价
    int minprice = INT_MAX;
    //max_profit tracks the maximum profit so far, initial profit is 0  max_price记录当前日期为止可获得的最大利润,初始利润为0
	int maxprofit = 0; 
	
	// Iterate through the prices array 遍历数组prices
    for (int price: prices) 
	{
		// Update the maximum profit 更新利润最大值 
        maxprofit = max(maxprofit, price - minprice); 
        // Update the minimum price 更新价格最小值 
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
