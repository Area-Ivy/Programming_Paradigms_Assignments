//����4�� 
//��дһ������һ���麯����һ�����麯�����ࡣ
//�̳�һ�����࣬��������Ķ��󣬲������ָ����ת�͡�
//ʹ�� <ctime> �е� clock() �����������麯����������麯������֮���ʱ��
//�ڼ�ʱѭ���ж�ÿ���������ж�ε����Թ۲���졣 

#include <iostream>
#include <ctime>

long long count;
long long vcount;

// ���ඨ��
class Base{
public:
	// �麯��
	virtual void virtualFunction(){
		count++;
	} 
	// ���麯��
	void nonVirtualFunction(){
		count++;
	}
	// ����������
    virtual ~Base() = default;
};

// �����ඨ��
class Derived : public Base{
public:
	// ��д������麯��
	void virtualFunction() override {
	    vcount++;
	}
};

void measureFunctionCallTime(Base* obj, int iterations){
	clock_t start,end;
	
	// �������麯������ʱ��
	start=clock();
	for(int i=0;i<iterations;i++){
		obj->nonVirtualFunction();// ��̬�󶨣�ֱ�ӵ��û���ķ��麯��
	}
	end=clock();
	std::cout << "Time taken by non-virtual function: " 
              << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
     
	// �����麯������ʱ��          
    start=clock();
	for(int i=0;i<iterations;i++){
		obj->virtualFunction(); // ��̬�󶨣�ͨ�� vtable ������������麯��
	}
	end=clock();
	std::cout << "Time taken by virtual function: " 
              << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
}

int main(){
	Derived derived; // �������������
	Base* obj=&derived; // �������������ת��Ϊ����ָ��
	int iterations=100000000; // ѭ��������ȷ������ʱ���㹻��
	measureFunctionCallTime(obj, iterations);
	return 0;
}
