// 分配土地.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述：
//从前有个村庄，村民们喜欢在各种田地上插上小旗子，旗子上标识了各种不同的数字。
//某天集体村民决定将覆盖相同数字的最小矩阵形的土地分配给村里做出巨大贡献的村民，
//请问此次分配土地，做出贡献的村民中最大会分配多大面积?
//输入描述：
//第一行输入 m 和 n，m 代表村子的土地的长，n代表土地的宽。
//第二行开始输入地图上的具体标识。
//输出描述：
//此次分配土地，做出贡献的村民中最大会分配多大面积。
//备注：
//旗子上的数字为1~500，土地边长不超过500，未插旗子的土地用0标识。

#define DEBUG

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

constexpr int MAX_LENGTH = 500;

#ifdef DEBUG
    template<class K, class V>
    static void out_map(const unordered_map<K, V>& map)
    {
        for (auto& t : map)
        {
            cout << "{" << t.first << ", " << t.second << "}\t";
        }
        cout << endl;
    }
#endif // DEBUG

static void find_area(const vector<vector<int>>& ground, unordered_map<int, int> &flag_area)
{
    // 遍历二维数组找到所有的棋子存放到{棋子-对应面积}的键值对中
    for (const auto& row : ground)
    {
        for (int t : row)
        {
            if (t != 0)
            {
                // 初始化各个棋子围成的面积为0
                flag_area[t] = 0;
            }
        }
    }
    // 棋子对应的最大行索引
    unordered_map<int, int> max_row(flag_area);
    // 棋子对应的最大列索引
    unordered_map<int, int> max_col(flag_area);
    // 棋子对应的最小行索引
    unordered_map<int, int> min_row(flag_area);
    // 棋子对应的最小列索引
    unordered_map<int, int> min_col(flag_area);
    // 初始化最小的索引为定义的边长的最大值
    for (auto& t : min_col)
    {
        t.second = MAX_LENGTH;
    }
    for (auto& t : min_row)
    {
        t.second = MAX_LENGTH;
    }

    // 遍历二维数组，找到棋子对应的最大/最小的行与列的索引
    for (int i = 0; i < ground.size(); ++i)
    {
        for (int j = 0; j < ground[0].size(); ++j)
        {
            if (ground[i][j] != 0)
            {
                min_col[ground[i][j]] = min(min_col[ground[i][j]], j);
                // 只要找到该棋子的列索引就更新最大索引
                max_col[ground[i][j]] = max(max_col[ground[i][j]], j);
                min_row[ground[i][j]] = min(min_row[ground[i][j]], i);
                // 只要找到该棋子的行索引就更新最大索引
                max_row[ground[i][j]] = max(max_row[ground[i][j]], i);
            }
        }
    }

    #ifdef DEBUG
        cout << "max_row：";
        out_map(max_row);
        cout << "min_row：";
        out_map(min_row);
        cout << "max_col：";
        out_map(max_col);
        cout << "min_col：";
        out_map(min_col);
    #endif // DEBUG

    // 计算各个棋子对应的行与列的距离
    unordered_map<int, int> row;
    unordered_map<int, int> col;
    for (auto& t : max_row)
    {
        row[t.first] = t.second - min_row[t.first] + 1;
    }
    for (auto& t : max_col)
    {
        col[t.first] = t.second - min_col[t.first] + 1;
    }

    // 计算各个棋子对应的围成的面积
    for (auto& t : row)
    {
        flag_area[t.first] = t.second * col[t.first];
    }
}

static int find_max_area(const unordered_map<int, int>& flag_area)
{
    int max_area = 0;
    for (auto& t : flag_area)
    {
        max_area = max(t.second, max_area);
    }
    return max_area;
}

int main()
{
    int row, col;
    cout << "输入长和宽：";
    cin >> row >> col;

    vector<vector<int>> ground(row, vector<int>(col));
    cout << endl << "输入棋子位置：" << endl;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cin >> ground[i][j];
        }
    }

    unordered_map<int, int> flag_area;

    find_area(ground, flag_area);

    int max_area = find_max_area(flag_area);

    cout << "最大的面积为：" << max_area << endl;

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
