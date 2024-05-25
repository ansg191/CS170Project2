//
// Created by Anshul Gupta on 5/24/24.
//

#ifndef CS170PROJECT2_CLASSIFIER_H
#define CS170PROJECT2_CLASSIFIER_H

#include "data.h"

/**
 * @class classifier
 * @brief Abstract base class for classifiers
 */
class classifier {
public:
	virtual ~classifier() = default;

	/**
	 * @brief Trains the classifier using the provided data view.
	 *
	 * @param view The data view used for training.
	 */
	virtual void train(data_view view) = 0;

	/**
	 * @brief Calculates the accuracy of a test using the provided data view.
	 *
	 * @param view The data view for which the test is performed.
	 * @return The accuracy of the test.
	 */
	[[nodiscard]] virtual double test(data_view view) const = 0;
};


#endif //CS170PROJECT2_CLASSIFIER_H
