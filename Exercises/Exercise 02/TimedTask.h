#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H
#include <iostream>
#include <chrono>
#include <string>

namespace seneca {
	class TimedTask {
		int t_numOfRecs;
		std::chrono::steady_clock::time_point t_startTime;
		std::chrono::steady_clock::time_point t_endTime;
		struct Task {
			std::string ta_taskName;
			std::string ta_unitsOfTime;
			std::chrono::nanoseconds ta_durationOfTask;
		};
		static const int maxTasks = 10;
		Task tasks[maxTasks];
	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask( const std::string);
		friend std::ostream& operator<<(std::ostream& os, const TimedTask&);
	};
}
#endif