#pragma once

#include <memory>
#include <type_traits>
#include "cpp_version.h"

#if CPP_STANDARD <= 201103L

namespace std {

template<typename T, typename... Args, enable_if_t<!is_array_v<T>, int> = 0>
inline unique_ptr<T> make_unique(Args&&... args)
{
	return (unique_ptr<T>(new T(forward<Args>(args)...)));
}

template<typename T, enable_if_t<is_array_v<T> && extent_v<T> == 0, int> = 0>
inline unique_ptr<T> make_unique(size_t size)
{
	typedef remove_extent_t<T> elem;
	return (unique_ptr<T>(new elem[size]()));
}

template<typename T, typename... Args>
typename enable_if<extent<T>::value != 0, void>::type make_unique(Args&&...) = delete;

}

#endif


