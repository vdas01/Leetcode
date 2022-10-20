//https://leetcode.com/problems/integer-to-roman/submissions/826361649/

class Solution {
public:
    string intToRoman(int num) {
        map<int,string,greater<int>>m = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50, 
         "L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
         string roman;
        for(auto it:m){
            if (num < 0)return roman;
            while(num>=it.first){
                roman+=m[it.first];
                num-=it.first;
            }
        }
        return roman;
    }
};
