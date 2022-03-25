#pragma once

#include <map>
#include <type_traits>
#include "nocopyable.h"

Utils_Beg

using namespace std;

using key_t = uint32_t;

template<typename Func>
class Events : NonCopyable {
public:
	static_assert(!is_function_v(Func), "para is not function");
	using key_t = uint32_t;
	key_t attach(Func&& f) {
		return assign(f);
	}

	key_t attach(const Func& f) {
		return assign(f);
	}

	void distach(key_t key) {
		obs_.erase(key);
	}

	template<typename ...Args>
	void notify_all(Args&&... args) {
		for (auto& it : obs_) {
			it.(forward<Args>(args)...);
		}
	}

	template<typename ...Args>
	void notify_one(key_t key, Args&&... args) {
		auto it = obs_.find(key);
		if (obs.end() == it) {
			return;
		}

		it->second(forward<Args>(args)...);
	}

private:
	template<typename F>
	key_t assign(F&& f) {
		key_t k = id_++;
		obs_.emplace(k, forward<F>(f));
	}

	key_t id_;
	map<key_t, Func> obs_;
};

Utils_End