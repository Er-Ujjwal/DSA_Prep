class Solution {
public:
    int digitsum(int num){
        int sum = 0;
        while (num>0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        int sum = num;    
        while (sum > 9){
            sum = digitsum(sum);
        }
        return sum;
    }    // OPtimal SImple Mathematical Approach is :
         // if (n==0) return 0;
         // return 1+(n-1)%9;
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna