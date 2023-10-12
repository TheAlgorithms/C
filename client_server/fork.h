/*
 * Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 * Copyright (C) DIGITEO - 2010 - Allan CORNET
 *
 * Copyright (C) 2012 - 2016 - Scilab Enterprises
 *
 * This file is hereby licensed under the terms of the GNU GPL v2.0,
 * pursuant to article 5.3.4 of the CeCILL v.2.1.
 * This file was originally licensed under the terms of the CeCILL v2.1,
 * and continues to be available under such terms.
 * For more information, see the COPYING file which you should have received
 * along with this program.
 *
 */
/*--------------------------------------------------------------------------*/
#ifndef __FORK_H__
#define __FORK_H__

/* http://technet.microsoft.com/en-us/library/bb497007.aspx */
/* http://undocumented.ntinternals.net/ */

#include <setjmp.h>
#include <windows.h>

#include "bool.h"

/**
 * simulate fork on Windows
 */
int fork(void);

/**
 * check if symbols to simulate fork are present
 * and load these symbols
 */
BOOL haveLoadedFunctionsForFork(void);

/*--------------------------------------------------------------------------*/
typedef LONG NTSTATUS;
/*--------------------------------------------------------------------------*/
typedef struct _SYSTEM_HANDLE_INFORMATION
{
    ULONG ProcessId;
    UCHAR ObjectTypeNumber;
    UCHAR Flags;
    USHORT Handle;
    PVOID Object;
    ACCESS_MASK GrantedAccess;
} SYSTEM_HANDLE_INFORMATION, *PSYSTEM_HANDLE_INFORMATION;
/*--------------------------------------------------------------------------*/
typedef struct _OBJECT_ATTRIBUTES
{
    ULONG Length;
    HANDLE RootDirectory;
    PVOID /* really PUNICODE_STRING */ ObjectName;
    ULONG Attributes;
    PVOID SecurityDescriptor;       /* type SECURITY_DESCRIPTOR */
    PVOID SecurityQualityOfService; /* type SECURITY_QUALITY_OF_SERVICE */
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;
/*--------------------------------------------------------------------------*/
typedef enum _MEMORY_INFORMATION_
{
    MemoryBasicInformation,
    MemoryWorkingSetList,
    MemorySectionName,
    MemoryBasicVlmInformation
} MEMORY_INFORMATION_CLASS;
/*--------------------------------------------------------------------------*/
typedef struct _CLIENT_ID
{
    HANDLE UniqueProcess;
    HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;
/*--------------------------------------------------------------------------*/
typedef struct _USER_STACK
{
    PVOID FixedStackBase;
    PVOID FixedStackLimit;
    PVOID ExpandableStackBase;
    PVOID ExpandableStackLimit;
    PVOID ExpandableStackBottom;
} USER_STACK, *PUSER_STACK;
/*--------------------------------------------------------------------------*/
typedef LONG KPRIORITY;
typedef ULONG_PTR KAFFINITY;
typedef KAFFINITY *PKAFFINITY;
/*--------------------------------------------------------------------------*/
typedef struct _THREAD_BASIC_INFORMATION
{
    NTSTATUS ExitStatus;
    PVOID TebBaseAddress;
    CLIENT_ID ClientId;
    KAFFINITY AffinityMask;
    KPRIORITY Priority;
    KPRIORITY BasePriority;
} THREAD_BASIC_INFORMATION, *PTHREAD_BASIC_INFORMATION;
/*--------------------------------------------------------------------------*/
typedef enum _SYSTEM_INFORMATION_CLASS
{
    SystemHandleInformation = 0x10
} SYSTEM_INFORMATION_CLASS;
/*--------------------------------------------------------------------------*/
typedef NTSTATUS(NTAPI *ZwWriteVirtualMemory_t)(
    IN HANDLE ProcessHandle, IN PVOID BaseAddress, IN PVOID Buffer,
    IN ULONG NumberOfBytesToWrite, OUT PULONG NumberOfBytesWritten OPTIONAL);
/*--------------------------------------------------------------------------*/
typedef NTSTATUS(NTAPI *ZwCreateProcess_t)(
    OUT PHANDLE ProcessHandle, IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes, IN HANDLE InheriteFromProcessHandle,
    IN BOOLEAN InheritHandles, IN HANDLE SectionHandle OPTIONAL,
    IN HANDLE DebugPort OPTIONAL, IN HANDLE ExceptionPort OPTIONAL);
/*--------------------------------------------------------------------------*/
typedef NTSTATUS(WINAPI *ZwQuerySystemInformation_t)(
    SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation,
    ULONG SystemInformationLength, PULONG ReturnLength);
typedef NTSTATUS(NTAPI *ZwQueryVirtualMemory_t)(
    IN HANDLE ProcessHandle, IN PVOID BaseAddress,
    IN MEMORY_INFORMATION_CLASS MemoryInformationClass,
    OUT PVOID MemoryInformation, IN ULONG MemoryInformationLength,
    OUT PULONG ReturnLength OPTIONAL);
/*--------------------------------------------------------------------------*/
typedef NTSTATUS(NTAPI *ZwGetContextThread_t)(IN HANDLE ThreadHandle,
                                              OUT PCONTEXT Context);
typedef NTSTATUS(NTAPI *ZwCreateThread_t)(
    OUT PHANDLE ThreadHandle, IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes, IN HANDLE ProcessHandle,
    OUT PCLIENT_ID ClientId, IN PCONTEXT ThreadContext,
    IN PUSER_STACK UserStack, IN BOOLEAN CreateSuspended);
/*--------------------------------------------------------------------------*/
typedef NTSTATUS(NTAPI *ZwResumeThread_t)(IN HANDLE ThreadHandle,
                                          OUT PULONG SuspendCount OPTIONAL);
typedef NTSTATUS(NTAPI *ZwClose_t)(IN HANDLE ObjectHandle);
typedef NTSTATUS(NTAPI *ZwQueryInformationThread_t)(
    IN HANDLE ThreadHandle, IN THREAD_INFORMATION_CLASS ThreadInformationClass,
    OUT PVOID ThreadInformation, IN ULONG ThreadInformationLength,
    OUT PULONG ReturnLength OPTIONAL);
/*--------------------------------------------------------------------------*/
static ZwCreateProcess_t ZwCreateProcess = NULL;
static ZwQuerySystemInformation_t ZwQuerySystemInformation = NULL;
static ZwQueryVirtualMemory_t ZwQueryVirtualMemory = NULL;
static ZwCreateThread_t ZwCreateThread = NULL;
static ZwGetContextThread_t ZwGetContextThread = NULL;
static ZwResumeThread_t ZwResumeThread = NULL;
static ZwClose_t ZwClose = NULL;
static ZwQueryInformationThread_t ZwQueryInformationThread = NULL;
static ZwWriteVirtualMemory_t ZwWriteVirtualMemory = NULL;
/*--------------------------------------------------------------------------*/
#define NtCurrentProcess() ((HANDLE)-1)
#define NtCurrentThread() ((HANDLE)-2)
/* we use really the Nt versions - so the following is just for completeness */
#define ZwCurrentProcess() NtCurrentProcess()
#define ZwCurrentThread() NtCurrentThread()
#define STATUS_INFO_LENGTH_MISMATCH ((NTSTATUS)0xC0000004L)
#define STATUS_SUCCESS ((NTSTATUS)0x00000000L)
/*--------------------------------------------------------------------------*/
/* setjmp env for the jump back into the fork() function */
static jmp_buf jenv;
/*--------------------------------------------------------------------------*/
/* entry point for our child thread process - just longjmp into fork */
static int child_entry(void)
{
    longjmp(jenv, 1);
    return 0;
}
/*--------------------------------------------------------------------------*/
static BOOL haveLoadedFunctionsForFork(void)
{
    HMODULE ntdll = GetModuleHandle("ntdll");
    if (ntdll == NULL)
    {
        return FALSE;
    }

    if (ZwCreateProcess && ZwQuerySystemInformation && ZwQueryVirtualMemory &&
        ZwCreateThread && ZwGetContextThread && ZwResumeThread &&
        ZwQueryInformationThread && ZwWriteVirtualMemory && ZwClose)
    {
        return TRUE;
    }

    ZwCreateProcess =
        (ZwCreateProcess_t)GetProcAddress(ntdll, "ZwCreateProcess");
    ZwQuerySystemInformation = (ZwQuerySystemInformation_t)GetProcAddress(
        ntdll, "ZwQuerySystemInformation");
    ZwQueryVirtualMemory =
        (ZwQueryVirtualMemory_t)GetProcAddress(ntdll, "ZwQueryVirtualMemory");
    ZwCreateThread = (ZwCreateThread_t)GetProcAddress(ntdll, "ZwCreateThread");
    ZwGetContextThread =
        (ZwGetContextThread_t)GetProcAddress(ntdll, "ZwGetContextThread");
    ZwResumeThread = (ZwResumeThread_t)GetProcAddress(ntdll, "ZwResumeThread");
    ZwQueryInformationThread = (ZwQueryInformationThread_t)GetProcAddress(
        ntdll, "ZwQueryInformationThread");
    ZwWriteVirtualMemory =
        (ZwWriteVirtualMemory_t)GetProcAddress(ntdll, "ZwWriteVirtualMemory");
    ZwClose = (ZwClose_t)GetProcAddress(ntdll, "ZwClose");

    if (ZwCreateProcess && ZwQuerySystemInformation && ZwQueryVirtualMemory &&
        ZwCreateThread && ZwGetContextThread && ZwResumeThread &&
        ZwQueryInformationThread && ZwWriteVirtualMemory && ZwClose)
    {
        return TRUE;
    }
    else
    {
        ZwCreateProcess = NULL;
        ZwQuerySystemInformation = NULL;
        ZwQueryVirtualMemory = NULL;
        ZwCreateThread = NULL;
        ZwGetContextThread = NULL;
        ZwResumeThread = NULL;
        ZwQueryInformationThread = NULL;
        ZwWriteVirtualMemory = NULL;
        ZwClose = NULL;
    }
    return FALSE;
}
/*--------------------------------------------------------------------------*/
int fork(void)
{
    HANDLE hProcess = 0, hThread = 0;
    OBJECT_ATTRIBUTES oa = {sizeof(oa)};
    MEMORY_BASIC_INFORMATION mbi;
    CLIENT_ID cid;
    USER_STACK stack;
    PNT_TIB tib;
    THREAD_BASIC_INFORMATION tbi;

    CONTEXT context = {CONTEXT_FULL | CONTEXT_DEBUG_REGISTERS |
                       CONTEXT_FLOATING_POINT};

    if (setjmp(jenv) != 0)
    {
        return 0; /* return as a child */
    }

    /* check whether the entry points are initilized and get them if necessary
     */
    if (!ZwCreateProcess && !haveLoadedFunctionsForFork())
    {
        return -1;
    }

    /* create forked process */
    ZwCreateProcess(&hProcess, PROCESS_ALL_ACCESS, &oa, NtCurrentProcess(),
                    TRUE, 0, 0, 0);

    /* set the Eip for the child process to our child function */
    ZwGetContextThread(NtCurrentThread(), &context);

    /* In x64 the Eip and Esp are not present, their x64 counterparts are Rip
    and Rsp respectively.
    */
#if _WIN64
    context.Rip = (ULONG)child_entry;
#else
    context.Eip = (ULONG)child_entry;
#endif

#if _WIN64
    ZwQueryVirtualMemory(NtCurrentProcess(), (PVOID)context.Rsp,
                         MemoryBasicInformation, &mbi, sizeof mbi, 0);
#else
    ZwQueryVirtualMemory(NtCurrentProcess(), (PVOID)context.Esp,
                         MemoryBasicInformation, &mbi, sizeof mbi, 0);
#endif

    stack.FixedStackBase = 0;
    stack.FixedStackLimit = 0;
    stack.ExpandableStackBase = (PCHAR)mbi.BaseAddress + mbi.RegionSize;
    stack.ExpandableStackLimit = mbi.BaseAddress;
    stack.ExpandableStackBottom = mbi.AllocationBase;

    /* create thread using the modified context and stack */
    ZwCreateThread(&hThread, THREAD_ALL_ACCESS, &oa, hProcess, &cid, &context,
                   &stack, TRUE);

    /* copy exception table */
    ZwQueryInformationThread(NtCurrentThread(), ThreadMemoryPriority, &tbi,
                             sizeof tbi, 0);
    tib = (PNT_TIB)tbi.TebBaseAddress;
    ZwQueryInformationThread(hThread, ThreadMemoryPriority, &tbi, sizeof tbi,
                             0);
    ZwWriteVirtualMemory(hProcess, tbi.TebBaseAddress, &tib->ExceptionList,
                         sizeof tib->ExceptionList, 0);

    /* start (resume really) the child */
    ZwResumeThread(hThread, 0);

    /* clean up */
    ZwClose(hThread);
    ZwClose(hProcess);

    /* exit with child's pid */
    return (int)cid.UniqueProcess;
}

#endif /* __FORK_H__ */
/*--------------------------------------------------------------------------*/
