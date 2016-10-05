///////////////////////////////////////////////////////////////////////////////
///
/// \file              python.cpp
/// \brief             Python exposition functions for state-observation
///
/// \copyright         2016 Wandercraft, 86 rue de Paris 91400 Orsay, France.
///
////////////////////////////////////////////////////////////////////////////////

#include "state-observation/python/python.hpp"

#include "state-observation/flexibility-estimation/python/flexibility-estimator-base.hpp"
#include "state-observation/flexibility-estimation/python/ekf-flexibility-estimator-base.hpp"
#include "state-observation/flexibility-estimation/python/fixed-contact-ekf-flex-estimator-imu.hpp"

namespace stateObservation
{
	namespace flexibilityEstimation
	{
		namespace python
		{
			void exposeFlexibilityEstimation()
			{
				FlexibilityEstimatorBaseVisitor::expose();
				EKFFlexibilityEstimatorBaseVisitor::expose();
				FixedContactEKFFlexEstimatorIMUVisitor::expose();
			}
		}  // end of namespace python.
	}  // end of namespace flexibilityEstimation.
}  // end of namespace stateObservation.
