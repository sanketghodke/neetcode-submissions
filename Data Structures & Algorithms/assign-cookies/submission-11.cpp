class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int left = 0;
        int right = 0;
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());

        while(left < s.size() && right < g.size()){
            if(g[right] <= s[left]){
                right++;
            }
            left++;
        }
        return right;
    }
};