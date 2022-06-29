    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        int lmax=height[0],rmax=height[j];
        int ans=0;
        
        while(i<j)
        {
            if(height[i]<height[j])
            {
                lmax=max(lmax,height[i]);
                ans+=lmax-height[i++];
            }
            else
            {
                rmax=max(rmax,height[j]);
                ans+=rmax-height[j--];
            }
        }
        return ans;
    }
