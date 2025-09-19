#include "string_table.hpp"
#include <stdexcept>
// TODO Part C (copy/move semantics): deep copy & efficient move; add/erase/contains/size; merge
StringTable::StringTable() = default;
StringTable::~StringTable() = default;
StringTable::StringTable(const StringTable&){ throw std::runtime_error("Not implemented"); }
StringTable& StringTable::operator=(const StringTable&){ throw std::runtime_error("Not implemented"); }
StringTable::StringTable(StringTable&&) noexcept = default;
StringTable& StringTable::operator=(StringTable&&) noexcept = default;
void StringTable::add(std::string){ throw std::runtime_error("Not implemented"); }
bool StringTable::erase(std::string_view){ throw std::runtime_error("Not implemented"); }
bool StringTable::contains(std::string_view) const { throw std::runtime_error("Not implemented"); }
std::size_t StringTable::size() const noexcept { return 0; }
StringTable merge(StringTable, StringTable){ throw std::runtime_error("Not implemented"); }
