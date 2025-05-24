#include <iostream>
#include <array>

class Matrix4x4 {
private:
    float data[4][4];  // 存储矩阵的二维数组

public:
    // 默认构造函数，接受标准输入的16个值
    Matrix4x4() {
        std::cout << "Enter 16 values for the matrix:" << std::endl;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                std::cin >> data[i][j];
    }

    // 接受数组的构造函数
    Matrix4x4(const std::array<float, 16>& values) {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                data[i][j] = values[i * 4 + j];
    }

    // 矩阵加法
    Matrix4x4 operator+(const Matrix4x4& other) const {
        Matrix4x4 result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // 矩阵乘法
    Matrix4x4 operator*(const Matrix4x4& other) const {
        Matrix4x4 result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < 4; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        return result;
    }

    // 打印矩阵
    void print() const {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
    }

    // += 操作符
    Matrix4x4& operator+=(const Matrix4x4& other) {
        *this = *this + other;
        return *this;
    }

    // 下标操作符，用于修改矩阵元素
    float& operator()(int row, int column) {
        return data[row][column];
    }

    // 常量下标操作符，用于访问矩阵元素
    float operator()(int row, int column) const {
        return data[row][column];
    }
};

