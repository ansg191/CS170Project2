//
// Created by Anshul Gupta on 5/24/24.
//

#ifndef CS170PROJECT2_DATA_H
#define CS170PROJECT2_DATA_H

#include <vector>

#include "node.h"

class data {
public:
	/// Load data from a file
	[[nodiscard]]
	static data load(const std::string &filename);

	[[nodiscard]] uint8_t label(size_t index) const { return labels[index]; }
	[[nodiscard]] double feature(size_t index, feature_t feature) const
	{
		return features[feature - 1][index];
	}
	[[nodiscard]] size_t size() const { return labels.size(); }

private:
	std::vector<uint8_t> labels;
	/// Stored in column-major order
	std::vector<std::vector<double>> features;

	data(std::vector<uint8_t> labels, std::vector<std::vector<double>> features);
};


#endif //CS170PROJECT2_DATA_H
