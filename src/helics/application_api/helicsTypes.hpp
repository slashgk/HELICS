/*

Copyright (C) 2017, Battelle Memorial Institute
All rights reserved.

This software was co-developed by Pacific Northwest National Laboratory, operated by the Battelle Memorial
Institute; the National Renewable Energy Laboratory, operated by the Alliance for Sustainable Energy, LLC; and the
Lawrence Livermore National Laboratory, operated by Lawrence Livermore National Security, LLC.

*/
#ifndef HELICS_TYPES_H_
#define HELICS_TYPES_H_
#pragma once
#include <string>
#include <vector>
#include <complex>
#include <typeinfo>

namespace helics
{
using identifier_type = unsigned long;

constexpr identifier_type invalid_id_value = (identifier_type)(-1);  //!< defining an invalid id value

																	 /** the known types of identifiers*/
enum class identifiers : char
{
	publication,
	subscription,
	filter,
	endpoint,

};
/** class defining an  identifier type
@details  the intent of this class is to limit the operations available on a publication identifier
to those that are a actually required and make sense, and make it as low impact as possible.
it also acts to limit any mistakes of a publication_id for a subscription_id or other types of interfaces
*/
template <class BaseType, identifiers ID, BaseType invalidValue = (BaseType(-1))>
class identifier_id_t
{
private:
	BaseType _value;  //!< the underlying index value

public:
	static const identifiers identity{ ID };  //!< the type of the identifier
	using underlyingType = BaseType;
	/** default constructor*/
	constexpr identifier_id_t() noexcept : _value(invalidValue) {};
	/** value based constructor*/
	constexpr identifier_id_t(BaseType val) noexcept : _value(val) {};
	/** copy constructor*/
	constexpr identifier_id_t(const identifier_id_t &id) noexcept : _value(id._value) {};
	/** assignment from number*/
	identifier_id_t &operator= (BaseType val) noexcept
	{
		_value = val;
		return *this;
	};
	/** copy assignment*/
	identifier_id_t &operator= (const identifier_id_t &id) noexcept
	{
		_value = id._value;
		return *this;
	};

	/** get the underlying value*/
	BaseType value() const noexcept { return _value; };
	/** equality operator*/
	bool operator== (identifier_id_t id) const noexcept { return (_value == id._value); };
	/** iequality operator*/
	bool operator!= (identifier_id_t id) const noexcept { return (_value != id._value); };
	/** less than operator for sorting*/
	bool operator< (identifier_id_t id) const noexcept { return (_value < id._value); };
};

using publication_id_t = identifier_id_t<identifier_type, identifiers::publication, invalid_id_value>;
using subscription_id_t = identifier_id_t<identifier_type, identifiers::subscription, invalid_id_value>;
using endpoint_id_t = identifier_id_t<identifier_type, identifiers::endpoint, invalid_id_value>;
using filter_id_t = identifier_id_t<identifier_type, identifiers::filter, invalid_id_value>;

/** template class for generating a known name of a type*/
template <class X>
inline std::string typeNameString()
{
	//this will probably not be the same on all platforms
	return std::string(typeid(X).name());
}
template <>
inline std::string typeNameString <std::vector<std::string>>()
{
	return "string_vector";
}
template <>
inline std::string typeNameString <std::vector<double>>()
{
	return "double_vector";
}

/** for float*/
template <>
inline std::string typeNameString<double>()
{
	return "double";
}

/** for float*/
template <>
inline std::string typeNameString<float>()
{
	return "float";
}
/** for character*/
template <>
inline std::string typeNameString<char>()
{
	return "char";
}
/** for unsigned character*/
template <>
inline std::string typeNameString<unsigned char>()
{
	return "uchar";
}
/** for integer*/
template <>
inline std::string typeNameString<std::int32_t>()
{
	return "int32";
}
/** for unsigned integer*/
template <>
inline std::string typeNameString<std::uint32_t>()
{
	return "uint32";
}
/** for 64 bit unsigned integer*/
template <>
inline std::string typeNameString<std::int64_t>()
{
	return "int64";
}
/** for 64 bit unsigned integer*/
template <>
inline std::string typeNameString<std::uint64_t>()
{
	return "uint64";
}
/** for complex double*/
template <>
inline std::string typeNameString<std::complex<float>>()
{
	return "complex_f";
}
/** for complex double*/
template <>
inline std::string typeNameString<std::complex<double>>()
{
	return "complex";
}
template <>
inline std::string typeNameString<std::string>()
{
	return "string";
}

enum class helicsType_t:int
{
	helicsString = 0,
	helicsDouble=1,
	helicsInt=2,
	
	helicsComplex=3,
	helicsVector=4,
	helicsInvalid=23425,
};

const std::string &typeNameStringRef(helicsType_t type);

helicsType_t getTypeFromString(const std::string &typeName);

std::string helicsComplexString(double real, double imag);
std::string helicsComplexString(std::complex<double> val);
std::string helicsVectorString(const std::vector<double> &val);

std::complex<double> helicsGetComplex(const std::string &val);

std::vector<double> helicsGetVector(const std::string &val);

void helicsGetVector(const std::string &val, std::vector<double> &data);

/** template class for generating a known name of a type*/
template <class X>
constexpr helicsType_t helicsType()
{
	return helicsType_t::helicsInvalid;
}
template <>
constexpr helicsType_t helicsType<std::string>()
{
	return helicsType_t::helicsString;
}

template <>
constexpr helicsType_t helicsType<double>()
{
	return helicsType_t::helicsDouble;
}

template <>
constexpr helicsType_t helicsType<float>()
{
	return helicsType_t::helicsDouble;
}

template <>
constexpr helicsType_t helicsType<int>()
{
	return helicsType_t::helicsInt;
}

template <>
inline helicsType_t helicsType<int64_t>()
{
	return helicsType_t::helicsInt;
}

template <>
constexpr helicsType_t helicsType<std::complex<double>>()
{
	return helicsType_t::helicsComplex;
}

template <>
constexpr helicsType_t helicsType<std::vector<double>>()
{
	return helicsType_t::helicsVector;
}

}
#endif