//
// Created by Anshul Gupta on 5/13/24.
//

#ifndef CS170PROJECT2_FORWARD_H
#define CS170PROJECT2_FORWARD_H

#include "greedy.h"

namespace searchers {

/**
 * @class forward
 * @brief A forward selection algorithm that extends the greedy search algorithm.
 *
 * This class is a concrete implementation of the greedy search algorithm that provides a
 * forward selection strategy.
 */
class forward : public greedy {
public:
	explicit forward(feature_t num_features) : greedy(num_features) {}

protected:
	node initial_state() override;
	[[nodiscard]] bool is_finished() const override;
	std::optional<node> next_state(feature_t feature) override;
};

} // namespace searchers

#endif //CS170PROJECT2_FORWARD_H
