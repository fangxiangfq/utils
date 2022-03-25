#pragma once

#include <memory>
#include <stdexcept>
#include "namespace_def.h"

Utils_Beg

using namespace std;

template <typename T>
class Singleton {
public:
	template <typename ...Args>
	static T& instance(Args&&... args) {
		if (!ptr) {
			ptr.reset(new T(forward<Args>(args)...);
		}

		return *ptr;
	}

	static T& get() throw (logic_error) {
		if (!ptr) {
			throw logic_error("instance not init yet");
		}

		return *ptr;
	}

private:
	Singleton() = delete;
	static unique_ptr<T> ptr;
};

template <typename T>
unique_ptr<T> Singleton<T>::ptr;

Utils_End