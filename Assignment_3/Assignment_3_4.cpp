
/*
// 1 
// Computes the nth Fibonacci number using recursion.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(2^n), Space complexity: O(n) due to call stack.
int fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺�ݹ�ʵ�֣�ʱ�临�Ӷ�ΪO(2^n)���ռ临�Ӷ�ΪO(n)�� 
//�ŵ㣺���׶����������٣�ֱ�۵ط�ӳ��Fibonacci���еĶ��塣
//���ó�����������С��ģ���ݡ�
//���﷨/�㷨ϸ�ڣ��ޡ�

// 2 
// Computes the nth Fibonacci number using iteration.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(1).
int fibonacci_iterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺ʹ��ѭ������ݹ飬����ʵ�֣�ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
//�ŵ㣺Ч�ʸߣ�ʱ�临�Ӷȵ͡�
//���ó����������ڴ��ģ���ݡ�
//���﷨/�㷨ϸ�ڣ��ޡ�



//3 
// Computes the nth Fibonacci number using dynamic programming.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(n).
#include <vector>
int fibonacci_dp(int n) {
    if (n <= 1) return n;
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺��̬�滮ʵ�֣�ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(n)��
//�ŵ㣺Ч�ʸߣ�ʱ�临�Ӷȵ͡�
//���ó����������ڴ��ģ���ݡ�
//���﷨/�㷨ϸ�ڣ���̬�滮��



//4 
// Computes the nth Fibonacci number using matrix exponentiation.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(log n), Space complexity: O(1).
#include <array>
std::array<std::array<long long, 2>, 2> matrix_multiply(const
std::array<std::array<long long, 2>, 2>& a, const std::array<std::array<long long,2>, 2>& b) {
    std::array<std::array<long long, 2>, 2> result = {{0}};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                result[i][j] += a[i][k] * b[k][j];
    return result;
}
long long fibonacci_matrix(int n) {
    if (n <= 1) return n;
    std::array<std::array<long long, 2>, 2> base = {{1, 1}, {1, 0}};
    std::array<std::array<long long, 2>, 2> result = {{1, 0}, {0, 1}};
    n--;
    while (n > 0) {
        if (n & 1) result = matrix_multiply(result, base);
        base = matrix_multiply(base, base);
        n >>= 1;
    }
    return result[0][0];
}
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺������ʵ�֣�ʱ�临�Ӷ�ΪO(log n)���ռ临�Ӷ�ΪO(1)��
//�ŵ㣺Ч�ʼ��ߣ�ʱ�临�ӶȺͿռ临�Ӷȵ͡�
//���ó����������ڴ��ģ���ݡ�
//���﷨/�㷨ϸ�ڣ�ʹ���˾������㣬ʹ��array�̶���С���飬ʹ��λ�����Ż���


// 5 
// Computes the nth Fibonacci number using memoization.
// @param n The index of the Fibonacci number to compute.
// @param memo A reference to an unordered_map to store computed Fibonacci numbers.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(n) due to memoization.
#include <unordered_map>
long long fibonacci_memoization(int n, std::unordered_map<int, long long>&memo) {
    if (n <= 1) return n;
    if (memo.find(n) != memo.end()) return memo[n];
    memo[n] = fibonacci_memoization(n - 1, memo) +fibonacci_memoization(n - 2, memo);
    return memo[n];
}
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺���仯�ݹ�ʵ�֣�ʹ�ù�ϣ��洢�м�����ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(n)��
//�ŵ㣺Ч�ʸߣ�ʱ�临�ӶȺͿռ临�Ӷȵ͡�
//���ó������ʺ���Ҫ��μ��㲻ͬn��Fibonacci���ĳ�����
//���﷨/�㷨ϸ�ڣ�ʹ�ü��仯�������������ظ����㣻ʹ��unordered_map�洢�м�����


// 6 
// Computes the nth Fibonacci number safely, returning std::nullopt for negative inputs.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number or std::nullopt if n is negative.
// @note Time complexity: O(n), Space complexity: O(1). 
#include <optional>
std::optional<long long> fibonacci_safe(int n) {
    if (n < 0) return std::nullopt;
    if (n <= 1) return n;
    long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺ʹ��std::optional������Ч���룬ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
//�ŵ㣺Ч�ʸߣ�ʱ�临�ӶȺͿռ临�Ӷȵ͡�
//���ó������ʺ���Ҫ�ϸ�������ĳ�����
//���﷨/�㷨ϸ�ڣ�ʹ����std::optional��


// 7 
// Computes the nth Fibonacci number using constexpr.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(1). 
constexpr long long fibonacci_constexpr(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺ʹ��constexpr�ؼ��֣�ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
//�ŵ㣺�����ڱ����ڼ���Fibonacci�����������ʱЧ�ʡ�
//���ó������ʺ���Ҫ�����ڳ����ĳ�����
//���﷨/�㷨ϸ�ڣ�ʹ����constexpr�ؼ��֡� 


// 8 
// Computes the nth Fibonacci number using parallel execution.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(n) due to async calls.
#include <future>
long long fibonacci_parallel(int n) {
    if (n <= 1) return n;
    auto future = std::async(std::launch::async, fibonacci_parallel, n - 2);
    long long result = fibonacci_parallel(n - 1);
    return result + future.get();
}
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺����ʵ�֣�ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(n)��
//�ŵ㣺�������ö�˴�����������ܡ�
//���ó������ʺϴ��ģ�������ж�˴������ĳ�����
//���﷨/�㷨ϸ�ڣ�ʹ����std::async��std::future��


// 9 
// Computes the nth Fibonacci number using bigint.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(1).
#include <boost/multiprecision/cpp_int.hpp>
boost::multiprecision::cpp_int fibonacci_bigint(int n) {
    if (n <= 1) return n;
    boost::multiprecision::cpp_int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
 return b;
}
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺ʹ��Boost��Ĵ��������ͣ�ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
//�ŵ㣺���Լ���ǳ����Fibonacci�������������
//���ó������ʺ���Ҫ������ģFibonacci���ĳ�����
//���﷨/�㷨ϸ�ڣ�ʹ����Boost���cpp_int���͡� 


// 10 
// Computes the nth Fibonacci number using template metaprogramming.
// @param N The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(1).
template<int N, typename = std::enable_if_t<(N >= 0)>>
struct Fibonacci {
    static constexpr long long value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};
template<>
struct Fibonacci<0> {
    static constexpr long long value = 0;
};
template<>
struct Fibonacci<1> {
    static constexpr long long value = 1;
};
//��ȷ�ԣ���ʵ������ȷ�ġ�
//�ص㣺ʹ��ģ��Ԫ��̣�ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
//�ŵ㣺�ڱ����ڼ���Fibonacci��������ʱ�㿪����
//���ó������ʺ���Ҫ�����ڳ����ĳ�����
//���﷨/�㷨ϸ�ڣ�ʹ��ģ��Ԫ��̡�   
*/


// ��ϵ�����ģ��Ԫ������ʱ����ͱ����ڼ���˫�ع��ܡ� 
// �����������ֽ������������ 
#include <iostream>
class Fibonacci {
public:
    // Runtime calculation
    static long long get(int n) {
        if (n <= 1) return n;
        
        long long a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            long long temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

    // Compile-time calculation
    template<int N>
    static constexpr long long constant() {
        if constexpr (N <= 1) {
            return N;
        } else {
            return constant<N-1>() + constant<N-2>();
        }
    }
};
int main() {
	
	std::cout << "Please choose the calculation method:"<<std::endl;
    std::cout << "1. Runtime calculation"<<std::endl;
    std::cout << "2. Compile-time calculation"<<std::endl;
    
    int choice;
    std::cin >> choice;
    if(std::cin.fail()||(choice!=1&&choice!=2)){
    	std::cout << "Wrong Input"<<std::endl;
    	return -1;
	}
    
	if(choice==1){
		// Runtime computation
		// Runtime calculations can use variables
		std::cout << "Please enter the index of the Fibonacci number to calculate(1-92): ";
	    int n;
	    std::cin>>n;
	    if(std::cin.fail()||n<1||n>92){
    	    std::cout << "Wrong Input"<<std::endl;
    	    return -1;
	    }
        std::cout << "F(" << n << ") = " << Fibonacci::get(n) << std::endl;
	}else{
		// Compile-time computation
		// Compile-time calculations can only use predefined values
		constexpr int N = 10;
        constexpr auto compile_time_result = Fibonacci::constant<N>();
        std::cout << "Compile-time F(" << N << ") = " << compile_time_result << std::endl;
	}
	
    return 0;
}


