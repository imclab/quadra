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

#ifndef _HEADER_BITMAP
#define _HEADER_BITMAP

#include <stdint.h>

#include "types.h"
#include "error.h"
#include "image.h"
#include "clipable.h"
#include "res_name.h"

#define COPY 1

class Video_bitmap;

class Bitmap: public Clipable {
	void initlines();
 public:
	int const realwidth;
 protected:
	int* zlines;
	uint8_t** const lines;
	uint32_t const size;
	uint8_t* mem;
	uint8_t const fmem;
 public:
	static Bitmap* loadPng(const ResName& n);
	Bitmap(int w, int h, int rw); // empty bitmap
	Bitmap(void* m, int w, int h, int rw); // bitmap pointing to existing memory
	Bitmap(void* m, int w, int h, int rw, int bob); // copies memory in bitmap
	Bitmap(const Image& raw);
	virtual ~Bitmap();
	void reload(const Image& raw);
	void setmem(const void* m) {
		mem=(uint8_t*)m;
		for(int i(0); i<height; i++)
			lines[i]=(uint8_t*) (((uint8_t *)mem)+zlines[i]);
	}
	uint8_t* operator[](const int y) const {
		return lines[y];
	}
	void draw(const Bitmap& d, const int dx, const int dy) const;
	void draw(const Video_bitmap* d, const int dx, const int dy) const;
	void hline(const int y, const int x, const int w, const uint8_t color) const;
	void vline(const int x, const int y, const int h, const uint8_t color) const;
	void put_pel(const int x, const int y, const uint8_t color) const;
	void fast_pel(const int x, const int y, const uint8_t color) const {
		*(operator[](y)+x) = color;
	}
	void clear(const uint8_t color) const;
};

#endif
