# Morgan and a String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Jack and Daniel are friends. Both of them like letters, especially uppercase ones.  
They are cutting uppercase letters from newspapers, and each one of them has his collection of letters stored in a stack. 

One beautiful day, Morgan visited Jack and Daniel. He saw their collections. He wondered what is the lexicographically minimal string made of those two collections. He can take a letter from a collection only when it is on the top of the stack.  Morgan wants to use all of the letters in their collections.  

As an example, assume Jack has collected $a = [A,C,A]$ and Daniel has $b = [B,C,F]$.  The example shows the top at index $0$ for each stack of letters. Assemble the string  as follows:  

```
Jack	Daniel	result
ACA	BCF
CA	BCF	A
CA	CF	AB
A	CF	ABC
A	CF	ABCA
    	F	ABCAC
    		ABCACF
```
**Note** the choice when there was a tie at `CA` and `CF`.

**Function Description**  

Complete the *morganAndString* function in the editor below.  

morganAndString has the following parameter(s):  

- *string a*: Jack's letters, top at index $0$  
- *string b*: Daniel's letters, top at index $0$  

Returns  
- *string*: the completed string  

**Input Format**

The first line contains the an integer $t$, the number of test cases.  

The next $t$ pairs of lines are as follows:  
- The first line contains string $a$  
- The second line contains string $b$.  



**Constraints**

- $1 \le T \le 5$  
- $1 \le |a|, |b| \le 10^5$  
- $a$ and $b$ contain upper-case letters only, ascii[A-Z].

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-29T12:55:02.877Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'morganAndString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

// string morganAndString(string a, string b) {
//     string ans="";
//     int l=0;
//     int l2=0;
//     while(l<a.size() && l2<b.size()){
//         if(a[l]<b[l2]){
//             ans+=a[l++];
//         }
//         else if(a[l]>b[l2]){
//             ans+=b[l2++];
//         }else{
//             int x=l;
//             int y=l2;
//             while(x<a.size() && y<b.size() && a[x]==b[y]){
//                 x++;
//                 y++;
//             }
//             if(x==a.size()){
//                 ans+=a[l++];
//             }
//             else if(y==b.size()){
//                 ans+=b[l2++];
//             }
//             else if(a[x]<b[y]){
//                 ans+=a[l++];
//             }
//             else{
//                 ans+=b[l2++];
//             }
//         }
//     }
//     while(l<a.size()){
//         ans+=a[l++];
//     }
//     while(l2<b.size()){
//         ans+=b[l2++];
//     }
//     return ans;
// }

string morganAndString(string a, string b) {
    a += '{';
    b += '{';

    int i = 0, j = 0;
    string ans;

    while (i < a.size() - 1 || j < b.size() - 1) {

        if (a.compare(i, string::npos, b, j, string::npos) <= 0)
            ans += a[i++];
        else
            ans += b[j++];
    }

    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = morganAndString(a, b);

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

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/morgan-and-a-string/problem)