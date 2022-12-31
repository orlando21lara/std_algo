#include "std_algo/sort.h"
#include <iostream>

// Working implementation of merge sort by recursively creating new vectors
std::vector<int> mergeVectors(const std::vector<int>& lv, const std::vector<int>& rv)
{
    std::vector<int> merged_vec(lv.size() + rv.size());

    int left_idx = 0, right_idx=0;
    for(int& elem : merged_vec)
    {
        if(left_idx >= lv.size())
        {
            elem = rv[right_idx++];
        }
        else if (right_idx >= rv.size())
        {
            elem = lv[left_idx++];
        }
        else if(lv[left_idx] > rv[right_idx])
        {
            elem = rv[right_idx++];
        }
        else
        {
            elem = lv[left_idx++];
        }
    }
    return merged_vec;
}

std::vector<int> mergeSort(const std::vector<int>& lv, const std::vector<int>& rv)
{
    std::vector<int> merged_left;
    std::vector<int> merged_right;
    if(lv.size() != 1)
    {
        std::vector<int> lv_left(lv.begin(), lv.begin() + (lv.size()/2));
        std::vector<int> lv_right(lv.begin() + lv_left.size(), lv.end());
        merged_left = mergeSort(lv_left, lv_right);
    }
    else
    {
        merged_left = lv;
    }

    if(rv.size() != 1)
    {
        std::vector<int> rv_left(rv.begin(), rv.begin() + (rv.size()/2));
        std::vector<int> rv_right(rv.begin() + rv_left.size(), rv.end());
        merged_right = mergeSort(rv_left, rv_right);
    }
    else
    {
        merged_right = rv;
    }

    return mergeVectors(merged_left, merged_right);
}

void mergeSort(std::vector<int>& vec)
{
    // The condition to stop the recursion should be when the vector is of size 1
    
    // Split the vector into two vectors and call merge sort on them
    std::vector<int> left_v(vec.begin(), vec.begin() + (vec.size()/2));
    std::vector<int> right_v(vec.begin() + left_v.size(), vec.end());

    vec = mergeSort(left_v, right_v);
}


// Second attempt at merge sort without creating new vectors recursively
void mergeSort2(std::vector<int>& vec)
{
    // From the original vector, I define indices that indicate the two halves in which the vector
    // would be split. The first half has the elements in the range left_idx -> mid_idx inclusive
    // The second half contains the elements mid_idx+1 -> right_idx inclusive
    int left_idx = 0;
    int right_idx = vec.size() - 1;
    int mid_idx = right_idx / 2;
    
    mergeSort2(vec, left_idx, mid_idx, right_idx);
}

void mergeSort2(std::vector<int>& vec, int left_idx=0, int mid_idx=0, int right_idx=0)
{
    if (left_idx == right_idx && left_idx == mid_idx)
    {
        // Nothing to do, there is only one element in this range so it is already sorted
        return;
    }
    
    // Compute two new halves from this range in the vector and call mergeSort separately on
    // the two sections. After the two function calls return, those two halves will be sorted
    int left_left_idx = left_idx;
    int left_right_idx = mid_idx;
    int left_mid_idx = left_left_idx + (left_right_idx - left_left_idx) / 2;

    int right_left_idx = mid_idx + 1;
    int right_right_idx = right_idx;
    int right_mid_idx = right_left_idx + (right_right_idx - right_left_idx) / 2;
    
    mergeSort2(vec, left_left_idx, left_mid_idx, left_right_idx);
    mergeSort2(vec, right_left_idx, right_mid_idx, right_right_idx);

    // From the two sorted portions of the split vector, I need to then merge its components by
    // making a call to the mergeHalves function and when this function returns then the two
    // halves will be sorted as a pair instead of being sorted individually
    mergeHalves(vec, left_idx, mid_idx, right_idx);
}

void mergeHalves(std::vector<int>& vec, int idx_l, int idx_m, int idx_r)
{
    idx_m++;

    while (idx_l < idx_m)
    {
        if (vec[idx_l] > vec[idx_m])
        {
            // Swap the element in the left vector and the first element in the right vector
            swap(vec, idx_l, idx_m);

            // The element that was taken from the left vector to the right vector should now be
            // moved further down the right vector until it is sorted
            int new_pos = idx_m;
            while(new_pos < idx_r && vec[new_pos] > vec[new_pos + 1])
            {
                swap(vec, new_pos, new_pos+1);
                new_pos++;
            }
        }

        idx_l++;
    }
}

void swap(std::vector<int> &v, int a, int b)
 {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
 }


