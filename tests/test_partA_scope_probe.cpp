#include "scope_probe.hpp"
#include <sstream>
#include <iostream>
int main(){
    std::ostringstream oss; auto* old = std::cout.rdbuf(oss.rdbuf());
    { ScopeProbe s1{"outer"}; { ScopeProbe s2{"inner"}; } }
    std::cout.rdbuf(old);
    auto out = oss.str();
    if (out.find("Enter: outer") == std::string::npos) return 1;
    if (out.find("Enter: inner") == std::string::npos) return 2;
    if (out.find("Exit: inner") == std::string::npos) return 3;
    if (out.find("Exit: outer") == std::string::npos) return 4;
    return 0;
}
