# Minimum Loss

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Lauren has a chart of distinct projected prices for a house over the next several years.  She must buy the house in one year and sell it in another, and she must do so at a loss.  She wants to minimize her financial loss.  

**Example**   
$price = [20, 15, 8, 2, 12]$   

Her minimum loss is incurred by purchasing in year $2$ at $price[1]=15$ and reselling in year $5$ at $price[4]=12$.  Return $15 - 12 = 3$.  

**Function Description**  

Complete the *minimumLoss* function in the editor below.   

minimumLoss has the following parameter(s):  

- *int price[n]:* home prices at each year  

**Returns**   

- *int:* the minimum loss possible  

**Input Format**

The first line contains an integer $n$, the number of years of house data. 		
The second line contains $n$ space-separated long integers that describe each $price[i]$.

**Constraints**

* $2\le n \le 2 \times 10^5$
* $ 1 \le price[i] \le 10^{16} $
* All the prices are distinct. 
* A valid answer exists.

**Subtasks**

* $2 \le n \le 1000$ for $50\%$ of the maximum score. 

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-31T12:04:22.354Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumLoss' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER_ARRAY price as parameter.
 */
int solve(vector<long>price){
    vector<pair<long,int>>store;
    for(int i=0;i<price.size();i++){
        store.push_back({price[i],i});
    }
    sort(store.begin(),store.end());
    long gap= INT_MAX;
    for(int i=0;i<store.size()-1;i++){
        if(store[i].second > store[i+1].second){
            gap= min(gap, store[i+1].first-store[i].first);
        }
    }
    return gap;
}
int minimumLoss(vector<long> price) {
    return solve(price);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split(rtrim(price_temp_temp));

    vector<long> price(n);

    for (int i = 0; i < n; i++) {
        long price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    int result = minimumLoss(price);

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

[View on HackerRank](https://www.hackerrank.com/challenges/minimum-loss/problem)