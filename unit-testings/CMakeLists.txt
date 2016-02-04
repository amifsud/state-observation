
# provide path to dependency libraries

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)
LINK_DIRECTORIES(${${PROJECT_NAME}_BINARY_DIR}/src)

ADD_EXECUTABLE(test-kalman-filter test-kalman-filter.cpp)
ADD_EXECUTABLE(test-kalman-filter-template test-kalman-filter-template.cpp)
ADD_EXECUTABLE(imu-test imu-test.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})
ADD_EXECUTABLE(HRP2LAAS-IMU-Observation HRP2LAAS-IMU-Observation.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})
ADD_EXECUTABLE(flex-estimation-test flex-estimation-test.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})
ADD_EXECUTABLE(simple-flex-estimation-test simple-flex-estimation-test.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})
ADD_EXECUTABLE(real-offline-flexibility-estimator real-offline-flexibility-estimator.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})
ADD_EXECUTABLE(other-tests other-tests.cpp)
ADD_EXECUTABLE(test_acceleration_stabilization test_acceleration_stabilization.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})
ADD_EXECUTABLE(test_imu-elastic-local-frame-dynamical-system test_imu-elastic-local-frame-dynamical-system.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})
ADD_EXECUTABLE(test_model-base-ekf-flex-estimator-imu test_model-base-ekf-flex-estimator-imu.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})
ADD_EXECUTABLE(test_model-base-ekf-flex-estimator-imu_withComBias_withForcesSensors test_model-base-ekf-flex-estimator-imu_withComBias_withForcesSensors.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})
ADD_EXECUTABLE(zmpEstimation zmpEstimation.cpp ${${PROJECT_NAME}_ABSOLUTE_HEADERS})


TARGET_LINK_LIBRARIES(test-kalman-filter ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(test-kalman-filter-template ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(imu-test ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(HRP2LAAS-IMU-Observation ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(flex-estimation-test ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(simple-flex-estimation-test ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(real-offline-flexibility-estimator ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(other-tests ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(other-tests ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(test_acceleration_stabilization ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(test_imu-elastic-local-frame-dynamical-system ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(test_model-base-ekf-flex-estimator-imu ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(test_model-base-ekf-flex-estimator-imu_withComBias_withForcesSensors ${Boost_LIBRARIES} ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(zmpEstimation ${Boost_LIBRARIES} ${PROJECT_NAME})

ADD_TEST(test-kalman-filter test-kalman-filter)
ADD_TEST(test-kalman-filter-template test-kalman-filter-template)
ADD_TEST(imu-test imu-test)
ADD_TEST(flex-estimation-test flex-estimation-test)
ADD_TEST(simple-flex-estimation-test simple-flex-estimation-test)
ADD_TEST(HRP2LAAS-IMU-Observation HRP2LAAS-IMU-Observation)
ADD_TEST(test_acceleration_stabilization test_acceleration_stabilization)
ADD_TEST(test_imu-elastic-local-frame-dynamical-system test_imu-elastic-local-frame-dynamical-system)
ADD_TEST(test_model-base-ekf-flex-estimator-imu test_model-base-ekf-flex-estimator-imu)
ADD_TEST(test_model-base-ekf-flex-estimator-imu_withComBias_withForcesSensors test_model-base-ekf-flex-estimator-imu_withComBias_withForcesSensors)
ADD_TEST(zmpEstimation zmpEstimation)

#ADD_TEST(real-offline-flexibility-estimator real-offline-flexibility-estimator)

#### Data
set(DATA_FOLDER ${CMAKE_SOURCE_DIR}/unit-testings/inputFiles)


add_custom_command(TARGET test_model-base-ekf-flex-estimator-imu POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory ${DATA_FOLDER}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${DATA_FOLDER}/WOforcesWOcombias
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WOforcesWOcombias/source_state.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WOforcesWOcombias/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WOforcesWOcombias/source_input.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WOforcesWOcombias/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WOforcesWOcombias/source_measurement.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WOforcesWOcombias/
)



add_custom_command(TARGET test_model-base-ekf-flex-estimator-imu_withComBias_withForcesSensors POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory ${DATA_FOLDER}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${DATA_FOLDER}/WforcesWcombias
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WforcesWcombias/source_state.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WforcesWcombias/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WforcesWcombias/source_input.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WforcesWcombias/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WforcesWcombias/source_measurement.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WforcesWcombias/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WforcesWcombias/source_inovation.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WforcesWcombias/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WforcesWcombias/source_predictedSensors.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WforcesWcombias/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WforcesWcombias/source_predictedState.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WforcesWcombias/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WforcesWcombias/source_simulatedSensors.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WforcesWcombias/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/WforcesWcombias/source_stateCovariance.dat
  ${CMAKE_BINARY_DIR}/unit-testings/inputFiles/WforcesWcombias/
)


