/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : N/A
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#include "logger.h"
#include <functional>
using namespace std;
namespace seneca {

	Logger::Logger() : l_events(nullptr), l_size{0} {}

	Logger::Logger(Logger&& l) {
		*this = move(l);
	}

	Logger& Logger::operator=(Logger&& l) noexcept{
		if (this != &l) {
			delete[] l_events;
			l_events = l.l_events;
			l_size = l.l_size;
			l.l_events = nullptr;
			l.l_size = 0;
		}
		return *this;
	}

	void Logger::addEvent(const Event& event) {
		Logger temp;
		temp.l_events = new Event[l_size + 1];
		for (int i = 0; i < l_size; i++) {
			temp.l_events[i] = move(l_events[i]);
		}
		temp.l_events[l_size] = event;
		temp.l_size = l_size + 1;

		*this = move(temp);
	}

	ostream& operator<<(ostream& os, const Logger& l) {}

	Logger::~Logger() {
		delete[] l_events;
	}
}