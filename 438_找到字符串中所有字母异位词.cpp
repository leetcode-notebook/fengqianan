#include <vector>
#include <string>
#include <map>

using namespace std;

//解法一：哈希表硬解
//失败原因：超时
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len1 = s.size();
        int len2 = p.size();
        if (len1 < len2)
            return {};
        vector<int> ans;

        map<char,int> mapp;
        for (auto c:p)
            mapp[c]++;

        for (int i=0; i<=len1-len2; i++) {
            map<char,int> temp;
            for (int j=0; j<len2; j++)         
                temp[s[i+j]]++;  
            if (temp == mapp)
                ans.push_back(i);
        }
        return ans; 
    }
};

//解法二：滑动窗口
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len1 = s.size();
        int len2 = p.size();
        if (len1 < len2)
            return {};
        vector<int> ans;
        int left=0, right=0;
        int flag=0;
        map<char,int> ref,act;
        //将p映射到哈希表ref中
        for (char c:p) 
            ref[c]++;     
        //因为本题中滑动窗口的大小是固定的，所以一开始让right先走窗口大小的长度。
        while (right < len2) { 
            act[s[right]]++;
            if (ref.count(s[right]) && act[s[right]]==ref[s[right]]) 
                flag++; 
            right++;
        }
        if (flag == ref.size()) 
            ans.push_back(0);
        //实现窗口滑动、找到符合要求的字符串起始位置。
        while (right < len1) {        
            act[s[right]]++;
            if (ref.count(s[right]) && act[s[right]]==ref[s[right]]) 
                flag++;
            act[s[left]]--;
            if (ref.count(s[left]) && ref[s[left]]-act[s[left]]==1) 
                flag--; 
            right++;
            left++;
            if (flag == ref.size())
                ans.push_back(left);
        }
        return ans;
    }
};

//方法三：和方法二基本相同
//不同点：判断窗口内数据是不是符合要求的方法不同。方法二通过设置flag自行判断，本方法通过判断两个哈希表是否相等实现
//两种方法的效率差不多，但是本方法代码量小，逻辑更简单。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len1 = s.size();
        int len2 = p.size();
        if (len1 < len2)
            return {};
        vector<int> ans;
        int left=0, right=0;
        map<char,int> ref,act;
        //将p映射到哈希表ref中
        for (char c:p) 
            ref[c]++;     
        //因为本题中滑动窗口的大小是固定的，所以一开始让right先走窗口大小的长度。
        while (right < len2) { 
            if (ref.count(s[right])) 
                act[s[right]]++;
            right++;
        }
        if (act == ref) 
            ans.push_back(0);
        //实现窗口滑动,找到符合要求的字符串起始位置。
        while (right < len1) {          
            if (ref.count(s[right])) 
                act[s[right]]++;
            if (ref.count(s[left])) 
                act[s[left]]--;  
            right++;
            left++;
            if (act == ref)
                ans.push_back(left);
        }
        return ans;
    }
};