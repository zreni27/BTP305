#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H
#include <iostream>
#include <string>

namespace seneca {
	class ProteinDatabase {
		std::string* p_uids;
		std::string* p_sequence;
		size_t p_proteinsStored;
	public:
		void set();
		ProteinDatabase();
		ProteinDatabase(std::string);
		ProteinDatabase(const ProteinDatabase&);
		ProteinDatabase& operator=(const ProteinDatabase&);
		ProteinDatabase(ProteinDatabase&&);
		ProteinDatabase& operator=(ProteinDatabase&&);
		size_t size();
		std::string operator[](size_t);
		std::string getUID(size_t);
		~ProteinDatabase();
	};
}

#endif