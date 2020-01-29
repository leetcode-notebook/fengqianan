/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.48%)
 * Likes:    3069
 * Dislikes: 0
 * Total Accepted:    330.1K
 * Total Submissions: 1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size(), ans=0;
        if(len == 0)
            return ans;
        
        int left=0, right=0; //初始化滑动窗口的左右边界，
        unordered_map<char,int> map; // 初始化哈希表
        int flag=0; //设置flag，用来统计哈希表中的字符有无重复

        //滑动窗口的实现
        while(right != len){
            //录入map，变更flag的值
            int temp=s[right];
            map[temp]++;
            if(map[temp] == 1)
                flag++;
            
            
            //判断是否有重复，更新返回值
            if(flag == right-left+1){
                if(flag > ans)
                    ans = flag;
            }
            else
                while(flag != right-left+1){
                    int temp1 = s[left];
                    map[temp1]--;
                    if(map[temp1] == 0)
                        flag--;
                    left++; //窗口左侧滑动
                }
 
            right++; //窗口右侧滑动
        }
        return ans;
    }
};
// @lc code=end

