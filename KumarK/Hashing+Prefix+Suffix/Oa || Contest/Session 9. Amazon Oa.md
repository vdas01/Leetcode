//https://leetcode.com/discuss/interview-question/3114099/AMAZON-OA-(INTERN-2024)

```
int calcRemovalCount(string &word, string &target) {
    int word_counts[26] = {0,}, target_counts[26] = {0,};
    for (char ch: word) {
        word_counts[ch - 'a'] += 1;
    }
    for (char ch: target) {
        target_counts[ch - 'a'] += 1;
    }
    int ans = INT_MAX;
    for (char ch: target) {
        ans = min(ans, word_counts[ch - 'a'] / target_counts[ch - 'a']);
    }
    return ans;
}
```
### or do using map
