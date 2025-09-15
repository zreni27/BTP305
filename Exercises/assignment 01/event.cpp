/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : N/A
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#include "event.h"
#include "settings.h"
#include <iomanip>
using namespace std;
namespace seneca {
	Event::Event() : e_eventName{}, e_duration{} {}
	
	Event::Event(const char* name, const std::chrono::nanoseconds& duration) : e_eventName(name), e_duration(duration) {}

	 ostream& operator<<(ostream& os, const Event& e) {
		 int cnt = 0;
		 int durationWidth = 0;
		 ++cnt;

		 if (g_settings.m_time_units == "seconds") {
			 durationWidth = 2;
		 }
		 else if (g_settings.m_time_units == "milliseconds") {
			 durationWidth = 5;
		 }
		 else if (g_settings.m_time_units == "microseconds") {
			 durationWidth = 8;
		 }
		 else if (g_settings.m_time_units == "nanoseconds") {
			 durationWidth = 11;
		 }

		 os << setw(2) << right << cnt << ": "
			 << setw(40) << right << e.e_eventName
			 << setw(durationWidth) << right << e.e_duration.count() << g_settings.m_time_units << endl;
	 }
}