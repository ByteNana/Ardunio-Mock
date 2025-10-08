#include <cstdio>

#include "freertos/FreeRTOS.h"

int main() {
  std::printf("Semaphore example:\n");
  auto* bin = xSemaphoreCreateBinary();
  auto* mtx = xSemaphoreCreateMutex();

  if (!bin || !mtx) {
    std::printf("Failed to create semaphores\n");
    return 1;
  }

  std::printf("Binary take before give: %d\n", (int)xSemaphoreTake(bin, 0));
  xSemaphoreGive(bin);
  std::printf("Binary take after give: %d\n", (int)xSemaphoreTake(bin, 0));

  std::printf("Mutex first take: %d\n", (int)xSemaphoreTake(mtx, 0));
  std::printf("Mutex second take: %d\n", (int)xSemaphoreTake(mtx, 0));
  xSemaphoreGive(mtx);
  std::printf("Mutex take after give: %d\n", (int)xSemaphoreTake(mtx, 0));

  vSemaphoreDelete(bin);
  vSemaphoreDelete(mtx);
  return 0;
}
