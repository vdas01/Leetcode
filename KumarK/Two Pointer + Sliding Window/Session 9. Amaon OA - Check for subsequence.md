//https://practice.geeksforgeeks.org/problems/check-for-subsequence4930/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


class Solution{
    public:
    bool isSubSequence(string A, string B) 
    {
        // code here
        int i = 0 , j =0;
        int n = A.length(), m = B.length();
        while(i < n && j < m){
            if(A[i] == B[j]){
                i++;
                j++;
            }
            else j++;
        }
        return i == n;
    }
};
