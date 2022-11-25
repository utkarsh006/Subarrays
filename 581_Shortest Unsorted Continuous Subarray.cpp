class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();

        
          if(n==1) return 0;
          
          for(int i=0; i<n; i++)
          {
              //if an element is not in ascending order then it's a
              // problematic element

                if(i==0) //check right neighbour only
                {
                    if(nums[i]>nums[i+1])
                    {
                        mini = min(mini,nums[i]);
                        maxi = max(maxi,nums[i]);
                    }
                }

                else if(i==n-1) //check left neighbour only
                {
                     if(nums[i]<nums[i-1])
                     {
                        mini = min(mini,nums[i]);
                        maxi = max(maxi,nums[i]);
                     }
                }

                else //conditions for being a problematic element
                {
                    if(nums[i]> nums[i+1] || nums[i]<nums[i-1])
                    {
                       mini = min(mini,nums[i]);
                       maxi = max(maxi,nums[i]);
                    }
                }
          }

        //array is already sorted
        if(mini == INT_MAX || maxi == INT_MIN) return 0;

          //find the position of min and max element
          // do max-min to find the length

            int i,j;

            for(i=0; i<n && nums[i]<=mini; i++);      //min element position
            for(j=n-1; j>=0 && nums[j]>=maxi; j--);  //max element position

            return j-i+1;
    }
};
