//
// Created by Anshul Gupta on 5/15/24.
//

#ifndef CS170PROJECT2_STEP_H
#define CS170PROJECT2_STEP_H

#include "../evaluator.h"

namespace evaluators {

/**
 * @class step
 * @brief A testing evaluator that increments the score on each node.
 *
 * This should force the algorithms to run through the entire graph.
 */
class step : public evaluator {
public:
	step() = default;

	double evaluate(const node &features) override;

private:
	double score = 0.0;
};

} // namespace evaluators

#endif //CS170PROJECT2_STEP_H
