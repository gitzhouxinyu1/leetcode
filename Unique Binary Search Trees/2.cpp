class Solution {
public:
    int numTrees(int n) {
        int w[n+1];
        w[0] = 1;
        w[1] = 1;
        for(int i=2; i<=n; i++) {
            int sum = 0;
            for(int j=0; j<i; j++) {
                sum += w[j] * w[i-j-1];
            }
            w[i] = sum;
        }
        return w[n];
    }
};


/*
动态规划要点：
1. 利用前结果
2. 利用实例推导公式（公式中包含前结果）


动态规划 ~= 递归的迭代实现

*/