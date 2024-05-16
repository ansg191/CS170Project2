//
// Created by Anshul Gupta on 5/13/24.
//

#include "backward.h"

namespace searchers {

// The initial state of the search is a set with all features.
node backward::initial_state() { return node(num_features); }

// The search is finished when the current set of features is empty.
bool backward::is_finished() const { return current_node->empty(); }

std::optional<node> backward::next_state(feature_t feature)
{
	// If the feature is invalid or not in the current set, return an empty optional.
	if (is_finished() || !current_node->has_feature(feature)) return std::nullopt;

	// Create a new node with the feature removed from the current node.
	node next = *current_node;
	next.remove_feature(feature);
	return next;
}

} // namespace searchers