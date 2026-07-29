# Matrix Layer Rotation

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a 2D  matrix of dimension $m \times n$ and a positive integer $r$. You have to rotate the matrix $r$ times and print the resultant matrix. Rotation should be in anti-clockwise direction.  

Rotation of a $4x5$ matrix is represented by the following figure. Note that in one rotation, you have to shift elements by one step only.

![matrix-rotation](https://hr-challenge-images.s3.amazonaws.com/2517/matrix-rotation.png)

It is guaranteed that the minimum of _m_ and _n_ will be even.  

As an example rotate the Start matrix by 2:

<pre>
	Start		  First 		  Second
	 1 2 3 4	   2  3  4  5      3  4  5  6
	12 1 2 5  ->   1  2  3  6 ->   2  3  4  7
	11 4 3 6      12  1  4  7      1  2  1  8
	10 9 8 7      11 10  9  8     12 11 10  9
</pre>

**Function Description**  

Complete the *matrixRotation* function in the editor below.  

matrixRotation has the following parameter(s):  

- *int matrix[m][n]:* a 2D array of integers  
- *int r:* the rotation factor   

**Prints**   
It should print the resultant 2D integer array and return nothing.  Print each row on a separate line as space-separated integers.  

**Input Format**

The first line contains three space separated integers, $m$, $n$, and $r$, the number of rows and columns in $matrix$, and the required rotation.    
The next $m$ lines contain $n$ space-separated integers representing the elements of a row of $matrix$.  

**Constraints**

$2 \le \text{m, n} \le 300$  
$1 \le r \le 10^9$  
$min(m, n) \% 2 = 0$  
$1 \le matrix[i][j] \le 10^8 \text{ where }i \in [1 \dots m] \text{ and }j \in [1 \dots n]$
 

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-29T10:34:43.721Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
    int n=matrix.size();
    int m=matrix[0].size();
    int times= min(n,m)/2;
    for(int l=0;l<times;l++){
        int top=l;
        int left=l;
        int bottom = n-1-l;
        int right = m-1-l;
        
        vector<int>store;
        //left column
        for(int i=top;i<=bottom;i++){
            store.push_back(matrix[i][left]);
        }
        //bottom row;
        for(int j=left+1;j<=right;j++){
            store.push_back(matrix[bottom][j]);
        }
        //right column
        for(int i=bottom-1;i>=top;i--){
            store.push_back(matrix[i][right]);
        }
        //top row
        for(int j=right-1;j>left;j--){
            store.push_back(matrix[top][j]);
        }
        
        int len= store.size();
        int rot= r %len;
        
        vector<int>rotated(len);
        
        for (int i = 0; i < len; i++) {
            rotated[(i + rot) % len] = store[i];
        }
        int idx=0;
        
        //left column
        for(int i=top;i<=bottom;i++){
            // store.push_back(matrix[left][i]);
            matrix[i][left]=rotated[idx++];
        }
        //bottom row;
        for(int j=left+1;j<=right;j++){
            // store.push_back(matrix[bottom][j]);
            matrix[bottom][j]=rotated[idx++];
        }
        //right column
        for(int i=bottom-1;i>=top;i--){
            // store.push_back(matrix[i][right]);
            matrix[i][right]= rotated[idx++];
        }
        //top row
        for(int j=right-1;j>left;j--){
            // store.push_back(matrix[top][j]);
            matrix[top][j]= rotated[idx++];
        } 
        
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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

[View on HackerRank](https://www.hackerrank.com/challenges/matrix-rotation-algo/problem)