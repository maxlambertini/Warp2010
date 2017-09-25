#ifndef COS_H
#define COS_H

#include "modulebase.h"


namespace noise
{

  namespace module
  {

    class  NOISE_SHARED_EXPORT  Cos : public Module
    {
    public:

        Cos();

        double m_exponent = 1.0;
        double m_frequency = 3.14159;
        double m_delta = 0.0;

        double GetExponent() const { return m_exponent; }
        void SetExponent(double e) { m_exponent = e; }
        double GetFrequency() const { return m_frequency; }
        void SetFrequency(double e) { m_frequency = e; }
        double GetDelta() const { return m_delta; }
        void SetDelta(double e) { m_delta = e; }

        virtual double GetValue (double x, double y, double z) const;
        virtual int GetSourceModuleCount () const
        {
            return 1;
        }

    };

    class  NOISE_SHARED_EXPORT  Sin : public Module
    {
    public:
        double m_exponent = 1.0;
        double m_frequency = 3.14159;
        double m_delta = 0.0;

        double GetExponent() const { return m_exponent; }
        void SetExponent(double e) { m_exponent = e; }
        double GetFrequency() const { return m_frequency; }
        void SetFrequency(double e) { m_frequency = e; }
        double GetDelta() const { return m_delta; }
        void SetDelta(double e) { m_delta = e; }

        Sin();
        virtual double GetValue (double x, double y, double z) const;
        virtual int GetSourceModuleCount () const
        {
            return 1;
        }

    };

  }
}
#endif // COS_H
