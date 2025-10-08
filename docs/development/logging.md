Logging (`esp_log.h`)
====================

Purpose
- Provide familiar logging macros with colorized, thread-safe console output for host builds.

Macros
- `log_e`, `log_w`, `log_i`, `log_d`, `log_v`, and `log_n`.
- Each macro prints: level prefix, `file:line`, formatted message, and resets color.

Configuration
- `LOG_LEVEL` controls verbosity (default: `LOG_LEVEL_INFO`).
  - Set via CMake: `-DLOG_LEVEL=4`, or `make build LOG_LEVEL=4`.

Behavior
- Uses an internal mutex to serialize output across threads.
- Formatting done via `vsnprintf` into a bounded buffer.

