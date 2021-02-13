///////////////////////////////////////////////////////////////////////////////
///
/// \file              fixed-contact-ekf-flex-estimator-imu.cpp
/// \brief             Python exposition functions for
///                    stateObservation::flexibilityEstimation::FlexibilityEstimationBase.
///
/// \copyright         2016 Wandercraft, 86 rue de Paris 91400 Orsay, France.
///
////////////////////////////////////////////////////////////////////////////////

#include <boost/python.hpp>

#include <state-observation/flexibility-estimation/python/fixed-contact-ekf-flex-estimator-imu.hpp>

namespace stateObservation
{
	namespace flexibilityEstimation
	{
		namespace python
		{
			template<class PyClass>
			void FixedContactEKFFlexEstimatorIMUVisitor::visit(PyClass& cl) const
			{
				cl
					.def("setContactsNumber", &FixedContactEKFFlexEstimatorIMU::setContactsNumber)
					.def("setContactPosition", &FixedContactEKFFlexEstimatorIMU::setContactPosition)
					.def("setVirtualMeasurementsCovariance",
					     &FixedContactEKFFlexEstimatorIMU::setVirtualMeasurementsCovariance)
					.def("getVirtualMeasurementsCovariance",
					     &FixedContactEKFFlexEstimatorIMU::getVirtualMeasurementsCovariance)
					.def("setSamplingPeriod", &FixedContactEKFFlexEstimatorIMU::setSamplingPeriod)
					;
			}


			void FixedContactEKFFlexEstimatorIMUVisitor::expose()
			{
				bp::class_<FixedContactEKFFlexEstimatorIMU,
					FixedContactEKFFlexEstimatorIMU*,
					bp::bases<EKFFlexibilityEstimatorBase>,
					boost::noncopyable>("FixedContactEKFFlexEstimatorIMU",
					                    "Fixed contact EKF Flexibility estimator with IMU",
					                    bp::init<double>(bp::args("dt"),
					                                     "@param dt Sampling period."))
					.def(FixedContactEKFFlexEstimatorIMUVisitor());
			}
		}  // end of namespace python.
	}  // end of namespace flexibilityEstimation
}  // end of namespace stateObservation.
