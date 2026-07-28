class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        string left="";
        string right="";
        string middle="";

        for(char c:s){
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            left.append(freq[i]/2,char('a'+i));
            if(freq[i]%2){
                middle=char('a'+i);
            }
        }
        right=left;
        sort(right.rbegin(),right.rend());
        return left+middle+right;

    }
};