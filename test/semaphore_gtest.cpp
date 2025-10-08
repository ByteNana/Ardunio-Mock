#include <gtest/gtest.h>

#include "freertos/FreeRTOS.h"

TEST(SemaphoreTest, BinaryAndMutex) {
  SemaphoreHandle_t bin = xSemaphoreCreateBinary();
  ASSERT_NE(bin, nullptr);
  EXPECT_EQ(xSemaphoreTake(bin, 0), pdFALSE);
  EXPECT_EQ(xSemaphoreGive(bin), pdTRUE);
  EXPECT_EQ(xSemaphoreTake(bin, 0), pdTRUE);
  vSemaphoreDelete(bin);

  SemaphoreHandle_t mtx = xSemaphoreCreateMutex();
  ASSERT_NE(mtx, nullptr);
  EXPECT_EQ(xSemaphoreTake(mtx, 0), pdTRUE);
  EXPECT_EQ(xSemaphoreTake(mtx, 0), pdFALSE);
  EXPECT_EQ(xSemaphoreGive(mtx), pdTRUE);
  EXPECT_EQ(xSemaphoreTake(mtx, 0), pdTRUE);
  vSemaphoreDelete(mtx);
}
