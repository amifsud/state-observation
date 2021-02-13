///////////////////////////////////////////////////////////////////////////////
///
/// \file              module.cpp
/// \brief             Python module implementation for state-observation.
///
/// \copyright         2016 Wandercraft, 86 rue de Paris 91400 Orsay, France.
///
////////////////////////////////////////////////////////////////////////////////

#include <boost/python.hpp>
#include <eigenpy/eigenpy.hpp>

#include "state-observation/python/python.hpp"

BOOST_PYTHON_MODULE(libstate_observation_py)
{
	// Expose unaligned Eigen vectors and matrices.
  eigenpy::enableEigenPy();

	using namespace stateObservation;

	flexibilityEstimation::python::exposeFlexibilityEstimation();
}
