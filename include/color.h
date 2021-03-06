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

#ifndef _HEADER_COLOR
#define _HEADER_COLOR

#include <stdint.h>

#include "palette.h"

class Color {
	uint8_t base;
	Palette& pal;
public:
	Color(uint8_t q, Palette& p);
	void set(int r, int g, int b, int r2, int g2, int b2);
	uint8_t shade(uint8_t i) const {
		return base+i;
	}
};

#endif
