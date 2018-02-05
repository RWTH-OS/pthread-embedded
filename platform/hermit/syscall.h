/*
 * Copyright (c) 2011, Stefan Lankes, RWTH Aachen University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the University nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


/*
 * Standalone version of include/hermit/syscall.h that only contains definitions
 * needed for pthread-embedded.
 */


#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#ifndef NORETURN
#define NORETURN	__attribute__((noreturn))
#endif

typedef unsigned int tid_t;


/* Opaque structures */
struct _HermitRecursiveMutex;
typedef struct _HermitRecursiveMutex HermitRecursiveMutex;

struct _HermitSemaphore;
typedef struct _HermitSemaphore HermitSemaphore;


/*
 * HermitCore is a libOS.
 * => classical system calls are realized as normal function
 * => forward declaration of system calls as function
 */
tid_t sys_getpid(void);
int sys_getprio(tid_t* id);
int sys_setprio(tid_t* id, int prio);
void NORETURN sys_exit(int arg);
void sys_msleep(unsigned int ms);
int sys_recmutex_init(HermitRecursiveMutex** recmutex);
int sys_recmutex_destroy(HermitRecursiveMutex* recmutex);
int sys_recmutex_lock(HermitRecursiveMutex* recmutex);
int sys_recmutex_unlock(HermitRecursiveMutex* recmutex);
int sys_sem_init(HermitSemaphore** sem, unsigned int value);
int sys_sem_destroy(HermitSemaphore* sem);
int sys_sem_wait(HermitSemaphore* sem);
int sys_sem_post(HermitSemaphore* sem);
int sys_sem_trywait(HermitSemaphore* sem);
int sys_sem_timedwait(HermitSemaphore *sem, unsigned int ms);
int sys_sem_cancelablewait(HermitSemaphore* sem, unsigned int ms);
int sys_clone(tid_t* id, void* ep, void* argv);
size_t sys_get_ticks(void);
void sys_yield(void);

#endif
