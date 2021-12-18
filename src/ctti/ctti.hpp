#pragma once

#include "ctti_fwd.hpp"
#include "type.hpp"

//*************************************************************************************************
#define DECLARE_STRUCT(STRUCT)\
	friend constexpr auto ::ctti::constexpr_type<::STRUCT>();\
	template <typename CttiDeclarationTypename>\
	static constexpr auto constexpr_type()\
	{\
		return ::ctti::TypeFactory<CttiDeclarationTypename>::get\
		(\
			::ctti::attr::Name(#STRUCT),\
			::ctti::attr::Sizeof(sizeof(STRUCT)),

//*************************************************************************************************
#define END_STRUCT\
			::ctti::attr::Struct()\
		);\
	}

//*************************************************************************************************
#define DECLARE_FUNDAMENTAL(TYPE)\
	template <>\
	constexpr auto ::ctti::constexpr_type<TYPE>()\
	{\
		return ::ctti::TypeFactory<TYPE>::get(\
            ::ctti::attr::Name(#TYPE),\
			::ctti::attr::Size(sizeof(TYPE)),\
			::ctti::attr::Fundamental()\
        );\
	}

DECLARE_FUNDAMENTAL(bool)

DECLARE_FUNDAMENTAL(short int)
DECLARE_FUNDAMENTAL(unsigned short int)
DECLARE_FUNDAMENTAL(int)
DECLARE_FUNDAMENTAL(unsigned int)
DECLARE_FUNDAMENTAL(long int)
DECLARE_FUNDAMENTAL(unsigned long int)
DECLARE_FUNDAMENTAL(long long int)
DECLARE_FUNDAMENTAL(unsigned long long int)

DECLARE_FUNDAMENTAL(signed char)
DECLARE_FUNDAMENTAL(unsigned char)
DECLARE_FUNDAMENTAL(char)
DECLARE_FUNDAMENTAL(wchar_t)
DECLARE_FUNDAMENTAL(char8_t)
DECLARE_FUNDAMENTAL(char16_t)
DECLARE_FUNDAMENTAL(char32_t)

DECLARE_FUNDAMENTAL(float)
DECLARE_FUNDAMENTAL(double)
DECLARE_FUNDAMENTAL(long double)

// #pragma once

// template <typename... Args>
// constexpr core::ConstexprString getFullTemplateStructName(core::ConstexprString className)
// {
// 	core::ConstexprString args = getFullTemplateStructName<Args...>();

// 	//auto classStatic = StringFactory<className.length()>(className.get());
// 	//auto argsStatic = StringFactory<args.length()>(args.get());

// 	//return core::ConstexprString((classStatic + "<" + argsStatic + ">").Get());
// 	return core::ConstexprString("asdf");
// }

// template <typename First, typename... Rest>
// constexpr const char* getFullTemplateStructName()
// {
// 	core::ConstexprString first = ctti::get<First>().template get<attr::Name>();
// 	core::ConstexprString rest = getFullTemplateStructName<Rest...>();
// 	auto firstStatic = StringFactory<first.length()>(first.get());
// 	auto restStatic = StringFactory<rest.length()>(rest.get());
// 	return (firstStatic + ", " + restStatic).Get();
// }

// template <typename Last>
// constexpr const char* getFullTemplateStructName()
// {
// 	return ctti::get<Last>().get<attr::Name>().get();
// }

/*
#define CTTI_DECLARE_TEMPLATE_STRUCT(STRUCT, ...)\
	friend constexpr auto ::ctti::get<::STRUCT<__VA_ARGS__>>();\
	template <typename CttiDeclarationTypename>\
	static constexpr auto getTypeInfo()\
	{\
		return ::ctti::AttrArrayFactory<CttiDeclarationTypename>::get\
		(\
			::attr::Name(#STRUCT),

*/