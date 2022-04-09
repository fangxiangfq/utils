#pragma once

#include "namespace_def.h"

Utils_Beg

static inline bool low_case(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

static inline bool up_case(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

static inline bool number(char ch)
{
	return ch >= '0' && ch <= '9';
}

static inline bool toupper(char ch)
{
	return (ch >= 'a' && ch <= 'z') ? (ch & ~0x20) : ch;
}

static inline char tolower(char ch)
{
	return (ch >= 'A' && ch <= 'Z') ? (ch | 0x20) : ch;
}

Utils_End
