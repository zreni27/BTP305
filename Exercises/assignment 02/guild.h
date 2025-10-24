/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/10/08
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include "character.h"
#include <iostream>
#include <string>
namespace seneca {
	class Guild {
		std::string m_name;
		Character** m_members;
		size_t m_amount;
	public:
		Guild() = default;
		Guild(const char*);

		Guild(const Guild&);
		Guild& operator=(const Guild&);

		Guild(Guild&&) noexcept;
		Guild& operator=(Guild&&) noexcept;

		~Guild();

		void addMember(Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;
		void emptyGuild();

	};
}
#endif