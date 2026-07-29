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
