#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include<climits>
using namespace std;

long long ans = LLONG_MAX;

void solve(int idx, long long currSum, long long totalSum, vector<int>& nums) {
    if (idx == nums.size()) {
        long long otherSum = totalSum - currSum;
        ans = min(ans, abs(currSum - otherSum));
        return;
    }

    
    solve(idx + 1, currSum + nums[idx], totalSum, nums);

   
    solve(idx + 1, currSum, totalSum, nums);
}

int main() {
    int n;
    cin >> n;
    vector<int> apples(n);
    for (int i = 0; i < n; i++) cin >> apples[i];

    long long totalSum = accumulate(apples.begin(), apples.end(), 0LL);

    solve(0, 0, totalSum, apples);

    cout << ans << "\n";
    return 0;
}
