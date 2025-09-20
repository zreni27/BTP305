/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/09/20
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
		 static int cnt = 0;
		 ++cnt;

		 long long durationValue = 0;
		 int durationWidth = 0;

		 if (g_settings.m_time_units == "seconds") {
			 durationValue = chrono::duration_cast<chrono::seconds>(e.e_duration).count();
			 durationWidth = 2;
		 }
		 else if (g_settings.m_time_units == "milliseconds") {
			 durationValue = chrono::duration_cast<chrono::milliseconds>(e.e_duration).count();
			 durationWidth = 5;
		 }
		 else if (g_settings.m_time_units == "microseconds") {
			 durationValue = chrono::duration_cast<chrono::microseconds>(e.e_duration).count();
			 durationWidth = 8;
		 }
		 else if (g_settings.m_time_units == "nanoseconds") {
			 durationValue = e.e_duration.count();
			 durationWidth = 11;
		 }
		 os << setw(2) << right << cnt << ": "
			 << setw(40) << right << e.e_eventName << " -> "
			 << setw(durationWidth) << right << durationValue << " " << g_settings.m_time_units;
		 return os;
	 }
}