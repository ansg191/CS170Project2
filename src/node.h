//
// Created by Anshul Gupta on 5/13/24.
//

#ifndef CS170PROJECT2_FEATURE_H
#define CS170PROJECT2_FEATURE_H

#include <cstdlib>
#include <ostream>
#include <set>

typedef size_t feature_t;

/**
 * @class node
 * @brief Represents a node state with a set of features
 */
class node {
public:
	/// Underlying storage for a set of features
	using feature_set = std::set<feature_t>;

	/// Constructs a feature set with no features
	node() = default;
	/// Constructs a feature set with all features from 1 to num_features
	explicit node(feature_t num_features) : features()
	{
		for (feature_t i = 1; i <= num_features; i++) { features.insert(i); }
	}
	/// Constructs a feature set with the given features
	explicit node(feature_set features) : features(std::move(features)) {}

	/// Equality operator
	bool operator==(const node &rhs) const { return features == rhs.features; }
	/// Inequality operator
	bool operator!=(const node &rhs) const { return !(rhs == *this); }

	/// Returns the set of features
	[[nodiscard]] const feature_set &get_features() const { return features; }

	/// Adds a feature to the set.
	void add_feature(feature_t feature) { features.insert(feature); }
	/// Removes a feature from the set.
	void remove_feature(feature_t feature) { features.erase(feature); }

	/// Returns true if the set contains the given feature.
	[[nodiscard]] bool has_feature(feature_t feature) const
	{
		return features.contains(feature);
	}

	/// Returns the number of features in the set.
	[[nodiscard]] size_t size() const { return features.size(); }
	/// Returns true if the set is empty.
	[[nodiscard]] bool empty() const { return features.empty(); }

	friend std::ostream &operator<<(std::ostream &os, const node &node)
	{
		os << "{";
		bool first = true;
		for (auto f: node.get_features()) {
			if (first) {
				os << f;
				first = false;
			} else {
				os << ", " << f;
			}
		}
		os << "}";
		return os;
	}

private:
	feature_set features;
};

#endif //CS170PROJECT2_FEATURE_H
