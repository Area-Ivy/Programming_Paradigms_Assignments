#include <string>
#include <iostream>

class Traveler {
private:
    std::string name;

public:
	// 构造函数：接受一个字符串参数
    Traveler(const std::string& n) : name(n) {}
    // 拷贝构造函数
    Traveler(const Traveler& other) : name(other.name) {}
    // 赋值运算符
    Traveler& operator=(const Traveler& other) {
        if (this != &other)
            name = other.name;
        return *this;
    }
};

class Pager {
private:
    std::string model;

public:
	// 构造函数：接受一个字符串参数
    Pager(const std::string& m) : model(m) {}
    // 拷贝构造函数
    Pager(const Pager& other) : model(other.model) {} 
    // 赋值运算符
    Pager& operator=(const Pager& other){
    	if(this!=&other)
    	    model = other.model;
    	return *this;
	}
};

// BusinessTraveler 类：继承自 Traveler
class BusinessTraveler : public Traveler {
private:
    Pager pager;// Pager 对象

public:
	
	// 默认构造函数：调用基类和 Pager 的默认构造函数
    BusinessTraveler() : Traveler("default"), pager("default") {}
	// 接受字符串参数的构造函数
    BusinessTraveler(const std::string& name, const std::string& pagerModel) 
        : Traveler(name), pager(pagerModel) {}
    // 拷贝构造函数
    BusinessTraveler(const BusinessTraveler& other)
        : Traveler(other), pager(other.pager) {}
    // 赋值运算符
    BusinessTraveler& operator=(const BusinessTraveler& other) {
        if (this != &other) {
            Traveler::operator=(other);
            pager = other.pager;
        }
        return *this;
    }
};
