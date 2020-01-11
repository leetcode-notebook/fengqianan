#include <vector>

using namespace std;

//方法一：两次遍历
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans;        
        for (auto itr=A.begin(); itr!=A.end(); itr++) 
            if (*itr%2 == 0) 
                ans.push_back(*itr);               
        for (auto itr=A.begin(); itr!=A.end(); itr++) 
            if (*itr%2 != 0) 
                ans.push_back(*itr);
        return ans;
    }
};


//方法二：原地算法，双指针
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0, j=A.size()-1;
        while(j>=i) {
            if (A[i]%2 == 0)
                i++;
            if (A[j]%2 == 1)
                j--;
            if (A[i]%2==1 && A[j]%2==0) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        return A;
    }
};
