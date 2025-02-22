/*
LC 4. Median of Two Sorted Arrays

Ideas:
    1. Merge the two sorted arrays and find the median
    2. Merge only upto half the length of the combined array and find the median. 
    
    3. Binary Search to achieve logaritmic time complexity
        3.1 Let k be the index of the target element (median) that we are looking for 
        3.2 Consider Amid <= Bmid
        3.3 We know that 
            3.3.1 Aleft <= Amid <= Aright
            3.3.2 Bleft <= Bmid <= Bright
        3.4 From 3.3.1 and 3.2 we can say that
            3.4.1 Aleft <= Amid <= Bmid <= Bright ====> Aleft <= Bright
            3.4.2 Therefore, Aleft <= Bright and Aleft <= Aright
        3.5 Similarly
            3.5.1 Bright >= Bleft and Bright >= Aleft
        3.6 Based on the index k, we can say that:
            3.6.1 if k > (A+B)/ 2, then we can SAFELY discard Aleft (Why can't we dicard Bleft? We can't say anything about the relation between Bleft and Aright, so we don't know which elements from Bleft or Aright are in the SECOND half of the combined array)
                3.6.1.1. While doing this, we also need to update k to k - (m/2) (Why? Because we are removing m/2 elements that are smaller than the kth element)
            3.6.2 Else, we can SAFELY discard Bright (Why not Aright? We can't say anything about the relation between Bleft and Aright, so we don't know which elements from Bleft or Aright are in the FIRST half of the combined array)
                3.6.2.1 We don't need to update k in this case (Why? The k smalles elements are still in the array)
        3.7 Similar argument for Bmid <= Amid
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
        int binary(vector<int>& nums1, vector<int>& nums2, int k, int start1, int end1, int start2, int end2){
            if(end1 < start1)
                return nums2[k-start1];
            
            if(end2 < start2)
                return nums1[k-start2];
            
            int mid1 = (start1 + end1) / 2;
            int mid2 = (start2 + end2) / 2;

            int mid_value1 = nums1[mid1];
            int mid_value2 = nums2[mid2];

            if(k > mid1+mid2){
                if(mid_value1 <= mid_value2){
                    return binary(nums1, nums2, k, mid1+1, end1, start2, end2);
                }
                else
                    return binary(nums1, nums2, k, start1, end1, mid2+1, end2);
            }
            else{
                if(mid_value1 <= mid_value2){
                    return binary(nums1, nums2, k, start1, end1, start2, mid2-1);
                }
                else
                    return binary(nums1, nums2, k, start1, mid1-1, start2, end2);
            }

            return -1;
        }
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();

            int total = m+n;

            if(total % 2){
                return binary(nums1, nums2, total/2, 0, m-1, 0, n-1);
            }
            else{
                return 1.0 * (binary(nums1, nums2, total/2, 0, m-1, 0, n-1) + binary(nums1, nums2, total/2 - 1, 0, m-1, 0, n-1)) / 2;
            }
        }
};

int main(){
    Solution s;
    return 0;
}