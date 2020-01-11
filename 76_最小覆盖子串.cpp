#include <string>
#include <map>

using namespace std;

//解法一：使用两个哈希表辅助实现判断
//失败原因：超时
class Solution
{
public:
    bool cmp(map<char, int> map1, map<char, int> map2, string t)
    {
        //比较前一个哈希表是不是包含后一个哈希表，即所有值都不小于后一个。
        for (auto c : t)
        {
            if (map1[c] < map2[c])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        //找到最小覆盖子串并返回
        int len1 = s.size(), len2 = t.size();
        if (len1 < len2)
            return "";
        map<char, int> m;

        //建立对应于t的哈希表
        for (auto c : t)
            m[c]++;

        //遍历s，寻找最小覆盖子串
        int from = 0, to = len1; //索引值范围
        for (int i = 0; i <= len1 - len2; i++)
        {
            map<char, int> temp;
            if (m.find(s[i]) != m.end())
                for (int j = i; j < len1; j++)
                {
                    if (m.find(s[j]) != m.end())
                    {
                        temp[s[j]]++;
                        if (temp[s[j]] == m[s[j]] && cmp(temp, m, t))
                            if (j - i < to - from)
                                from = i, to = j;
                    }
                }
        }
        if (to == len1) //不存在最小覆盖子串
            return "";
        return s.substr(from, to - from + 1);
    }
};

//解法二：滑动窗口
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int len1 = s.size(), len2 = t.size();
        if (len1 < len2 || len2 == 0)
            return "";
        int start = 0, minLen = INT_MAX; //开始位置的索引和最小长度
        int left = 0, right = 0;
        map<char, int> map1, map2; //map1是t对应的哈希表，map2是滑动窗口对应的哈希表
        int flag = 0; //记录符合要求的元素个数，全部符合要求即 flag == map1.size()
        for (auto c : t)
            map1[c]++;
        while (right <= len1)
        {
            if (map1.count(s[right]))
            {
                map2[s[right]]++;
                if (map2[s[right]] == map1[s[right]])
                    flag++;
            }
            while (flag == map1.size())
            {
                if (right - left < minLen)
                {
                    minLen = right - left;
                    start = left;
                }
                if (map1.count(s[left]))
                {
                    if (map2[s[left]] == map1[s[left]])
                        flag--;
                    map2[s[left]]--;
                }
                left++;
            }
            right++;
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(start, minLen + 1);
    }
};