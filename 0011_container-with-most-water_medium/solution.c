class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int maxarea=0;
        int r = height.size()-1;
        while(l<r){
            int area = min(height[l],height[r])*(r-l);
            maxarea=max(maxarea,area);
            if(height[l]<=height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
    }
};