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
