#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include "iostream"
#include "Pair.h"

namespace seneca {
	template <typename T, unsigned int CAPACITY>
	class Collection {
		T c_elems[CAPACITY]{};
		unsigned int c_size{};
	public:
		static T c_elem;

		Collection() = default;

		unsigned int size() const { return c_size; }

		void display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;

			for (unsigned int i = 0; i < c_size; ++i)
				os << c_elems[i] << std::endl;

			os << "----------------------" << std::endl;
		}

		virtual bool add(const T& item) {
			if (c_size < CAPACITY) {
				c_elems[c_size++] = item;
				return true;
			}
			return false;
		}

		T operator[](unsigned int i) const {
			if (i < c_size)
				return c_elems[i];
			return c_elem;
		}

		virtual ~Collection() = default;
	};

	template <typename T, unsigned int CAPACITY>
	T seneca::Collection<T, CAPACITY>::c_elem{};

	template <>
	Pair Collection<Pair, 100>::c_elem{ "No Key", "No Value" };
}

#endif