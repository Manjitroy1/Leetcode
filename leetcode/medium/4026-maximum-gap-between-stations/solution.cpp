class Solution {
public:

    bool possible(string skill, string station, int mid) {

        int n = skill.size();
        int m = station.size();

        int first = 0;

        while (first < m && station[first] != skill[0]) {
            first++;
        }

        if (first == m)
            return false;

        int j = 1;
        int last = first;

        for (int i = first + 1; i < m && j < n; i++) {

            if (station[i] == skill[j] && (i - last >= mid)) {

                j++;
                last = i;

                if (j >= n)
                    return true;
            }
        }

        return false;
    }

    int maximumGap(string skill, string station) {

        int n = skill.size();
        int m = station.size();

        if (n == 1)
            return 0;

        int l = 0;
        int h = m - 1;

        int ans = 0;

        while (l <= h) {

            int mid = (l + h) >> 1;

            if (possible(skill, station, mid)) {

                ans = mid;       // NOT h
                l = mid + 1;

            } else {

                h = mid - 1;
            }
        }

        return ans;
    }
};