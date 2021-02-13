///////////////////////////////////////////////////////////////////////////////
///
/// \file              ekf-flexibility-estimator-base.cpp
/// \brief             Python exposition functions for
///                    stateObservation::flexibilityEstimation::FlexibilityEstimationBase.
///
/// \copyright         2016 Wandercraft, 86 rue de Paris 91400 Orsay, France.
///
////////////////////////////////////////////////////////////////////////////////

#include <boost/python.hpp>

#include <state-observation/flexibility-estimation/python/ekf-flexibility-estimator-base.hpp>

namespace stateObservation
{
	namespace flexibilityEstimation
	{
		namespace python
		{
			template<class PyClass>
			void EKFFlexibilityEstimatorBaseVisitor::visit(PyClass& cl) const
			{
				cl
					.def("setFlexibilityCovariance", &EKFFlexibilityEstimatorBase::setFlexibilityCovariance)
					.def("getFlexibilityCovariance", &EKFFlexibilityEstimatorBase::getFlexibilityCovariance)
					.def("setProcessNoiseCovariance", &EKFFlexibilityEstimatorBase::setProcessNoiseCovariance)
					.def("getProcessNoiseCovariance", &EKFFlexibilityEstimatorBase::getProcessNoiseCovariance)
					.def("setMeasurementNoiseCovariance",
					     &EKFFlexibilityEstimatorBase::setMeasurementNoiseCovariance)
					.def("getMeasurementNoiseCovariance",
					     &EKFFlexibilityEstimatorBase::getMeasurementNoiseCovariance)
					.def("getMeasurement", &EKFFlexibilityEstimatorBase::getMeasurement)
					.def("setInput", &EKFFlexibilityEstimatorBase::setInput)
					.def("getInput", &EKFFlexibilityEstimatorBase::getInput)
					.def("setMeasurementInput", &EKFFlexibilityEstimatorBase::setMeasurementInput)
					.def("getMeasurementInput", &EKFFlexibilityEstimatorBase::getMeasurementInput)
					.def("getFlexibilityVector",
					     &EKFFlexibilityEstimatorBase::getFlexibilityVector,
					     bp::return_value_policy<bp::return_by_value>())
					.def("getStateSize", &EKFFlexibilityEstimatorBase::getStateSize)
					.def("getMeasurementSize", &EKFFlexibilityEstimatorBase::getMeasurementSize)
					.def("getInputSize", &EKFFlexibilityEstimatorBase::getInputSize)
					.def("getSimulatedMeasurement", &EKFFlexibilityEstimatorBase::getSimulatedMeasurement)
					.def("resetCovarianceMatrices", &EKFFlexibilityEstimatorBase::resetCovarianceMatrices)
					.def("getInovation", &EKFFlexibilityEstimatorBase::getInovation)
					.def("getPredictedMeasurement", &EKFFlexibilityEstimatorBase::getPredictedMeasurement)
					.def("getPrediction", &EKFFlexibilityEstimatorBase::getPrediction)
					.def("getLastPredictedMeasurement",
					     &EKFFlexibilityEstimatorBase::getLastPredictedMeasurement)
					.def("getLastPrediction", &EKFFlexibilityEstimatorBase::getLastPrediction)
					;
			}


			void EKFFlexibilityEstimatorBaseVisitor::expose()
			{
				bp::class_<EKFFlexibilityEstimatorBase,
					EKFFlexibilityEstimatorBase*,
					bp::bases<FlexibilityEstimatorBase>,
					boost::noncopyable>("EKFFlexibilityEstimatorBase",
					                    "EKF Flexibility estimator interface",
					                    bp::no_init)
					.def(EKFFlexibilityEstimatorBaseVisitor());
			}
		}  // end of namespace python.
	}  // end of namespace flexibilityEstimation
}  // end of namespace stateObservation.
