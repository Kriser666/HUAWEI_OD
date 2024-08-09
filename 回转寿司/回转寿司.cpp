// 回转寿司.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述
//寿司店周年庆，正在举办优惠活动回馈新老客户寿司转盘上总共有n盘寿司，prices[i] 是第 i 盘寿司的价格，如果客户选择了第 i盘寿司，寿司店免费赠送客户距离第 i 盘寿司最近的下一盘寿司 j，前提是prices[j] < prices[i]，如果没有满足条件的 j，则不赠送寿司。
//每个价格的寿司都可无限供应。
//输入
//输入的每一个数字代表每盘寿司的价格，每盘寿司的价格之间使用空格分隔
//寿司的盘数 n范围为 : 1 <= n <= 500
//输出
//输出享受优惠后的一组数据，每个值表示客户选择第 i 盘寿司时实际得到的寿司的总价格。使用空格进行分隔。

#define DEBUG

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

static void find_lowest_sum_price(const vector<int>& prices, vector<int>& sum_prices)
{
    size_t n = prices.size();
    for (int i = 0; i < n; ++i)
    {
        int j = i;
        while (j < n + i)
        {
            if (prices[i] > prices[j % n])
            {
                sum_prices[i] += prices[j % n];
                break;
            }
            ++j;
        }
    }
}

int main()
{
    vector<int> prices;
#ifdef DEBUG
    cout << "输入价格：" << endl;
#endif // DEBUG
    
    string input_line;
    getline(cin, input_line);
    istringstream iss(input_line);
    int n;
    while (iss >> n)
    {
        prices.push_back(n);
    }
    
    vector<int> sum_prices(prices);
    find_lowest_sum_price(prices, sum_prices);
#ifdef DEBUG
    cout << "每个盘子对应的原始总价格为：" << endl;
#endif // DEBUG

    for (int& sum_price : sum_prices)
    {
        cout << sum_price << ' ';
    }
    cout << endl;
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
