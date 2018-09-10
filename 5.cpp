#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1) {
            return s;
        }
        
        int steps = 0;
        int navigateDown = true;
        vector<string> zigzag(min(numRows, int(s.size())));

        for (int i = 0; i < s.size(); i++)
        {
            zigzag[steps].push_back(s[i]);

            if (navigateDown)
            {
                steps++;
                if (steps == numRows)
                {
                    steps = numRows - 2;
                    navigateDown = false;
                }
            }
            else
            {
                steps--;
                if (steps < 0)
                {
                    steps = 1;
                    navigateDown = true;
                }
            }
        }

        string str;
        for (int i = 0; i < zigzag.size(); i++)
        {
            str += zigzag[i];
            cout << zigzag[i] << endl;
        }

        return str;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.convert("PAYPALISHIRING",3);
    return 0;
}
