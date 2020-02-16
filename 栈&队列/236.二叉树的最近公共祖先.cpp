/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (59.15%)
 * Likes:    369
 * Dislikes: 0
 * Total Accepted:    43.6K
 * Total Submissions: 73K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出: 3
 * 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出: 5
 * 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>
#include "TreeNode.h"
#include <vector>

using namespace std;

//双栈
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> currTrack, //当前路径
                    trackP, trackQ; //到节点P和Q的路径
        stack<TreeNode*> unprocessedList, //未访问节点
                         parentList; //对应未访问节点的父节点
        unprocessedList.push(root);
        parentList.push(nullptr);
        TreeNode *currNode; //当前节点
        while (unprocessedList.empty() == 0) {
            currNode = unprocessedList.top();
            unprocessedList.pop();
            parentList.pop();
            currTrack.push_back(currNode); //更新路径
            if (currNode->right) {
                unprocessedList.push(currNode->right);
                parentList.push(currNode);
            }
            if (currNode->left) {
                unprocessedList.push(currNode->left);
                parentList.push(currNode);
            }
            if (currNode == p)
                trackP = currTrack;
            if (currNode == q)
                trackQ = currTrack;
            if (!currNode->left && !currNode->right) //更新路径
                if (unprocessedList.empty() == 0)
                    while (currTrack.back() != parentList.top()) 
                        currTrack.pop_back();
        }
        int len = trackP.size()>trackQ.size()?trackQ.size():trackP.size();
        int i;
        for (i=0; i<len; i++)
            if (trackP[i] != trackQ[i])
                break;
        return trackQ[i-1];
    }
};
// @lc code=end

