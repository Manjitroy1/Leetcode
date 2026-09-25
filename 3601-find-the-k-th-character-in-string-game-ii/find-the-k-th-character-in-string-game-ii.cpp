class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        int n = operations.size();

        // Length after all operations
        __int128 len = 1;

        for (int i = 0; i < n; i++) {
            len *= 2;
        }

        int cnt = 0;

        // Work backwards
        for (int i = n - 1; i >= 0; i--) {

            __int128 half = len / 2;

            if ((__int128)k > half) {

                // k lies in the second half
                k -= (long long)half;

                if (operations[i] == 1)
                    cnt++;
            }

            // Move to the previous string
            len = half;
        }

        return char('a' + (cnt % 26));
    }
};