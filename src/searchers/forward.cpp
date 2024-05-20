//
// Created by Anshul Gupta on 5/13/24.
//

#include "forward.h"

namespace searchers {

// The initial state of the search is an empty set.
node forward::initial_state() { return {}; }

bool forward::is_finished() const
{
	// The search is finished when the current node has the maximum number of features.
	return current_node->size() == num_features;
}

std::optional<node> forward::next_state(feature_t feature)
{
	// If the feature is invalid or already in the current node, return an empty optional.
	if (feature > num_features || current_node->contains(feature)) return std::nullopt;

	// Create a new node with the feature added to the current node.
	node next = *current_node;
	next.add(feature);
	return next;
}

} // namespace searchers