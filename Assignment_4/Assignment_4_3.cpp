#include <string>
#include <iostream>

class Traveler {
private:
    std::string name;

public:
	// ���캯��������һ���ַ�������
    Traveler(const std::string& n) : name(n) {}
    // �������캯��
    Traveler(const Traveler& other) : name(other.name) {}
    // ��ֵ�����
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
	// ���캯��������һ���ַ�������
    Pager(const std::string& m) : model(m) {}
    // �������캯��
    Pager(const Pager& other) : model(other.model) {} 
    // ��ֵ�����
    Pager& operator=(const Pager& other){
    	if(this!=&other)
    	    model = other.model;
    	return *this;
	}
};

// BusinessTraveler �ࣺ�̳��� Traveler
class BusinessTraveler : public Traveler {
private:
    Pager pager;// Pager ����

public:
	
	// Ĭ�Ϲ��캯�������û���� Pager ��Ĭ�Ϲ��캯��
    BusinessTraveler() : Traveler("default"), pager("default") {}
	// �����ַ��������Ĺ��캯��
    BusinessTraveler(const std::string& name, const std::string& pagerModel) 
        : Traveler(name), pager(pagerModel) {}
    // �������캯��
    BusinessTraveler(const BusinessTraveler& other)
        : Traveler(other), pager(other.pager) {}
    // ��ֵ�����
    BusinessTraveler& operator=(const BusinessTraveler& other) {
        if (this != &other) {
            Traveler::operator=(other);
            pager = other.pager;
        }
        return *this;
    }
};
