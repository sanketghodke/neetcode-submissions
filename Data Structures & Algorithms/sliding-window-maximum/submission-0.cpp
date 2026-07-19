class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int, int>> pq; 
        // {value, index}

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Add current element
            pq.push({nums[i], i});

            // When window size reaches k
            if (i >= k - 1) {

                // Remove elements outside the window
                while (pq.top().second <= i - k) {
                    pq.pop();
                }

                // Maximum element is at the top
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};