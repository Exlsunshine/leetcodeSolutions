#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool canCross(vector<int> &stones)
    {
        for (int i = stones.size() - 2; i >= 0; i--)
        {
            if (isNReachable(stones, i, stones[stones.size() - 1] - stones[i]))
                return true;
        }

        return false;
    }

    // 判断青蛙跳到给定的下标n时，下一跳是否可以到达needUnits步
    bool isNReachable(vector<int> &v, int n, int needUnits)
    {
        // 第1步时，下一跳若大于1则必定不可达
        // 因为第一跳只能跳一步
        // 第2步时，下一跳若大于2则必定不可达
        // 因为第一跳只能跳一步
        if (n == 0)
            return !(needUnits > 1);
        if (n == 1)
            return !(abs(1 - needUnits) > 1);

        for (int i = n - 1; i >= 0; i--)
        {
            // 从i跳到下标n时的units数目
            int lastUnits = v[n] - v[i];

            // 若lastUnits与needUnits不在±1内
            // 则从下标n开始的一跳，无法跳跃needUnits步
            if (abs(lastUnits - needUnits) > 1)
                continue;
            else
            {
                // 若lastUnits与needUnits在±1内
                // 则判断跳到i时，是否有lastUnits步
                // 找到了，则表示存在：从上一下标跳到i，再从i跳到n，且到n时下一跳可以跳needUnits步 的路径
                if (isNReachable(v, i, lastUnits))
                    return true;
            }
        }

        return false;
    }
};

vector<int> generateValid()
{
    vector<int> v;
    // v.push_back(0);
    // v.push_back(1);
    // v.push_back(3);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(8);
    // v.push_back(12);
    // v.push_back(17);

    // v.push_back(0);
    // v.push_back(1);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(7);
    // v.push_back(9);
    // v.push_back(10);
    // v.push_back(12);

    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(10);
    v.push_back(13);
    v.push_back(14);

    return v;
}

vector<int> generateInvalid()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(8);
    v.push_back(9);
    v.push_back(11);

    return v;
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = generateValid();

    cout << s.canCross(v) << endl;
    return 0;
}