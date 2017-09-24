#include "cos.h"
#include <math.h>

using namespace noise::module;

Cos::Cos() : Module (GetSourceModuleCount ())
{

}

double Cos::GetValue(double x, double y, double z) const
{
    assert (m_pSourceModule[0] != NULL);

    double value = m_pSourceModule[0]->GetValue (x, y, z);
    return pow(cos(m_delta +m_frequency* value),m_exponent);
}

Sin::Sin() : Module (GetSourceModuleCount ())
{

}

double Sin::GetValue(double x, double y, double z) const
{
    assert (m_pSourceModule[0] != NULL);

    double value = m_pSourceModule[0]->GetValue (x, y, z);
    return pow(sin(m_delta +m_frequency* value),m_exponent);
}

