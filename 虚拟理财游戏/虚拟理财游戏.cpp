// 虚拟理财游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述
//在一款虚拟游戏中生活，你必须进行投资以增强在虚拟游戏中的资产以免被淘汰出局。现有一家 Bank，它提供有若干理财产品 m，风险及投资回报不同，你有 N（元）进行投资，能接受的总风险值为 X。
//你要在可接受范围内选择最优的投资方式获得最大回报。
//说明：
//1、在虚拟游戏中，每项投资风险值相加为总风险值；
//2、在虚拟游戏中，最多只能投资 2 个理财产品；
//3、在虚拟游戏中，最小单位为整数，不能拆分为小数； 投资额 * 回报率 = 投资回报
//输入
//第一行：产品数(取值范围[1, 20])，总投资额(整数，取值范围[1, 10000])，可接受的总风险(整数，取值范围[1, 200])
//第二行：产品投资回报率序列，输入为整数，取值范围[1, 60]
//第三行：产品风险值序列，输入为整数，取值范围[1, 100]
//第四行：最大投资额度序列，输入为整数，取值范围[1, 10000]
//输出
//每个产品的投资额序列

#define DEBUG

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

using namespace std;

static pair<size_t, int> find_nth_largest(const vector<int>& vec, const int n)
{
    vector<int> temp = vec;
    auto n_pos = temp.begin() + (temp.size() - n);
    nth_element(temp.begin(), n_pos, temp.end(), [](int a, int b) {return a < b; });
    int value = *n_pos;
    auto n_it = find_if(vec.begin(), vec.end(), [value](int x) { return x == value; });
    if (n_it != vec.end())
    {
        return { distance(vec.begin(), n_it), value };
    }
    return { static_cast<size_t>(0), -1};
}

class Virtual_game
{
private:
    // 产品数
    int product_num;
    // 总投资额
    int total_investment;
    // 可接受的总风险
    int total_risk;
    // 产品投资回报率序列
    unique_ptr<vector<int>> rate_of_returns;
    // 产品风险值序列
    unique_ptr<vector<int>> risks;
    // 产品最大投资额度序列
    unique_ptr<vector<int>> investments;

public:
    Virtual_game(int, int, int);

    void find_max_returns();
};

int main()
{
#ifdef DEBUG
    cout << "输入产品数(1, 20)，总投资额(1, 10000)，可接受的总风险(1, 200)：" << endl;
#endif // DEBUG
    int product_num, total_investment, total_risk;
    cin >> product_num >> total_investment >> total_risk;

    Virtual_game virtual_game(product_num, total_investment, total_risk);

    virtual_game.find_max_returns();
    return 0;
}

Virtual_game::Virtual_game(int prod_num, int total_inv, int total_ris)
    :product_num(prod_num), total_investment(total_inv), total_risk(total_ris), 
    rate_of_returns(make_unique<vector<int>>(prod_num)), risks(make_unique<vector<int>>(prod_num)), investments(make_unique<vector<int>>(prod_num))
{
#ifdef DEBUG
    cout << "Virtual_game类初始化" << endl;
#endif // DEBUG
#ifdef DEBUG
    cout << "输入产品投资回报率序列(1，60)：" << endl;
#endif // DEBUG
    for (int i = 0; i < product_num; ++i)
    {
        cin >> (*rate_of_returns)[i];
    }
#ifdef DEBUG
    cout << "输入产品风险值序列(1，100)：" << endl;
#endif // DEBUG
    for (int i = 0; i < product_num; ++i)
    {
        cin >> (*risks)[i];
    }
#ifdef DEBUG
    cout << "输入最大投资额度序列(1，10000)：" << endl;
#endif // DEBUG
    for (int i = 0; i < product_num; ++i)
    {
        cin >> (*investments)[i];
    }
#ifdef DEBUG
    cout << "Virtual_game类初始化完成" << endl;
#endif // DEBUG
}

void Virtual_game::find_max_returns()
{
    pair<size_t, int> max_return_rate;
    pair<size_t, int> sec_return_rate;
    bool find = false;
    // 计算出每一项的总回报
    vector<int> last_inv(product_num);
    for (size_t i = 0; i < product_num; ++i)
    {
        last_inv[i] = rate_of_returns->at(i) * investments->at(i);
    }
    for (int i = 1; i < product_num; ++i)
    {
        if (!find)
        {
            // 先找到最大的两个回报的索引
            max_return_rate = find_nth_largest(last_inv, i);
            for (int j = i; j < product_num; ++j)
            {
                sec_return_rate = find_nth_largest(last_inv, j + 1);
                // 尝试给这两个索引处的产品进行最大投资额度
                int cur_total_investments = investments->at(max_return_rate.first) + investments->at(sec_return_rate.first);
                // 如果当前总投资额超过上限，那就继续循环
                if (cur_total_investments > total_investment)
                {
                    continue;
                }
                // 计算当前总风险
                int cur_total_risk = risks->at(max_return_rate.first) + risks->at(sec_return_rate.first);
                // 如果当前总风险没有超过可接受总风险，就直接跳出
                if (cur_total_risk <= total_risk)
                {
                    find = true;
                    break;
                }
            }
        }
    }
    
    if (find)
    {
        for (int i = 0; i < product_num; ++i)
        {
            if (max_return_rate.first == i)
            {
                cout << investments->at(max_return_rate.first) << ' ';
            }
            else if (sec_return_rate.first == i)
            {
                cout << investments->at(sec_return_rate.first) << ' ';
            }
            else
            {
                cout << 0 << ' ';
            }
        }
    }
    else
    {
        cout << "未找到最大回报！" << endl;
    }
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