#pragma once

#include <spdlog/spdlog.h>

namespace Jengin {
	class Log {
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
#if JN_ENGINE_BUILD
	#define JN_CORE_TRACE(...)    ::Jengin::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define JN_CORE_INFO(...)     ::Jengin::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define JN_CORE_WARN(...)     ::Jengin::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define JN_CORE_ERROR(...)    ::Jengin::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define JN_CORE_FATAL(...)    ::Jengin::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#endif

#define JN_TRACE(...)             ::Jengin::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JN_INFO(...)              ::Jengin::Log::GetClientLogger()->info(__VA_ARGS__)
#define JN_WARN(...)              ::Jengin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JN_ERROR(...)             ::Jengin::Log::GetClientLogger()->error(__VA_ARGS__)
#define JN_FATAL(...)             ::Jengin::Log::GetClientLogger()->fatal(__VA_ARGS__)
