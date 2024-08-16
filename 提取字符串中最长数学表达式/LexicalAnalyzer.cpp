#include "LexicalAnalyzer.h"

bool LexicalAnalyzer::is_other(const char& c) const
{
	return !is_op(c) && !is_digit(c);
}

void LexicalAnalyzer::pre_process_str()
{
	// 预处理
	if (input_str[0] == '-' || input_str[0] == '+')
	{
		input_str = '0' + input_str;
	}
	if (input_str[0] == '*')
	{
		input_str = '1' + input_str;
	}
}

void LexicalAnalyzer::find_max_op()
{
	string expr;
	size_t str_length = input_str.size();
	//int idx_of_op = 0;
	for (int i = 0; i < str_length; ++i)
	{
		ostringstream left_str_oss;
		ostringstream op_oss;
		ostringstream right_str_oss;
		bool valid_expr = true;
		// 先找到运算符
		if (is_op(input_str[i]))
		{
			op_oss << input_str[i];
			// 从下一个位置开始往前和后扫描，下一位为非数字和非运算符就进行下一趟循环
			for (int j = i - 1; j > -1; --j)
			{
				if (is_digit(input_str[j]))
				{
					left_str_oss << input_str[j];
				}
				// 连续的运算符
				else if(is_op(input_str[j]))
				{
					valid_expr = false;
					break;
				}
				else
				{
					break;
				}
			}
			for (int j = i + 1; j < str_length; ++j)
			{
				if (is_digit(input_str[j]))
				{
					right_str_oss << input_str[j];
				}
				// 连续的运算符
				else if (is_op(input_str[j]))
				{
					valid_expr = false;
					break;
				}
				else
				{
					break;
				}
			}
			if (valid_expr)
			{
				expr = left_str_oss.str();
				std::reverse(expr.begin(), expr.end());
				expr += op_oss.str();
				expr += right_str_oss.str();
			}
			// 保存当前表达式
			exprs.push_back(expr);
			
		}

	}
	// 寻找最长表达式
	for (int i = 0; i < exprs.size(); ++i)
	{
		max_expr_idx = max_expr_idx >= exprs[i].size() ? max_expr_idx : i;
	}
	max_expr = exprs[max_expr_idx];
}

void LexicalAnalyzer::process_expr()
{
	long value = 0;
	size_t max_size = max_expr.size();
	string num_str;
	ostringstream oss;
	for (int i = 0; i < max_size; ++i)
	{
		// 找到数字（第一个肯定是数字）
		if (is_digit(max_expr[i]))
		{
			oss << max_expr[i];
		}
		if (is_op(max_expr[i]))
		{
			num_str = oss.str();
			// 字符串转为数字
			long num = stol(num_str);
			numbers.push(num);
			ops.push(max_expr[i]);
			oss.str("");
		}
		// 最后一个字符
		if (i == max_size - 1)
		{
			num_str = oss.str();
			// 字符串转为数字
			long num = stol(num_str);
			numbers.push(num);
		}
	}
	// 计算
	while (!ops.empty())
	{
		long top = 0;
		switch (ops.top())
		{
		case '+':
			top = numbers.top();
			numbers.pop();
			value = numbers.top() + top;
			numbers.pop();
			numbers.push(value);
			ops.pop();
			break;
		case '-':
			top = numbers.top();
			numbers.pop();
			value = numbers.top() - top;
			numbers.pop();
			numbers.push(value);
			ops.pop();
			break;
		case '*':
			top = numbers.top();
			numbers.pop();
			value = numbers.top() * top;
			numbers.pop();
			numbers.push(value);
			ops.pop();
			break;
		default:
			break;
		}
	}
}

LexicalAnalyzer::LexicalAnalyzer(string& str):input_str(str)
{
#ifdef DEBUG
	cout << "构造函数调用了" << endl;
#endif // DEBUG

}

long LexicalAnalyzer::get_max_expr_value(const string& str)
{
	pre_process_str();
	find_max_op();
	process_expr();
	return numbers.top();
}
