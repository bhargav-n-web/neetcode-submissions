class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0,left;stack<int> st;heights.push_back(0); 
        for(int right=0;right<heights.size();right++){
            while(!st.empty()&&heights[st.top()]>heights[right]){
                left=st.top();
                st.pop();
                int width=st.empty()?right:right-st.top()-1;
                ans=max(ans,heights[left]*width);
            }
           
            st.push(right);
        }
        return ans;
    }
};
