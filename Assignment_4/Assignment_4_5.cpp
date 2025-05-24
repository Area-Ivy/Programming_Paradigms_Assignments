#include <iostream>
#include <memory>

class Base{
public:
	virtual ~Base() = default;// 虚析构函数，确保派生类的析构函数被调用
	virtual Base* clone() const = 0; // 纯虚函数，派生类必须实现
	virtual void display() const = 0; // 纯虚函数，用于显示信息
};

class Derived1 : public Base{
public:
	// 克隆函数：返回当前对象的副本
	Derived1* clone() const override{
	    return new Derived1(*this); // 创建 Derived1 类型的新对象并返回
	}
	
	// display：用于显示派生类的信息
    void display() const override {
        std::cout << "I am a Derived1 object!" << std::endl;
    }
};

class Derived2 : public Base{
public:
	// 克隆函数：返回当前对象的副本
    Derived2* clone() const override {
        return new Derived2(*this); // 创建 Derived2 类型的新对象并返回
    }

    // display：用于显示派生类的信息
    void display() const override {
        std::cout << "I am a Derived2 object!" << std::endl;
    }
};

int main(){
//	Base* obj1 = new Derived1(); // 创建 Derived1 对象
//	Base* obj2 = new Derived2(); // 创建 Derived2 对象
	
	// 创建 Derived1 对象
	Derived1 derived1;
    Base* obj1 = &derived1;
    
	// 创建 Derived2 对象
    Derived2 derived2;
    Base* obj2 = &derived2;
	
	// 克隆这两个对象
    Base* clone1 = obj1->clone();  // 克隆 obj1
    Base* clone2 = obj2->clone();  // 克隆 obj2

    // 使用多态性来调用派生类的 display 方法
    clone1->display();  // 输出：I am a Derived1 object!
    clone2->display();  // 输出：I am a Derived2 object!

    // 清理资源
    delete obj1;
    delete obj2;
    delete clone1;
    delete clone2;

    return 0;
}
