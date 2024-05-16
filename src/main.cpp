#include <iostream>

#include "evaluator.h"
#include "searcher.h"

#include "evaluators/random.h"
#include "evaluators/step.h"
#include "searchers/backward.h"
#include "searchers/forward.h"

feature_t selectFeaturesCount();
std::unique_ptr<searcher> selectSearch(feature_t num_features);
std::unique_ptr<evaluator> selectEvaluator();

int main()
{
	std::cout << "Welcome to Anshul Gupta's (agupt109) Feature Selection Algorithm."
	          << std::endl;

	feature_t num_features = selectFeaturesCount();
	auto searcher = selectSearch(num_features);
	auto evaluator = selectEvaluator();

	while (searcher->iterate(evaluator.get())) {
		std::cout << "Feature set " << searcher->get_current_node() << " was best"
		          << " with score " << searcher->get_current_score() << std::endl;
	}

	std::cout << "Finished Search! Best features set is " << searcher->get_current_node()
	          << " with a score of " << searcher->get_current_score() << std::endl;

	return 0;
}

feature_t selectFeaturesCount()
{
	feature_t num_features;
	std::cout << "Please enter the number of features: ";
	std::cin >> num_features;
	return num_features;
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

std::unique_ptr<evaluator> selectEvaluator()
{
	std::cout << "Please select the evaluator for the models:" << std::endl
	          << "1. Random" << std::endl
	          << "2. Step (constantly increasing score)" << std::endl;

	int choice;
	std::cin >> choice;

	switch (choice) {
	case 1:
		return std::make_unique<evaluators::random>();
	case 2:
		return std::make_unique<evaluators::step>();
	default:
		std::cout << "Invalid choice. Exiting." << std::endl;
		exit(1);
	}
}
