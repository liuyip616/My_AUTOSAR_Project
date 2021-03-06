/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/



/*
 * context.h
 *
 *
 * PPAGE
 * PC
 * PC
 *
 */

#ifndef CONTEXT_H_
#define CONTEXT_H_

#define OS_KERNEL_CODE_PPAGE	0x38

#define SC_PATTERN				0xde
#define LC_PATTERN				0xad

#if defined(CFG_HCS12D)
#define Y_SP_OFFSET             6  // The offset from P to Y in the context
#if defined(__IAR_SYSTEMS_ICC__)
#define	CONTEXT_SIZE_W		  5  // The context size in words
#define HIGH_BYTE_RETURN_ADRESS 8 // The offset in the context that contains the high order byte of return address
#define LOW_BYTE_RETURN_ADRESS  9 // The offset in the context that contains the low order byte of return address
#else
#define	CONTEXT_SIZE_W		  9  // The context size in words
#define HIGH_BYTE_RETURN_ADRESS 16 // The offset in the context that contains the high order byte of return address
#define LOW_BYTE_RETURN_ADRESS  17 // The offset in the context that contains the low order byte of return address
#endif

#elif defined(CFG_HCS12XD)
#define Y_SP_OFFSET             7    // The offset from P to Y in the context
#if defined(__IAR_SYSTEMS_ICC__)
#define	CONTEXT_SIZE_W			6   // The context size in words ( Actual size 9+1/2)
#define HIGH_BYTE_RETURN_ADRESS 9   // The offset in the context that contains the high order byte of return address
#define LOW_BYTE_RETURN_ADRESS  10   // The offset in the context that contains the low order byte of return address
#else
#define	CONTEXT_SIZE_W			10   // The context size in words ( Actual size 9+1/2)
#define HIGH_BYTE_RETURN_ADRESS 17   // The offset in the context that contains the high order byte of return address
#define LOW_BYTE_RETURN_ADRESS  18   // The offset in the context that contains the low order byte of return address
#endif
#else
#error "HC1X: Subarchitecture not defined."
#endif

#endif /* CONTEXT_H_ */
