# Pairs

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers and a target value, determine the number of pairs of array elements that have a difference equal to the target value.  

**Example**   
$k = 1$  
$arr = [1, 2, 3, 4]$   

There are three values that differ by $k = 1$: $2-1 = 1$, $3-2 = 1$, and $4-3 = 1$.  Return $3$.  

**Function Description**

Complete the *pairs* function below.   

pairs has the following parameter(s):

- *int k:* an integer, the target difference
- *int arr[n]:* an array of integers   

**Returns**   

- *int:* the number of pairs that satisfy the criterion


**Input Format**

The first line contains two space-separated integers $n$ and $k$, the size of $arr$ and the target value.     
The second line contains $n$ space-separated integers of the array $arr$.
  

    

**Constraints**

- $2 \le n \le 10^5$  
- $0 \lt k \lt 10^9$  
- $0 \lt arr[i] \lt 2^{31} - 1$    
- each integer $arr[i]$ will be unique

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-31T09:33:38.649Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int pairs(int k, vector<int> arr) {
    unordered_map<int,int>mpp;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i]>k){
            int req= arr[i]-k;
            if(mpp.count(req)){
                cnt+=mpp[req];
            }
        }
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

    fout << result << "\n";

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

[View on HackerRank](https://www.hackerrank.com/challenges/pairs/problem)