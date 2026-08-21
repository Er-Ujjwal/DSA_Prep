class Solution {
public:
    long long gcdll(long long a, long long b){
        while (b){
            long long t = a%b;
            a=b;
            b=t;
        }
        return a;
    }
    long long lcmll(long long a, long long b){
        return a/gcdll(a, b)*b;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto check = [&](long long x){
            long long cnt = 0;
            for (int mask = 1; mask < (1<<n); mask++){
                long long L = 1;
                bool ok = true;
                for (int i=0; i<n; i++){
                    if (mask & (1<<i)){
                        L = lcmll(L, coins[i]);
                        if (L > x){
                            ok = false;
                            break;
                        }
                    }
                }
                if (!ok) continue;
                if (__builtin_popcount(mask) & 1) cnt += x/L;
                else cnt -= x/L;
            }
            return cnt >= k;
        };
        long long lo = 1;
        long long hi = 1LL*(*min_element(coins.begin(), coins.end()))*k;
        while (lo < hi){
            long long mid = (lo + hi)/2;
            if (check(mid)) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna