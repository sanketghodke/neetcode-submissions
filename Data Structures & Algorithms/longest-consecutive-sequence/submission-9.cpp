class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        if(! nums.size()) return 0;
        int fin_ans=1;
        for(auto it: nums){
            int ans=1;
            if(! st.count(it-1)){
                // this is a starting point of sequence
                // it is the first element
                
                while(st.count(it+1)){
                    ans++;
                    it++;
                }
            }
            else{
                
                ans = 1;
            }
            if(fin_ans < ans) {
                fin_ans=ans;}
        }
        return fin_ans;
    }
};
