Examples
========

Runnable programs that demonstrate the FreeRTOS subset and Arduino shims. No gtest/gmock used here.

Binaries
- `queue_example`: Creates a queue, sends/receives integers, prints states.
- `semaphore_example`: Exercises a binary semaphore and a mutex.
- `task_example`: Starts the scheduler, checks tick progress, runs a simple self-deleting task.

Build and run
- `make build` builds the library and examples.
- `make examples` enumerates and runs the built example executables.
- Or run them directly under `build/examples/`.

