///////////////////////////////////////////////////////////////////////////////
///
/// \file              python.hpp
/// \brief             Python exposition functions for state-observation.
///
/// \copyright         2016 Wandercraft, 86 rue de Paris 91400 Orsay, France.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_OBSERVATION_PYTHON_PYTHON_HPP
#define STATE_OBSERVATION_PYTHON_PYTHON_HPP

namespace stateObservation
{
	namespace flexibilityEstimation
	{
		namespace python
		{
			///////////////////////////////////////////////////////////////////////////////
			///
			/// \brief Expose flexibility estimation objects.
			///
			////////////////////////////////////////////////////////////////////////////////
			void exposeFlexibilityEstimation();
		}  // end of namespace python
	}  // end of namespace flexibilityEstimation.
}  // end of namespace stateObservation.

#endif  // STATE_OBSERVATION_PYTHON_PYTHON_HPP
