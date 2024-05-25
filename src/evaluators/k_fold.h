//
// Created by Anshul Gupta on 5/24/24.
//

#ifndef CS170PROJECT2_K_FOLD_H
#define CS170PROJECT2_K_FOLD_H

#include "../classifier.h"
#include "../data.h"
#include "../evaluator.h"

namespace evaluators {

/**
 * @class k_fold
 * @brief Class for performing leave-one-out k-fold cross-validation.
 *
 * The k_fold class inherits from the evaluator base class and implements the evaluate() method for
 * evaluating a set of features using leave-one-out k-fold cross-validation.
 *
 * It splits the dataset into k equal-sized folds, trains the classifier on k-1 folds, and evaluates
 * the accuracy on the remaining fold. This is repeated k times, each time using a different fold as
 * the test set. The final accuracy is the average of the accuracies obtained in each iteration.
 */
class k_fold : public evaluator {
public:
	/**
	 * @brief Constructor for the k_fold class.
	 *
	 * @param classifier The classifier to be trained and evaluated.
	 * @param dataset The dataset to be used for training and evaluation.
	 * @param k The number of folds to use for cross-validation.
	 */
	k_fold(std::unique_ptr<classifier> classifier, data dataset, size_t k)
	    : classifier(std::move(classifier)), dataset(std::move(dataset)), k(k)
	{}

	double evaluate(const node &features) override;

private:
	std::unique_ptr<classifier> classifier;
	data dataset;
	size_t k;
};

} // namespace evaluators

#endif //CS170PROJECT2_K_FOLD_H
