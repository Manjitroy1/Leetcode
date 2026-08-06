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
