//
// Created by Anshul Gupta on 5/13/24.
//

#ifndef CS170PROJECT2_GREEDY_H
#define CS170PROJECT2_GREEDY_H

#include "../searcher.h"

namespace searchers {

/**
 * @class greedy
 * @brief A greedy search algorithm that iterates over nodes and selects the best neighbor at each
 * iteration.
 *
 * This class is an abstract base class that provides the basic structure for a greedy search
 * algorithm built on top of the searcher interface.
 *
 * Implementations of this class must provide the initial state, the stopping condition, and the
 * method to select the next state from the current state.
 */
class greedy : public searcher {
public:
	explicit greedy(feature_t num_features) : num_features(num_features) {}

	bool iterate(evaluator *eval) override;

protected:
	/// The number of features in the search space.
	feature_t num_features;

	/// The initial state of the search.
	virtual node initial_state() = 0;

	/// Whether the search has reached a stopping condition (not related to the score).
	[[nodiscard]] virtual bool is_finished() const = 0;

	/// Performs an operation on the current state and returns the next state.
	virtual std::optional<node> next_state(feature_t feature) = 0;
};

} // namespace searchers

#endif //CS170PROJECT2_GREEDY_H
