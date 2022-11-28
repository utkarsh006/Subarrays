class Solution {
public:

// i+1 indicates the number of index present on the left of array including arr[i] and n-i indicates how many index are present to the right of array including arr[i]

    int sumOddLengthSubarrays(vector<int>& arr)
    {
        int sum=0,n=arr.size();

        for(int i=0;i<n;i++)
        {
            int temp=((i+1)*(n-i)+1)/2;
            sum+=temp*arr[i];
        }
        return sum;
    }
};
