//
// Created by Anshul Gupta on 5/12/24.
//

#ifndef CS170PROJECT2_SEARCHER_H
#define CS170PROJECT2_SEARCHER_H

#include "evaluator.h"
#include "node.h"

/**
 * @class searcher
 * @brief The abstract base class for search algorithms.
 *
 * The searcher class provides an interface for implementing search algorithms
 * that iteratively evaluate and explore a space of nodes.
 *
 * This class defines the common functionality for search algorithms, such as
 * iterating over nodes, storing the current node and its score, and providing
 * access to the current node and score.
 */
class searcher {
public:
	virtual ~searcher() = default;

	/**
	 * @brief Abstract method to iterate the search algorithm.
	 *
	 * @param eval A pointer to an evaluator object used to evaluate nodes.
	 *
	 * @return A boolean indicating whether the search algorithm should continue.
	 */
	virtual bool iterate(evaluator *eval) = 0;

	/// Get the current node.
	[[nodiscard]] const node &get_current_node() const { return *current_node; }
	/// Get the current score of the current node.
	[[nodiscard]] double get_current_score() const { return current_score; }

protected:
	std::optional<node> current_node;
	double current_score = -std::numeric_limits<double>::infinity();
};

#endif //CS170PROJECT2_SEARCHER_H
