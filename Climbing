class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        int p2 = 1;
        int p1 = 1;
        for(int i = 2;i<=n;i++){
          int current = p1 + p2;
          p2 = p1;
          p1 = current;
        }
        return p1;
    }
    
};
