#pragma once
#include <cstdint>
#include "Validator.h"

class IdValidator : public Validator <uint32_t>
{
public:
	IdValidator();
	virtual bool fieldIsValid(const uint32_t& id);

private:
	std::string error();
	void checkLength(uint32_t id);
	void multId(uint32_t id);

	int m_sum;
	int m_length;
};
