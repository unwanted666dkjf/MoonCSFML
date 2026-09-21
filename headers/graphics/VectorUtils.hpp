#ifndef MOON_CSFML_GRAPHICS_VECTOR_UTILS_HPP
#define MOON_CSFML_GRAPHICS_VECTOR_UTILS_HPP


#include <cmath>

#include <vector>

#include <algorithm>


template <typename T>
void moon_vector_reverse(std::vector<T>& values) {
	std::reverse(values.begin(), values.end());
}

template <typename T>
void moon_vector_insert(
	std::vector<T>& values,
	unsigned long index,
	const T& value
) {
	values.insert(values.begin() + index, value);
}

template <typename T>
void moon_vector_insert_pointer(
	std::vector<T*>& values,
	unsigned long index,
	T* value
) {
	values.insert(values.begin() + index, value);
}

template <typename T>
void moon_vector_extend(
	std::vector<T>& self,
	const std::vector<T>& values
) {
	self.insert(self.end(), values.begin(), values.end());
}

template <typename T>
void moon_vector_remove(
	std::vector<T>& self,
	const unsigned long& index
) {
	self.erase(self.begin() + index);
}

template <typename T>
T moon_vector_pop(
	std::vector<T>& self,
	const unsigned long& index
) {
	T element = self[index];
	self.erase(self.begin() + index);
	return element;
}

template <typename T>
std::vector<T> moon_vector_slice(
	const std::vector<T>& values,
	long long start,
	long long stop,
	const long long& step
) {
	std::vector<T> result;

	if (step == 0LL) {
		return result;
	}

	const long long size = static_cast<long long>(values.size());

	if (start < 0LL) {
		start += size;
	}
	if (stop < 0LL) {
		stop += size;
	}

	double expected_size = std::abs(
		(1. * stop - 1. * start) / (1. * step)
	);
	unsigned long needed_size = static_cast<unsigned long>(expected_size);
	if (expected_size > static_cast<double>(needed_size)) {
		needed_size++;
	}
	needed_size++;					// At least 1 will be reserved.
	result.reserve(needed_size);

	if (step < 0LL) {
		for (; stop >= start; stop += step) {
			result.push_back(values[stop]);
		}
	} else {
		for (; start < stop; start += step) {
			result.push_back(values[start]);
		}
	}

	return result;
}


#endif
