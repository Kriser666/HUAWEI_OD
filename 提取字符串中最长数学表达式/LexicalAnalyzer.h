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

    // �Ƿ�Ϊ������
    inline bool is_op(const char& c) const
    {
        return c == '+' || c == '-' || c == '*';
    }
    // �Ƿ�Ϊ����
    inline bool is_digit(const char& c) const
    {
        return c >= '0' && c <= '9';
    }
    // �Ƿ�Ϊ�����ַ�
    bool is_other(const char& c) const;
    // �ַ�Ԥ����
    void pre_process_str();
    // �ҵ���ı��ʽ
    void find_max_op();
    // ������ʽ�ַ���
    void process_expr();
public:
    LexicalAnalyzer(string&);
    ~LexicalAnalyzer() = default;
    // ��ȡ���ս��
    long get_max_expr_value(const string& str);
    inline string get_max_expr() const
    {
        return max_expr;
    }
};
#endif // !__LEXICAL_ANALYZER__

