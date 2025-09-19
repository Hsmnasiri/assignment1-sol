#include "string_table.hpp"
#include <algorithm>
StringTable::StringTable() = default;
StringTable::~StringTable() = default;
StringTable::StringTable(const StringTable& o) : data_(o.data_) {}
StringTable& StringTable::operator=(const StringTable& o){ if (this!=&o) data_=o.data_; return *this; }
StringTable::StringTable(StringTable&& o) noexcept : data_(std::move(o.data_)) {}
StringTable& StringTable::operator=(StringTable&& o) noexcept { if (this!=&o) data_=std::move(o.data_); return *this; }
void StringTable::add(std::string s){ if(!contains(s)) data_.push_back(std::move(s)); }
bool StringTable::erase(std::string_view key){
    auto it = std::remove_if(data_.begin(), data_.end(), [&](const std::string& s){return s==key;});
    bool removed = it!=data_.end(); data_.erase(it, data_.end()); return removed;
}
bool StringTable::contains(std::string_view key) const { return std::find(data_.begin(), data_.end(), key)!=data_.end(); }
std::size_t StringTable::size() const noexcept { return data_.size(); }
StringTable merge(StringTable a, StringTable b){ for(auto& s: b.data_) a.add(std::move(s)); return a; }
