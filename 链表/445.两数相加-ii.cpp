//本题使用vector
//若使用两个栈存储两个链表的值，会更简便

/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (53.27%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 22.4K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
 * 
 * 
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 进阶:
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 示例:
 * 
 * 
 * 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出: 7 -> 8 -> 0 -> 7
 * 
 * 
 */

// @lc code=start
#include "ListNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1->val == 0)
            return l2;
        if (l2->val == 0)
            return l1;

        vector<ListNode*> addr1, addr2;
        ListNode *p=l1, *q=l2;
        while (p) {
            addr1.push_back(p);
            p = p->next;
        }
        while (q) {
            addr2.push_back(q);
            q = q->next;
        }

        int len1=addr1.size(), len2=addr2.size();
        vector<ListNode*> addr_max = len1>len2?addr1:addr2;
        int len_min = min (len1, len2);
        int len_max = max (len1, len2);
        int diff = len_max-len_min;      
        int flag = 0, preFlag = 0;
        ListNode *res=nullptr, *r; //res需要初始化为空指针，不然没有指向任何空间，调试时会出错。
        for (int i=0; i<len_min; i++) {
            int temp = addr1[len1-1-i]->val + addr2[len2-1-i]->val + preFlag;
            if (temp > 9) {
                temp = temp%10;
                flag = 1;
            }
            r = new ListNode(temp);
            r->next = res;
            res = r;
            preFlag = flag;
            flag = 0;
        }
        for (int i=0; i<diff; i++) {
            int temp = addr_max[diff-1-i]->val+preFlag;
            if (temp > 9) {
                temp = 0;
                flag = 1;
            }
            r = new ListNode(temp);
            r->next = res;
            res = r;
            preFlag = flag;
            flag = 0;
        }
        if (preFlag) {
            r = new ListNode(1);
            r->next = res;
            res = r;
        }
        return res;
    }
};
// @lc code=end

