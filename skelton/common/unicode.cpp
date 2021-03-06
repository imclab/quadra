/* -*- Mode: C++; c-basic-offset: 2; tab-width: 2; indent-tabs-mode: nil -*-
 * 
 * Quadra, an action puzzle game
 * Copyright (C) 1998-2000  Ludus Design
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <string.h>
#include "unicode.h"

Unicode::Unicode(char *s): the_string(strlen(s)*2) {
	uint32_t i;
	for(i=0; i<strlen(s); i++) {
		the_string[i*2] = s[i];
		the_string[i*2+1] = 0;
	}
}

Unicode &Unicode::cat(char *s) {
	uint8_t a_zero=0;
	uint32_t i;
	for(i=0; i<strlen(s); i++) {
		the_string.append((uint8_t *)&s[i], 1);
		the_string.append(&a_zero, 1);
	}
	return *this;
}

Unicode::operator uint8_t *() {
	return the_string.get();
}

uint32_t Unicode::size() {
	return the_string.size();
}
