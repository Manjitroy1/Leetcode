#define ll long long
class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        ll s1=accumulate(source.begin(),source.end(),0);
        ll s2=accumulate(target.begin(),target.end(),0);

        return s1==s2;
        
    }
};