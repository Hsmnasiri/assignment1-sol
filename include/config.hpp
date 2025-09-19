#pragma once
#include <optional>
#include <string>
#include <unordered_map>
using ConfigMap = std::unordered_map<std::string, std::string>;
ConfigMap parse_config_throwing(std::string_view path);
std::optional<ConfigMap> parse_config_safe(std::string_view path);
