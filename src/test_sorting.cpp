#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "../include/my_sorting.h"

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
	start = std::chrono::steady_clock::now();
    }

    ~Timer()
    {
	end = std::chrono::steady_clock::now();
	duration = end - start;

	float ms = duration.count() * 1000.0f;
	std::cout << "Timer took: " << ms << "ms" << std::endl;
    }
};

void printVector(const std::vector<int>& v)
{
    std::cout << "( ";
    for(const int& elem : v)
    {
	std::cout << elem << " ";
    }
    std::cout << ")" << std::endl;
}

bool vectorSorted(const std::vector<int>& v)
{
    bool sorted = true;

    if(v.size() <= 1)
	return sorted;

    for(int i=1; i < v.size(); i++)
    {
	if(v[i] < v[i-1])
	{
	    sorted = false;
	    break;
	}
    }

    return sorted;
}

void randomizeVector(std::vector<int>& v)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 100);

    for(int& elem : v)
    {
	elem = distrib(gen);
    }
}

int main()
{

    /* Testing if my implementation of merge sort is working correctly*/
    std::vector<int> vec(15);
    randomizeVector(vec);

    std::cout << "Is sorted(" << ((vectorSorted(vec)) ? "True" : "False") << "): ";
    printVector(vec);

    mergeSort(vec);

    std::cout << "Is sorted(" << ((vectorSorted(vec)) ? "True" : "False") << "): ";
    printVector(vec);


    /* Testing the time performance of my merge sort implementation*/
    int max_iter = 10;
    int num_elem = 100;
    double my_total_time = 0;

    for(int i=0; i < max_iter; i++)
    {
	std::vector<int> vec(num_elem);
	randomizeVector(vec);

	auto start = std::chrono::steady_clock::now();
	mergeSort(vec);
	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> elapsed_sec = end - start;
	std::cout << elapsed_sec.count()*1000.0f << std::endl;

        my_total_time += elapsed_sec.count() * 1000.0f;
    }
    std::cout << "My avg time: " << my_total_time/max_iter << " ms" << std::endl;
}
