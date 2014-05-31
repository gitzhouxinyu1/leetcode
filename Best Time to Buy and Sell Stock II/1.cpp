class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        
        int pro = 0, buy = prices[0], n = prices.size();
        for(int i=0; i<n-1; i++) {
            if(prices[i] > prices[i+1]) {
                pro += prices[i] - buy;
                buy = prices[i+1];
            }
        }
        pro += prices[n-1] - buy;
        return pro;
    }
};