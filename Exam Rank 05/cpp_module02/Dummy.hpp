#pragma once
# include "ATarget.hpp"

class	Dummy: public ATarget 
{
	public:
		Dummy();
		~Dummy();

		ATarget*	clone() const;

	private:
		Dummy(const Dummy& other);
		Dummy&	operator = (const Dummy& other);
};