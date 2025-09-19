#include "temp_file.hpp"
#include <stdexcept>
// TODO Part B (RAII TempFile): create unique file; delete in dtor; implement moves; write/read; exception safety
TempFile::TempFile(){ throw std::runtime_error("Not implemented"); }
TempFile::~TempFile(){ /* TODO */ }
TempFile::TempFile(TempFile&&) noexcept = default;
TempFile& TempFile::operator=(TempFile&&) noexcept = default;
void TempFile::write_line(std::string_view){ throw std::runtime_error("Not implemented"); }
std::string TempFile::read_all() const { throw std::runtime_error("Not implemented"); }
