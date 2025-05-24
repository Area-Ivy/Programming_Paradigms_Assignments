#include <iostream>
using namespace std;

// 定义链表的节点结构
struct Node {
    int data;  // 巧克力的编号
    Node* next;  // 指向下一个节点
    Node(int d) : data(d), next(nullptr) {}
};

// 判断一个数是否是幸运数字：7的倍数或者包含数字7
bool luckyNumber(int num) 
{
    if (num % 7 == 0) 
	    return true;  // 检查是否是7的倍数
    while (num > 0) 
	{  // 检查是否包含数字7
        if (num % 10 == 7) 
		    return true;
        num /= 10;
    }
    return false;
}

int lastChocolate(int n) 
{
	// n为1时无需创建链表 
	if(n==1) 
	    return 1;
	
    // 创建循环链表
    Node* head = new Node(1); 
    Node* prev = head;
    for (int i = 2; i <= n; i++) 
	{
        Node* newNode = new Node(i);
        prev->next = newNode;
        prev = newNode;
    }
    
    // 将最后一个节点连接回头节点，形成循环
    prev->next = head;  

    // 初始化 
    Node* current = head;
    Node* prevNode = nullptr;
    int currentNumber = 1;

    while (current->next != current) // 当链表中还有多于1个节点时进行循环 
	{  
	    // 如果当前报数是幸运数字
        if (luckyNumber(currentNumber)) 
		{  
            // 删除当前节点
            if (prevNode) 
			{
                prevNode->next = current->next;
            }
            Node* toDelete = current;
            current = current->next;
            delete toDelete;  // 释放内存
        } 
		else
		 {
            // 正常移动到下一个节点
            prevNode = current;
            current = current->next;
        }
        currentNumber++;  // 更新报数
    }

    // 循环结束后，current即为最后剩下的节点 
    int lastChocolatePosition = current->data;
    delete current;  // 释放最后一个节点的内存
    return lastChocolatePosition;
}

int main() {
    int n;
    cout << "Enter the number of chocolates: ";
    cin >> n;
    if(cin.fail()||n<=0)// 输入错误处理 
		{
			cout<<"Wrong input!"<<endl;
		} 
		else
		{
			int result = lastChocolate(n);
            cout << result << endl;
		}

    return 0;
}
