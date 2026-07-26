class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto it: stones){
            q.push(it);
        }

        while(q.size()>1){
            int num1 = q.top();
            q.pop();
            int num2 = q.top();
            q.pop();
            if(num1 != num2) {
                q.push(num1-num2);
            }
        }
        if(q.size()==1) return q.top();
        return 0;
    }
};
