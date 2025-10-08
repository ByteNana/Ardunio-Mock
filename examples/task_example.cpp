#include <cstdio>

#include "freertos/FreeRTOS.h"

static void work(void*) {
  for (int i = 0; i < 3; ++i) { vTaskDelay(pdMS_TO_TICKS(10)); }
  vTaskDelete(nullptr);
}

int main() {
  std::printf("Task example:\n");
  vTaskStartScheduler();
  TickType_t t0 = xTaskGetTickCount();
  vTaskDelay(pdMS_TO_TICKS(5));
  std::printf("Tick advanced: %u -> %u\n", (unsigned)t0, (unsigned)xTaskGetTickCount());

  TaskHandle_t h = nullptr;
  if (xTaskCreate(work, "work", 2048, nullptr, tskIDLE_PRIORITY + 1, &h) != pdPASS) {
    std::printf("Failed to create task\n");
    return 1;
  }

  vTaskDelay(pdMS_TO_TICKS(50));
  vTaskEndScheduler();
  return 0;
}
