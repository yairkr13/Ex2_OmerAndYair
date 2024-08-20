#pragma once
#include "Validator.h"

template <typename T>
class RangeValidator : public Validator <T>
{
public:
	RangeValidator(T num1, T num2);
	~RangeValidator() {};
	
	virtual bool fieldIsValid(const T& val);

private:
	std::string error();

	T m_min;
	T m_max;
};

// ---------------- FUNCTIONS ---------------

template<typename T>
RangeValidator<T>::RangeValidator(T num1, T num2)
	: m_min(num1), m_max(num2)
{}

template<typename T>
std::string RangeValidator<T>::error()
{
	return "ERROR: Out of range";
}

template<typename T>
bool RangeValidator<T>::fieldIsValid(const T& val)
{
	return (val >= m_min && val <= m_max);
}
