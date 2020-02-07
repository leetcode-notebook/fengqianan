/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 *
 * https://leetcode-cn.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (47.13%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    12.5K
 * Total Submissions: 26.5K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * 给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26
 * 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU
 * 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
 * 
 * 然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
 * 
 * 你需要计算完成所有任务所需要的最短时间。
 * 
 * 示例 1：
 * 
 * 
 * 输入: tasks = ["A","A","A","B","B","B"], n = 2
 * 输出: 8
 * 执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
 * 
 * 
 * 注：
 * 
 * 
 * 任务的总个数为 [1, 10000]。
 * n 的取值范围为 [0, 100]。
 * 
 * 
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//方法一：常规排序
//不通过：超出时间限制
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        int *map = new int [26];
        for (char c : tasks) {
            map[c-'A']++;
        }

        int a = 0; //记录最后一步多走的idle数量。
        sort (map, map+25);
        while (map[25] != 0) {
            int i = 0, temp =0;
            while (i <= n) {
                if (i<26 && map[25-i] != 0) {                   
                    map[25-i]--;
                    ans++; 
                }
                else {
                    ans++;
                    temp++;
                }               
                i++;
            }
            a = temp;
            sort (map, map+25);
        }

        return ans-a;
    }
};

//解法二：设计
//根据官方解答中的方法三解答https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26); //记录每个任务的频次
        int maxTimes = 0; //最高的频次
        int maxLetters = 0; //出现最高频次的任务的数量
        for (char c:tasks) 
            maxTimes = max(maxTimes, ++count[c-'A']);
        for (int i=0; i<26; i++) 
            if (count[i] == maxTimes)
                maxLetters++;
        return max((int)tasks.size(), (maxTimes-1)*(n+1)+maxLetters);
    }
};
// @lc code=end

