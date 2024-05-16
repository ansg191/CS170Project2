//
// Created by Anshul Gupta on 5/13/24.
//

#ifndef CS170PROJECT2_BACKWARD_H
#define CS170PROJECT2_BACKWARD_H

#include "greedy.h"

namespace searchers {

/**
 * @class backward
 * @brief A backward elimination algorithm that iterates over nodes and removes features one at a
 * time.
 *
 * This class is derived from the greedy class and provides the implementation for a backward
 * elimination algorithm.
 */
class backward : public greedy {
public:
	explicit backward(feature_t num_features) : greedy(num_features) {}

protected:
	node initial_state() override;
	[[nodiscard]] bool is_finished() const override;
	std::optional<node> next_state(feature_t feature) override;
};

} // namespace searchers

#endif //CS170PROJECT2_BACKWARD_H
