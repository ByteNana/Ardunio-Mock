#include <gtest/gtest.h>

#include "freertos/FreeRTOS.h"

TEST(QueueTest, BasicSendReceive) {
  QueueHandle_t q = xQueueCreate(2, sizeof(uint32_t));
  ASSERT_NE(q, nullptr);

  uint32_t v1 = 0xAABBCCDD;
  uint32_t v2 = 0x01020304;
  uint32_t v3 = 0x12345678;

  EXPECT_EQ(xQueueSend(q, &v1, 0), pdTRUE);
  EXPECT_EQ(xQueueSend(q, &v2, 0), pdTRUE);
  EXPECT_EQ(xQueueSend(q, &v3, 0), pdFALSE);
  EXPECT_EQ(uxQueueMessagesWaiting(q), 2u);

  uint32_t r1 = 0, r2 = 0;
  EXPECT_EQ(xQueueReceive(q, &r1, 0), pdTRUE);
  EXPECT_EQ(xQueueReceive(q, &r2, 0), pdTRUE);
  EXPECT_EQ(r1, v1);
  EXPECT_EQ(r2, v2);

  EXPECT_EQ(uxQueueMessagesWaiting(q), 0u);

  vQueueDelete(q);
}
