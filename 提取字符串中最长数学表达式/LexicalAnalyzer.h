#ifndef __LEXICAL_ANALYZER__
#define __LEXICAL_ANALYZER__

#define DEBUG

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class LexicalAnalyzer
{
private:
    string input_str;
    vector<string> exprs;
    int max_expr_idx = 0;
    string max_expr;
    stack<long> numbers;
    stack<char> ops;

    // 是否为操作符
    inline bool is_op(const char& c) const
    {
        return c == '+' || c == '-' || c == '*';
    }
    // 是否为数字
    inline bool is_digit(const char& c) const
    {
        return c >= '0' && c <= '9';
    }
    // 是否为其他字符
    bool is_other(const char& c) const;
    // 字符预处理
    void pre_process_str();
    // 找到最长的表达式
    void find_max_op();
    // 处理表达式字符串
    void process_expr();
public:
    LexicalAnalyzer(string&);
    ~LexicalAnalyzer() = default;
    // 获取最终结果
    long get_max_expr_value(const string& str);
    inline string get_max_expr() const
    {
        return max_expr;
    }
};
#endif // !__LEXICAL_ANALYZER__

