///////////////////////////////////////////////////////////////////////////////
///
/// \file              flexibility-estimator-base.hpp
/// \brief             Python exposition functions for
///                    stateObservation::flexibilityEstimation::FlexibilityEstimationBase.
///
/// \copyright         2016 Wandercraft, 86 rue de Paris 91400 Orsay, France.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_OBSERVATION_PYTHON_FLEXIBILITY_ESTIMATOR_BASE_HPP
#define STATE_OBSERVATION_PYTHON_FLEXIBILITY_ESTIMATOR_BASE_HPP

#include <boost/python.hpp>

#include <state-observation/flexibility-estimation/flexibility-estimator-base.hpp>

namespace stateObservation
{
	namespace flexibilityEstimation
	{
		namespace python
		{
			namespace bp = boost::python;

			struct FlexibilityEstimatorBaseVisitor :
				public bp::def_visitor<FlexibilityEstimatorBaseVisitor>
			{
			public:
				///////////////////////////////////////////////////////////////////////////////
				///
				/// \brief Expose C++ API through the visitor.
				///
				///////////////////////////////////////////////////////////////////////////////
				template<class PyClass>	void visit(PyClass& cl) const;

				///////////////////////////////////////////////////////////////////////////////
				///
				/// \brief Expose.
				///
				///////////////////////////////////////////////////////////////////////////////
				static void expose();
			};
		}  // end of namespace python.
	}  // end of namespace flexibilityEstimation
}  // end of namespace stateObservation.

#endif  // STATE_OBSERVATION_PYTHON_FLEXIBILITY_ESTIMATOR_BASE_HPP
