#pragma once
#include <string>

template <typename T>
class Validator
{
public:
	Validator() {};
	virtual std::string error() = 0;
	virtual bool fieldIsValid(const T& val) = 0;
};