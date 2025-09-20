/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/09/20
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#include "logger.h"
using namespace std;
namespace seneca {

	Logger::Logger() : l_events(nullptr), l_size{0} {}

	Logger::Logger(Logger&& l) noexcept {
		l_events = l.l_events;
		l_size = l.l_size;
		l.l_events = nullptr;
		l.l_size = 0;
	}

	Logger& Logger::operator=(Logger&& l) noexcept { 
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
		Event* newEvent = new Event[l_size + 1];

		for (size_t i = 0; i < l_size; i++) {
			newEvent[i] = l_events[i];
		}

		newEvent[l_size] = event;

		delete[] l_events;
		l_events = newEvent;
		l_size++;
	}

	ostream& operator<<(ostream& os, const Logger& l) {
		for (size_t i = 0; i < l.l_size; i++) {
			os << l.l_events[i] << endl;
		}
		return os;
	}

	Logger::~Logger() {
		delete[] l_events;
	}
}