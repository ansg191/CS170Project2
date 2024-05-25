#include <chrono>
#include <iostream>

#include "classifier.h"
#include "data.h"
#include "searcher.h"

#include "classifiers/nearest_neighbor.h"
#include "evaluators/k_fold.h"
#include "searchers/backward.h"
#include "searchers/forward.h"

std::unique_ptr<searcher> selectSearch(feature_t num_features);
data selectData();
std::tuple<size_t, size_t> selectK();

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout << "Welcome to Anshul Gupta's (agupt109) Feature Selection Algorithm.\n";

	data d = selectData();

	auto [knn, kfold] = selectK();
	auto classifier = std::make_unique<classifiers::nearest_neighbor>(knn);

	auto evaluator = std::make_unique<evaluators::k_fold>(std::move(classifier), d, kfold);
	auto searcher = selectSearch(d.num_features());

	auto start = std::chrono::high_resolution_clock::now();
	auto t1 = start;
	while (searcher->iterate(evaluator.get())) {
		auto t2 = std::chrono::high_resolution_clock::now();

		std::cout << "Feature set " << searcher->get_current_node() << " was best"
		          << " with score " << searcher->get_current_score() << " (time: "
		          << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		          << "ms)" << std::endl;

		t1 = std::chrono::high_resolution_clock::now();
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Finished Search! Best features set is " << searcher->get_current_node()
	          << " with a score of " << searcher->get_current_score() << " (time: "
	          << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
	          << "ms)\nTotal time: "
	          << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - start).count()
	          << "ms" << std::endl;

	return 0;
}

std::unique_ptr<searcher> selectSearch(feature_t num_features)
{
	std::cout << "Please select the search algorithm you would like to use:" << std::endl;
	std::cout << "1. Forward Selection" << std::endl;
	std::cout << "2. Backward Elimination" << std::endl;

	int choice;
	std::cin >> choice;

	switch (choice) {
	case 1:
		return std::make_unique<searchers::forward>(num_features);
	case 2:
		return std::make_unique<searchers::backward>(num_features);
	default:
		std::cout << "Invalid choice. Exiting." << std::endl;
		exit(1);
	}
}

data selectData()
{
	std::cout << "Provide the path to a data file: ";

	std::string path;
	std::cin >> path;

	data d = data::load(path);
	d.normalize();
	return d;
}

std::tuple<size_t, size_t> selectK()
{
	std::cout << "Please select the K value for the nearest neighbor: ";

	size_t knn;
	std::cin >> knn;

	std::cout << "Please select the K value for the k-fold cross validation: ";

	size_t kfold;
	std::cin >> kfold;

	return {knn, kfold};
}
