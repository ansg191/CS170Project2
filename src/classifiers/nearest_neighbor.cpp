//
// Created by Anshul Gupta on 5/24/24.
//

#include <cassert>

#include "nearest_neighbor.h"

namespace classifiers {

nearest_neighbor::nearest_neighbor(size_t k) : k(k)
{
	assert(k > 0);
	assert(k % 2 == 1); // k must be odd
}

void nearest_neighbor::train(data_view view)
{
	// No training optimization is performed in this classifier.
	// It could be optimized by using data structures like k-d trees or vp-trees.
	training_data.emplace(view);
}

double nearest_neighbor::test(data_view view) const
{
	// If the training data is not available, throw an exception.
	if (!training_data.has_value()) throw std::runtime_error("Training data is not available.");

	// Check that the features in the test data is the same as the features in the training
	// data.
	if (view.get_features() != training_data->get_features())
		throw std::runtime_error("The number of features in the test data is not the same "
		                         "as the number of features in the training data.");

	// Initialize the number of correct predictions to 0.
	size_t correct_predictions = 0;

	// For each data point in the test data, find the k nearest neighbors in the training data.
	for (size_t i = 0; i < view.size(); ++i) {
		uint8_t predicted_label = predict(view, i);
		uint8_t actual_label = view.label(i);

		if (predicted_label == actual_label) correct_predictions++;
	}

	// Return the accuracy of the classifier.
	return static_cast<double>(correct_predictions) / static_cast<double>(view.size());
}
uint8_t nearest_neighbor::predict(const data_view &view, size_t index) const
{
	// k-nearest distances
	std::vector<std::pair<uint8_t, double>> distances(k,
	                                                  {0, std::numeric_limits<double>::max()});

	// For each data point in the training data, calculate the Euclidean distance.
	// Could be reduced using optimizations. See train() function.
	for (size_t i = 0; i < training_data->size(); ++i) {
		// Calculate the Euclidean distance between the test data point and the training
		// data point.
		double distance = 0.0;
		for (const auto &feature: view.get_features().get_features()) {
			double diff =
			        view.feature(index, feature) - training_data->feature(i, feature);
			distance += diff * diff;
		}

		// Find the element pointer of the maximum distance in the distances vector.
		auto max_distance = std::max_element(
		        distances.begin(), distances.end(),
		        [](const auto &lhs, const auto &rhs) { return lhs.second < rhs.second; });

		// If the current distance is less than the maximum distance, replace the maximum
		// distance.
		if (distance < max_distance->second) {
			max_distance->first = training_data->label(i);
			max_distance->second = distance;
		}
	}

	// Return the most common label among the k-nearest neighbors.
	size_t label_counts[UINT8_MAX] = {0};
	for (const auto &[label, _]: distances) label_counts[label]++;

	auto most_common_label = std::max_element(std::begin(label_counts), std::end(label_counts));
	return std::distance(label_counts, most_common_label);
}

} // namespace classifiers
