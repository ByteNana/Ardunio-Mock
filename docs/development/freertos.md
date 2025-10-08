FreeRTOS Subset (Native Mocks)
==============================

A minimal, host-native model of key FreeRTOS concepts implemented with `std::thread` and `std::condition_variable`.

Core Headers
- `freertos/FreeRTOS.h`: umbrella include; adds `xTaskCreatePinnedToCore` shim.
- `freertos/FreeRTOSConfig.h`: minimal config for host builds.
- `freertos/projdefs.h`: typedefs (`BaseType_t`, `UBaseType_t`, `TickType_t`) and macros (`pdTRUE`, `pdFALSE`, `pdMS_TO_TICKS`).

Queue
- Header/impl: `freertos/queue/queue.h`, `src/freertos/queue/queue.cpp`.
- API: `xQueueCreate`, `vQueueDelete`, `xQueueSend`, `xQueueReceive`, `uxQueueMessagesWaiting`.
- Behavior: fixed-size items, bounded capacity; blocking waits respect `xTicksToWait` using timed waits.

Semaphore
- Header/impl: `freertos/semaphore/semaphore.h`, `src/freertos/semaphore/semaphore.cpp`.
- Binary: starts unavailable; `xSemaphoreGive/Take` toggles availability.
- Mutex: starts available; `Take` waits if already taken.

Task
- Header/impl: `freertos/task/task.h`, `src/freertos/task/task.cpp`.
- `xTaskCreate`: launches a host thread to run `TaskFunction_t`.
- `vTaskDelete(nullptr)`: self-termination via internal exception to unwind thread.
- `vTaskDelay`: sleeps with cancellation support.
- Scheduler: `vTaskStartScheduler` sets a tick base; `xTaskGetTickCount` returns ms since start; `vTaskEndScheduler` stops it.

Hooks
- `src/freertos/freertos_hooks.c` provides no-op or diagnostic implementations of common hooks.

Limitations
- Timing and scheduling are best-effort and wall-clock based, not hard real-time.
- API surface is intentionally small; extend as your use cases require.

