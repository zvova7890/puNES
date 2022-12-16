/*
 *  Copyright (C) 2010-2023 Fabio Cavallo (aka FHorse)
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

#ifndef MAPPER_168_H_
#define MAPPER_168_H_

#include "common.h"

void map_init_168(void);
void extcl_cpu_wr_mem_168(WORD address, BYTE value);
BYTE extcl_save_mapper_168(BYTE mode, BYTE slot, FILE *fp);
void extcl_wr_chr_168(WORD address, BYTE value);

#endif /* MAPPER_168_H_ */
