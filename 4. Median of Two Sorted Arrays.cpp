class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        // int cnt = 0; //find the first element

        // int ind1 = (n + m)/2 - 1, ind2 = (m + n)/2;
        // int ele1 = -1, ele2 = -1;

        // int i=0, j=0;

        // while(i < n && j < m)
        // {
        //     if(nums1[i] < nums2[j])
        //     {
        //         if(cnt == ind1) ele1 = nums1[i];
        //         if(cnt == ind2) ele2 = nums1[i];
        //         cnt++;
        //         i++;
        //     }
        //     else
        //     {
        //         if(cnt == ind1) ele1 = nums2[j];
        //         if(cnt == ind2) ele2 = nums2[j];
        //         cnt++;
        //         j++; 
        //     }
        // }

        // while(i < n){
        //     if(cnt == ind1) ele1 = nums1[i];
        //     if(cnt == ind2) ele2 = nums1[i];
        //     cnt++;
        //     i++;
        // }

        // while(j < m){
        //     if(cnt == ind1) ele1 = nums2[j];
        //     if(cnt == ind2) ele2 = nums2[j];
        //     cnt++;
        //     j++;
        // }

        // int totalSize = n + m;

        // if(totalSize % 2 == 1){
        //     return ele2;
        // }
        // else{
        //     return ((double)(ele1 + ele2) /2.0);
        // }


        /* O(min(logn, logm)) */

    int totalSize = n + m;
    int leftPart = (totalSize+1)/2;//divide the array into left and right part 

    //swap the array
    if(n > m){
        return findMedianSortedArrays(nums2, nums1);
    }

    int low = 0, high = n;


    while(low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = leftPart - mid1;

        //calculated the l1, l2 , r1 and r2
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n){
            r1 = nums1[mid1];
        }
        if(mid2 < m){
            r2 = nums2[mid2];
        }
        if(mid1 > 0){
            l1 = nums1[mid1 - 1];
        }
        if(mid2 > 0){
            l2 = nums2[mid2 - 1];
        }

        if(l1 <= r2 && l2 <= r1){
            if(totalSize % 2 == 1){
                return max(l1, l2);
            }
            else{
                return ((double)(min(r1, r2) + max(l1, l2)))/2.0;
            }
        }

        else if(l1 > r2){
            high = mid1 - 1;
        }
        else {
            low = mid1 + 1;
        }
        
    }
        return 0;
    }
};
