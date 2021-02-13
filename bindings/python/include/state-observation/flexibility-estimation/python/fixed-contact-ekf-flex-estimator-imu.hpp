///////////////////////////////////////////////////////////////////////////////
///
/// \file              fixed-contact-ekf-flex-estimator-imu.hpp
/// \brief             Python exposition functions for
///                    stateObservation::flexibilityEstimation::EKFFlexibilityEstimationBase.
///
/// \copyright         2016 Wandercraft, 86 rue de Paris 91400 Orsay, France.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_OBSERVATION_PYTHON_FIXED_CONTACT_EKF_FLEX_ESTIMATOR_IMU_HPP
#define STATE_OBSERVATION_PYTHON_FIXED_CONTACT_EKF_FLEX_ESTIMATOR_IMU_HPP

#include <boost/python.hpp>

#include <state-observation/flexibility-estimation/fixed-contact-ekf-flex-estimator-imu.hpp>

namespace stateObservation
{
	namespace flexibilityEstimation
	{
		namespace python
		{
			namespace bp = boost::python;

			struct FixedContactEKFFlexEstimatorIMUVisitor :
				public bp::def_visitor<FixedContactEKFFlexEstimatorIMUVisitor>
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
				/// \brief Build FixedContactEKFFlexEstimatorIMU instance.
				///
				///////////////////////////////////////////////////////////////////////////////
				static FlexibilityEstimatorBase* make(double dt);

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

#endif  // STATE_OBSERVATION_PYTHON_FIXED_CONTACT_EKF_FLEX_ESTIMATOR_IMU_HPP
