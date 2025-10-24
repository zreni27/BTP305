/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/10/08
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#include "guild.h"
using namespace std;
namespace seneca {

	Guild::Guild(const char* name) : m_name(name), m_members(nullptr), m_amount(0) {}

	Guild::Guild(const Guild& o) {
		*this = o;
	}

	Guild& Guild::operator=(const Guild& o) {
		if (this != &o) {
			emptyGuild();
			m_name = o.m_name;
			m_amount = o.m_amount;
			if (m_amount > 0) {
				m_members = new Character*[m_amount];
				for (size_t i = 0; i < m_amount; ++i) {
					m_members[i] = o.m_members[i];
				}
			}
		}
		return *this;
	}

	Guild::Guild(Guild&& o) noexcept {
		*this = move(o);
	}

	Guild& Guild::operator=(Guild&& o) noexcept {
		if (this != &o) {
			emptyGuild();
			m_name = move(o.m_name);
			m_amount = o.m_amount;
			m_members = o.m_members;

			o.m_members = nullptr;
			o.m_amount = 0;
		}
		return *this;
	}

	Guild::~Guild() {
		emptyGuild();
	}

	void Guild::addMember(Character* c) {
		if (!c) return;
		for (size_t i = 0; i < m_amount; i++) {
			if (m_members[i]->getName() == c->getName()) {
				return;
			}
		}
	
		c->setHealthMax(c->getHealthMax() + 300);
			Character** temp = new Character*[m_amount + 1];
			for (size_t i = 0; i < m_amount; ++i) {
				temp[i] = m_members[i];
			}
			temp[m_amount] = c;
			delete[] m_members;
			m_members = temp;
			++m_amount;
		}

	void Guild::removeMember(const std::string& c) {
		if (!m_members || m_amount == 0) return;

		size_t idx = m_amount;
		for (size_t i = 0; i < m_amount; ++i) {
			if (m_members[i]->getName() == c) {
				idx = i;
				break;
			}
		}
		if (idx == m_amount) {
			return;
		}
		m_members[idx]->setHealthMax(m_members[idx]->getHealthMax() - 300);
	
		if (m_amount == 1) {
			emptyGuild();
			return;
		}
		Character** temp = new Character*[m_amount - 1];
		size_t j = 0;
		for (size_t i = 0; i < m_amount; ++i) {
			if (i != idx) {
				temp[j++] = m_members[i];
			}
		}
		delete[] m_members;
		m_members = temp;
		--m_amount;
	}

	Character* Guild::operator[](size_t idx) const {
		if (idx < m_amount) {
			return m_members[idx];
		}
		return nullptr;
	}

	void Guild::showMembers() const {
		if (m_amount == 0 && m_name.empty()) {
			cout << "No guild." << endl;
			return;
		}
		cout << "[Guild] " << m_name << endl;
		for (size_t i = 0; i < m_amount; i++) {
			cout << "    " << (i + 1) << ": " << *m_members[i] << endl;
		}
	}

	void Guild::emptyGuild() {
		delete[] m_members;             
		m_members = nullptr;
		m_amount = 0;
	}
}