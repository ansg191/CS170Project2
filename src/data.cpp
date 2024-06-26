//
// Created by Anshul Gupta on 5/24/24.
//

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

#include "data.h"

data::data(std::vector<label_t> labels, std::vector<std::vector<double>> features)
    : labels(std::move(labels)), features(std::move(features))
{
	// Assert that the data is not empty
	assert(!this->labels.empty());
	assert(!this->features.empty());
	// Assert that all features have the same number of samples
	for (const auto &feature: this->features) { assert(feature.size() == this->labels.size()); }
}

data data::load(const std::string &filename)
{
	// Open the file
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to open file " << filename << std::endl;
		exit(1);
	}

	// Structure to store the data in
	std::vector<label_t> labels;
	std::vector<std::vector<double>> features; // Stored in column-major order

	// Read the data from the file line by line
	for (std::string line; std::getline(file, line);) {
		std::istringstream ss(line);

		// Read the label
		double label = -1;
		ss >> label;
		if (label < LABEL_MIN || label > LABEL_MAX) {
			std::cerr << "Invalid label in line: " << line << std::endl;
			exit(1);
		}
		labels.push_back(static_cast<label_t>(label));

		// Read the features into the features vector
		size_t feature_index = 0;
		while (!ss.eof()) {
			double feature;
			ss >> feature;

			if (feature_index >= features.size()) { features.emplace_back(); }
			features[feature_index].push_back(feature);

			feature_index++;
		}
	}

	std::cout << "Loaded " << labels.size() << " samples with " << features.size()
	          << " features each from " << filename << std::endl;

	return {std::move(labels), std::move(features)};
}

void data::normalize()
{
	// Normalize each feature
	for (auto &feature: features) {
		// Find the minimum and maximum values
		double min = *std::min_element(feature.begin(), feature.end());
		double max = *std::max_element(feature.begin(), feature.end());

		// Normalize the feature
		for (auto &value: feature) { value = (value - min) / (max - min); }
	}
}

label_t data_view::label(size_t index) const
{
	assert(index < len);
	size_t wrapped_index = (start + index) % data.size();
	return data.label(wrapped_index);
}

double data_view::feature(size_t index, feature_t feature) const
{
	assert(index < len);
	assert(this->features.contains(feature));
	size_t wrapped_index = (start + index) % data.size();
	return data.feature(wrapped_index, feature);
}
