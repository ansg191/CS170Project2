//
// Created by Anshul Gupta on 5/24/24.
//

#ifndef CS170PROJECT2_NEAREST_NEIGHBOR_H
#define CS170PROJECT2_NEAREST_NEIGHBOR_H

#include <optional>

#include "../classifier.h"

namespace classifiers {

/**
 * @class nearest_neighbor
 * @brief A class representing a nearest neighbor classifier.
 *
 * The nearest_neighbor class is a concrete implementation of the classifier abstract base class.
 * It uses the k-nearest neighbor algorithm to classify data points based on their feature values.
 */
class nearest_neighbor : public classifier {
public:
	/**
	 * @brief Construct a nearest_neighbor object with a specified value of k.
	 *
	 * The k parameter determines the number of neighbors used for classification.
	 * It must be a positive odd integer.
	 *
	 * @param k The number of neighbors to consider for classification.
	 *
	 * @pre k > 0 and odd
	 */
	explicit nearest_neighbor(size_t k);

	void train(data_view view) override;
	[[nodiscard]] double test(data_view view) const override;

private:
	size_t k;
	std::optional<data_view> training_data;

	/**
	 * @brief Predicts the label of a given data point based on its nearest neighbors.
	 *
	 * This function predicts the label of a given data point based on its k nearest neighbors.
	 * It calculates the Euclidean distance between the test data point and each training data
	 * point, and selects the k nearest neighbors with the lowest distances.
	 * It then returns the most common label among these k nearest neighbors.
	 *
	 * @note This could be optimized by using k-d trees or vp-trees to reduce the number of
	 * distance calculations.
	 *
	 * @param view The data view containing the data.
	 * @param index The index of the data point in the view to be predicted.
	 * @return The predicted label of the data point.
	 */
	[[nodiscard]] label_t predict(const data_view &view, size_t index) const;
};

} // namespace classifiers

#endif //CS170PROJECT2_NEAREST_NEIGHBOR_H
