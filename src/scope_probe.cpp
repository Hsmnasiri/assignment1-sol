#include "scope_probe.hpp"
#include <iostream>
ScopeProbe::ScopeProbe(std::string n) : name(std::move(n)) { std::cout << "Enter: " << name << "\n"; }
ScopeProbe::~ScopeProbe() { std::cout << "Exit: " << name << "\n"; }
