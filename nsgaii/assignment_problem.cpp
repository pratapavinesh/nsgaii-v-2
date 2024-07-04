#include "assignment_problem.h"
#include "individual.h"
#include "math_aux.h"

#include <cmath>
#include <vector>
#include<iostream>

using std::size_t;
using std::cos;

// ----------------------------------------------------------------------
//		CProblemAssignment
// ----------------------------------------------------------------------

CProblemAssignment::CProblemAssignment(size_t M, size_t k, const std::string& name, double lbs, double ubs) :
	BProblem(name),
	M_(M),
	k_(k)
{
	lbs_.resize( k_, lbs); // lower bound
	ubs_.resize( k_, ubs); // upper bound 
}


bool CProblemAssignment5::Evaluate(CIndividual* indv) const
{
	CIndividual::TDecVec& x = indv->vars();
	CIndividual::TObjVec& f = indv->objs();

	if (x.size() != k_) return false; // #variables does not match

	f.resize(M_, 0);
	for (size_t i = 1; i < k_; ++i) {
	f[0] += -10 * exp(-0.2 * sqrt(MathAux::square(x[i - 1]) + MathAux::square(x[i])));
	}
	for (size_t i = 0; i < k_; ++i) {
	f[1] += pow(abs(x[i]), 0.8) + 5 * sin(pow(x[i], 3));
	}
	

	return true;
}


bool CProblemAssignment6::Evaluate(CIndividual* indv) const
{
	CIndividual::TDecVec& x = indv->vars();
	CIndividual::TObjVec& f = indv->objs();
	//std::cout << (x.size() == k_)<<'\n';
	if (x.size() != k_) return false; // #variables does not match

	f.resize(M_, 0);
	f[0] = MathAux::square(x[0]);
	f[1] = MathAux::square(x[0] - 2);

	return true;
}

