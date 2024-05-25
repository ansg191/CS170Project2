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

	/// Min-max normalize the features
	void normalize();

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

/**
 * @class data_view
 * @brief Represents a view into a subset of data with a specific set of features
 *
 * The data_view class provides a way to access a subset of data with a specific set of features.
 * It allows accessing the label and features of individual data points within the view.
 *
 * The view acts like a ring-buffer. This way, we can create views that may not be contiguous in the
 * original data, but still allow for easy access to the data points.
 */
class data_view {
public:
	data_view(const data &data, const node &features, size_t start, size_t len)
	    : data(data), features(features), start(start), len(len)
	{}

	[[nodiscard]] uint8_t label(size_t index) const;
	[[nodiscard]] double feature(size_t index, feature_t feature) const;
	[[nodiscard]] size_t size() const { return len; }

	[[nodiscard]] const node &get_features() const { return features; }

private:
	const data &data;
	const node &features;
	size_t start, len;
};


#endif //CS170PROJECT2_DATA_H
