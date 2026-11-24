class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<long> distance;vector<vector<int>>ans;
        priority_queue<long,vector<long>,greater<long>>pq;
        unordered_map<long,vector<vector<int>>> u;
        for(auto x:points){
            long dist=x[0]*x[0]+x[1]*x[1];
            u[dist].push_back(x);
            pq.push(dist);
        }
        int count=0;
        while(count<k){
            long key=pq.top();
            for(auto x:u[key]){
                ans.push_back(x);
                count++;
            }
            u[key].clear();
            pq.pop();
        }
        return ans;

    }
};
