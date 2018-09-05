#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", which the length is 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
            Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int maxCnt = 0, cnt = 0;
        int usedMap[128]; // usedMap[i]=-1表示字符i尚未遇到，否则表示字符i的最近一次遇到的下标
        int fromIdx = 0;
        memset(usedMap, -1, 128 * sizeof(int));

        for (int i = 0; i < s.length(); i++)
        {
            if (usedMap[s[i]] == -1)
            {
                // 如果s[i]没有遇见过，则设置其状态为使用过
                usedMap[s[i]] = i;
                cnt++;
            }
            else if (usedMap[s[i]] < fromIdx)
            {
                // 如果s[i]之前遇到过了，
                // 但是若最近一次遇到s[i]的下标 < 当前cnt表示的连续的没有相同字符的长度的起始
                // 则表示s[i]可以被认为尚未使用过（当前这一轮中尚未包含过s[i]，s[i]!=-1是因为之前遇到过），
                // 设置其状态为使用过
                usedMap[s[i]] = i;
                cnt++;
            }
            else
            {
                // 若s[i]在当前这一轮已经遇到过了，即遇到了相同字符的情况
                // 上一次遇到s[i]是在usedMap[s[i]]处，本次是在i处，
                // 因此，(usedMap[s[i]], i] 为两个相同字符之间的没有重复字符的子串
                // 因此，cnt = len((usedMap[s[i]], i)]；
                // 因此，fromIdx = 从上一次遇到s[i]的下标的后一位开始(相当于丢弃上一次遇到的s[i]，把本次遇到的s[i]记录到最新的一轮比较中)
                cnt = i - usedMap[s[i]];

                fromIdx = usedMap[s[i]] + 1;
                usedMap[s[i]] = i;
            }

            maxCnt = max(cnt, maxCnt);
        }

        return maxCnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << " should = 3" << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << " should = 1" << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << " should = 3" << endl;
    cout << s.lengthOfLongestSubstring("vaavmxcznvbcxxczxcnccbb") << " should = 7" << endl;

    return 0;
}
