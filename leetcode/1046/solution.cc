class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while(q.size() > 1) {
            int top1 = q.top();
            q.pop();
            int top2 = q.top();
            q.pop();
            int sub = top1 - top2;
            if(sub > 0) q.push(sub);
        }
        return q.size() == 0 ? 0 : q.top();
    }
};
