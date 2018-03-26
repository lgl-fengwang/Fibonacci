#include <iostream>
#include <cmath>
#include <Windows.h>
#include <ctime>
#include <climits>

using namespace std;

unsigned long long fibonacciRecursion(int n); //�ݹ����쳲���������
unsigned long long fibonacciRecursive(int n); //�������쳲���������
unsigned long long fibonacciGeneral(int n); //ͨ�ʽ���쳲���������

int main() {
    SetConsoleTitle("Fibonacci");
    clock_t startTime;
    clock_t endTime;
    double after;
    cout << "쳲���������" << endl;
    cout << "�ڼ���:";
    int item;
    cin >> item;
    long long answer;

    cout << "CPUһ�����ڵ�ʱ�Ӽ�ʱ��Ԫ:" << CLOCKS_PER_SEC << endl;
    cout << "unsigned long long�����������ֵ:" << ULLONG_MAX << endl;

    startTime = clock();
    answer = fibonacciRecursion(item);
    endTime = clock();
    after = (endTime - startTime) * 1.0 / CLOCKS_PER_SEC;
    cout << "�ݹ��:" << answer << " ��ʱ:" << after << "s" << endl;

    startTime = clock();
    answer = fibonacciRecursive(item);
    endTime = clock();
    after = (endTime - startTime) * 1.0 / CLOCKS_PER_SEC;
    cout << "���ƽ�:" << answer << " ��ʱ:" << after << "s" << endl;

    startTime = clock();
    answer = fibonacciGeneral(item);
    endTime = clock();
    after = (endTime - startTime) * 1.0 / CLOCKS_PER_SEC;
    cout << "ͨ�ʽ��:" << answer << " ��ʱ:" << after << "s" << endl;

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