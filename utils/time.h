#pragma once

#include <chrono>
#include "namespace_def.h"

Utils_Beg

using namespace std::chrono;

class Timer {
public:
	Timer() :beg_(high_resolution_clock::now()) {}
	void reset() { beg_ = high_resolution_clock::now(); }

	template<typename dur=microseconds>
	int64_t elapse() const {
		return duration_cast<dur>(high_resolution_clock::now() - beg_).count();
	}

private:
	time_point<high_resolution_clock> beg_;
};

class CurrentTime {
public:

};

Utils_End