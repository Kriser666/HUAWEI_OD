// 智能成绩表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述
//小明来到某学校当老师，需要将学生按考试总分或单科分数进行排名，你能帮帮他吗？
//输入
//第1行输入两个整数，学生人数n和科目数量m。0 < n < 100，0 < m < 10
//第2行输入m个科目名称，彼此之间用空格隔开，科目名称只由英文字母构成，单个长度不超过10个字符。
//科目的出现顺序和后续输入的学生成绩一一对应。不会出现重复的科目名称。
//第3行开始的行，每行包含一个学生的姓名和该生m个科目的成绩，空格隔开，学生不会重名。 学生姓名只由英文字母构成，长度不超过10个字符。
//成绩是0~100的整数，依次对应第2行中输入的科目。
//第n + 2行，输入用作排名的科目名称。 若科目不存在，则按总分进行排序。
//输出
//输出一行，按成绩排序后的学生名字，空格隔开。成绩相同的按照学生姓名字母顺序排序。

#define DEBUG

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#ifdef DEBUG

template<class T>
void print_vec(const vector<T>& vec)
{
    for (const T& t : vec)
    {
        cout << t << ' ';
    }
    cout << endl;
}

#endif // DEBUG

static void sort_students_by_subject_score(vector<pair<string, vector<int>>>& stu_scores, int idx)
{
    // 稳定排序
    stable_sort(stu_scores.begin(), stu_scores.end(), [idx](const pair<string, vector<int>>& a, const pair<string, vector<int>>& b) {
        if (a.second[idx] != b.second[idx])
            return a.second[idx] > b.second[idx];
        else
            return a.first < b.first;
        });
}

static void sort_students_by_total_score(vector<pair<string, vector<int>>>& stu_scores)
{
    stable_sort(stu_scores.begin(), stu_scores.end(), [](const pair<string, vector<int>>& a, const pair<string, vector<int>>& b) {
        int sum_a = 0, sum_b = 0;
        for (int score : a.second) sum_a += score;
        for (int score : b.second) sum_b += score;
        if (sum_a != sum_b)
            return sum_a > sum_b;
        else
            return a.first < b.first;
        });
}

int main()
{
    int n, m;
#ifdef DEBUG
    cout << "输入学生人数n和科目数量m。0 < n < 100，0 < m < 10：" << endl;
#endif // DEBUG
    cin >> n >> m;

    // 科目数组
    vector<string> subjects(m);
#ifdef DEBUG
    cout << "输入" << m << "个课程名：" << endl;
#endif // DEBUG
    for (int i = 0; i < m; ++i)
    {
        cin >> subjects[i];
    }

    // 分数数组
    vector<int> scores(m);
    vector<pair<string, vector<int>>> student_scores;
#ifdef DEBUG
    cout << "请输入学生姓名和科目成绩：" << endl;
#endif // DEBUG

    for (int i = 0; i < n; ++i)
    {
        string name;
        cin >> name;
        for (int j = 0; j < m; ++j)
        {
            cin >> scores[j];
        }
        student_scores.push_back({ name, scores });
    }

#ifdef DEBUG
    cout << "请输入要排序的科目：" << endl;
#endif // DEBUG

    string subject;
    cin >> subject;

    // 寻找科目
    int idx_of_subject = -1;
    for (int i = 0; i < m; ++i)
    {
        if (subject == subjects[i])
        {
            idx_of_subject = i;
            break;
        }
    }

    // 未找到科目
    if (idx_of_subject == -1)
    {
        sort_students_by_total_score(student_scores);

    }
    // 找到科目
    else
    {
        sort_students_by_subject_score(student_scores, idx_of_subject);
    }
#ifdef DEBUG
    cout << "排序后：" << endl;
#endif // DEBUG

    for (const auto& stu_score : student_scores)
    {
        cout << stu_score.first << ' ';
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
