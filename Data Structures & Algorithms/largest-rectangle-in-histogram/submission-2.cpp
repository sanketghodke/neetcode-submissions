class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // i need stack where i need to store pse

        stack<int> st;
        int maxA = INT_MIN;

        for(int i =0; i<heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()? -1: st.top();
                maxA = max(maxA, heights[element]* (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = heights.size();
            int element = st.top(); 
            st.pop();
            int pse = st.empty()? -1: st.top();
            maxA = max(maxA, heights[element]* (nse - pse - 1));
        }
        return maxA;
    }
};
