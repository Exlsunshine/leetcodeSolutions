#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int myAtoi(string str)
    {
        // filter out the leading spaces
        int i = 0, result = 0;
        while (i < str.size() && str[i] == ' ')
            i++;
        if (i >= str.size())
            return result;

        // get sign bit
        int sign = 1;
        if (str[i] == '+')
        {
            sign = 1;
            i++;
        }
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        }

        for (; i < str.size(); i++)
        {
            // if charactor is not number, just break
            if (str[i] < '0' || str[i] > '9')
                break;

            // checkout if overflow
            // result = result * 10 + str[i] - '0'
            // so, if result is overflow, that means:
            // result > INT_MAX or result < INT_MIN
            // 1) result > INT_MAX
            // result * 10 + str[i] - '0' > INT_MAX
            // where 0 <= str[i] - '0' <= 9, because str[i] is a single number
            // thus, if result > INT_MAX / 10, then result * 10 > INT_MAX, so result * 10 + str[i] - '0' > INT_MAX
            if ((result > INT_MAX / 10) ||
                (result == INT_MAX / 10 && (str[i] - '0') > 7))
            {
                if (sign > 0)
                    return INT_MAX;
                else 
                    return INT_MIN;
            }
            else
                result = result * 10 + str[i] - '0';
        }

        return result * sign;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.myAtoi("2147483646") << endl;
    return 0;
}
