class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n=prices.size();
        int m=discounts.size();
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());

        double ans=0.0;
        
        int i=m-1;
        int j=n-1;
        while(i>=0 && j>=0){
            double p = (prices[j]*(100-discounts[i])) / 100.0 ;
            ans+=p;
            
            i--;
            j--;
        }
        
        while(j>=0){
            ans+= (double)prices[j];
            j--;
        }

        return ans;
        
    }
};