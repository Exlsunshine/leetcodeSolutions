class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int reverse = 0;
        int n = x;
        // 其实可以转换一半的数字就可以判断出是否回文
        while (n > 0)
        {
            reverse = reverse * 10 + n % 10;
            n /= 10;
        }
        
        return reverse == x;
    }
};