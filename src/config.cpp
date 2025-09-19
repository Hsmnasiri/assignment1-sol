#include "config.hpp"
#include <cctype>
#include <fstream>
#include <stdexcept>
namespace {
bool is_blank_or_comment(const std::string& line){
    for(char c: line){ if (std::isspace((unsigned char)c)) continue; if(c=='#') return true; return false; }
    return true;
}
void trim(std::string& s){
    size_t b = s.find_first_not_of(" \t\r\n");
    size_t e = s.find_last_not_of(" \t\r\n");
    if (b == std::string::npos) { s.clear(); return; }
    s = s.substr(b, e-b+1);
}
}
ConfigMap parse_config_throwing(std::string_view path){
    std::ifstream in{std::string(path)};
    if(!in) throw std::runtime_error("cannot open file");
    ConfigMap m; std::string line; size_t lineno=0;
    while(std::getline(in,line)){
        ++lineno; if(is_blank_or_comment(line)) continue;
        auto pos = line.find('='); if(pos==std::string::npos) throw std::runtime_error("malformed line "+std::to_string(lineno));
        std::string k = std::string(line.substr(0,pos)); std::string v = std::string(line.substr(pos+1));
        trim(k); trim(v); if(k.empty()) throw std::runtime_error("empty key at line "+std::to_string(lineno));
        m.emplace(std::move(k), std::move(v));
    }
    return m;
}
std::optional<ConfigMap> parse_config_safe(std::string_view path){
    try { return parse_config_throwing(path); } catch(...) { return std::nullopt; }
}
