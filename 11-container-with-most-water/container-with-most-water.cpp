class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0,end=height.size()-1,max_area=0;
        while(start<end)
        {
            int width= end-start;
            int minheight = min(height[start],height[end]);
            int area = width*minheight;

            max_area = max(max_area,area);

            if(height[start]<height[end])
            {
                start++;
            }
            else
            end--;

        }
        return max_area;

    }
};