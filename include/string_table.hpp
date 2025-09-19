#pragma once
#include <string>
#include <string_view>
#include <vector>
class StringTable {
public:
    StringTable();
    ~StringTable();
    StringTable(const StringTable&);
    StringTable& operator=(const StringTable&);
    StringTable(StringTable&&) noexcept;
    StringTable& operator=(StringTable&&) noexcept;
    void add(std::string s);
    bool erase(std::string_view key);
    bool contains(std::string_view key) const;
    std::size_t size() const noexcept;
    friend StringTable merge(StringTable a, StringTable b);
private:
    std::vector<std::string> data_;
};
