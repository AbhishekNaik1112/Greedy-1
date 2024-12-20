// Non Overlapping Intervals - https://leetcode.com/problems/non-overlapping-intervals/description/

// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

// Constraints:

// 1 <= intervals.length <= 105
// intervals[i].length == 2
// -5 * 104 <= starti < endi <= 5 * 104    


#include <bits/stdc++.h>
using namespace std;

int calculate(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });  //sorting acc to 2nd el
    int res = 0;
    int end = INT_MIN;
    for (auto& i : arr) {
        if (i[0] < end) res++;
        else end = i[1];
    }
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << calculate(arr) ;
    return 0;
}
