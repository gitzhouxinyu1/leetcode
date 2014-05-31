class Solution {
public:
    int reverse(int x) {
        char chars[10];
        int n;
        // to reverse char array
        int_to_revDigit(x, chars, &n);
        // to int
        return digit_to_int(chars, n);
    }
    
private:
    void int_to_revDigit(int x, char *chars, int *n) {
        int i = 0;
        if(x < 0) {
            x = -x;
            chars[i++] = '-';
        }
        while(x > 0) {
            chars[i++] = x % 10 + '0';
            x = x / 10;
        }
        *n = i;
    }
    
    int digit_to_int(char *chars, int n) {
        if(n < 1) return 0;
        
        int sum = 0, i = 0, sign = 1;
        if(chars[0] == '-') {
            sign = -1;
            i++;
        }
        while(i < n) {
            sum = sum * 10 + chars[i++] - '0';
        }
        return sign*sum;
    }
};