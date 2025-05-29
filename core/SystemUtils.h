#pragma once
#include <string>

namespace SystemUtils {
	std::string FormatBytes(size_t bytes);
	std::string FormatTime(const FILETIME& tm);
}