//
// Created by Anshul Gupta on 5/13/24.
//

#ifndef CS170PROJECT2_RANDOM_H
#define CS170PROJECT2_RANDOM_H

#include <random>

#include "../evaluator.h"

namespace evaluators {

/**
 * @class random
 * @brief A class for evaluating a feature set by assigning a random value to it.
 */
class random : public evaluator {
public:
	random();

	double evaluate(const node &features) override;

private:
	/// Random number generator seeded with a random device.
	std::default_random_engine rng;
	/// Uniform distribution for generating random real numbers between 0 and 1.
	std::uniform_real_distribution<double> dist;
};

} // namespace evaluators

#endif //CS170PROJECT2_RANDOM_H
