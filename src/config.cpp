#include "config.hpp"
#include <stdexcept>
// TODO Part D (error handling): throwing version + safe optional version
ConfigMap parse_config_throwing(std::string_view){ throw std::runtime_error("Not implemented"); }
std::optional<ConfigMap> parse_config_safe(std::string_view){ return std::nullopt; }
