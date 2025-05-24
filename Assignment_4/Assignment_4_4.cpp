//问题4： 
//编写一个包含一个虚函数和一个非虚函数的类。
//继承一个新类，创建该类的对象，并向基类指针上转型。
//使用 <ctime> 中的 clock() 函数来测量虚函数调用与非虚函数调用之间的时间差。
//在计时循环中对每个函数进行多次调用以观察差异。 

#include <iostream>
#include <ctime>

long long count;
long long vcount;

// 基类定义
class Base{
public:
	// 虚函数
	virtual void virtualFunction(){
		count++;
	} 
	// 非虚函数
	void nonVirtualFunction(){
		count++;
	}
	// 虚析构函数
    virtual ~Base() = default;
};

// 派生类定义
class Derived : public Base{
public:
	// 重写基类的虚函数
	void virtualFunction() override {
	    vcount++;
	}
};

void measureFunctionCallTime(Base* obj, int iterations){
	clock_t start,end;
	
	// 测量非虚函数调用时间
	start=clock();
	for(int i=0;i<iterations;i++){
		obj->nonVirtualFunction();// 静态绑定，直接调用基类的非虚函数
	}
	end=clock();
	std::cout << "Time taken by non-virtual function: " 
              << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
     
	// 测量虚函数调用时间          
    start=clock();
	for(int i=0;i<iterations;i++){
		obj->virtualFunction(); // 动态绑定，通过 vtable 调用派生类的虚函数
	}
	end=clock();
	std::cout << "Time taken by virtual function: " 
              << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
}

int main(){
	Derived derived; // 创建派生类对象
	Base* obj=&derived; // 将派生类对象上转型为基类指针
	int iterations=100000000; // 循环次数，确保测量时间足够长
	measureFunctionCallTime(obj, iterations);
	return 0;
}
