#include <cstdint>
#include <cstdio>

#include "freertos/FreeRTOS.h"

int main() {
  std::printf("Queue example:\n");
  QueueHandle_t q = xQueueCreate(2, sizeof(uint32_t));
  if (!q) {
    std::printf("Failed to create queue\n");
    return 1;
  }

  uint32_t a = 42, b = 7;
  xQueueSend(q, &a, 0);
  xQueueSend(q, &b, 0);
  std::printf("Messages waiting: %u\n", (unsigned)uxQueueMessagesWaiting(q));

  uint32_t r = 0;
  xQueueReceive(q, &r, 0);
  std::printf("Received: %u\n", (unsigned)r);

  vQueueDelete(q);
  return 0;
}
