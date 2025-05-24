#include <iostream>
#include <array>

class Matrix4x4 {
private:
    float data[4][4];  // �洢����Ķ�ά����

public:
    // Ĭ�Ϲ��캯�������ܱ�׼�����16��ֵ
    Matrix4x4() {
        std::cout << "Enter 16 values for the matrix:" << std::endl;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                std::cin >> data[i][j];
    }

    // ��������Ĺ��캯��
    Matrix4x4(const std::array<float, 16>& values) {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                data[i][j] = values[i * 4 + j];
    }

    // ����ӷ�
    Matrix4x4 operator+(const Matrix4x4& other) const {
        Matrix4x4 result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // ����˷�
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

    // ��ӡ����
    void print() const {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
    }

    // += ������
    Matrix4x4& operator+=(const Matrix4x4& other) {
        *this = *this + other;
        return *this;
    }

    // �±�������������޸ľ���Ԫ��
    float& operator()(int row, int column) {
        return data[row][column];
    }

    // �����±�����������ڷ��ʾ���Ԫ��
    float operator()(int row, int column) const {
        return data[row][column];
    }
};

