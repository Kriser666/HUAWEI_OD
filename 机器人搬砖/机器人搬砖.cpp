// 机器人搬砖.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述
//机器人搬砖，一共有N堆砖存放在N个不同的仓库中，第i堆砖中有bricks[i]块砖头，要求在8小时内搬完。机器人每小时能搬砖的数量取决于有多少能量格，机器人一个小时中只能在一个仓库中搬砖，
//机器人的能量格每小时补充一次且能量格只在这一个小时有效，为使得机器人损耗最小化，尽量减小每次补充的能量格数。
//为了保障在8小时内能完成搬砖任务，请计算每小时给机器人充能的最小能量格数。
//备注 :
//1、无需考虑机器人补充能量格的耗时
//2、无需考虑机器人搬砖的耗时
//3、机器人每小时补充能量格只在这一个小时中有效。
//输入
//程序输入为"30 12 25 8 19"一个整数数组，数组中的每个数字代表第i堆砖的个数，每堆砖的个数不超过100
//输出
//输出在8小时内完成搬砖任务，机器人每小时最少需要充多少个能量格；如果8个小时内无论如何都完成不了任务，则输出"-1"

#define DEBUG

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

constexpr int MAX_ENERGY = 99999999;

static int b_search(vector<int>& bricks, int left, int right)
{
    int lowest_energy = MAX_ENERGY;

    while (left <= right)
    {
        // 采用偏移量法防止大整数溢出
        int mid = left + (right - left) / 2;
        // 计算当前电量能否在8小时内搬完砖
        auto can_move = 
            [bricks](int cur_energy) -> bool 
            {
                // 每小时x电量的情况下搬完所有砖的总次数（总小时数）
                int times_all = 0;
                for (auto& brick : bricks)
                {
                    // 每小时x电量的情况下搬完当前砖块的次数
                    int times = static_cast<double> (brick) / static_cast<double>(cur_energy) - static_cast<double>(brick / cur_energy) > 0.000001 
                        ? brick / cur_energy + 1 : brick / cur_energy;
                    times_all += times;
                }
                return times_all > 8 ? false : true;
            };
        // 8小时内可以搬完，但不一定是最小电量，应该减小每小时的电量，即右边界 = mid - 1
        if (can_move(mid))
        {
            right = mid - 1;
            lowest_energy = mid < lowest_energy ? mid : lowest_energy;
        }
        // 8小时内搬不完，那就应该增大每小时的电量，即左边界 = mid + 1
        else
        {
            left = mid + 1;
        }
    }
    return lowest_energy;
}

static int find_lowest_energy(vector<int>& bricks)
{
    size_t bricks_size = bricks.size();

    // 最大的情况下，每小时搬一个仓库，那大于八个仓库肯定不能用八小时搬完
    if (bricks_size > 8)
    {
        return -1;
    }
    int lowest_num = 1, maxmum_num = 0;
    // 先找vector的最大电量
    for (auto& energy : bricks)
    {
        if (energy > maxmum_num)
        {
            maxmum_num = energy;
        }
    }
    int lowest_energy = b_search(bricks, lowest_num, maxmum_num);
    return lowest_energy;
}

int main()
{
#ifdef DEBUG
    cout << "输入砖块，空格隔开：" << endl;
#endif // DEBUG
    string string_line_temp;
    getline(cin, string_line_temp);
    istringstream iss(string_line_temp);


    vector<int> bricks;
    int num_temp;
    while (iss >> num_temp)
    {
        bricks.push_back(num_temp);
    }

    int lowest_energy = find_lowest_energy(bricks);

#ifdef DEBUG
    cout << "最小的电量为：" << endl;
#endif // DEBUG
    cout << lowest_energy;

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
