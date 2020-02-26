/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (61.19%)
 * Likes:    451
 * Dislikes: 0
 * Total Accepted:    112.6K
 * Total Submissions: 182.6K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

//解法一：排序
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        sort(begin(nums), end(nums));
        return nums[len/2];
    }
};  

//解法二：投票解法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, //候选人
            count = 0; //票数
        for (int i:nums) {
            if (count == 0) //票数为0时更换候选人
                candidate = i;
            count += (candidate==i)?1:-1;
        }
        return candidate;
    }
};
// @lc code=end

