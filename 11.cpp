#include <vector>
#include <iostream>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int from = 0, to = height.size() - 1;
        int maxWater = 0;

        while (from < to)
        {
            // height[from], height[to] 
            // water = min(height[from], height[to]) * (to - from)
            maxWater = max(maxWater, min(height[from], height[to]) * (to - from));

            // 短板的一侧向中间移动：
            // 因为 water = min(height[from], height[to]) * (to - from)
            // 所以头尾指针向重甲移动的时候，to - from 减小的情况下，只能提高min(height[from], height[to])
            // 所以要将短板一侧向中间移动
            if (height[from] < height[to])
                from++;
            else
                to--;
        }

        return maxWater;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
