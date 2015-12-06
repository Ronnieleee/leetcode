// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Ronnie
// Date   : 2015-12-06

/*******************************************************************************
*
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays.
* The overall run time complexity should be O(log (m+n)).
*
*******************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

/* using vector
double findKth(vector<int> &v1, vector<int> &v2, int k) {
    int m = v1.size();
    int n = v2.size();
    vector<int> v3;

    if (m > n) {
        return findKth(v2, v1, k);
    }
    if (m == 0) {
        return v2[k-1];
    }
    if (k == 1) {
        return min(v1[0], v2[0]);
    }

    int p1 = min(k / 2, m);
    int p2 = k - p1;
    if (v1[p1-1] < v2[p2-1]) {
        v3 = vector<int>(find(v1.begin(), v1.begin(), v1[p1]), v1.end());
        return findKth(v3, v2, k-p1);
    }
    else if (v1[p1 - 1] > v2[p2 - 1]) {
        v3 = vector<int>(find(v2.begin(), v2.end(), v2[p2]), v2.end());
        return findKth(v1, v3, k-p2);
    }
    else
        return v1[p1 - 1];
}

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int total = nums1.size() + nums2.size();
        if (total & 0x1)
            return findKth(nums1, nums2, total / 2 + 1);
        else
            return (findKth(nums1, nums2, total / 2)
                    + findKth(nums1, nums2, total / 2 + 1)) / 2;
    }
};
*/

double findKth(int a[], int m, int b[], int n, int k)
{
    //always assume that m is equal or smaller than n
    if (m > n)
        return findKth(b, n, a, m, k);
    if (m == 0)
        return b[k - 1];
    if (k == 1)
        return min(a[0], b[0]);
    //divide k into two parts
    int pa = min(k / 2, m), pb = k - pa;
    if (a[pa - 1] < b[pb - 1])
        return findKth(a + pa, m - pa, b, n, k - pa);
    else if (a[pa - 1] > b[pb - 1])
        return findKth(a, m, b + pb, n - pb, k - pb);
    else
        return a[pa - 1];
}

class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        int total = m + n;
        if (total & 0x1)
            return findKth(A, m, B, n, total / 2 + 1);
        else
            return (findKth(A, m, B, n, total / 2)
                    + findKth(A, m, B, n, total / 2 + 1)) / 2;
    }
};
