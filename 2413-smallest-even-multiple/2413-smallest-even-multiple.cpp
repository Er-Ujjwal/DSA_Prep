class Solution {
public:
    int findGCD(int a, int b){
        while (b != 0){
            int rem = a%b;
            a = b;
            b = rem;
        }
        return a;
    }
    int smallestEvenMultiple(int n) {
        return ((2/findGCD(2,n))*n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna