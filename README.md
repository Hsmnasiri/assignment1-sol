# CSI 2372 — Assignment 1 (Weeks 1–3)

**Autograded on GitHub Classroom** using GitHub Actions + CTest.

## Points (total 10.0)
- Build hygiene — **1.0** (visible)
- Part A: ScopeProbe — **2.5** (visible)
- Part B: RAII — **2.5** (hidden)
- Part C: Copy/Move — **3.0** (hidden)
- Part D: Error handling — **2.5** (hidden)
- Reflection (1.0) is graded in the LMS.

> Hidden tests are in a private instructor repo and are fetched during CI.

## Build & Test locally
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
ctest --test-dir build -V
```

## Implement
- Part A: implement `ScopeProbe` ctor/dtor (see src/scope_probe.cpp)
- Part B: implement `TempFile` RAII (src/temp_file.cpp)
- Part C: implement `StringTable` semantics (src/string_table.cpp)
- Part D: implement config parsing (src/config.cpp)
