#include "sorting.h"
#include <vector>
#include <chrono>
#include <algorithm>




int main()
{


	std::vector<int>test;


	


	nwacc::fill_vector(test, 50);



	/*
	nwacc::shuffle(test);

	//insertion sort
	auto start_time = std::chrono::high_resolution_clock::now();
	nwacc::insertion_sort(test);
	auto finish_time = std::chrono::high_resolution_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time).count();
	std::cout << "insertion sort " << elapsed_time << std::endl;


	nwacc::shuffle(test);


	//radix sort
	auto start_time = std::chrono::high_resolution_clock::now();
	nwacc::radix_sort(test);
	auto finish_time = std::chrono::high_resolution_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time).count();
	std::cout << "radix sort " << elapsed_time << std::endl;


	nwacc::shuffle(test);
	

	//merge sort
	auto start_time = std::chrono::high_resolution_clock::now();
	nwacc::merge_sort(test);
	auto finish_time = std::chrono::high_resolution_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time).count();
	std::cout << "merge sort " << elapsed_time << std::endl;
	

	
	nwacc::shuffle(test);

	//STL sort
	auto start_time = std::chrono::high_resolution_clock::now();
	std::sort(test.begin(), test.end());
	auto finish_time = std::chrono::high_resolution_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time).count();
	std::cout << "STL sort " << elapsed_time << std::endl;
	*/

	nwacc::shuffle(test);

	//quick sort 3
	auto start_time = std::chrono::high_resolution_clock::now();
	nwacc::quick_sort3(test);
	auto finish_time = std::chrono::high_resolution_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time).count();
	std::cout << "quick sort '3' " << elapsed_time << std::endl;


	nwacc::print(test);



	
}
