// 螺旋数字矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述：
//疫情期间，小明隔离在家，百无聊赖，在纸上写数字玩。
//他发明了一种写法：给出数字个数n和行数m(0 < n < 999，0 < m < 999)，从左上角的1开始，按照顺时针螺旋向内写方式，依次写出2, 3, ..., n，最终形成一个m行矩阵。
//小明对这个矩阵有些要求：
//1. 每行数字的个数一样多
//2. 列的数量尽可能少
//3. 填充数字时优先填充外部
//4. 数字不够时，使用单个 * 号占位
//输入：
//两个整数，空格隔开，依次表示n、m
//输出：
//符合要求的唯一短阵

#define DEBUG

#include <iostream>
#include <vector>

using namespace std;

// 输出
template<class T>
void print_matrix(const vector<vector<T>>& matrix)
{
    for (const auto& vec_t : matrix)
    {
        for (const T& T_t : vec_t)
        {
            cout << T_t << ' ';
        }
        cout << endl;
    }
}
template<>
void print_matrix(const vector<vector<int>>& matrix)
{
	for (const auto& vec_t : matrix)
	{
		for (const int& i_t : vec_t)
		{
            if (i_t != 0)
                cout << i_t << ' ';
            else
                cout << '*' << ' ';
		}
		cout << endl;
	}
}

// 填充螺旋矩阵
static void spiral_matrix(vector<vector<int>>& matrix, int n)
{
    int num = 1;
    // 要填充的坐标
    int x = 0;
    int y = 0;
    // 数组各个维度的位数
    size_t mat_max_row = matrix.size();
    size_t mat_max_col = matrix[0].size();
    // 数组总位数
    size_t matrix_size = mat_max_row * mat_max_col;
    // 数字循环
    while (num <= n)
    {
        // 向右走
        while (y < mat_max_col && matrix[x][y] == 0 && num <= n)
        {
            matrix[x][y++] = num++;
        }
        // 调转方向，调整位置
        --y;
        ++x;
        // 向下走
        while (x < mat_max_row && matrix[x][y] == 0 && num <= n)
        {
            matrix[x++][y] = num++;
        }
        // 调转方向，调整位置
        --x;
        --y;
        // 向左走
        while (y > -1 && matrix[x][y] == 0 && num <= n)
        {
			matrix[x][y--] = num++;
        }
		// 调转方向，调整位置
		++y;
		--x;
        // 向上走
        while (x > -1 && matrix[x][y] == 0 && num <= n)
        {
			matrix[x--][y] = num++;
        }
		// 调转方向，调整位置
		++x;
		++y;
    }
}

int main()
{
    int n, m;
#ifdef DEBUG
    cout << "输入数字个数n和行数m：" << endl;
#endif // DEBUG
    cin >> n >> m;
    // 列数为相除的向上取整
    int quotient = n / m;
    int col = (static_cast<double>(n) / static_cast<double>(m)) - static_cast<double>(quotient) > 0.000001 ? (quotient + 1) : (quotient);
    vector<vector<int>> matrix(m, vector<int>(col));
    spiral_matrix(matrix, n);
#ifdef DEBUG
    cout << "结果为：" << endl;
#endif // DEBUG

    print_matrix(matrix);
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
