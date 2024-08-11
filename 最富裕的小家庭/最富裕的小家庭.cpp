// 最富裕的小家庭.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述：
//在一棵树中，每个节点代表一个家庭成员，节点的数字表示其个人的财富值，一个节点及其直接相连的子节点被定义为一个小家庭。
//现给你一棵树，请计算出最富裕的小家庭的财富和。
//输入：
//第一行为一个数N，表示成员总数，成员编号1 - N，1 <= N <= 1000
//第二行为N个空格分隔的数，表示编号1 - N的成员的财富值，0 <= 财富值 <= 1000000
//接下来N - 1行，每行两个空格分隔的整数(N1, N2)，表示N1是N2的父节点。
//输出：
//最富裕的小家庭的财富和

#define DEBUG

#include <iostream>
#include <vector>

using namespace std;

static int find_wealthiest_family(const vector<vector<int>>& matrix, const vector<int> wealths)
{
    int wealthiest_family = 0;
    for(int i = 0; i < matrix.size(); ++i)
    {
        // 先初始化家庭财富为这个人的财富
        int wealth_family = wealths[i];
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            // 从matrix数组找到直接相连的子节点的索引，并通过wealths找到财富值
            wealth_family += wealths[matrix[i][j]];
        }
        wealthiest_family = wealthiest_family > wealth_family ? wealthiest_family : wealth_family;
    }
    return wealthiest_family;
}

int main()
{
#ifdef DEBUG
    cout << "输入成员总数N：" << endl;
#endif // DEBUG
    int n;
    cin >> n;
#ifdef DEBUG
    cout << "输入N个空格分隔的数，表示编号1 - N的成员的财富值：" << endl;
#endif // DEBUG
    vector<int> wealth(n);
    for (int& i_t : wealth)
    {
        cin >> i_t;
    }
#ifdef DEBUG
	cout << "接下来N - 1行，每行两个空格分隔的整数N1, N2，表示N1是N2的父节点：" << endl;
#endif // DEBUG
    // 采用邻接表方法
    vector<vector<int>> tree_matrix(n, vector<int>());
    // 哪一行的索引代表哪个节点，后面的元素为其直接相连的子节点
    for (int i = 1; i < n; ++i)
    {
        size_t father_idx, son_idx;
        cin >> father_idx >> son_idx;
        try
        {
            if (son_idx > n || son_idx < 0)
            {
                cerr << "N2不在成员数范围内！" << endl;
            }
            tree_matrix.at(father_idx - 1).push_back(static_cast<int>(son_idx - 1));
        }
        catch (const std::out_of_range&)
        {
            cerr << "N1不在成员数范围内！" << endl;
        }
    }
#ifdef DEBUG
    cout << "最富裕的小家庭的财富和：" << endl;
#endif // DEBUG
    int weathiest_family = find_wealthiest_family(tree_matrix, wealth);
    cout << weathiest_family << endl;
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
