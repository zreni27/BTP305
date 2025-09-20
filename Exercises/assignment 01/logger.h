/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/09/20
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include "event.h"
#include <iostream>

namespace seneca {
	class Logger {
		Event* l_events;
		size_t l_size;
	public:
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;

		Logger();

		Logger(Logger&&) noexcept;
		Logger& operator=(Logger&&) noexcept;

		void addEvent(const Event& event);
		friend std::ostream& operator<<(std::ostream&, const Logger&);

		~Logger();
	};
}
#endif