//
// Created by Anshul Gupta on 5/13/24.
//

#include "random.h"

namespace evaluators {

random::random()
{
	std::random_device rd;
	rng = std::default_random_engine(rd());
	dist = std::uniform_real_distribution(0.0, 1.0);
}

double random::evaluate(const node &features) { return dist(rng); }

} // namespace evaluators