//
// Created by Anshul Gupta on 5/13/24.
//

#ifndef CS170PROJECT2_EVALUATOR_H
#define CS170PROJECT2_EVALUATOR_H

#include "node.h"

/**
 * @class evaluator
 * @brief Abstract base class for evaluating a set of features in a node
 *
 * The evaluator class provides an interface for evaluating a set of features
 * in a node. Subclasses should implement the evaluate() method to calculate
 * a numerical value representing the quality or fitness of the given set
 * of features.
 */
class evaluator {
public:
	virtual ~evaluator() = default;

	/**
	 * @brief Evaluate the given set of features
	 *
	 * @param features The set of features to evaluate
	 * @return A numerical value representing the quality or fitness of the given set of features.
	 */
	virtual double evaluate(const node &features) = 0;
};

#endif //CS170PROJECT2_EVALUATOR_H
