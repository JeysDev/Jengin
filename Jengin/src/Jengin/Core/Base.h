#pragma once

#ifndef JN_PLATFORM_WINDOWS
	#error "Only Windows is supported for now"
#endif

#define HZ_EXPAND_MACRO(x) x

#ifdef JN_ENABLE_ASSERTS
	#define JN_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { JN##type##ERROR(msg, __VA_ARGS__); JN_DEBUGBREAK(); } }
	#define JN_INTERNAL_ASSERT_WITH_MSG(type, check, ...) JN_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define JN_INTERNAL_ASSERT_NO_MSG(type, check) JN_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", JN_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define JN_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define JN_INTERNAL_ASSERT_GET_MACRO(...) JN_EXPAND_MACRO( JN_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, JN_INTERNAL_ASSERT_WITH_MSG, JN_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define JN_ASSERT(...) JN_EXPAND_MACRO( JN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define JN_CORE_ASSERT(...) JN_EXPAND_MACRO( JN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define JN_ASSERT(...)
	#define JN_CORE_ASSERT(...)
#endif
#define BIT(x) (1 << x)