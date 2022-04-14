#include <iostream>
#include <vector>


void printVector(std::vector<int>& v)
{
    std::cout << "( ";
    for(const int& elem : v)
    {
	std::cout << elem << " ";
    }
    std::cout << ")" << std::endl;
}

// I need two functions, a general mergeSort and a merging function that takes as input
// two sorted arrays
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



int main()
{
    std::vector<int> vec = {3, 6, 7, 69, 76, 8, 987, 34, 56, 78, 93, 81, 69};

    std::cout << "Before sorting: ";
    printVector(vec);

    mergeSort(vec);

    std::cout << "After sorting: ";
    printVector(vec);
}
