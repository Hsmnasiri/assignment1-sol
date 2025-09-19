#pragma once
#include <string>
struct ScopeProbe {
    std::string name;
    explicit ScopeProbe(std::string n);
    ~ScopeProbe();
    ScopeProbe(const ScopeProbe&) = delete;
    ScopeProbe& operator=(const ScopeProbe&) = delete;
};
