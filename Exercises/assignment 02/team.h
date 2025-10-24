/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/10/08
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
#include "character.h"
#include <string>
namespace seneca {
	class Team {
		std::string m_name;
		Character** m_members;
		size_t m_amount;
	public:
		Team() = default;
		Team(const char*);

		Team(const Team&);
		Team& operator=(const Team&);

		Team(Team&&) noexcept;
		Team& operator=(Team&&) noexcept;

		~Team();

		void addMember(const Character*);
		void removeMember(const std::string&);
		Character* operator[](size_t) const;
		void showMembers() const;
		void emptyTeam();
	};
}
#endif