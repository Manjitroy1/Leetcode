class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long index = k - 1; // Convert to 0-based index
        int total_shifts = 0;
        
        for (int i = 0; i < operations.size(); i++) {
            // Check if the i-th bit of the index is 1
            if ((index >> i) & 1) {
                total_shifts += operations[i];
            }
            
            // Optional optimization: Stop early if index has no more 1-bits
            if ((index >> i) == 0) {
                break;
            }
        }
        
        return 'a' + (total_shifts % 26);
    }
};