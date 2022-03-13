#pragma once
#include "namespace_def.h"
#include <iostream>
#include <algorithm>

NameSpace_Beg(utils)

template<typename It>
void print(It beg, It end)
{
	std::for_each(beg, end, [](typename It::value_type& it) -> void { std::cout << it << " "; });
	std::cout << std::endl;
}

NameSpace_End(utils)