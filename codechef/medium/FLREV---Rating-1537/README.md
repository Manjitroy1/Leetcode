# FLREV - Rating 1537

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Flower Reversal

There is a row of $N$ flowerpots, numbered $1$ to $N$ from left to right.

Each flowerpot contains exactly one flower, with that flower being either red or blue.
You are given a binary string $S$ representing the colors of the flowers, where $S_i = 0$ means the flower in the $i$-th pot is red and $S_i = 1$ means it's blue.

Define the  *beauty*  of an arrangement of flowers to be the number of adjacent pairs of same-colored flowers - that is, the number of $i$ ($1 \le i \lt N$) such that $S_i = S_{i+1}$.

You want the beauty of the flowerpots to be as large as possible.
To achieve that, you can choose  **at most one**  contiguous range of flowerpots and reverse their order.

That is, at most once, you can choose indices $L$ and $R$ such that $1 \le L \le R \le N$ and reverse the order of the pots from indices $L$ to $R$, inclusive of both endpoints.
This results in the order of colors becoming

$$ S_1 S_2 \ldots S_{L-1} S_R S_{R-1} \ldots S_L S_{R+1} \ldots S_N $$

Find the  **maximum**  possible beauty of the flowerpot arrangement after at most one reversal.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains a single integer $N$, the number of flowerpots. The second line contains the binary string $S$ representing the colors of the flowers.
### Output Format

For each test case, output on a new line the maximum possible beauty of the flowerpots after at most one reversal.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 2\cdot 10^5$
- $S_i \in \{0, 1\}$
- The sum of $N$ over all test cases won't exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
4
3
000
6
000111
5
00110
5
01010

```

```
2
4
3
2

```

### Explanation:

 **Test case $1$:**  The beauty is $2$ since $S_1 = S_2$ and $S_2 = S_3$ already. Reversals don't change anything, so the answer is $2$.

 **Test case $2$:**  The beauty of $\texttt{000111}$ is $4$, and no reversal can improve it so the answer is $4$.

 **Test case $3$:**  We have $\texttt{00110}$. Reverse the substring from index $1$ to index $4$ to obtain $\texttt{11000}$ which has a beauty of $3$, which is the best we can do.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-30T14:15:26.977Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
int solve(string& s){
    int n=s.size();
    
    int beauty=0;
    int cnt01=0;
    int cnt10=0;
    
    bool improve=false;
    // bool improve2=false;
    
    
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            beauty++;
        }else{
            if(s[i]=='0' && s[i+1]=='1') cnt01++;
            else cnt10++;
        }
        
        // if(cnt01 >=2 || cnt10>=2) improve2=true;
        
        if(s[i]!=s[i+1] && s[i+1]==s[0]) improve=true;
        if(s[i+1]!=s[i] && s[n-1]==s[i]) improve=true;
    }
    if(cnt01 >=2 || cnt10>=2) return beauty+2;
    if(improve){
        return beauty+1;
    }
    return beauty;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    string s;
	    cin>>n;
	    cin>>s;
	    int ans=solve(s);
	    cout<<ans<<endl;
	    
	}
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/FLREV)