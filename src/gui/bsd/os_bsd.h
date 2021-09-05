/*
 *  Copyright (C) 2010-2021 Fabio Cavallo (aka FHorse)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef OS_BSD_H_
#define OS_BSD_H_

#include <sys/types.h>
#include <sys/sysctl.h>
#include <time.h>
#include <stdio.h>

static double high_resolution_ms(void);
static int __nsleep(const struct timespec *req, struct timespec *rem);

void gui_init_os(void) {
	// cerco la HOME e imposto la directory base
	{
		gui.home = getenv("HOME");

		if (!gui.home) {
			gui.home = QDir::homePath().toUtf8().constData();
		}

		if (info.portable) {
			uTCHAR path[usizeof(info.base_folder)];
			size_t len = usizeof(path);
			int name[] = { CTL_KERN, KERN_PROC_CWD, 0 };

			name[2] = getpid();
			umemset(&path, 0x00, usizeof(path));

			if (sysctl(name, 3, &path, &len, NULL, 0) != 0) {
				fprintf(stderr, "INFO: Error on sysctl.\n");
				info.portable = FALSE;
			} else {
				ustrncpy(info.base_folder, path, usizeof(info.base_folder));
			}
		} else {
			usnprintf(info.base_folder, usizeof(info.base_folder), uL("" uPERCENTs "/." NAME), gui.home);
		}
 	}

	gettimeofday(&gui.counterStart, nullptr);
	gui_get_ms = high_resolution_ms;
}
void gui_sleep(double ms) {
	struct timespec req = {}, rem = {};
	time_t sec;

	if (ms <= 0) {
		return;
	}

	sec = (time_t)(ms / 1000.0f);
	ms = ms - ((double)sec * 1000.0f);
	req.tv_sec = sec;
	req.tv_nsec = ms * 1000000L;
	__nsleep(&req, &rem);
}
int gui_screen_id(void) {
	int wid = qt.screen->wogl->winId();

	return (wid);
}

static double high_resolution_ms(void) {
	struct timeval time;
	double elapsed_seconds;
	double elapsed_useconds;

	gettimeofday(&time, nullptr);

	elapsed_seconds  = time.tv_sec  - gui.counterStart.tv_sec;
	elapsed_useconds = time.tv_usec - gui.counterStart.tv_usec;

	return ((elapsed_seconds * 1000.0f) + (elapsed_useconds / 1000.0f));
}
static int __nsleep(const struct timespec *req, struct timespec *rem) {
	struct timespec temp_rem;

	if (nanosleep(req, rem) == -1) {
		__nsleep(rem, &temp_rem);
	} else {
		return (EXIT_ERROR);
	}

	return (EXIT_OK);
}

#endif /* OS_BSD_H_ */
