#include "main.h"

// a sample exported function
int DLL_EXPORT Check(queue_t myQueue){
    int sumHours = 0;
    int queueSize = queue_getSize(myQueue);
    for (int i = 0; i < queueSize; i++){
        sumHours += queue_dequeueSomeWork(myQueue);
    }
    if (sumHours < 40)
        return 1;
    else return 0;
}

void DLL_EXPORT Reaction(){
    printf("Warning!\n");
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
