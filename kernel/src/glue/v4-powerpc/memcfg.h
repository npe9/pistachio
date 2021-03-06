/*********************************************************************
 *                
 * Copyright (C) 1999-2010,  Karlsruhe University
 * Copyright (C) 2008-2009,  Volkmar Uhlig, IBM Corporation
 *                
 * File path:     src/glue/v4-powerpc/memcfg.h
 * Description:   
 *                
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *                
 * $Id$
 *                
 ********************************************************************/

#ifndef __GLUE__V4_POWERPC__MEMCFG_H__
#define __GLUE__V4_POWERPC__MEMCFG_H__

#include INC_ARCH(phys.h)
#include INC_ARCH(page.h)

#if !defined(ASSEMBLY)

INLINE addr_t memcfg_kip_end()
{
    extern word_t _end_kip[];
    return (addr_t)_end_kip;
}

INLINE addr_t memcfg_stack_bottom()
{
    extern word_t _init_stack_bottom[];
    return (addr_t)_init_stack_bottom;
}

INLINE addr_t memcfg_stack_top()
{
    extern word_t _init_stack_top[];
    return (addr_t)_init_stack_top;
}

INLINE addr_t memcfg_syscall_start()
{
    extern word_t _start_syscall[];
    return addr_align( (addr_t)_start_syscall, POWERPC_PAGE_SIZE );
}

INLINE addr_t memcfg_syscall_end()
{
    extern word_t _end_syscall[];
    return addr_align_up( (addr_t)_end_syscall, POWERPC_PAGE_SIZE );
}

INLINE addr_t memcfg_start_kernel()
{
    extern word_t _start_kernel[];
    return addr_align( (addr_t)_start_kernel, POWERPC_PAGE_SIZE );
}

INLINE addr_t memcfg_end_kernel()
{
    extern word_t _end[];
    return addr_align_up( (addr_t)_end, POWERPC_PAGE_SIZE );
}

INLINE addr_t memcfg_end_kernel_phys()
{
    extern word_t _end_kernel_phys[];
    return addr_align_up( (addr_t)_end_kernel_phys, POWERPC_PAGE_SIZE );
}

INLINE addr_t memcfg_start_code()
{
    return memcfg_start_kernel();
}

INLINE addr_t memcfg_end_code()
{
    extern word_t _etext[];
    return addr_align_up( (addr_t)_etext, POWERPC_PAGE_SIZE );
}

INLINE addr_t memcfg_start_data()
{
    extern word_t _start_data[];
    return addr_align( (addr_t)_start_data, POWERPC_PAGE_SIZE );
}

INLINE addr_t memcfg_end_data()
{
    return memcfg_end_kernel();
}

INLINE addr_t memcfg_end_data_phys()
{
    extern word_t _end_data_phys[];
    return addr_align_up( (addr_t)_end_data_phys, POWERPC_PAGE_SIZE );
}

INLINE addr_t memcfg_start_except()
{
    extern word_t _start_except[];
    return (addr_t)_start_except;	// not page aligned!
}

INLINE addr_t memcfg_end_except()
{
    extern word_t _end_except[];
    return (addr_t)_end_except;		// not necessarily page aligned
}

INLINE addr_t memcfg_start_cpu_phys()
{
    extern word_t _cpu_phys[];
    return (addr_t)_cpu_phys;
}

INLINE addr_t memcfg_end_cpu_phys()
{
    return memcfg_end_kernel_phys();
}

#endif

#endif /* !__GLUE__V4_POWERPC__MEMCFG_H__ */
