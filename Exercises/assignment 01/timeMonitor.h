/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/09/20
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include <chrono>
#include <string>
#include "event.h"
namespace seneca {
	class TimeMonitor {
		std::string tm_currentEvent;
		std::chrono::steady_clock::time_point m_startTime;
	public:
		void startEvent(const char*);
		Event stopEvent();
	};
}
#endif