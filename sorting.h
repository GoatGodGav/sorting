#ifndef SORTING_H_
#define SORTING_H_

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <random>
#include <vector>
#include <chrono>

namespace nwacc
{
	void fill_vector(std::vector<int>& list, size_t size)
	{
		list.clear();
		for (auto index = 0U; index < size; index++)
		{
			list.push_back(index % 10);
		}
	}

	inline void shuffle(std::vector<int>& list)
	{
		std::shuffle(list.begin(), list.end(),
			std::mt19937(std::random_device()()));
	}

	inline bool is_sorted(std::vector<int>& list)
	{
		return std::is_sorted(list.begin(), list.end());
	}






	void print(const std::vector<int>& list, std::ostream& out = std::cout)
	{
		for (auto element : list) {
			out << element << " ";
		}

		out << std::endl;
	}





	void radix_sort(std::vector<int>& list, const int digit_count = 10)
	{
		

		const int k_radix = 10;
		auto vector_index = 0U;
		auto queue_index = 0U;
		std::queue<int> queues[k_radix]; 
		for (auto digit_index = 0, factor = 1;
			digit_index < digit_count;
			factor *= k_radix,
			digit_index++) {
			
			for (vector_index = 0U; vector_index < list.size(); vector_index++) {
				queues[(list[vector_index] / factor) % k_radix].push(list[vector_index]);
			}

			for (vector_index = queue_index = 0;
				vector_index < k_radix;
				vector_index++) {
				while (!queues[vector_index].empty()) {
					list[queue_index++] = queues[vector_index].front();
					queues[vector_index].pop();
				}
			}
		}

	}







	



	template <typename T>
	void shell_sort(std::vector<T>& list)
	{
		int arr[8] = {701,301,132,57,23,10,4,1};
		unsigned int gap;

		for (auto i = 0; i <= 8 ; i++ ) {
			
			gap = arr[i];

			for (auto index = gap; index < list.size(); index++) 
			{
				auto temp = std::move(list[index]);

				auto inner_index = index;

				for (; inner_index >= gap &&temp < list[inner_index - gap];inner_index -= gap)
				{
					list[inner_index] = std::move(list[inner_index - gap]);
				}

				list[inner_index] = std::move(temp);
			}
		}


	}











	template <typename T>
	void insertion_sort(std::vector<T>& list)
	{
		
		for (auto index = 1U; index < list.size(); index++) {

			
			auto temp = std::move(list[index]);
			auto inner_index = 0U;
			for (inner_index = index;
				inner_index > 0 &&
				temp < list[inner_index - 1];
				inner_index--) {
				
				list[inner_index] = std::move(list[inner_index - 1]);
			}
			
			
			list[inner_index] = std::move(temp);
		}


	}


	template <typename T>
	void insertion_sort(std::vector<T>& list, int left, int right)
	{
		for (auto index = left + 1; index <= right; index++) {
			auto temp = std::move(list[index]);
			auto inner_index = index;
			for (inner_index = index;
				inner_index > left &&
				temp < list[inner_index - 1]; inner_index--) {
				list[inner_index] = std::move(list[inner_index - 1]);
			}
			list[inner_index] = std::move(temp);
		}
	}





	//
	//
	//
	//
	//
	//
	//
	//





	template <typename T>
	const T& median_of_three(std::vector<T>& list, int left, int right)
	{
		auto center = (left + right) / 2;

		if (list[center] < list[left]) 
		{
			std::swap(list[left], list[center]);
		} 

		if (list[right] < list[left])
		{
			std::swap(list[left], list[right]);
		} 

		if (list[right] < list[center])
		{
			std::swap(list[center], list[right]);
		} 

		std::swap(list[center], list[right - 1]);

		return list[right - 1];
	}




	template <typename T>
	void quick_sort3(std::vector<T>& list, int left, int right)
	{

		if (left + 5 <= right)
		{
			const T& pivot = median_of_three(list, left, right);//find pivot
			auto left_index = left;
			auto right_index = right - 1;
			auto is_done = false;

			while (!is_done) {
				while (list[++left_index] < pivot) {}
				while (pivot < list[--right_index]) {}
				if (left_index < right_index) {
					std::swap(list[left_index], list[right_index]);
				}
				else {
					is_done = true;
				}
			}

			std::swap(list[left_index], list[right - 1]);

			quick_sort3(list, left, left_index - 1);
			quick_sort3(list, left_index + 1, right);
		}
		else {

			insertion_sort(list, left, right);
		}


	}



	template <typename T>
	void quick_shell(std::vector<T>& list, int left, int right)
	{

		if (left + 2500 <= right)
		{
			const T& pivot = median_of_three(list, left, right);//find pivot
			auto left_index = left;
			auto right_index = right - 1;
			auto is_done = false;

			while (!is_done) {
				while (list[++left_index] < pivot) {}
				while (pivot < list[--right_index]) {}
				if (left_index < right_index) {
					std::swap(list[left_index], list[right_index]);
				}
				else {
					is_done = true;
				}
			}

			std::swap(list[left_index], list[right - 1]);

			quick_sort3(list, left, left_index - 1);
			quick_sort3(list, left_index + 1, right);
		}
		else {

			shell_sort(list);
		}


	}


	
	template <typename T>
	const T& median_of_five(std::vector<T>& list, int left, int right)
	{
		int first = (left + right) / 2;
		int second = first / 2;
		int third = second * 3;

		if (list[first] < list[left])
		{
			std::swap(list[first], list[left]);
		}

		if (list[second] < list[left])
		{
			std::swap(list[left], list[second]);
		}

		if (list[third] < list[left])//
		{
			std::swap(list[third], list[left]);
		}

		if (list[right] < list[left])
		{
			std::swap(list[left], list[right]);
		}




		if (list[second] < list[first])
		{
			std::swap(list[second], list[first]);
		}

		if (list[third] < list[first])
		{
			std::swap(list[third], list[first]);
		}

		if (list[right] < list[first])
		{
			std::swap(list[right], list[first]);
		}



		if (list[third] < list[second])
		{
			std::swap(list[third], list[second]);
		}

		if (list[right] < list[second])
		{
			std::swap(list[right], list[second]);
		}



		if (list[right] < list[third])
		{
			std::swap(list[right], list[third]);
		}


		

		return list[second];
	}
	


	template <typename T>
	void quick_sort5(std::vector<T>& list, int left, int right)
	{
		if (left + 10 <= right)
		{
			int i = left, j = right;

			int tmp;

			int pivot = list[median_of_five(list, left, right)];


			while (i <= j) {

				while (list[i] < pivot)

					i++;

				while (list[j] > pivot)

					j--;

				if (i <= j) {

					tmp = list[i];

					list[i] = list[j];

					list[j] = tmp;

					i++;

					j--;

				}

			};

			if (left < j)
			{
				quick_sort5(list, left, j);
			}
			if (i < right)
			{
				quick_sort5(list, i, right);
			}
			else
			{
				insertion_sort(list, left, right);
			}

		}

	}
	




	template <typename T>
		void quick_sort_middle(std::vector<T>& list, int left, int right) {

		int i = left, j = right;

		int tmp;

		int pivot = list[(left + right) / 2];


		while (i <= j) {

			while (list[i] < pivot)

				i++;

			while (list[j] > pivot)

				j--;

			if (i <= j) {

				tmp = list[i];

				list[i] = list[j];

				list[j] = tmp;

				i++;

				j--;

			}

		};

		if (left < j)

			quick_sort_middle(list, left, j);

		if (i < right)

			quick_sort_middle(list, i, right);

	}


	



		template <typename T>
		void quick_sort_first(std::vector<T>& list, int left, int right) {

			int i = left;
			int j = right;

			int tmp;

			int pivot = list[left];


			while (i <= j) {

				while (list[i] < pivot)

					i++;

				while (list[j] > pivot)

					j--;

				if (i <= j) {

					tmp = list[i];

					list[i] = list[j];

					list[j] = tmp;

					i++;

					j--;

				}

			};

			if (left < j)

				quick_sort_first(list, left, j);

			if (i < right)

				quick_sort_first(list, i, right);

		}









	template <typename T>
	void quick_sort_random(std::vector<T>& list, int left, int right)
	{

		int i = left;
		int j = right;

		int tmp;

		int pivot = list[rand() % ((right - left ) + 1) + left];


		while (i <= j) {

			while (list[i] < pivot)

				i++;

			while (list[j] > pivot)

				j--;

			if (i <= j) {

				tmp = list[i];

				list[i] = list[j];

				list[j] = tmp;

				i++;

				j--;

			}

		};

		if (left < j)

			quick_sort_random(list, left, j);

		if (i < right)

			quick_sort_random(list, i, right);

	}







	template <typename T>
	void merge(
		std::vector<T>& list,
		std::vector<T>& temp,
		int left_index,
		int right_index,
		int right_end_index)
	{


		const auto left_end_index = right_index - 1;
		const auto number_of_elements = right_end_index -
			left_index + 1;
		auto temp_index = left_index;


		while (left_index <= left_end_index &&
			right_index <= right_end_index) {
			if (list[left_index] <= list[right_index]) {
				temp[temp_index++] =
					std::move(list[left_index++]);
			}
			else {
				temp[temp_index++] =
					std::move(list[right_index++]);
			}
		}


		while (left_index <= left_end_index) {
			temp[temp_index++] =
				std::move(list[left_index++]);
		}

		
		while (right_index <= right_end_index) {
			temp[temp_index++] =
				std::move(list[right_index++]);
		}

		for (
			auto index = 0;
			index < number_of_elements;
			++index,
			--right_end_index) {
			list[right_end_index] =
				std::move(temp[right_end_index]);
		}
	}

	template <typename T>
	void merge_sort(
		std::vector<T>& list,
		std::vector<T>& temp,
		int left,
		int right)
	{

		if (left < right) {
			auto center = (left + right) / 2;
			
			merge_sort(list, temp, left, center);
			merge_sort(list, temp, center + 1, right);
			merge(list, temp, left, center + 1, right);
		} 
	}

	template <typename T>
	void merge_sort(std::vector<T>& list)
	{
		std::vector<T> temp(list.size());
		merge_sort(list, temp, 0, list.size() - 1);
	}

}

#endif