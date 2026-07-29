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
