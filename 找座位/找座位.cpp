// 找座位.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述：
//在一个大型体育场内举办了一场大型活动，由于疫情防控的需要，要求每位观众都必须间隔至少一个空位才允许落座。
//现在给出一排观众座位分布图，座位中存在已落座的观众，请计算出，在不移动现有观众座位的情况下，最多还能坐下多少名观众。
//输入描述：
//一个数组，用来标识某一排座位中，每个座位是否已经坐人。0表示该座位没有坐人，1表示该座位已经坐。
//1≤数组长度≤10000
//输出描述：
//整数，在不移动现有观众座位的情况下，最多还能坐下多少名观众。

#include <iostream>
#include <string>

using namespace std;


static int max_man(const string &seats)
{
    size_t n = seats.size();
    int count = 0;

    string temp_seats(seats);
    // 遍历每个空位  
    for (int i = 0; i < n; ++i) 
    {
        if (temp_seats[i] == '0')
        {
            // 检查左侧（注意边界条件）  
            bool leftValid = (i == 0) || (temp_seats[i - 1] == '0');
            // 检查右侧（注意边界条件）  
            bool rightValid = (i == n - 1) || (temp_seats[i + 1] == '0');

            // 如果左右两侧中至少有一侧是已坐人的座位或者是边界，则可以放置新观众  
            if (leftValid && rightValid) 
            {
                temp_seats[i] = '1'; 
                ++count;
            }
        }
    }

    return count;
}

int main()
{
    cout << "输入座位，1代表坐人了，0代表没坐人：";
    string seats;
    cin >> seats;
    int max_man_num = max_man(seats);

    cout << endl << "最大可坐个数：" << max_man_num;
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
