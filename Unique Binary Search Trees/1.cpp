class Solution {
public:
    int numTrees(int n) {
        return numTrees_iter(1, n);
    }
    
    int numTrees_iter(int start, int end) {
        if(start >= end)
            return 1;
        
        int totalNum = 0;
        for(int i=start; i<=end; i++) {
            totalNum += numTrees_iter(start, i-1) * numTrees_iter(i+1, end);
        }
        return totalNum;
    }
};