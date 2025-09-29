#ifndef SENECA_SET_H
#define SENECA_SET_H
#include "Collection.h"
#include <cmath>
namespace seneca {
	template <typename T>
	class Set : public Collection<T, 100> {
	public:
		bool add(const T& item) override {
			for (unsigned int i = 0; i < this->size(); ++i) {
				if (this->operator[](i) == item)
					return false;
			}
			return Collection<T, 100>::add(item);
		}
	};

	template<>
	class Set<double> : public Collection<double, 100> {
	public:
		bool add(const double& item) override {
			for (unsigned int i = 0; i < this->size(); ++i) {
				if (std::fabs(this->operator[](i) - item) <= 0.01)
					return false; // already exists within tolerance
			}
			return Collection<double, 100>::add(item);
		}
	};
}
#endif