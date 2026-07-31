# Gridland Metro

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

The city of Gridland is represented as an $n \times m$ matrix where the rows are numbered from $1$ to $n$ and the columns are numbered from $1$ to $m$.

Gridland has a network of train tracks that always run in straight horizontal lines along a row. In other words, the start and end points of a train track are $(r, c1)$ and $(r, c2)$, where $r$ represents the row number, $c1$ represents the starting column, and $c2$ represents the ending column of the train track. 

The mayor of Gridland is surveying the city to determine the number of locations where lampposts can be placed. A lamppost can be placed in any cell that is *not occupied* by a train track.

Given a map of Gridland and its $k$ train tracks, find and print the number of cells where the mayor can place lampposts.

**Note:** A train track may overlap other train tracks within the same row. 

**Example**   

If Gridland's data is the following (1-based indexing):

<pre>
k = 3
r	c1	c2
1	1	4
2	2	4
3	1	2
4	2	3
</pre>

It yields the following map:

![image](https://s3.amazonaws.com/hr-assets/0/1523893004-b858dbd32c-gridland_2.png)  

In this case, there are five open cells (red) where lampposts can be placed.

**Function Description**

Complete the *gridlandMetro* function in the editor below.  

gridlandMetro has the following parameter(s):  

- *int n:*: the number of rows in Gridland
- *int m:*: the number of columns in Gridland
- *int k:*: the number of tracks
- *track[k][3]:* each element contains $3$ integers that represent $\text{row, column start, column end}$, all 1-indexed   

**Returns**   

- *int*: the number of cells where lampposts can be installed   

**Input Format**

The first line contains three space-separated integers $n, m$ and $k$, the number of rows, columns and tracks to be mapped.	  

Each of the next $k$ lines contains three space-separated integers, $r, c1$ and $c2$, the row number and the track column start and end.  


**Constraints**

* $1\le n, m \le 10^9$
* $0\le k \le1000$
* $1\le r \le n $
* $1\le c1 \le c2 \le m$


**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-31T09:20:45.669Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridlandMetro' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. INTEGER k
 *  4. 2D_INTEGER_ARRAY track
 */
long long solve(int n, int m, int k, vector<vector<int>>& track) {
   long long total= 1LL* n*m;
   long long occupied=0;
   int i=0;
   while(i<k){
        long long row=track[i][0];
        long long l=track[i][1];
        long long r=track[i][2];
        i++;
        
        while(i<k && track[i][0]==row){
            if(track[i][1]<= r+1){
                r= max(r, (long long)track[i][2]);
            }else{
                occupied+=(r-l+1);
                
                l=track[i][1];
                r=track[i][2];
            }
            i++;
        }
        occupied+=(r-l+1);
        
   }
   return (total-occupied);
    
}
long long gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    sort(track.begin(),track.end());
    return solve(n,m,k,track);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<vector<int>> track(k);

    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        string track_row_temp_temp;
        getline(cin, track_row_temp_temp);

        vector<string> track_row_temp = split(rtrim(track_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int track_row_item = stoi(track_row_temp[j]);

            track[i][j] = track_row_item;
        }
    }

    long long result = gridlandMetro(n, m, k, track);

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

[View on HackerRank](https://www.hackerrank.com/challenges/gridland-metro/problem)