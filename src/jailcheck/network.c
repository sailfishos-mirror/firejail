/*
 * Copyright (C) 2014-2025 Firejail Authors
 *
 * This file is part of firejail project
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include "jailcheck.h"
#include <netdb.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <linux/connector.h>
#include <linux/netlink.h>
#include <linux/if_link.h>
#include <linux/sockios.h>
#include <sys/ioctl.h>


void network_test(void) {
	// I am root running in a network namespace
	struct ifaddrs *ifaddr, *ifa;
	int found = 0;

	// walk through the linked list
	if (getifaddrs(&ifaddr) == -1)
		errExit("getifaddrs");
	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
		if (strcmp(ifa->ifa_name, "lo") == 0)
			continue;

		found = 1;
		break;
	}

	freeifaddrs(ifaddr);

	if (found)
		printf("   Networking: enabled\n");
	else
		printf("   Networking: disabled\n");
}
