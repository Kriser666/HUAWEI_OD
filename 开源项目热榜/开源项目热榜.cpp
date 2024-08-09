// 开源项目热榜.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述
//某个开源社区希望将最近热度比较高的开源项目出一个榜单，推荐给社区里面的开发者。对于每个开源项目，开发者可以进行关注(watch)、收藏(star)、fork、提issue、提交合并请求(MR)等。数据库里面统计了每个开源项目关注、收藏、fork、issue、MR 的数量，开源项目的热度根据这 5 个维度的加权求和进行排序。
//H = W( watch ) * #watch + W( star ) * #star + W( fork ) * #fork + W( issure ) * #issure + W( mr ) * #mr
//- H：表示热度值；
//- W( watch )，W( star ) ，W( fork )，W( issure ) ，W( mr )：分别表示 5 个统计维度的权重；
//- #watch ，#star，#fork，#issure，#mr：分别表示 5 个统计维度的统计值。
//榜单按照热度值降序排序，对于热度值相等的，按照项目名字转换为全小写字母后的字典序排序。
//输入
//第一行输入为 N，表示开源项目的个数，0 < N < 100。
//第二行输入为权重值列表，一共 5 个整型值，分别对应关注、收藏、fork、issue、MR 的权重，权重取值 0 < M ≤ 50。
//第三行开始接下来的 N 行为开源项目的统计维度，每一行的格式为：
//name nr_watch nr_star nr_fork nr_issue nr_mr
//其中 name 为开源项目的名字，由英文字母组成，长度 ≤50，其余 5 个整型值分别为该开源项目关注、收藏、fork、issue、MR 的数量，数量取值 0 < nr ≤ 1000。
//输出
//按照热度降序，输出开源项目的名字，对于热度值相等的，按照项目名字转换为全小写字母后的字典序排序

#define DEBUG
#include <iostream>
#include <vector>
#include <map>
using namespace std;

constexpr int MAX_WEIGHT_LENGTH = 5;

static int compute_hot(const vector<int>& weights)
{

}

int main()
{
    int n;
#ifdef DEBUG
    cout << "输入项目个数：" << endl;
#endif // DEBUG
    cin >> n;
    map<string, vector<int>> project_scores;

#ifdef DEBUG
    cout << "输入各个项目的权重：" << endl;
#endif // DEBUG

    for (int i = 0; i < MAX_WEIGHT_LENGTH; ++i)
    {

    }
    
#ifdef DEBUG
    cout << "输入项目 watch star fork issue mr：" << endl;
#endif // DEBUG
    for (int i = 0; i < n; ++i)
    {
        vector<int> scores(n);
        string name;
        cin >> name;
        for (int j = 0; j < MAX_WEIGHT_LENGTH; ++j)
        {
            cin >> scores[j];
        }
        project_scores.insert({ name, scores });
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
