#ifndef ASSIGNMENT_PROBLEM__
#define ASSIGNMENT_PROBLEM__

#include "base_problem.h"
#include <cstddef>
#include<iostream>

// ----------------------------------------------------------------------
class CProblemAssignment : public BProblem
{
public:
	CProblemAssignment(std::size_t M, std::size_t k, const std::string& name, double lbs, double ubs);

	virtual std::size_t num_variables() const { return k_; }
	virtual std::size_t num_objectives() const { return M_; }

	virtual bool Evaluate(CIndividual* indv) const = 0;

protected:
	std::size_t M_; // number of objectives
	std::size_t k_; // number of variables
};


// ----------------------------------------------------------------------
//		CProblemAssignment5
// ----------------------------------------------------------------------

class CProblemAssignment5 : public CProblemAssignment
{
public:
	explicit CProblemAssignment5(std::size_t M, std::size_t k , double lbs , double ubs ) :CProblemAssignment(M, k, "Assignment5", lbs,ubs) {}
	virtual bool Evaluate(CIndividual* indv) const;
};


// ----------------------------------------------------------------------
//		CProblemAssignment6
// ----------------------------------------------------------------------

class CProblemAssignment6 : public CProblemAssignment
{
public:
	explicit CProblemAssignment6(std::size_t M, std::size_t k, double lbs, double ubs) :CProblemAssignment(M, k, "Assignment6", lbs, ubs) {
		//std::cout << "what happend !" << lbs << '\n';
	}
	virtual bool Evaluate(CIndividual* indv) const;
};

#endif