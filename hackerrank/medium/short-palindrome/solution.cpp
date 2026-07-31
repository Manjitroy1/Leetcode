#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'shortPalindrome' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

const long long md=1e9+7;
int shortPalindrome(string& s) {
    long long ans=0;
    long long cnt1[26]={0};
    long long cnt2[26][26] ={0};
    long long cnt3[26][26]={0};
    
    // we will traverse from left to right and store
    // number of single char is there like a
    //number of double char like ab
    // for axx if the currecnt char is x then we find number of ax is availibale
    //if the current char is x we find number of xbb is there
    for(int i=0;i<s.size();i++){
        int x= s[i]-'a';
        
        //axxa
        for(int j=0;j<26;j++){              //check total number of xyy
            ans = (ans + cnt3[x][j]) %md;   // as current char is x
        }
        //axx
        for(int j=0;j<26;j++){
            cnt3[j][x] = (cnt3[j][x] + cnt2[j][x]) %md;  //check total number of ax 
                                                          // as current char is x
        }
        
        //ax
        for(int j=0;j<26;j++){
            cnt2[j][x] = (cnt2[j][x] + cnt1[j]) % md;
        }
        
        //x
        cnt1[x] = (cnt1[x] + 1)%md;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = shortPalindrome(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
