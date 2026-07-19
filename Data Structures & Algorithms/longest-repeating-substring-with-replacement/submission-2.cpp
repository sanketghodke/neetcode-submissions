class Solution {
public:
    int characterReplacement(string s, int k) {
        // length - max freq() >= k

        int left=0;
        vector<int> freq(26,0);
        int res = 0;
        
        for(int right = 0 ; right<s.size(); right ++){
            freq[s[right]-'A']++;
            int maxf = 0;
            for(int i=0; i<26;i++){
                maxf=max(maxf,freq[i]);
            }
            if(right-left+1 - maxf <= k){
                res = max(res, right-left+1);
            }
            else{
                freq[s[left]-'A']--;
                left++;
            }
        }
        return res;

            
        
    }
    
};
