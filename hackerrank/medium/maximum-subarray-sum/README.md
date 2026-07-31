# Maximum Subarray Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

We define the following:

- A *subarray* of array $a$ of length $n$ is a contiguous segment from $a[i]$ through $a[j]$ where $0 \le i \le j \lt n$.
- The *sum* of an array is the sum of its elements.

Given an $n$ element array of integers, $a$, and an integer, $m$, determine the maximum value of the sum of any of its subarrays modulo $m$. 

**Example**    
$a=[1,2,3]$    
$m=2$     

The following table lists all subarrays and their moduli:

```
		sum	%2
[1]		1	1
[2]		2	0
[3]		3	1
[1,2]		3	1
[2,3]		5	1
[1,2,3]		6	0
```
The maximum modulus is $1$.

**Function Description**

Complete the *maximumSum* function in the editor below.  

maximumSum has the following parameter(s):

- *long a[n]:* the array to analyze   
- *long m:* the modulo divisor   

**Returns**   
- *long:* the maximum (subarray sum modulo $m$)   

**Input Format**

The first line contains an integer $q$, the number of queries to perform.

The next $q$ pairs of lines are as follows:

- The first line contains two space-separated integers $n$ and (long)$m$, the length of $a$ and the modulo divisor.  
- The second line contains $n$ space-separated long integers $a[i]$.

**Constraints**

- $2 \le n \le 10^{5}$  
- $1 \le m \le 10^{14}$  
- $1 \le a[i] \le 10^{18}$  
- $2 \le $ the sum of $n$ over all test cases $ \le 5 \times 10^5$   

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-31T18:25:22.105Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY a
 *  2. LONG_INTEGER m
 */

long maximumSum(vector<long> a, long m) {
    set<long>stt;
    vector<long>prefix(a.size());
    
    
    prefix[0] = a[0] % m;
    stt.insert(prefix[0]);
    long ans=prefix[0];
     
    for(int i=1;i<a.size();i++){
        prefix[i] = (prefix[i-1] + a[i])%m;
        
        if(prefix[i]==(m-1)) return prefix[i];
        
        ans = max(ans, prefix[i]);
        auto it= stt.upper_bound(prefix[i]);
        if(it!=stt.end()){
            ans= max(ans, ((prefix[i]-*it+m)%m) );
        }
        
        stt.insert(prefix[i]);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        long m = stol(first_multiple_input[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

        fout << result << "\n";
    }

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

[View on HackerRank](https://www.hackerrank.com/challenges/maximum-subarray-sum/problem)