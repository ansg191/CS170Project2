//
// Created by Anshul Gupta on 5/15/24.
//

#include "step.h"

namespace evaluators {

double step::evaluate(const node &)
{
	score += 1.0;
	return score;
}

} // namespace evaluators
