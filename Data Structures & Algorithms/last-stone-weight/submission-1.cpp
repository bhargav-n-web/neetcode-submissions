class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      if(stones.size()<2)
        return stones[0];
      priority_queue<int> pq;
      for(auto st:stones){
        pq.push(st);
      }
      vector<int> wieghts(2,0);
      while(pq.size()>=2){
        wieghts[0]=pq.top();pq.pop();
        wieghts[1]=pq.top();pq.pop();
        int diff=wieghts[0]-wieghts[1];
        pq.push(diff);
      }
      return pq.top();

    }
};
