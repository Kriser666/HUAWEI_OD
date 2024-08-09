// 最长子字符串的长度（一）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述
//给你一个字符串 s，首尾相连成一个环形，请你在环中找出'。'字符出现了偶数次最长子字符串的长度。
// 
//输入描述
//输入是一个小写字母组成的字符串
// 
//输出描述
//输出是一个整数
// 
//备注
//1 <= s.length <= 500000
//s只包含小写英文字母

#include <iostream>
#include <string>
#include <unordered_map>  
#include <algorithm>

using namespace std;

static int count_ch(string& str, char ch)
{
    int count = 0;
    for (char temp : str)
    {
        if (temp == ch)
        {
            ++count;
        }
    }
    return count;
}

static int find_substr_max_length_include_ch(string& str, char ch)
{
    cout << "当前处理的字符串为：" << str << endl;
    // 统计字符串中字符ch出现的次数
    int count = count_ch(str, ch);
    if (count == 0 || count == 1)
    {
        return 0;
    }
    int max_length = 1;
    // 出现偶数次，那么最长字串就是自己本身
    if (count % 2 == 0)
    {
        max_length = str.length();
    }
    else
    {
        // 出现奇数次count，那么需要寻找包含count - 1的最长字串，即到最后一个ch之前的子字符串
        auto begin = str.begin();
        auto end = str.end();
        int cur_substr_count_ch = 0;
        while (begin != end)
        {
            // 当前字符为ch且当前ch的数量为ch计数减1
            if ((*begin == ch) && (cur_substr_count_ch == count - 1))
            {
                --max_length;
                cout << "命中条件，当前遍历字符为" << *begin << "，max_length应该取上一个字符的长度，为" << max_length << endl;
                break;
            }
            // 下一个字符为ch且当前ch的数量为ch计数减1
            if ((begin + 1 != end) && ((*(begin + 1) == ch)) && (cur_substr_count_ch == count - 1))
            {
                cout << "命中条件，当前遍历字符为" << *begin << "，max_length为" << max_length << endl;
                break;
            }
            cout << "当前遍历字符为" << *begin << "，max_length为" << max_length << endl;
            if (*begin == ch)
            {
                ++cur_substr_count_ch;
            }
            ++max_length;
            ++begin;
        }
    }
    return max_length;
}

static size_t findMaxLength(string str, char ch) {  
    
    int maxLength = 0;  
    // 统计字符串中字符ch出现的次数
    int count = count_ch(str, ch);
    // 出现偶数次，那么最长字串就是自己本身
    if (count % 2 == 0)
    {
        return str.size();
    }
    // 出现奇数次，那么最长子串为本身-1（因为是循环，所以ch可以移动到最后一个位置，那么该ch之前的所有就是ch出现偶数次的最长子串）
    else
    {
        return str.size() - 1;
    }
  
    return maxLength;  
}
int main()
{
    string str = {};
    cout << "请输入字符串：" << endl;
    cin >> str;
    char ch = '\0';
    cout << "请输入想要统计的字符：" << endl;
    cin >> ch;

    //int max_length = find_substr_max_length_include_ch(str, ch);
    //// 循环其余字符串
    //for (int i = 0; i < str.length() - 1; ++i)
    //{
    //    cout << endl << endl << endl;
    //    rotate(str.begin(), str.begin() + 1, str.end());
    //    max_length = max(find_substr_max_length_include_ch(str, ch), max_length);
    //}
    int max_length = findMaxLength(str, ch);
    cout << "包含字符" << ch << "的最长子字串长度为：" << max_length << endl;
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
