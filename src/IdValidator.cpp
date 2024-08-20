#include "IdValidator.h"

IdValidator::IdValidator()
	:m_sum(0), m_length(0)
{}

bool IdValidator::fieldIsValid(const uint32_t& idNum)
{
	m_sum = 0;
	m_length = 1;

	checkLength(idNum);
	if (m_length != 9)
		return false;

	multId(idNum);

	if (m_sum % 10 == 0)
		return true;

	return false;
}

std::string IdValidator::error()
{
	return "ERROR: Wrong control digit";
}

void IdValidator::checkLength(uint32_t id)
{
	while (id / 10 != 0)
	{
		id = id / 10;
		m_length++;
	}
}

void IdValidator::multId(uint32_t id)
{
	for (int i = 0; i <= m_length; i++)
	{
		int num,			// The single num in the ID that will be check
			binary, 		// The numbers 1 or 2 that will be mult with num
			mult,			// Result of multiplication of num with 1 or 2
			sum_of_mult;

		num = id % 10;			// Take the last number in the ID
		id = id / 10;			// Updates the ID without the last number

		if (i % 2 == 0)
			binary = 1;
		else
			binary = 2;

		mult = num * binary;

		if (mult > 9)
			sum_of_mult = (mult / 10) + (mult % 10);
		else
			sum_of_mult = mult;

		m_sum += sum_of_mult;
	}
}
