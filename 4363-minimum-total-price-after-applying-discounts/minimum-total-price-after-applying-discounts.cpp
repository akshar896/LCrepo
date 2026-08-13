class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(discounts.rbegin(),discounts.rend());
        sort(prices.rbegin(),prices.rend());
        double ans=0;
        int n=prices.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(j<discounts.size()){
                ans+=double(prices[i] * (100 - discounts[j])) / 100;
                j++;
            }
            else{
                ans+=prices[i];
            }
        }
        return ans;
    }
};