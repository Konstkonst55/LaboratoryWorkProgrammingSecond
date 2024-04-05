#include "Lab12.h"

template <typename T> double getSortTime(sortType<T>, T[], const int, comparatorType<T>);

void runSorting() {
	const int n = 20000, border = n * 2;
	int* arrInt = new int[n];
	float* arrFloat = new float[n];

	const auto compInt = [](int l, int r) { return l > r; };
	const auto compFloat = [](float l, float r) { return l > r; };

	const vector<pair<sortType<int>, string>> vpIntSorts = { 
		{ Sorting::BubbleSort<int>, "Bubble Int" },
		{ Sorting::SelectSort<int>, "Select Int" },
		{ Sorting::InsertSort<int>, "Insert Int" },
		{ Sorting::ShellSort<int>, "Shell Int" }
	};

	const vector<pair<sortType<float>, string>> vpFloatSorts = {
		{ Sorting::BubbleSort<float>, "Bubble Float" },
		{ Sorting::SelectSort<float>, "Select Float" },
		{ Sorting::InsertSort<float>, "Insert Float" },
		{ Sorting::ShellSort<float>, "Shell Float" }
	};

	for (int i = 0; i < vpIntSorts.size(); i++) {
		fillRandIntVector(arrInt, n, -border, border);
		fillRandFloatVector(arrFloat, n, (float)(-border), (float)border);
		cout << format("{}: {:.10}", vpIntSorts[i].second, getSortTime<int>(vpIntSorts[i].first, arrInt, n, compInt)) << endl;
		cout << format("{}: {:.10}", vpFloatSorts[i].second, getSortTime<float>(vpFloatSorts[i].first, arrFloat, n, compFloat)) << endl << endl;
	}
}

template <typename T> double getSortTime(sortType<T> sort, T arr[], const int len, comparatorType<T> comp) {
	auto start = high_resolution_clock::now();
	sort(arr, len, comp);
	auto end = high_resolution_clock::now();
	duration<double> duration = end - start;
	return duration.count();
}