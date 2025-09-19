#include "temp_file.hpp"
#include <cstdio>
#include <fstream>
#include <stdexcept>
#include <utility>
#include <vector>
#if defined(_WIN32)
  #include <io.h>
  #include <windows.h>
  #include <fcntl.h>
  #include <sys/stat.h>
#else
  #include <unistd.h> 
#endif
namespace {
std::string make_temp_path() {
#if defined(_WIN32)
    char buf[MAX_PATH];
    DWORD n = GetTempPathA(MAX_PATH, buf);
    std::string dir = (n ? std::string(buf, n) : std::string("."));
    char namebuf[L_tmpnam_s];
    if (tmpnam_s(namebuf, L_tmpnam_s) != 0) { throw std::runtime_error("tmpnam_s failed"); }
    return dir + "csi2372_" + std::string(namebuf + 1);
#else
    std::string path = "/tmp/csi2372_XXXXXX";
    std::vector<char> w(path.begin(), path.end()); w.push_back('\0');
    int fd = mkstemp(w.data());
    if (fd == -1) throw std::runtime_error("mkstemp failed");
    ::close(fd);
    return std::string(w.data());
#endif
}
}
TempFile::TempFile() : path_(make_temp_path()) {
    std::ofstream ofs(path_, std::ios::app);
    if (!ofs) throw std::runtime_error("Failed to create temp file");
}
TempFile::~TempFile() { if (!path_.empty()) std::remove(path_.c_str()); }
TempFile::TempFile(TempFile&& o) noexcept : path_(std::move(o.path_)) { o.path_.clear(); }
TempFile& TempFile::operator=(TempFile&& o) noexcept {
    if (this != &o) {
        if (!path_.empty()) std::remove(path_.c_str());
        path_ = std::move(o.path_);
        o.path_.clear();
    }
    return *this;
}
void TempFile::write_line(std::string_view sv) {
    std::ofstream ofs(path_, std::ios::app);
    if (!ofs) throw std::runtime_error("open for write failed");
    ofs << sv << '\n';
    if (!ofs) throw std::runtime_error("write failed");
}
std::string TempFile::read_all() const {
    std::ifstream ifs(path_);
    if (!ifs) throw std::runtime_error("open for read failed");
    std::string all, line;
    while (std::getline(ifs, line)) { all += line; all += '\n'; }
    return all;
}
