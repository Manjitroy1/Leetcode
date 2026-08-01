#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stringSimilarity' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int brute(string& s){
    int n=s.size();
    int ans=n;
    for(int i=n-1;i>=1;i--){
        
        if(s[0]==s[i]){
            int cnt=0;
            int j=0;
            int k=i;
            while( k<n && s[j]==s[k]){
                j++;
                k++;
                cnt++;
            }
            ans+=cnt;
        }
    }
    return ans;
}
long long better(string s) {
    int n = s.size();

    vector<int> z(n, 0);

    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {

        if (i <= R)
            z[i] = min(R - i + 1, z[i - L]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }

    long long ans = n;

    for (int i = 1; i < n; i++)
        ans += z[i];

    return ans;
}
long long stringSimilarity(string s) {
    // return brute(s);
    return better(s);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        long long result = stringSimilarity(s);

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
