/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/09/20
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#include "timeMonitor.h"
using namespace std;

namespace seneca {

	void TimeMonitor::startEvent(const char* name) {
		tm_currentEvent = name;
		m_startTime = chrono::steady_clock::now();
	}

	Event TimeMonitor::stopEvent() {
		auto endTime = chrono::steady_clock::now();
		auto duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - m_startTime);

		return Event(tm_currentEvent.c_str(), duration);
	}
}