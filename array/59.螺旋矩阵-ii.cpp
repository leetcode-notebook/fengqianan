/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (76.28%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 31.6K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n, vector<int> (n, 0));
        int m = 1;
        for (int i=0; i<(n+1)/2; i++) {
            m = circle(res, i, m);
        }
        return res; 
    }

private:
    int circle (vector<vector<int>> &res, int k/*从res(k, k)开始*/, int m) {
    //赋值一圈
        int n = res.size();
        int row=k, col=k;
        //case1:实心圈
        if (k == n-k-1) {
            res[row][col] = m;
            return 0;
        }
        //case2:空心圈
        while (col < n-k-1) {
            res[row][col] = m;
            m++;
            col++;
        }
        while (row < n-k-1) {
            res[row][col] = m;
            m++;
            row++;
        }
        while (col > k) {
            res[row][col] = m;
            m++;
            col--;
        }
        while (row > k) {
            res[row][col] = m;
            m++;
            row--;
        }
        return m;
    }
};
// @lc code=end
