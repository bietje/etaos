/*
 *  ETA/OS - Time core
 *  Copyright (C) 2014   Michel Megens
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

#include <etaos/kernel.h>
#include <etaos/types.h>
#include <etaos/atomic.h>
#include <etaos/time.h>
#include <etaos/irq.h>
#include <etaos/tick.h>
#include <etaos/stdio.h>

static irqreturn_t systick_irq_handle(struct irq_data *irq, void *data)
{
	struct clocksource *cs = (struct clocksource*)data;

	atomic64_inc(&cs->tc);
	return IRQ_HANDLED;
}

void systick_setup(int irq, struct clocksource *src)
{
	irq_request(irq, &systick_irq_handle, IRQ_RISING_MASK, src);
}
