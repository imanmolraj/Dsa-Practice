class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26,0);
        for(int i =0;i<s.size();i++)
        {
            count[s[i]-'a']++;
        }

        string ans;
        for(char i : order)
        {
            int char_ind= i-'a';
            while(count[char_ind])
            {
                ans+=i;
                count[char_ind]--;
            }
        }

        //remaining character left in s
        for(int i=0;i<26;i++)
        {
            while(count[i])
            {
                char c = 'a'+i;
                ans+=c;
                count[i]--;
            }
        }
        return ans;
    }
};