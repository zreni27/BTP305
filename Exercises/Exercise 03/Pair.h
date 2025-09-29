#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H
#include <string>
namespace seneca {
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
		Pair() = default;
		// Define equality operator
		bool operator==(const Pair& other) const {
			return m_key == other.m_key && m_value == other.m_value;
		}

		// << operator
		friend std::ostream& operator<<(std::ostream& os, const Pair& p) {
			os << "[" << p.m_key << ": " << p.m_value << "]";
			return os;
		}
	};
}
#endif