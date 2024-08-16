// 内存冷热标记.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述
//现代计算机系统中通常存在多级的存储设备，针对海量workload的优化的一种思路是将热点内存页优先放到快速存储层级，这就需要对内存页进行冷热标记。
//一种典型的方案是基于内存页的访问频次进行标记，如果统计窗口内访问次数大于等于设定阈值，则认为是热内存页，否则是冷内存页。
//对于统计窗口内跟踪到的访存序列和阈值，现在需要实现基于频次的冷热标记。内存页使用页框号作为标识。
//输入
//第一行为输入为N，表示访存序列的记录条数，0 < N < 10000。
//第二行为访存序列，空格间隔的N个内存页框号，页框号范围0 - 65535，同一页框号可能重复出现，出现的次数即为对应页框号的频次。
//第三行为热内存页的频次阈值T，正整数，范围1 < T < 10000
//输出
//第一行输出标记为热内存的内存页个数，如果没有被标记为热内存的，则输出0。
//如果第一行>0，则接下来按照访问频次降序输出内存页框号，一行一个，频次一样的页框号，页框号小的排前面。

#define DEBUG

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
#ifdef DEBUG
    cout << "输入访存序列的记录条数：" << endl;
#endif // DEBUG
    int n;
    cin >> n;
#ifdef DEBUG
    cout << "输入访存序列，空格间隔，页框号范围0 - 65535：" << endl;
#endif // DEBUG
    map<int, int> mem_count;
    vector<int> mem(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> mem[i];
    }
#ifdef DEBUG
    cout << "输入热阈值：" << endl;
#endif // DEBUG
    int threshold;
    cin >> threshold;
    for (auto& i : mem)
    {
        auto it = mem_count.find(i);
        if (it != mem_count.end())
        {
            ++mem_count[i];
        }
        else
        {
            mem_count.insert({ i, 1 });
        }
    }
    // 根据热阈值去除不满足条件的键值对
    vector<int> to_erase_key;
    for (auto& pair_t : mem_count)
    {
        if (pair_t.second < threshold)
        {
            to_erase_key.push_back(pair_t.first);
        }
    }
    for (auto& i : to_erase_key)
    {
        mem_count.erase(i);
    }

    // 按访问次数降序排序
    vector<pair<int, int>> v_mem_count;
    for (auto& pair_t : mem_count)
    {
        v_mem_count.push_back(pair_t);
    }
    stable_sort(v_mem_count.begin(), v_mem_count.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; });
#ifdef DEBUG
    cout << "标记为热内存的内存页的个数为：";
#endif // DEBUG
    cout << v_mem_count.size() << endl;
#ifdef DEBUG
    cout << "页框号分别为：" << endl;
#endif // DEBUG
    for (auto& pair_t : v_mem_count)
    {
        cout << pair_t.first << endl;
    }
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
