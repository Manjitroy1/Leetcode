class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        // left[k] = all possible sums by choosing k elements from left half
        // right[k] = all possible sums by choosing k elements from right half
        vector<vector<int>> left(half + 1), right(half + 1);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Generate all subset sums
        for (int mask = 0; mask < (1 << half); mask++) {
            int cnt = 0;
            int leftSum = 0;
            int rightSum = 0;

            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    leftSum += nums[i];
                    rightSum += nums[i + half];
                }
            }

            left[cnt].push_back(leftSum);
            right[cnt].push_back(rightSum);
        }

        // Sort all right subset sums
        for (int i = 1; i <= half; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // Choose i elements from left and half-i from right
        for (int i = 1; i <= half; i++) {

            int need = half - i;

            for (int leftSum : left[i]) {

                double target = totalSum / 2.0 - leftSum;

                auto &vec = right[need];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int chosen = leftSum + *it;
                    ans = min(ans, abs(totalSum - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    int chosen = leftSum + *it;
                    ans = min(ans, abs(totalSum - 2 * chosen));
                }
            }
        }

        return ans;
    }
};