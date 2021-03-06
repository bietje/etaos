/*
 *  ETA/OS - AVR CPU
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

#ifndef __AVR_CPU_H__
#define __AVR_CPU_H__

#include <etaos/kernel.h>
#include <etaos/time.h>

CDECL
extern void avr_start_sysclk(int irq, struct clocksource *src);
CDECL_END
#endif

