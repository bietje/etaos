/*
 *  ETA/OS - Timer header
 *  Copyright (C) 2016   Michel Megens <dev@michelmegens.net>
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

#ifndef __TIME_H__
#define __TIME_H__

#include <etaos/kernel.h>
#include <etaos/timer.h>

struct tm {
	int tm_sec,
	    tm_min,
	    tm_hour,
	    tm_mday,
	    tm_mon,
	    tm_year,
	    tm_wday,
	    tm_yday,
	    tm_isdst;

};

extern struct tm _tm;

CDECL
extern struct tm *localtime(const time_t *t);
extern int localtime_r(const time_t *t, struct tm *time);

extern struct tm *gmtime(const time_t *t);
extern int gmtime_r(const time_t *t, struct tm *gmt);
CDECL_END

#endif

