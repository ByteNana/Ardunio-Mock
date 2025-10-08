Build, Config, and Editor Integration
====================================

Build
- Make-based workflow (wraps CMake):
  - Configure + build: `make build`
  - Clean: `make clean`
  - Run examples: `make examples`
  - Run tests: `make test` (enables GoogleTest via FetchContent)
- Direct CMake:
  - `cmake -B build`
  - `cmake --build build`
  - `ctest --test-dir build -V`

Configuration
- Log level for `esp_log.h`: `LOG_LEVEL` (0..5).
  - With make: `make build LOG_LEVEL=4`
  - With CMake: `cmake -DLOG_LEVEL=4 -B build`

Editor (clangd)
- Preferred: `make setup` generates `build/compile_commands.json` and copies it to repo root.
- Fallback: `.clangd` provides default flags (`-Isrc` and `-std=c++11`) for headers or files not in the compile DB.

Notes
- The library builds as a single static target `ArduinoNativeMocks` and exposes `src/` as the PUBLIC include dir.
- Threading is provided by CMake’s `Threads::Threads` (POSIX threads or platform-specific equivalent).

