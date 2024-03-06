#include <vector>
#include <iostream>
#include <cmath>

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    size_t total_size = (nums1.size() + nums2.size());
    if (nums1.empty())
    {
        if (nums2.size() % 2 == 0)
        {
            return (nums2[(nums2.size() / 2.0) - 1] + nums2[nums2.size() / 2.0]) / 2.0;
        }
        else
        {
            return nums2[nums2.size() / 2.0];
        }
    }
    else if (nums2.empty())
    {
        if (nums1.size() % 2 == 0)
        {
            return (nums1[(nums1.size() / 2.0) - 1] + nums1[nums1.size() / 2.0]) / 2.0;
        }
        else
        {
            return nums1[nums1.size() / 2.0];
        }
    }
    std::size_t i1 = 0, i2 = 0;
    if (total_size % 2 == 0)
    {
        std::size_t median_index2 = (int)(total_size / 2.0), median_index1 = median_index2 - 1;
        int median1 = 0;
        while (i1 < nums1.size() && i2 < nums2.size())
        {
            if (nums1[i1] < nums2[i2])
            {
                if ((i1 + i2) == median_index1)
                {
                    median1 = nums1[i1];
                }
                else if ((i1 + i2) == median_index2)
                {
                    return (median1 + nums1[i1]) / 2.0;
                }
                i1++;
            }
            else
            {
                if ((i1 + i2) == median_index1)
                {
                    median1 = nums2[i2];
                }
                else if ((i1 + i2) == median_index2)
                {
                    return (median1 + nums2[i2]) / 2.0;
                }
                i2++;
            }
        }
        if (i1 == nums1.size())
        {
            if ((i1 + i2) == median_index2)
            {
                return (median1 + nums2[median_index2 - nums1.size()]) / 2.0;
            }
            else
            {
                return (nums2[median_index1 - nums1.size()] + nums2[median_index2 - nums1.size()]) / 2.0;
            }
        }
        else
        {
            if ((i1 + i2) == median_index2)
            {
                return (median1 + nums1[median_index2 - nums2.size()]) / 2.0;
            }
            else
            {
                return (nums1[median_index1 - nums2.size()] + nums1[median_index2 - nums2.size()]) / 2.0;
            }
        }
    }
    else
    {
        std::size_t median_index = total_size / 2.0;
        while (i1 < nums1.size() && i2 < nums2.size())
        {
            if (nums1[i1] < nums2[i2])
            {
                if ((i1 + i2) == median_index)
                {
                    return nums1[i1];
                }
                i1++;
            }
            else
            {
                if ((i1 + i2) == median_index)
                {
                    return nums2[i2];
                }
                i2++;
            }
        }
        if (i1 == nums1.size())
        {
            return nums2[median_index - i1];
        }
        else
        {
            return nums1[median_index - i2];
        }
    }
}

int main()
{
    std::vector<int> n{1, 2}, m{3, 4};
    std::cout << "output: " << findMedianSortedArrays(n, m) << std::endl;
    std::cout << "output: " << findMedianSortedArrays(m, n) << std::endl;

    n = {}, m = {2, 3, 5};
    std::cout << "output: " << findMedianSortedArrays(n, m) << std::endl;
    std::cout << "output: " << findMedianSortedArrays(m, n) << std::endl;

    n = {1, 4}, m = {2, 3, 5};
    std::cout << "output: " << findMedianSortedArrays(n, m) << std::endl;
    std::cout << "output: " << findMedianSortedArrays(m, n) << std::endl;

    n = {2, 3, 4}, m = {1};
    std::cout << "output: " << findMedianSortedArrays(n, m) << std::endl;
    std::cout << "output: " << findMedianSortedArrays(m, n) << std::endl;

    n = {1, 2, 4}, m = {3};
    std::cout << "output: " << findMedianSortedArrays(n, m) << std::endl;
    std::cout << "output: " << findMedianSortedArrays(m, n) << std::endl;

    return 0;
}