//一个游标指向A数组m+n-1,另外两个游标指向A的m-1和B的n-1；比较大小，较大的放在A中；
//需要注意的是检查两个数组的游标是否为0；
class Solution {
public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                int k = 0;
                int i = m-1;
                int j = n-1;
                for (k = m + n -1 ;k>=0;k--) {
                        if (i>=0 && j>=0 && nums1[i] >= nums2[j]) {
                                nums1[k] = nums1[i--];
                        } 
                        else if(i>=0 && j>=0 && nums1[i] < nums2[j]) {
                                nums1[k] = nums2[j--];
                        }
                        else if (i<0 && j>=0) {
                                nums1[k] = nums2[j--];
                        }
                        else {
                                nums1[k] = nums1[i--];
                        }
                }
        }
};
