//
// Created by Anshul Gupta on 5/13/24.
//

#include <iostream>

#include "greedy.h"

namespace searchers {

bool greedy::iterate(evaluator *eval)
{
	// Initial state
	if (!current_node) {
		auto node = initial_state();
		current_node = node;
		current_score = eval->evaluate(*current_node);

		std::cout << "Initial score with features " << *current_node << " is "
		          << current_score << std::endl
		          << std::endl;

		return true;
	}

	if (is_finished()) {
		std::cout << "\tNo more child nodes. Search finished" << std::endl << std::endl;
		return false;
	}

	// Loop through neighbors
	double bestScore = -std::numeric_limits<double>::infinity();
	node bestNode;
	for (feature_t f = 1; f <= num_features; ++f) {
		auto neighbor = next_state(f);
		if (!neighbor) continue;

		double score = eval->evaluate(*neighbor);
		if (score > bestScore) {
			bestScore = score;
			bestNode = *neighbor;
		}

		std::cout << "\tUsing feature(s) " << *neighbor << " gives a score of " << score
		          << std::endl;
	}

	std::cout << std::endl;

	// Update current node
	if (bestScore > current_score) {
		current_node = bestNode;
		current_score = bestScore;
		return true;
	} else {
		// The current node is the best node, iteration is finished
		std::cout << "\tAccuracy has decreased. Stopping search." << std::endl << std::endl;
		return false;
	}
}

} // namespace searchers