/**
 * \file      observer-base.hpp
 * \author    Mehdi Benallegue
 * \date       2012
 * \brief      Defines the base class of a state
 *             observer.
 *             The observer is destinated to any dynamical system with a vector
 *             state representation
 *             The file describes also
 *             the used data structures and exceptions of the derivated classes
 *
 * \details
 *
 *
 */



#ifndef OBSERVERBASEHPP
#define OBSERVERBASEHPP

#include <Eigen/Core>
#include <Eigen/Dense>
#include <exception>
#include <boost/static_assert.hpp>
#include <boost/assert.hpp>

namespace stateObserver
{
    /**
     * \class    ObserverException
     * \brief    The base class for the exceptions thrown by an observer
     *
     * \details
     *
     */
    class ObserverException: public std::exception
    {
    public:
        ObserverException(const char * const & c)
                :std::exception(), what_(c)
        {}

        virtual const char* what() const throw()
        {
            return what_;
        }

    protected:
        const char* what_;

    };

    /**
     * \class  InitializationException
     * \brief  An exception thrown in cas of uninitialized variable
     *
     * \details
     *
     */
    class InitializationException: public ObserverException
    {
    public:
        InitializationException(const char * const & c)
                :ObserverException(c)
        {}
    };

    /**
     * \class  TimeException
     * \brief  An exception thrown when the user tries to observe a value with
     *         a wrong time parameter (too early or too late)
     *
     * \details
     *
     */
    class TimeException: public ObserverException
    {
    public:
        TimeException(const char * const & c)
                :ObserverException(c)
        {}
    };

    /**
     * \class    DiscreteTimeMatrix
     * \brief    This class describes a structure composed by a matrix
     *           of a given size and a time-index parameter. It can tell also if
     *           it initialized or not.
     *           It is templated by:
     *           \li r : number of rows
     *           \li c : number of columns
     *           r and c must be positive.
     *
     * \details
     *
     */
    class DiscreteTimeMatrix
    {
    public:

        ///Definition of matrix type
        typedef Eigen::MatrixXd MatrixT;

        ///Default constructor
        DiscreteTimeMatrix();

        ///A constructor with a given matrix value and a time index
        DiscreteTimeMatrix(const MatrixT& v, unsigned k);

        ///Set the value of the matrix and the time sample
        inline void set(const MatrixT& v,unsigned k);

        ///Get the matrix value
        inline MatrixT operator()()const;

        ///Get the time index
        inline const unsigned & getTime()const;

        ///Says whether the matrix is initialized or not
        inline const bool & isSet()const;

        ///Switch off the initalization flag, the value is no longer accessible
        inline void reset();

    protected:

        inline void check_()const;

        ///this variable ensures the matrix is initialized,
        bool isSet_;

        unsigned k_;
        MatrixT v_;
    };


    /**
     * \class  ObserverBase
     * \brief  The base class for observers.
     *         The observer is destinated to any dynamical system with a vector
     *         state representation. This class mostly defined an abstract
     *         interface, static constants and types. It is templated by:
     *
     *         \li n : size of the state vector
     *         \li m : size of the measurements vector
     *         \li p : size of the input vector
     *
     * \details
     *
     */


    class ObserverBase
    {
    public:

        ///StateVector is the type of state vector
        typedef Eigen::VectorXd StateVector;

        ///MeasureVector is the type of measurements vector
        typedef Eigen::VectorXd MeasureVector;

        ///InputVector is the type of the input vector
        typedef Eigen::VectorXd InputVector;


        ObserverBase();

        ObserverBase(unsigned n, unsigned m, unsigned p=0);



        ///Destructor
        virtual ~ObserverBase(){};


        virtual void setStateSize(unsigned n);

        virtual unsigned getStateSize() const;

        virtual void setMeasureSize(unsigned m);

        virtual unsigned getMeasureSize() const;

        virtual void setInputSize(unsigned p);

        virtual unsigned getInputSize() const;




        ///Set the value of the state vector at time index k
        virtual void setState(const StateVector& x_k,unsigned k)=0;

        ///Remove all the given past values of the state
        virtual void clearStates()=0;

        ///Set the value of the measurements vector at time index k
        virtual void setMeasurement(const MeasureVector& x_k,unsigned k)=0;

        ///Remove all the given past values of the measurements
        virtual void clearMeasurements()=0;

        ///Set the value of the input vector at time index k
        virtual void setInput(const InputVector& x_k,unsigned k)=0;

        ///Remove all the given past values of the inputs
        virtual void clearInputs()=0;

        ///Run the observer loop and gets the state estimation of the state at
        ///instant k
        virtual StateVector getEstimateState(unsigned k)=0;

        ///Reinitializes the whole observer
        ///default behavior is to call the three "ObserverBase::clear*" methods
        virtual void reset();


        virtual Eigen::VectorXd stateVectorConstant( double c ) const;

        virtual Eigen::VectorXd stateVectorRandom() const;

        virtual Eigen::VectorXd stateVectorZero() const;

        virtual bool checkStateVector(const StateVector &) const;


        virtual Eigen::VectorXd measureVectorConstant( double c ) const;

        virtual Eigen::VectorXd measureVectorRandom() const;

        virtual Eigen::VectorXd measureVectorZero() const;

        virtual bool checkMeasureVector(const MeasureVector &) const;


        virtual Eigen::VectorXd inputVectorConstant( double c ) const;

        virtual Eigen::VectorXd inputVectorRandom() const;

        virtual Eigen::VectorXd inputVectorZero() const;

        virtual bool checkInputVector(const InputVector &) const;

    protected:


        ///stateSize is the size of the state vector
        unsigned n_;

        ///measureSize is the size of measurements vector
        unsigned m_;

        ///inputSize is the size of the input vector
        unsigned p_;

    };

#include <state-observer/observer-base.hxx>

}

#endif
