// 提取字符串中最长数学表达式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述：
//提取字符串中的最长合法简单数学表达式，字符串长度最长的，并计算表达式的值。
//如果没有，则返回0。简单数学表达式只能包含以下内容：0 - 9数字，符号 + -*
//说明：
//1. 所有数字，计算结果都不超过long
//2. 如果有多个长度一样的，请返回第一个表达式的结果
//3. 数学表达式，必须是最长的，合法的
//4. 操作符不能连续出现，如 + -- + 1 是不合法的
//输入：
//字符串
//输出：
//表达式值

#include <iostream>  
#include <string>
#include "LexicalAnalyzer.h"
using namespace std;

int main() {
    string input;
#ifdef DEBUG
    cout << "Enter the string: ";
#endif // DEBUG
    cin >> input;
    LexicalAnalyzer lexicalAnalyzer(input);
    long value = lexicalAnalyzer.get_max_expr_value(input);
#ifdef DEBUG
    cout << "最长表达式为：" << lexicalAnalyzer.get_max_expr() << endl;
    cout << "值为：";
#endif // DEBUG
    cout << value;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
