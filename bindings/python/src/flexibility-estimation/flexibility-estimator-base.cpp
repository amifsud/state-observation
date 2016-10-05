///////////////////////////////////////////////////////////////////////////////
///
/// \file              flexibility-estimator-base.cpp
/// \brief             Python exposition functions for
///                    stateObservation::flexibilityEstimation::FlexibilityEstimationBase.
///
/// \copyright         2016 Wandercraft, 86 rue de Paris 91400 Orsay, France.
///
////////////////////////////////////////////////////////////////////////////////

#include <boost/python.hpp>

#include <state-observation/flexibility-estimation/python/flexibility-estimator-base.hpp>

namespace stateObservation
{
	namespace flexibilityEstimation
	{
		namespace python
		{
			template<class PyClass>
			void FlexibilityEstimatorBaseVisitor::visit(PyClass& cl) const
			{
				cl
					.def("setFlexibilityGuess", &FlexibilityEstimatorBase::setFlexibilityGuess)
					.def("setMeasurement", &FlexibilityEstimatorBase::setMeasurement)
					.def("getFlexibility", &FlexibilityEstimatorBase::getFlexibility)
					;
			}


			void FlexibilityEstimatorBaseVisitor::expose()
			{
				bp::class_<FlexibilityEstimatorBase,
					FlexibilityEstimatorBase*,
					boost::noncopyable>("FlexibilityEstimatorBase",
					                    "Flexibility estimator interface",
					                    bp::no_init)
					.def(FlexibilityEstimatorBaseVisitor());
			}
		}  // end of namespace python.
	}  // end of namespace flexibilityEstimation
}  // end of namespace stateObservation.
