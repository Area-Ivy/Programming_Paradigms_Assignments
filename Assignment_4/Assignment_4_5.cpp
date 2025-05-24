#include <iostream>
#include <memory>

class Base{
public:
	virtual ~Base() = default;// ������������ȷ�����������������������
	virtual Base* clone() const = 0; // ���麯�������������ʵ��
	virtual void display() const = 0; // ���麯����������ʾ��Ϣ
};

class Derived1 : public Base{
public:
	// ��¡���������ص�ǰ����ĸ���
	Derived1* clone() const override{
	    return new Derived1(*this); // ���� Derived1 ���͵��¶��󲢷���
	}
	
	// display��������ʾ���������Ϣ
    void display() const override {
        std::cout << "I am a Derived1 object!" << std::endl;
    }
};

class Derived2 : public Base{
public:
	// ��¡���������ص�ǰ����ĸ���
    Derived2* clone() const override {
        return new Derived2(*this); // ���� Derived2 ���͵��¶��󲢷���
    }

    // display��������ʾ���������Ϣ
    void display() const override {
        std::cout << "I am a Derived2 object!" << std::endl;
    }
};

int main(){
//	Base* obj1 = new Derived1(); // ���� Derived1 ����
//	Base* obj2 = new Derived2(); // ���� Derived2 ����
	
	// ���� Derived1 ����
	Derived1 derived1;
    Base* obj1 = &derived1;
    
	// ���� Derived2 ����
    Derived2 derived2;
    Base* obj2 = &derived2;
	
	// ��¡����������
    Base* clone1 = obj1->clone();  // ��¡ obj1
    Base* clone2 = obj2->clone();  // ��¡ obj2

    // ʹ�ö�̬��������������� display ����
    clone1->display();  // �����I am a Derived1 object!
    clone2->display();  // �����I am a Derived2 object!

    // ������Դ
    delete obj1;
    delete obj2;
    delete clone1;
    delete clone2;

    return 0;
}
