#include <iostream>
#include <string>
using namespace std;

// 定义 Rectangle 结构体
struct Rectangle {
    int x, y;

    // 构造函数
    Rectangle(int x = 0, int y = 0) : x(x), y(y) {}

    // 重载 >= 运算符，比较面积
    bool operator>=(const Rectangle& other) const {
        return (x * y) >= (other.x * other.y);
    }

    // 打印矩形的信息
    void print() const {
        cout << x << "," << y;
    }
};

// 泛型 max 函数模板
template <typename T>
T max(T t1, T t2, T t3) {
    if (t1 >= t2 && t1 >= t3) return t1;
    else if (t2 >= t1 && t2 >= t3) return t2;
    else return t3;
}

// 特化 max 函数模板，处理 string 类型
template <>
string max<string>(string t1, string t2, string t3) {
    auto compare = [](const string& a, const string& b) {
        if (a.length() > b.length()) return true;
        else if (a.length() < b.length()) return false;
        return a >= b;
    };

    if (compare(t1, t2) && compare(t1, t3)) return t1;
    else if (compare(t2, t1) && compare(t2, t3)) return t2;
    return t3;
}

// 特化 max 函数模板，处理 Rectangle 类型
template <>
Rectangle max<Rectangle>(Rectangle t1, Rectangle t2, Rectangle t3) {
    if (t1 >= t2 && t1 >= t3) return t1;
    else if (t2 >= t1 && t2 >= t3) return t2;
    else return t3;
}

// 特化 max 函数模板，处理 Rectangle* 类型
template <>
Rectangle* max<Rectangle*>(Rectangle* t1, Rectangle* t2, Rectangle* t3) {
    if (*t1 >= *t2 && *t1 >= *t3) return t1;
    else if (*t2 >= *t1 && *t2 >= *t3) return t2;
    else return t3;
}

int main() {
    // 1. int 类型数据
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << max(a1, a2, a3) << endl;

    // 2. double 类型数据
    double b1, b2, b3;
    cin >> b1 >> b2 >> b3;
    cout << max(b1, b2, b3) << endl;

    // 3. char 类型数据
    char c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    cout << max(c1, c2, c3) << endl;

    // 4. string 类型数据
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << max(s1, s2, s3) << endl;

    // 5. Rectangle 类型数据 (输入格式：x,y)
    Rectangle r1, r2, r3;
    char co;
    cin >> r1.x >> co >> r1.y >> r2.x >> co >> r2.y >> r3.x >> co >> r3.y;
    Rectangle r = max(r1, r2, r3);
    r.print();
    cout << endl;

    // 6. Rectangle* 类型数据 (输入格式：x,y)
    int r1_x, r1_y, r2_x, r2_y, r3_x, r3_y;
    cin >> r1_x >> co >> r1_y >> r2_x >> co >> r2_y >> r3_x >> co >> r3_y;
    Rectangle* ptr1 = new Rectangle(r1_x, r1_y);
    Rectangle* ptr2 = new Rectangle(r2_x, r2_y);
    Rectangle* ptr3 = new Rectangle(r3_x, r3_y);
    Rectangle* ptr = max(ptr1, ptr2, ptr3);
    ptr->print();
    cout << endl;

    // 删除动态分配的内存
    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}
