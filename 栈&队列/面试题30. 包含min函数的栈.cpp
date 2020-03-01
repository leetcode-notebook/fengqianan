#include <algorithm>

using namespace std;

//可以改进的更容易理解和实现，但是会降低效率
//维护的两个数组同步删增，而不是本题解中：将每个区间的最小值的索引存储起来
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {    }
    
    void push(int x) {
        s[end] = x;
        end++;
        if (x < s[sMin[endMin-1]]) {
            sMin[endMin] = end-1;
            endMin++;
        }
    }
    
    void pop() {
        if (end) {
            if (end-1 == sMin[endMin-1] && endMin > 1)
                endMin--;
            end--;
        }
    }
    
    int top() {
        if (end)
            return s[end-1];
        else
            return INT_MIN;
    }
    
    int min() {
        return s[sMin[endMin-1]];
    }

private:
    int s[20001], //存储栈内元素
        sMin[20001] = {0}, //存储不同阶段的最小值在s中的索引
        endMin = 1, //记录在sMin中的最小值的索引的后一个位置
        end = 0; //记录栈顶元素在数组中的位置的后一个的索引
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */