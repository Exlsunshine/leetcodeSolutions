#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int col = 0;
        string str;
        int maxLen = 0;

        if (strs.size() < 1)
            return str;

        while (true)
        {
            char lastChar = 0;
            for (int i = 0; i < strs.size(); i++)
            {
                maxLen = max(maxLen, int(strs[i].size()));
                if (col >= strs[i].size())
                    return str;

                if (lastChar == 0)
                    lastChar = strs[i][col];
                else if (lastChar == strs[i][col])
                    continue;
                else
                    return str;
            }

            str.push_back(strs[0][col]);
            col++;
            
            if (col >= maxLen)
                break;
        }
        
        return str;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> v;
    v.push_back("flower");
    v.push_back("flow");
    v.push_back("flight");
    v.push_back("falight");
    Solution s;
    cout << s.longestCommonPrefix(v);
    return 0;
}
