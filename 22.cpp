/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        string s;
        helper(n, n, v, s);
        return v;
    }

    void helper(int left, int right, vector<string> &v, string s)
    {
        // 括号用完了，直接返回
        if (left == 0 && right == 0)
        {
            v.push_back(s);
            return;
        }

        // 如果左括号还有余额，使用一个左括号
        if (left > 0)
            helper(left - 1, right, v, s + "(");

        // 如果右括号还有余额，使用一个右括号
        // 需要保证 s 当前左括号个数 > 右括号个数
        // 所以，转换为 左括号余额个数 < 右括号余额个数
        if (right > 0 && left < right)
            helper(left, right - 1, v, s + ")");
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> v = s.generateParenthesis(3);

    for (int i = 0; i < v.size(); i++)
        cout << i << " " << v[i] << endl;
    return 0;
}