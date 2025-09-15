#include "TimedTask.h"
#include <iomanip>
using namespace std;

namespace seneca {
	TimedTask::TimedTask() : t_numOfRecs{ 0 }, t_startTime{}, t_endTime{} {};

	void TimedTask::startClock() {
		t_startTime = chrono::steady_clock::now();
	};

	void TimedTask::stopClock() {
		t_endTime = chrono::steady_clock::now();
	};

	void TimedTask::addTask( const string name) {
		auto duration = std::chrono::duration_cast<chrono::nanoseconds>(t_endTime - t_startTime);
		tasks[t_numOfRecs].ta_taskName = name;
		tasks[t_numOfRecs].ta_unitsOfTime = "nanoseconds";
		tasks[t_numOfRecs].ta_durationOfTask = duration;
		t_numOfRecs++;
	};

	ostream& operator<<(ostream& os, const TimedTask& tt) {
		os << "Execution Times: " << endl;
		os << "--------------------------" << endl;
		for (int i = 0; i < tt.t_numOfRecs; i++) {
			os << setw(21) << left << tt.tasks[i].ta_taskName
				<< setw(13) << right << tt.tasks[i].ta_durationOfTask.count()
				<< " " << tt.tasks[i].ta_unitsOfTime << '\n';
		}
		os << "--------------------------";
		return os;
	}
}

