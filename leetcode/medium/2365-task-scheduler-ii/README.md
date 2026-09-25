# Task Scheduler II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a  **0-indexed**  array of positive integers `tasks`, representing tasks that need to be completed  **in order**, where `tasks[i]` represents the  **type**  of the `ith` task.

You are also given a positive integer `space`, which represents the  **minimum**  number of days that must pass  **after**  the completion of a task before another task of the  **same**  type can be performed.

Each day, until all tasks have been completed, you must either:

- Complete the next task from tasks, or
- Take a break.

Return *the  **minimum**  number of days needed to complete all tasks*.

 

 **Example 1:** 

```
Input: tasks = [1,2,1,2,3,1], space = 3
Output: 9
Explanation:
One way to complete all tasks in 9 days is as follows:
Day 1: Complete the 0th task.
Day 2: Complete the 1st task.
Day 3: Take a break.
Day 4: Take a break.
Day 5: Complete the 2nd task.
Day 6: Complete the 3rd task.
Day 7: Take a break.
Day 8: Complete the 4th task.
Day 9: Complete the 5th task.
It can be shown that the tasks cannot be completed in less than 9 days.

```

 **Example 2:** 

```
Input: tasks = [5,8,8,5], space = 2
Output: 6
Explanation:
One way to complete all tasks in 6 days is as follows:
Day 1: Complete the 0th task.
Day 2: Complete the 1st task.
Day 3: Take a break.
Day 4: Take a break.
Day 5: Complete the 2nd task.
Day 6: Complete the 3rd task.
It can be shown that the tasks cannot be completed in less than 6 days.

```

 

 **Constraints:** 

- 1 <= tasks.length <= 105
- 1 <= tasks[i] <= 109
- 1 <= space <= tasks.length

## Solution

**Language:** C++  
**Runtime:** 47 ms (beats 96.18%)  
**Memory:** 106.1 MB (beats 48.73%)  
**Submitted:** 2026-09-25T18:18:29.012Z  

```cpp
class Solution {
public:
 long long solve(vector<int>& tasks, int space) {
        //map to store last time it was done
        unordered_map<int,int>mpp;
        int n=tasks.size();
        long long time=1;
        for(int& t:tasks){
            if(!mpp.count(t)){
                mpp[t]=time;
                time++;
            }else{
                int last= mpp[t];
                // can be done in last+space+1 thus gap =space+1
                int gap=time-last;
                if(gap<space+1){
                    time+=(space+1-gap);
                }
                mpp[t]=time;
                time++;
            }
        }
        return time-1;
    }
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long time=0;
        int n=tasks.size();
        unordered_map<int,long long>mpp; //tasks, time
        
        for(int& t:tasks){
            auto it=mpp.find(t);

            if(it!=mpp.end()){
                long long next=it->second+space;
                time=max(time,next);
            }
            
            mpp[t]=++time;

        }
        return time;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/task-scheduler-ii/)