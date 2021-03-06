/*
 *  ETA/OS - AVR IRQ support
 *  Copyright (C) 2014, 2015   Michel Megens
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

#define AVR_IRQ_CORE 1

#include <etaos/kernel.h>
#include <etaos/types.h>
#include <etaos/irq.h>
#include <etaos/bitops.h>
#include <etaos/list.h>

#include <asm/io.h>
#include <asm/irq.h>

void arch_irq_disable(void)
{
	cli();
}

void arch_irq_enable(void)
{
	sei();
}

void arch_local_irq_enable(void)
{
	arch_irq_enable();
}

void arch_local_irq_disable(void)
{
	arch_irq_disable();
}

unsigned long arch_irq_get_flags(void)
{
	return ((unsigned long) (SREG & AVR_IRQ_BITS));
}

void arch_irq_restore_flags(unsigned long *flags)
{
	if(test_bit(AVR_IRQ_FLAG, flags))
		sei();
	return;
}

void raw_irq_enabled_flags(unsigned long *flags)
{
	unsigned char status;

	__asm__ __volatile__(
			"in %0, %1"	"\n\t"
			: "=&r" (status)
			: "M" (AVR_STATUS_ADDR)
			: "memory"
			);
	*flags = (status & (1UL << AVR_INTERRUPT_FLAG)) != 0;
}

void cpu_request_irq(struct irq_data *data)
{
	switch(data->irq) {
	default:
		break;
	}
}

#ifdef CONFIG_IRQ_DEBUG
extern unsigned long test_sys_tick;
unsigned long test_sys_tick = 0;
#endif

extern void preempt_schedule(void);
SIGNAL(TIMER0_OVERFLOW_VECTOR)
{
	struct irq_chip *chip = arch_get_irq_chip();

#ifdef CONFIG_IRQ_DEBUG
	test_sys_tick++;

	if((test_sys_tick % 5000) == 0)
		chip->chip_handle(EXT_IRQ0_NUM);
#endif

	chip->chip_handle(TIMER0_OVERFLOW_VECTOR_NUM);

#ifdef CONFIG_PREEMPT
	__asm__ __volatile__(
			"sei"	"\n\t"
			:
			:
			: "memory"
			);
	preempt_schedule();
	__asm__ __volatile__(
			"cli"	"\n\t"
			:
			:
			: "memory"
			);
#endif
}

SIGNAL(SPI_STC_VECTOR)
{
	struct irq_chip *chip = arch_get_irq_chip();
	chip->chip_handle(SPI_STC_VECTOR_NUM);
}

SIGNAL(TWI_STC_VECTOR)
{
	struct irq_chip *chip = arch_get_irq_chip();
	chip->chip_handle(TWI_STC_VECTOR_NUM);
}

SIGNAL(USART_RX_STC_VECTOR)
{
	struct irq_chip *chip = arch_get_irq_chip();
	chip->chip_handle(USART_RX_STC_NUM);
}

SIGNAL(ADC_COMPLETED_VECTOR)
{
	struct irq_chip *chip = arch_get_irq_chip();
	chip->chip_handle(ADC_COMPLETED_NUM);
}

