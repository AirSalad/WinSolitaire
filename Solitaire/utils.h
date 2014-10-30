#pragma once
#if !defined(__UTILS_H__)
#define __UTILS_H__
// Library Includes
#include <strstream>
// Local Includes
// Types
// Constants
// Prototypes
#define VALIDATE(a) if (!a) return (false)
template<typename T>
std::string ToString(const T& _value)
{
std::strstream theStream;
theStream << _value << std::ends;
return (theStream.str());
}
#endif // __UTILS_H__