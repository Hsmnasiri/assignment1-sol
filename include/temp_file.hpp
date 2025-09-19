#pragma once
#include <string>
#include <string_view>
class TempFile {
public:
    TempFile();
    ~TempFile();
    TempFile(const TempFile&) = delete;
    TempFile& operator=(const TempFile&) = delete;
    TempFile(TempFile&&) noexcept;
    TempFile& operator=(TempFile&&) noexcept;
    void write_line(std::string_view sv);
    std::string read_all() const;
    const std::string& path() const { return path_; }
private:
    std::string path_;
};
