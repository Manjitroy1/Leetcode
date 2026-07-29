# Bear and Steady Gene

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A gene is represented as a string of length $n$ (where $n$ is divisible by $4$), composed of the letters $\text{A}$, $\text{C}$, $\text{T}$, and $\text{G}$.
It is considered to be *steady* if each of the four letters occurs exactly $\frac{n}{4}$ times.  For example, $\text{GACT}$ and $\text{AAGTGCCT}$ are both steady genes.

Bear Limak is a famous biotechnology scientist who specializes in modifying bear DNA to make it steady.  Right now, he is examining a gene represented as a string $gene$.  It is not necessarily steady.  Fortunately, Limak can choose one (maybe empty) substring of $gene$ and replace it with any string of the same length.

Modifying a large substring of bear genes can be dangerous.
Given a string $gene$, can you help Limak find the length of the smallest possible substring that he can replace to make $gene$ a steady gene?

*Note*: A substring of a string $s$ is a subsequence made up of zero or more *contiguous* characters of $s$.

As an example, consider $gene = ACTGAAAG$.  The substring $AA$ just before or after $G$ can be replaced with $CT$ or $TC$.  One selection would create $ACTGACTG$.

**Function Description**

Complete the $steadyGene$ function in the editor below.  It should return an integer that represents the length of the smallest substring to replace.  

steadyGene has the following parameter:  

- *gene*: a string

**Input Format**

The first line contains an interger $n$ divisible by $4$, that denotes the length of a string $gene$.  
The second line contains a string $gene$ of length $n$.


**Constraints**

- $4 \le n \le 500\,000$  
- $n$ is divisible by $4$  
- $gene[i] \in [CGAT]$  

**Subtask**  

- $4 \le n \le 2000$ in tests worth $30\%$ points.

**Output Format**

Print the length of the minimum length substring that can be replaced to make $gene$ stable.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-29T05:52:51.931Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

int getIdx(char ch) {
    if (ch == 'A') return 0;
    if (ch == 'C') return 1;
    if (ch == 'G') return 2;
    return 3; // T
}

int steadyGene(string gene) {
    int n = gene.size();
    int req = n / 4;

    vector<int> freq(4, 0);

    // Count frequencies
    for (char ch : gene)
        freq[getIdx(ch)]++;

    // Already steady
    if (freq[0] == req && freq[1] == req &&
        freq[2] == req && freq[3] == req)
        return 0;

    int ans = n;
    int l = 0;

    for (int r = 0; r < n; r++) {

        // Character enters window, so remove it from outside counts
        freq[getIdx(gene[r])]--;

        // If outside window is already valid,
        // try shrinking the window.
        while (l <= r &&
               freq[0] <= req &&
               freq[1] <= req &&
               freq[2] <= req &&
               freq[3] <= req) {

            ans = min(ans, r - l + 1);

            // Move left boundary
            freq[getIdx(gene[l])]++;
            
            l++;
        }
    }

    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

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

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/bear-and-steady-gene/problem)