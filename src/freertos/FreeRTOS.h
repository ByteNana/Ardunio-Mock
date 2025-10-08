#pragma once

#include "FreeRTOSConfig.h"
#include "projdefs.h"
#include "queue/queue.h"
#include "semaphore/semaphore.h"
#include "task/task.h"

inline BaseType_t xTaskCreatePinnedToCore(
    TaskFunction_t pxTaskCode, const char* const pcName, const portSTACK_TYPE usStackDepth,
    void* const pvParameters, UBaseType_t uxPriority, TaskHandle_t* const pxCreatedTask,
    BaseType_t coreID) {
  return xTaskCreate(pxTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask);
}
