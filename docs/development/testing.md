Testing (GoogleTest/GoogleMock)
===============================

Layout
- Sources to test live in `src/`. Tests live in `test/`.
- We keep `src/Stream.h` free of gmock; test-only `MockStream.h` lives in `src/` for convenience.

Building tests
- Enable tests at configure time (FetchContent will download GoogleTest on first run):
  - `cmake -DENABLE_GTEST_TESTS=ON -B build && cmake --build build`
  - Or simply `make test` (runs configure + build + ctest).

Running tests
- `ctest --test-dir build -V` or `make test`.

Writing tests
- Include the mocks and headers normally:
  - `#include "MockStream.h"`
  - `#include "freertos/FreeRTOS.h"`
- Link against `ArduinoNativeMocks` and GoogleTest/GoogleMock. The repo’s `test/CMakeLists.txt` handles this wiring for the built-in tests.

CI
- GitHub Actions builds and runs tests in `.github/workflows/ci.yml`.

