#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        if (m == 0 && n == 0)
            return 0.0;

        int i(0), j(0), k(0);
        bool end_of_num1(false), end_of_num2(false);
        vector<int> sort_nums;

        for (k = 0; k < (m + n) / 2 + 1; ++k)
        {
            if (i == m)
            {
                end_of_num1 = true;
                break;
            }

            if (j == n)
            {
                end_of_num2 = true;
                break;
            }

            if (nums1[i] < nums2[j])
            {
                sort_nums.push_back(nums1[i]);
                ++i;
            }
            else
            {
                sort_nums.push_back(nums2[j]);
                ++j;
            }
        }

        if (end_of_num1)
        {
            for (; k < (m + n) / 2 + 1; ++k, ++j)
                sort_nums.push_back(nums2[j]);
        }
        else if (end_of_num2)
        {
            for (; k < (m + n) / 2 + 1; ++k, ++i)
                sort_nums.push_back(nums1[i]);
        }

        if ((m + n) % 2 == 1)
            return (double)sort_nums[(m + n) / 2];
        else
            return (sort_nums[(m + n) / 2 - 1] + sort_nums[(m + n) / 2]) / 2.0;
    }
};

void testCase1()
{
    int aNums1[2] = {1, 3};
    int aNums2[1] = {2};
    vector<int> vNums1(aNums1, aNums1 + 2);
    vector<int> vNums2(aNums2, aNums2 + 1);
    Solution s;
    double result = s.findMedianSortedArrays(vNums1, vNums2);
    cout << result << endl;
}

void testCase2()
{
    int aNums1[2] = {1, 2};
    int aNums2[2] = {3, 4};
    vector<int> vNums1(aNums1, aNums1 + 2);
    vector<int> vNums2(aNums2, aNums2 + 2);
    Solution s;
    double result = s.findMedianSortedArrays(vNums1, vNums2);
    cout << result << endl;
}

int main()
{
    testCase1();
    testCase2();
    return 0;
}