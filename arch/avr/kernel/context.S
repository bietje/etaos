/*
 *  Eta/OS - AVR5 context
 *  Copyright (C) 2014   Michel Megens <dev@bietje.net>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <asm/config.h>
#include <asm/io.h>

.section .text
/*
 * avr_switch_context(current, next->sp)
 * 
 * next->sp     => r24:r25
 * current      => r22:r23
 */
.func avr_switch_context
.global avr_switch_context
.extern avr_save_stack
avr_switch_context:
	cli
	push r0
	in r0, AVR_STATUS_ADDR
	push r0
	push r1
	push r2
	push r3
	push r4
	push r5
	push r6
	push r7
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
	push r16
	push r17
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r28
	push r29
	push r30
	push r31

	push r24
	push r25

	in r24, AVR_STACK_LOW_ADDR
	in r25, AVR_STACK_HI_ADDR
	XCALL avr_save_stack 
		/* avr_save_stack(stack_t sp, struct thread *curr) */

	pop r25
	pop r24

	out AVR_STACK_HI_ADDR, r25
	out AVR_STACK_LOW_ADDR, r24

	pop r31
	pop r30
	pop r29
	pop r28
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r17
	pop r16
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop r7
	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0

	out AVR_STATUS_ADDR, r0
	pop r0
	ret

.endfunc
