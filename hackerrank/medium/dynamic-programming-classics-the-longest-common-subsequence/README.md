# The Longest Common Subsequence

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.  Longest common subsequence (_LCS_) of 2 sequences is a subsequence, with maximal length, which is common to both the sequences.   
<br>
Given two sequences of integers, $A = [a[1], a[2],\ldots, a[n]]$ and $B = [b[1], b[2],\ldots,b[m] ]$, find the longest common subsequence and print it as a line of space-separated integers. If there are multiple common subsequences with the same maximum length, print any one of them.

In case multiple solutions exist, print any of them. It is guaranteed that at least one non-empty common subsequence will exist.    

**Recommended References**  

This Youtube video tutorial explains the problem and its solution quite well.  

[(iframe youtube V5hZoJ6uK-s 560 315)]  
 
**Function Description**  

Complete the *longestCommonSubsequence* function in the editor below.  It should return an integer array of a longest common subsequence.  

longestCommonSubsequence has the following parameter(s):  

- *a*: an array of integers  
- *b*: an array of integers


**Input Format**

The first line contains two space separated integers $n$ and $m$, the sizes of sequences $A$ and $B$.  
The next line contains $n$ space-separated integers $A[i]$.  
The next line contains $m$ space-separated integers $B[j]$.

**Constraints**  

$1 \le n \le 100$  
$1 \le m \le 100$  
$0 \le a[i] \lt 1000, \text{ where } i \in [1, n]$  
$ 0 \le b[j] \lt 1000, \text{ where } j \in [1,m]$  

**Constraints**

$1 \le n, m \le 100$  
$0 \le a[i], b[j] \lt 1000$  
  

**Output Format**

Print the longest common subsequence as a series of space-separated integers on one line. In case of multiple valid answers, print any one of them.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-29T07:14:51.798Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'longestCommonSubsequence' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */
vector<int>lcs(vector<int>&a, vector<int>&b){
    int n1=a.size(),n2=b.size();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]= 1+ dp[i-1][j-1];
            }else{
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int mx= dp[n1][n2];
    vector<int>ans(mx);
    int cnt=1;
    int up=n1; //a
    int left=n2; //b
    
    while(up>=1 && left>=1){
        if(a[up-1]== b[left-1]){
            ans[mx-cnt]= a[up-1];
            up--;
            left--;
            cnt++;
        }else if(dp[up-1][left]>=dp[up][left-1]){
            up--;
        }else{
            left--;
        }
        
    }
    return ans;
}
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    return lcs(a,b);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split(rtrim(b_temp_temp));

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem)