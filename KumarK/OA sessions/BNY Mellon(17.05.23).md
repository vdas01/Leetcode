//https://leetcode.com/discuss/interview-question/3532259/BNY-Melon-SETUP-HackerRank-questions

```
#include <iostream>
#include <vector>
using namespace std;

char findLongestSingleSlot(vector<vector<int>>& a) {
    int ans = 0;
    int nurseid = -1;
    int startTime = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i][1] - startTime > ans) {
            ans = a[i][1] - startTime;
            nurseid = a[i][0];
        }
        startTime = a[i][1];
    }
    return 'a' + nurseid;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    cout << findLongestSingleSlot(a) << endl;

    return 0;
}
