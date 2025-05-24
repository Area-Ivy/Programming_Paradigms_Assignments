#include <iostream>
using namespace std;

// ��������Ľڵ�ṹ
struct Node {
    int data;  // �ɿ����ı��
    Node* next;  // ָ����һ���ڵ�
    Node(int d) : data(d), next(nullptr) {}
};

// �ж�һ�����Ƿ����������֣�7�ı������߰�������7
bool luckyNumber(int num) 
{
    if (num % 7 == 0) 
	    return true;  // ����Ƿ���7�ı���
    while (num > 0) 
	{  // ����Ƿ��������7
        if (num % 10 == 7) 
		    return true;
        num /= 10;
    }
    return false;
}

int lastChocolate(int n) 
{
	// nΪ1ʱ���贴������ 
	if(n==1) 
	    return 1;
	
    // ����ѭ������
    Node* head = new Node(1); 
    Node* prev = head;
    for (int i = 2; i <= n; i++) 
	{
        Node* newNode = new Node(i);
        prev->next = newNode;
        prev = newNode;
    }
    
    // �����һ���ڵ����ӻ�ͷ�ڵ㣬�γ�ѭ��
    prev->next = head;  

    // ��ʼ�� 
    Node* current = head;
    Node* prevNode = nullptr;
    int currentNumber = 1;

    while (current->next != current) // �������л��ж���1���ڵ�ʱ����ѭ�� 
	{  
	    // �����ǰ��������������
        if (luckyNumber(currentNumber)) 
		{  
            // ɾ����ǰ�ڵ�
            if (prevNode) 
			{
                prevNode->next = current->next;
            }
            Node* toDelete = current;
            current = current->next;
            delete toDelete;  // �ͷ��ڴ�
        } 
		else
		 {
            // �����ƶ�����һ���ڵ�
            prevNode = current;
            current = current->next;
        }
        currentNumber++;  // ���±���
    }

    // ѭ��������current��Ϊ���ʣ�µĽڵ� 
    int lastChocolatePosition = current->data;
    delete current;  // �ͷ����һ���ڵ���ڴ�
    return lastChocolatePosition;
}

int main() {
    int n;
    cout << "Enter the number of chocolates: ";
    cin >> n;
    if(cin.fail()||n<=0)// ��������� 
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
