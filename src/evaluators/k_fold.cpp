//
// Created by Anshul Gupta on 5/24/24.
//

#include "k_fold.h"

namespace evaluators {

double k_fold::evaluate(const node &features)
{
	size_t k_size = dataset.size() / k; // Size of each fold

	double total_accuracy = 0;
	for (size_t i = 0; i < k; ++i) {
		// Create a view of the dataset for training and testing
		data_view training(dataset, features, (i + 1) * k_size, (k - 1) * k_size);
		data_view testing(dataset, features, i * k_size, k_size);

		// Train the classifier on the training set
		classifier->train(training);

		// Test the classifier on the testing set and accumulate the accuracy
		double accuracy = classifier->test(testing);
		total_accuracy += accuracy;
	}

	// Return the average accuracy over all folds
	return total_accuracy / static_cast<double>(k);
}

} // namespace evaluators
