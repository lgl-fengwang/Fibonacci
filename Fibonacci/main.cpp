#include <iostream>
#include <cmath>
#include <Windows.h>
#include <ctime>
#include <climits>

using namespace std;

unsigned long long fibonacciRecursion(int n); //递归求解斐波那契数列
unsigned long long fibonacciRecursive(int n); //递推求解斐波那契数列
unsigned long long fibonacciGeneral(int n); //通项公式求解斐波那契数列

int main() {
    SetConsoleTitle("Fibonacci");
    clock_t startTime;
    clock_t endTime;
    double after;
    cout << "斐波那契数列" << endl;
    cout << "第几项:";
    int item;
    cin >> item;
    long long answer;

    cout << "CPU一秒钟内的时钟计时单元:" << CLOCKS_PER_SEC << endl;
    cout << "unsigned long long数据类型最大值:" << ULLONG_MAX << endl;

    startTime = clock();
    answer = fibonacciRecursion(item);
    endTime = clock();
    after = (endTime - startTime) * 1.0 / CLOCKS_PER_SEC;
    cout << "递归解:" << answer << " 用时:" << after << "s" << endl;

    startTime = clock();
    answer = fibonacciRecursive(item);
    endTime = clock();
    after = (endTime - startTime) * 1.0 / CLOCKS_PER_SEC;
    cout << "递推解:" << answer << " 用时:" << after << "s" << endl;

    startTime = clock();
    answer = fibonacciGeneral(item);
    endTime = clock();
    after = (endTime - startTime) * 1.0 / CLOCKS_PER_SEC;
    cout << "通项公式解:" << answer << " 用时:" << after << "s" << endl;

    cin.get();
    cin.get();
    return 0;
}

unsigned long long fibonacciRecursion(int n) {
    if (n < 2) {
        return n == 0 ? 0 : 1;
    }
    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

unsigned long long fibonacciRecursive(int n) {
    unsigned long long temp1 = 0;
    unsigned long long temp2 = 1;
    unsigned long long val;
    if (n < 2) {
        return n == 0 ? temp1 : temp2;
    }
    for (int i = 1; i < n; ++i) {
        val = temp1 + temp2;
        temp1 = temp2;
        temp2 = val;
    }
    return val;
}

unsigned long long fibonacciGeneral(int n) {
    return 1 / sqrt(5) * (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n));
}