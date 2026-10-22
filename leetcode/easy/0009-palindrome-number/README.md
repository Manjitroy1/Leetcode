# Palindrome Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `x`, return `true` if `x` is a  **palindrome**, and `false` otherwise.

 

 **Example 1:** 

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

```

 **Example 2:** 

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

```

 **Example 3:** 

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

```

 

 **Constraints:** 

- -231 <= x <= 231 - 1

 

 **Follow up:**  Could you solve it without converting the integer to a string?

## Solution

**Language:** Java  
**Runtime:** 17 ms (beats 5.15%)  
**Memory:** 45.7 MB (beats 80.82%)  
**Submitted:** 2026-10-22T11:13:45.254Z  

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        
        // int a=x;
        // int num=0;
        // while(a>0){
        //     num= num*10 + (a%10);
        //     a/=10;
        // }
        // return num==x;
        String first = Integer.toString(x);
        String second = new StringBuilder(first).reverse().toString();

        return first.equals(second);

    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/palindrome-number/)