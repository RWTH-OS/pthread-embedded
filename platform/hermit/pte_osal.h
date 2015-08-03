#ifndef _OS_SUPPORT_H_
#define _OS_SUPPORT_H_

#include <stdint.h>

typedef int pte_osThreadHandle;

typedef int pte_osSemaphoreHandle;

typedef int pte_osMutexHandle;

// Platform specific one must be included first
//#include "psp_osal.h"

#include "pte_generic_osal.h"



#endif // _OS_SUPPORT_H
