# Bus Station

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are $n$ **groups of friends**, and each group is numbered from 1 to $n$. The $i$<sup>th</sup> group contains $a_i$ people. 

They live near a bus stop, and only a single bus operates on this route. An empty bus arrives at the bus stop and all the groups want to travel by the bus. 

However,  **group of friends** do not want to get separated. So they enter the bus only if the bus can carry the entire group. 

Moreover, the groups do not want to change their relative positioning while travelling.  In other words, group 3 cannot travel by bus, unless group 1 and group 2 have either (a) already traveled by the bus in the previous trip or (b) they are also sitting inside the bus at present.

You are given that a bus of size $x$ can carry $x$ people simultaneously.  
<br>
Find the size $x$ of the bus so that 
(1) the bus can transport all the groups and 
(2) every time when the bus starts from the bus station, there is no empty space in the bus (i.e. the total number of people present inside the bus is equal to $x$)?

**Input Format**  
The first line contains an integer $n$ $(1 \le n \le 10^5)$. The second line contains $n$ space-separated integers $a_1, a_2, \dots, a_n$ $(1 \le a_i \le 10^4)$.

**Output Format**

Print all possible sizes of the bus in an increasing order.

**Sample Input**

    8
    1 2 1 1 1 2 1 3
    
**Sample Output**

    3 4 6 12
    
**Sample Explanation**

In the above example, 
$a_1$ = 1, $a_2$ = 2, $a_3$ = 1, $a_4$ = 1, $a_5$ = 1, $a_6$ = 2, $a_7$ = 1, $a_8$ = 3.

If x = 1 : 
In the first trip, $a_1$ go by the bus.
There will be no second trip because the bus cannot accommodate group 2. Hence "x = 1" is not the required answer.

If x = 2 :
No bus trip is possible. That's because $a_1$ cannot go alone, as one seat will be left vacant in the bus. And, $a_1$ & $a_2$ cannot go together, because the bus is cannot accommodate both the groups simultaneously.

If x = 3 : 
In the first trip, $a_1$ & $a_2$ go by the bus. 
In the second trip, $a_3$, $a_4$ & $a_5$ go by the bus. 
In the third trip, $a_6$ & $a_7$ go by the bus. 
In the fourth trip, $a_8$ go by the bus. 

If x = 4 : 
In the first trip, $a_1$, $a_2$ & $a_3$ go by the bus. 
In the second trip,  $a_4$, $a_5$ & $a_6$go by the bus. 
In the third trip, $a_7$ & $a_8$ go by the bus. 

Similarly you can figure out the output for x= 5, 6 & 7.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-06T13:17:47.348Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

bool ispossible(vector<int>&arr, int total,int curr){
    int n=arr.size();
    if(curr>=n) return true;
    
    int i=curr;
    int sum=0;
    while(i<n){
        sum+=arr[i];
        if(total == sum){
            sum=0;
        }else if(sum>=total) return false;
        i++;
    }
    return sum==0;
}
vector<int> solve(vector<int> arr) {
    int n=arr.size();
    if(n==1) return arr;
    vector<int>ans;
    int l= *max_element(arr.begin(),arr.end());
    int h = accumulate(arr.begin(),arr.end(),0);
    
    int i=0;
    int sum=0;
    
    while(i<n && sum<l){
        sum+=arr[i];
        i++;
    }
    sum-=arr[i-1];
    i--;
    for(int k=i;k<n;k++){
        sum+=arr[k];
        if(h%sum!=0) continue;
        if(ispossible(arr,sum,k+1)){
            ans.push_back(sum);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> result = solve(a);

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

[View on HackerRank](https://www.hackerrank.com/challenges/bus-station/problem)