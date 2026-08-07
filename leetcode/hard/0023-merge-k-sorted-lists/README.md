# Merge k Sorted Lists

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

 *Merge all the linked-lists into one sorted linked-list and return it.* 

 

 **Example 1:** 

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

```

 **Example 2:** 

```
Input: lists = []
Output: []

```

 **Example 3:** 

```
Input: lists = [[]]
Output: []

```

 

 **Constraints:** 

- k == lists.length
- 0 <= k <= 104
- 0 <= lists[i].length <= 500
- -104 <= lists[i][j] <= 104
- lists[i] is sorted in ascending order.
- The sum of lists[i].length will not exceed 104.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 61.27%)  
**Memory:** 19 MB (beats 20.07%)  
**Submitted:** 2026-08-07T17:27:58.505Z  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* node=& dummy;

        while(l1 && l2){
            if(l1->val> l2->val){
                node->next=l2;
                l2 = l2->next;
            }else{
                node->next=l1;
                l1 = l1->next;
            }
            node=node->next;
        }
        node->next= l1? l1:l2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while(lists.size()>1){
            vector<ListNode*>temp; // store all merge pair
            for(int i=0;i<lists.size();i+=2){
                ListNode* l1= lists[i];
                ListNode* l2= i+1 < lists.size() ? lists[i+1] : nullptr;
                temp.push_back(merge(l1,l2));
            }
            lists=temp;
        }
        return lists[0];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/merge-k-sorted-lists/)