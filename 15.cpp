#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 数组先排序
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            // 跳过相同的数字
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int from = i + 1, to = nums.size() - 1;
            while (from < to)
            {
                int a = nums[i];
                int b = nums[from];
                int c = nums[to];

                if (a * -1 == b + c)
                {
                    vector<int> v;
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    result.push_back(v);

                    // 找到一种可能之后，指针继续迁移，查看是否存在其他组合
                    from++;
                    to--;
                    while (from < to && nums[from] == nums[from - 1])
                        from++; // 跳过相同的数字
                    while (from < to && nums[to] == nums[to + 1])
                        to--; // 跳过相同的数字
                }
                else if (a * -1 > b + c)
                    from++;
                else
                    to--;
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
