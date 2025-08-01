#include <stdio.h>

#include "XCEPTEST_test.h"
#include "XCEP.h"

void ignore_handler(const XCEP_t_Exception* inException) {
    printf("Ignoring exception: %d\n", inException->code);
}

int main() {
    const int result = XCEPTEST_RunTest();

#if XCEP_CONF_ENABLE_THREAD_SAFE
    SetThreadUncaughtExceptionHandler(ignore_handler);
    SetThreadUncaughtExceptionHandler(NULL);
#endif

    const t_Exception exception = NewException(100, "Test Error 100 have been triggered");
    PrintException("Test Exception print", &exception);

    return result;
}