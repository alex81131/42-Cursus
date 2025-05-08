#pragma once
# include "ATarget.hpp"
# include <map>

class	TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();

		void		learnTargetType(ATarget* target);
		void		forgetTargetType(const std::string& targetType);
		ATarget*	createTarget(const std::string& targetType);

	private:
		std::map<std::string, ATarget*>	_targets;

		TargetGenerator(const TargetGenerator& other);					// TargetGenerator bob(jim);
		TargetGenerator&	operator = (const TargetGenerator& other);	// bob = jim;
};