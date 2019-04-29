/*
WINBASEAPI
__out_opt
HANDLE
WINAPI
CreateMutexA(
    __in_opt LPSECURITY_ATTRIBUTES lpMutexAttributes,
    __in     BOOL bInitialOwner,
    __in_opt LPCSTR lpName
    );
*/
HANDLE mutex = CreateMutex(NULL,FALSE,NULL);
WaitForSingleObject(mutex, INFINITE);
ReleaseMutex(mutex);
/*
WINBASEAPI
__out_opt
HANDLE
WINAPI
CreateEventA(
    __in_opt LPSECURITY_ATTRIBUTES lpEventAttributes,
    __in     BOOL bManualReset,
    __in     BOOL bInitialState,
    __in_opt LPCSTR lpName
    );
*/
HANDLE event = CreateEvent(NULL,false,false,"");// auto, non-signaled
WaitForSingleObject(event, INFINITE);//wait event until signaled
ResetEvent(event);//set the specified event to non-signaled state
SetEvent(event);//set the specified event to signaled state

CRITICAL_SECTION mutex;
InitializeCriticalSection(&mutex);
EnterCriticalSection(&mutex);
LeaveCriticalSection(&mutex);
TryEnterCriticalSection(&mutex);
DeleteCriticalSection(&mutex);

/*
WINBASEAPI
__out_opt
HANDLE
WINAPI
CreateSemaphoreW(
    __in_opt LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    __in     LONG lInitialCount,
    __in     LONG lMaximumCount,
    __in_opt LPCWSTR lpName
    );
*/
HANDLE semaphore = CreateSemaphore(NULL,0,LONG_MAX,NULL);
WaitForSingleObject(semaphore, INFINITE);
ReleaseSemaphore(semaphore,1,NULL);
