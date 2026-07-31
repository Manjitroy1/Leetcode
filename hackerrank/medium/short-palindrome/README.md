# Short Palindrome

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Consider a string, $s$, of $n$ lowercase English letters where each character, $s_i$ ($0 \le i \lt n)$, denotes the letter at index $i$ in $s$. We define an $(a, b, c, d)$ palindromic tuple of $s$ to be a sequence of indices in $s$ satisfying the following criteria:

* $s_a = s_d$, meaning the characters located at indices $a$ and $d$ are the same.
* $s_b = s_c$, meaning the characters located at indices $b$ and $c$ are the same.
* $0 \le a \lt b \lt c \lt d \lt |s|$, meaning that $a$, $b$, $c$, and $d$ are ascending in value and are valid indices within string $s$.

Given $s$, find and print the number of $(a, b, c, d)$ tuples satisfying the above conditions. As this value can be quite large, print it modulo $(10^9 + 7)$.  

**Function Description**  
Complete the function *shortPalindrome* in the editor below.  

*shortPalindrome* has the following paramter(s):  
- *string s:* a string  

**Returns**  
- *int:* the number of tuples, modulo $(10^9 + 7)$  

**Input Format**

A single string, $s$. 

**Constraints**

* $1 \le |s| \le 10^6$
* It is guaranteed that $s$ only contains lowercase English letters.  

**Sample Input 0**

	kkkkkkz

**Sample Output 0**

	15

**Explanation 0**

The letter `z` will not be part of a valid tuple because you need at least two of the same character to satisfy the conditions defined above. Because all tuples consisting of four `k`'s are valid, we just need to find the number of ways that we can [choose](https://en.wikipedia.org/wiki/Binomial_coefficient) four of the six `k`'s. This means our answer is ${6 \choose 4}\mod{(10^9 + 7)} = 15$.

**Sample Input 1**

	ghhggh

**Sample Output 1**

	4

**Explanation 1**

The valid tuples are:

1. $(0, 1, 2, 3)$
2. $(0, 1, 2, 4)$
3. $(1 ,3, 4, 5)$
4. $(2 ,3, 4, 5)$

Thus, our answer is $4\mod{(10^9 + 7)} = 4$.

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-31T15:12:46.447Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'shortPalindrome' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

const long long md=1e9+7;
int shortPalindrome(string& s) {
    long long ans=0;
    long long cnt1[26]={0};
    long long cnt2[26][26] ={0};
    long long cnt3[26][26]={0};
    
    // we will traverse from left to right and store
    // number of single char is there like a
    //number of double char like ab
    // for axx if the currecnt char is x then we find number of ax is availibale
    //if the current char is x we find number of xbb is there
    for(int i=0;i<s.size();i++){
        int x= s[i]-'a';
        
        //axxa
        for(int j=0;j<26;j++){              //check total number of xyy
            ans = (ans + cnt3[x][j]) %md;   // as current char is x
        }
        //axx
        for(int j=0;j<26;j++){
            cnt3[j][x] = (cnt3[j][x] + cnt2[j][x]) %md;  //check total number of ax 
                                                          // as current char is x
        }
        
        //ax
        for(int j=0;j<26;j++){
            cnt2[j][x] = (cnt2[j][x] + cnt1[j]) % md;
        }
        
        //x
        cnt1[x] = (cnt1[x] + 1)%md;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = shortPalindrome(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/short-palindrome/problem)