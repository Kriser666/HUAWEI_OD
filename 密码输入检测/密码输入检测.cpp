// 密码输入检测.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述：
//给定用户密码 输入流 input，输入流中字符'<'表示退格，可以清除前一个输入的字符，请你编写程序，
//输出最终得到的密码字符，并判断密码是否满足如下的密码安全要求。
//密码安全要求如下：
//1.密码长度≥8;
//2.密码至少需要包含1个大写字母；
//3.密码至少需要包含1个小写字母；
//4.密码至少需要包含1个数字；
//5.密码至少需要包含1个字母和数字以外的非空白特殊字符；
//注意空串退格后仍然为空串，且用户输入的字符串不包含'<'字符和空白字符。
//输入描述：
//用一行字符串表示输入的用户数据，输入的字符串中'<'字符标识退格，用户输入的字符串不包含空白字符，例如:
//ABC<c89%000<
//输出描述：
//输出经过程序处理后，输出的实际密码字符串，并输出改密码字符串是否满足密码安全要求。两者间由','分隔，例如:
//ABc89%00, true

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <stack>
using namespace std;

static void process_passwd(string& passwd)
{
    stack<char> processed_passwd;
    for (char t : passwd)
    {
        if (t == '<')
        {
            if (!processed_passwd.empty())
            {
                processed_passwd.pop();
            }
            continue;
        }
        processed_passwd.push(t);
    }
    passwd.clear();
    ostringstream os;
    while (!processed_passwd.empty())
    {
         os << processed_passwd.top();
         processed_passwd.pop();
    }
    passwd = os.str();
    reverse(passwd.begin(), passwd.end());
}

static void check_passwd(const string &passwd, unordered_map<int, bool> &roles)
{
    roles[1] = passwd.size() >= 8;
    for (char ch : passwd)
    {
        if (roles[2] != true)
        {
            roles[2] = ch >= 'A' && ch <= 'Z';
        }
        if (roles[3] != true)
        {
            roles[3] = ch >= 'a' && ch <= 'z';
        }
        if (roles[4] != true)
        {
            roles[4] = ch >= '0' && ch <= '9';
        }
        if (roles[5] != true)
        {
            roles[5] = (ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 63) && ch != '<';
        }
    }
}

int main()
{
    cout << "输入密码，<表示退格：" << endl;
    string passwd;
    cin >> passwd;
    process_passwd(passwd);
    cout << "处理后的密码：" << passwd << ", ";
    unordered_map<int, bool> roles = { {1, false}, {2, false}, {3, false}, {4, false}, {5, false} };
    check_passwd(passwd, roles);
    if (roles[1] == roles[2] == roles[3] == roles[4] == roles[5] == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
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
