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

static uint8_t font_size[][2] = {
	{12, 12},
	{14, 12}
};
static char font_8x10[156][97] = {
"                 ..         .  .        .. ..         .        .   .       ...         ..       ",
"                .++.       .+..+.     ..++.++.       .+.      .+. .+.     .+++.       .++.      ",
"               .+@@+.     .+@++@+.   .++@@+@@+.     .+@+.    .+@+.+@+.   .+@@@+. .   .+@@+.     ",
"               .+@@+.     .+@++@+.  .+@@@@@@@@+.   .+@@@+.  .+@+@++@+.  .+@@++@+.+.   .+@+.     ",
"               .+@@+.     .+@++@+.   .+@@++@@+.   .+@+@+@+.  .+@++@+.   .+@@+.+++@+. .+@+.      ",
"               .+@@+.      .+..+.   .+@@@@@@@@+.   .+@@+.     .+.+@+.    .+@@+@@@+.   .+.       ",
"                .++.        .  .     .+@@+@@++.     .+@@+.     .+@+.+.  .+@@++@@+.     .        ",
"               .+@@+.                 .++.++..    .+@+@+@+.    .+@++@+. .+@@++@@+.              ",
"               .+@@+.                  .. ..       .+@@@+.    .+@++@+@+. .+@@@@+.               ",
"                .++.                                .+@+.     .+@+.+@+.   .++++.                ",
"                 ..                                  .+.       .+. .+.     ....                 ",
"                                                      .         .   .                           ",
/*
*  12345678    12345678    12345678    12345678    12345678    12345678    12345678    12345678
*012345678901012345678901012345678901012345678901012345678901012345678901012345678901012345678901
*/
"      ..        ..            .                                                            .    ",
"     .++.      .++.         ..+..         .                                               .+.   ",
"    .+@@+.    .+@@+.       .++@++.       .+.                                             .+@+.  ",
"   .+@@+.      .+@@+.     .+@+@+@+.     .+@+.                  ......                    .+@+.  ",
"  .+@@+.        .+@@+.     .+@@@+.     .++@++.                .++++++.                  .+@+.   ",
"  .+@@+.        .+@@+.    .+@+@+@+.   .+@@@@@+.    ..        .+@@@@@@+.    ..           .+@+.   ",
"  .+@@+.        .+@@+.     .++@++.     .++@++.    .++.        .++++++.    .++.         .+@+.    ",
"  .+@@+.        .+@@+.      ..+..       .+@+.    .+@@+.        ......    .+@@+.        .+@+.    ",
"   .+@@+.      .+@@+.         .          .+.      .+@+.                  .+@@+.       .+@+.     ",
"    .+@@+.    .+@@+.                      .      .+@+.                    .++.        .+@+.     ",
"     .++.      .++.                               .+.                      ..          .+.      ",
"      ..        ..                                 .                                    .       ",
"    ....         ..         ....       ......         ...      ......        ...       ......   ",
"   .++++.       .++.       .++++.     .++++++.       .+++.    .++++++.      .+++.     .++++++.  ",
"  .+@@@@+.     .+@@+.     .+@@@@+.   .+@@@@@@+.     .+@@@+.  .+@@@@@@+.    .+@@@+.   .+@@@@@@+. ",
" .+@@++@@+.   .+@@@+.    .+@+++@@+.   .+++@@+.     .+@+@@+.  .+@@++++.    .+@@+.      .++++@@+. ",
" .+@@+@@@+.    .+@@+.     .+.++@@+.    .+@@+.     .+@++@@+.  .+@@@@@+.   .+@@+++.      ...+@@+. ",
" .+@@@+@@+.    .+@@+.      .+@@@+.    .+@@@@+.   .+@+++@@+.   .++++@@+.  .+@@@@@+.      .+@@+.  ",
" .+@@++@@+.    .+@@+.     .+@@++.     .++++@@+.  .+@@@@@@@+.  .+..+@@+.  .+@@++@@+.    .+@@+.   ",
" .+@@++@@+.    .+@@+.    .+@@++++.   .+@+++@@+.   .++++@@+.  .+@+++@@+.  .+@@++@@+.    .+@@+.   ",
"  .+@@@@+.     .+@@+.    .+@@@@@@+.   .+@@@@+.     ...+@@+.   .+@@@@+.    .+@@@@+.     .+@@+.   ",
"   .++++.       .++.      .++++++.     .++++.         .++.     .++++.      .++++.       .++.    ",
"    ....         ..        ......       ....           ..       ....        ....         ..     ",
"                                                                                                ",
"    ....        ....                                                                    ....    ",
"   .++++.      .++++.      ..          ..             ..                    ..         .++++.   ",
"  .+@@@@+.    .+@@@@+.     ++.        .++.           .++.      ......      .++.       .+@@@@+.  ",
" .+@@++@@+.  .+@@++@@+.  .+@@+.      .+@@+.         .+@@+.    .++++++.    .+@@+.     .+@+++@@+. ",
" .+@@++@@+.  .+@@++@@+.  .+@@+.      .+@@+.        .+@@+.    .+@@@@@@+.    .+@@+.     .+..+@@+. ",
"  .+@@@@+.    .+@@@@@+.   .++.        .++.        .+@@+.      .++++++.      .+@@+.     ..+@@+.  ",
" .+@@++@@+.    .+++@@+.   .++.        .++.         .+@@+.    .+@@@@@@+.    .+@@+.      .+@@+.   ",
" .+@@++@@+.    .++@@+.   .+@@+.      .+@@+.         .+@@+.    .++++++.    .+@@+.        .++.    ",
"  .+@@@@+.    .+@@@+.    .+@@+.       .+@+.          .++.      ......      .++.        .+@@+.   ",
"   .++++.      .+++.      .++.       .+@+.            ..                    ..          .++.    ",
"    ....        ...        ..         .+.                                                ..     ",
"                                       .                                                        ",
"    ....        ....       .....        ....       .....       ......      ......       ....    ",
"   .++++.      .++++.     .+++++.      .++++.     .+++++.     .++++++.    .++++++.     .++++.   ",
"  .+@@@@+.    .+@@@@+.   .+@@@@@+.    .+@@@@+.   .+@@@@@+.   .+@@@@@@+.  .+@@@@@@+.   .+@@@@+.  ",
" .+@++++@+.  .+@@++@@+.  .+@@++@@+.  .+@@+++@+.  .+@@++@@+.  .+@@++++.   .+@@++++.   .+@@+++@+. ",
".+@++@@++@+. .+@@++@@+.  .+@@++@@+.  .+@@+..+.   .+@@++@@+.  .+@@+++.    .+@@+++.    .+@@++++.  ",
".+@+@++@+@+. .+@@@@@@+.  .+@@@@@+.   .+@@+. .    .+@@++@@+.  .+@@@@@+.   .+@@@@@+.   .+@@+@@@+. ",
".+@+@++@+@+. .+@@++@@+.  .+@@++@@+.  .+@@+..+.   .+@@++@@+.  .+@@+++.    .+@@+++.    .+@@++@@+. ",
".+@++@@+@+.  .+@@++@@+.  .+@@++@@+.  .+@@+++@+.  .+@@++@@+.  .+@@++++.   .+@@+..     .+@@++@@+. ",
" .+@+++++.   .+@@++@@+.  .+@@@@@+.    .+@@@@+.   .+@@@@@+.   .+@@@@@@+.  .+@@+.       .+@@@@+.  ",
"  .+@@@@+.    .++..++.    .+++++.      .++++.     .+++++.     .++++++.    .++.         .++++.   ",
"   .++++.      ..  ..      .....        ....       .....       ......      ..           ....    ",
"    ....                                                                                        ",
"   ..  ..        ..            ..      ..  ..      ..         .     ..     ..    .      ....    ",
"  .++..++.      .++.          .++.    .++..++.    .++.       .+.   .++.   .++.  .+.    .++++.   ",
" .+@@++@@+.    .+@@+.        .+@@+.  .+@@++@@+.  .+@@+.     .+@+. .+@@+. .+@@+..+@+.  .+@@@@+.  ",
" .+@@++@@+.    .+@@+.        .+@@+.  .+@@+@@+.   .+@@+.     .+@@+.+@@@+. .+@@@+.+@+. .+@@++@@+. ",
" .+@@++@@+.    .+@@+.      ...+@@+.  .+@@@@+.    .+@@+.     .+@@@+@@@@+. .+@@@@++@+. .+@@++@@+. ",
" .+@@@@@@+.    .+@@+.     .++.+@@+.  .+@@@+.     .+@@+.     .+@+@@@+@@+. .+@+@@@+@+. .+@@++@@+. ",
" .+@@++@@+.    .+@@+.    .+@@++@@+.  .+@@@@+.    .+@@+...   .+@++@++@@+. .+@++@@@@+. .+@@++@@+. ",
" .+@@++@@+.    .+@@+.    .+@@++@@+.  .+@@+@@+.   .+@@++++.  .+@+.+.+@@+. .+@+.+@@@+. .+@@++@@+. ",
" .+@@++@@+.    .+@@+.     .+@@@@+.   .+@@++@@+.  .+@@@@@@+. .+@+...+@@+. .+@+..+@@+.  .+@@@@+.  ",
"  .++..++.      .++.       .++++.     .++..++.    .++++++.   .+.   .++.   .+.  .++.    .++++.   ",
"   ..  ..        ..         ....       ..  ..      ......     .     ..     .    ..      ....    ",
"                                                                                                ",
"   .....        ....       .....         ...       ......      ..  ..      ..  ..     .. .. ..  ",
"  .+++++.      .++++.     .+++++.       .+++.     .++++++.    .++..++.    .++..++.   .++.++.++. ",
" .+@@@@@+.    .+@@@@+.   .+@@@@@+.     .+@@@+.   .+@@@@@@+.  .+@@++@@+.  .+@@++@@+. .+@@+@@+@@+.",
" .+@@++@@+.  .+@@++@@+.  .+@@++@@+.   .+@@++@+.   .++@@++.   .+@@++@@+.  .+@@++@@+. .+@@+@@+@@+.",
" .+@@++@@+.  .+@@++@@+.  .+@@++@@+.   .+@@@++.     .+@@+.    .+@@++@@+.  .+@@++@@+. .+@@+@@+@@+.",
" .+@@@@@+.   .+@@++@@+.  .+@@@@@+.     .+@@@+.     .+@@+.    .+@@++@@+.  .+@@++@@+. .+@@+@@+@@+.",
" .+@@+++.    .+@@++@@+.  .+@@++@@+.    .++@@@+.    .+@@+.    .+@@++@@+.  .+@@++@@+. .+@@+@@+@@+.",
" .+@@+..     .+@@++@@+.  .+@@++@@+.   .+@++@@+.    .+@@+.    .+@@++@@+.  .+@@++@+.  .+@@+@@+@+. ",
" .+@@+.       .+@@@@+.   .+@@++@@+.    .+@@@+.     .+@@+.     .+@@@@+.   .+@@@@+.   .+@@@@@@+.  ",
"  .++.         .+++@@+.   .++..++.      .+++.       .++.       .++++.     .++++.     .++++++.   ",
"   ..           ...++.     ..  ..        ...         ..         ....       ....       ......    ",
"                   ..                                                                           ",
"   ..  ..      ..  ..      ......        ...        .           ...           .                 ",
"  .++..++.    .++..++.    .++++++.      .+++.      .+.         .+++.         .+.                ",
" .+@@++@@+.  .+@@++@@+.  .+@@@@@@+.    .+@@@+.    .+@+.       .+@@@+.       .+@+.               ",
" .+@@++@@+.  .+@@++@@+.   .++++@@+.    .+@@+.     .+@+.        .+@@+.      .+@+@+.              ",
" .+@@++@@+.  .+@@++@@+.    ..+@@+.     .+@@+.      .+@+.       .+@@+.     .+@+.+@+.             ",
"  .+@@@@+.    .+@@@@+.     .+@@+.      .+@@+.      .+@+.       .+@@+.      .+. .+.              ",
" .+@@++@@+.    .+@@+.     .+@@+..      .+@@+.       .+@+.      .+@@+.       .   .               ",
" .+@@++@@+.    .+@@+.    .+@@++++.     .+@@+.       .+@+.      .+@@+.                 ........  ",
" .+@@++@@+.    .+@@+.    .+@@@@@@+.    .+@@+.        .+@+.     .+@@+.                .++++++++. ",
"  .++..++.      .++.      .++++++.     .+@@@+.       .+@+.    .+@@@+.               .+@@@@@@@@+.",
"   ..  ..        ..        ......       .+++.         .+.      .+++.                 .++++++++. ",
"                                         ...           .        ...                   ........  ",
"     .                     ..                          ..                     ...               ",
"    .+.                   .++.                        .++.                   .+++.              ",
"   .+@+.        ....     .+@@+..        ....        ..+@@+.     ....        .+@@@+.     .....   ",
"  .+@+.        .++++.    .+@@+++.      .++++.      .+++@@+.    .++++.      .+@@++.     .+++++.  ",
"  .+@@+.      .+@@@@+.   .+@@@@@+.    .+@@@@+.    .+@@@@@+.   .+@@@@+.    .+@@@@+.    .+@@@@@+. ",
"   .++.        .+++@@+.  .+@@++@@+.  .+@@+++@+.  .+@@++@@+.  .+@@++@@+.    .+@@+.    .+@@++@@+. ",
"    ..        .+@@@@@+.  .+@@++@@+.  .+@@+..+.   .+@@++@@+.  .+@@@@@@+.    .+@@+.    .+@@++@@+. ",
"             .+@@++@@+.  .+@@++@@+.  .+@@+++@+.  .+@@++@@+.  .+@@++++.     .+@@+.     .+@@@@@+. ",
"              .+@@@@@+.  .+@@@@@+.    .+@@@@+.    .+@@@@@+.   .+@@@@+.     .+@@+.      .+++@@+. ",
"               .+++++.    .+++++.      .++++.      .+++++.     .++++.       .++.      .+@@@@+.  ",
"                .....      .....        ....        .....       ....         ..        .++++.   ",
"                                                                                        ....    ",
"   ..            ..            ..      ..           ...                                         ",
"  .++.          .++.          .++.    .++.         .+++.                                        ",
" .+@@+..       .+@@+.        .+@@+.  .+@@+...     .+@@@+.     .......      .....        ....    ",
" .+@@+++.       .++.          .++.   .+@@+.++.     .+@@+.    .+++++++.    .+++++.      .++++.   ",
" .+@@@@@+.     .+@@+.        .+@@+.  .+@@++@@+.    .+@@+.   .+@@@@@@@+.  .+@@@@@+.    .+@@@@+.  ",
" .+@@++@@+.    .+@@+.        .+@@+.  .+@@+@@+.     .+@@+.   .+@@+@@+@@+. .+@@++@@+.  .+@@++@@+. ",
" .+@@++@@+.    .+@@+.       ..+@@+.  .+@@@@+.      .+@@+.   .+@@+@@+@@+. .+@@++@@+.  .+@@++@@+. ",
" .+@@++@@+.    .+@@+.      .+.+@@+.  .+@@+@@+.     .+@@+.   .+@@+@@+@@+. .+@@++@@+.  .+@@++@@+. ",
" .+@@++@@+.    .+@@+.     .+@++@@+.  .+@@++@@+.    .+@@+.   .+@@+@@+@@+. .+@@++@@+.   .+@@@@+.  ",
"  .++..++.      .++.       .+@@@+.    .++..++.      .++.     .++.++.++.   .++..++.     .++++.   ",
"   ..  ..        ..         .+++.      ..  ..        ..       .. .. ..     ..  ..       ....    ",
"                             ...                                                                ",
"                                                     ..                                         ",
"                                                    .++.                                        ",
"   .....        .....       .. ..       .....      .+@@+.      ..  ..      ..  ..     .. .. ..  ",
"  .+++++.      .+++++.     .++.++.     .+++++.     .+@@+.     .++..++.    .++..++.   .++.++.++. ",
" .+@@@@@+.    .+@@@@@+.   .+@@+@@+.   .+@@@@@+.   .+@@@@+.   .+@@++@@+.  .+@@++@@+. .+@@+@@+@@+.",
" .+@@++@@+.  .+@@++@@+.   .+@@@@@+.  .+@@++++.     .+@@+.    .+@@++@@+.  .+@@++@@+. .+@@+@@+@@+.",
" .+@@++@@+.  .+@@++@@+.   .+@@+++.    .+@@@@+.     .+@@+.    .+@@++@@+.  .+@@++@@+. .+@@+@@+@@+.",
" .+@@++@@+.  .+@@++@@+.   .+@@+..     .++++@@+.    .+@@+.    .+@@++@@+.  .+@@++@+.  .+@@+@@+@+. ",
" .+@@@@@+.    .+@@@@@+.   .+@@+.     .+@@@@@+.      .+@@+.    .+@@@@@+.  .+@@@@+.   .+@@@@@@+.  ",
" .+@@+++.      .+++@@+.    .++.       .+++++.        .++.      .+++++.    .++++.     .++++++.   ",
"  .++...        ...++.      ..         .....          ..        .....      ....       ......    ",
"   ..              ..                                                                           ",
"                                         ...         ..       ...           ..  .               ",
"                                        .+++.       .++.     .+++.         .++..+.       .      ",
"   ..  ..      ..  ..      ......      .+@@@+.     .+@@+.   .+@@@+.       .+@@++@+.     .+.     ",
"  .++..++.    .++..++.    .++++++.    .+@@++.      .+@@+.    .++@@+.     .+@++@@+.     .+@+.    ",
" .+@@++@@+.  .+@@++@@+.  .+@@@@@@+.  .++@@+.       .+@@+.     .+@@++.     .+..++.     .+@@@+.   ",
" .+@@++@@+.  .+@@++@@+.   .+++@@+.  .+@@@+.        .+@@+.      .+@@@+.     .  ..     .+@@+@@+.  ",
"  .+@@@@+.   .+@@++@@+.    .+@@+.    .++@@+.       .+@@+.     .+@@++.               .+@@+.+@@+. ",
" .+@@++@@+.   .+@@@@@+.   .+@@+++.    .+@@+.       .+@@+.    .++@@+.                .+@@+++@@+. ",
" .+@@++@@+.    .+++@@+.  .+@@@@@@+.    .+@@@+.     .+@@+.   .+@@@+.                 .+@@@@@@@+. ",
"  .++..++.    .+@@@@+.    .++++++.      .+++.      .+@@+.    .+++.                   .+++++++.  ",
"   ..  ..      .++++.      ......        ...        .++.      ...                     .......   ",
"                ....                                 ..                                         ",
"       .        .                                                                               ",
"      .+.      .+.                                                                              ",
"     .+@+.    .+@+.          ..       ........                  ....                            ",
"    .+@@+.    .+@@+.        .++.     .++++++++.                .++++.                           ",
"   .+@@@+.    .+@@@+.      .+@@+.   .+@@@@@@@@+.   ......     .+@@@@+.                          ",
"  .+@@@@+.    .+@@@@+.    .+@@@@+.   .+@@@@@@+.   .++++++.   .+@@@@@@+.                         ",
"  .+@@@@+.    .+@@@@+.   .+@@@@@@+.   .+@@@@+.   .+@@@@@@+.  .+@@@@@@+.                         ",
"   .+@@@+.    .+@@@+.   .+@@@@@@@@+.   .+@@+.   .+@@@@@@@@+. .+@@@@@@+.                         ",
"    .+@@+.    .+@@+.     .++++++++.     .++.     .+@@@@@@+.   .+@@@@+.                          ",
"     .+@+.    .+@+.       ........       ..       .++++++.     .++++.                           ",
"      .+.      .+.                                 ......       ....                            ",
"       .        .                                                                               "};

static char font_12x10[144][113] = {
"                    ..          ..  ..        ..  ..       .........    ....   ..      ......         ..        ",
"                   .++.        .++..++.     ..++..++..    .+++++++++.  .++++. .++.    .++++++.       .++.       ",
"                  .+@@+.      .+@@++@@+.   .++@@++@@++.  .+@@@@@@@@@+..+@@@@+.+@@+.  .+@@@@@@+.     .+@@+.      ",
"                  .+@@+.      .+@@++@@+.  .+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@++@@@+. .+@@@@@@@@+.    .+@@+.      ",
"                  .+@@+.      .+@@++@@+.  .+@@@@@@@@@@+..+@@++@@++++. .+@@@@+@@@+.  .+@@++++@@++.   .+@@+.      ",
"                  .+@@+.      .+@@++@@+.   .++@@++@@++. .+@@@@@@@@@+.  .++++@@@+..   .+@@@@@@+@@+.  .+@@+.      ",
"                  .+@@+.       .++..++.    .++@@++@@++.  .+@@@@@@@@@+.  ..+@@@++++.  .+@@@@@@@@@+.   .++.       ",
"                   .++.         ..  ..    .+@@@@@@@@@@+. .++++@@++@@+.  .+@@@+@@@@+..+@@++++@@@+.     ..        ",
"                  .+@@+.                  .+@@@@@@@@@@+..+@@@@@@@@@@+. .+@@@++@@@@+..+@@@@@@@@@@+.              ",
"                  .+@@+.                   .++@@++@@++. .+@@@@@@@@@+.  .+@@+.+@@@@+. .+@@@@@@+@@+.              ",
"                   .++.                     ..++..++..   .+++++++++.    .++. .++++.   .++++++.++.               ",
"                    ..                        ..  ..      .........      ..   ....     ...... ..                ",
"       ..          ..         ..  ..  ..        ..                                                         ..   ",
"      .++.        .++.       .++..++..++.      .++.                                                       .++.  ",
"     .+@@+.      .+@@+.     .+@@++@@++@@+.    .+@@+.                                                     .+@@+. ",
"    .+@@@+.      .+@@@+.    .+@@@+@@+@@@+.  ...+@@+...                  ..........                      .+@@@+. ",
"   .+@@@+.        .+@@@+.    .+@@@@@@@@+.  .++++@@++++.    ..          .++++++++++.                    .+@@@+.  ",
"   .+@@+.          .+@@+.     .+@@@@@@+.  .+@@@@@@@@@@+.  .++.        .+@@@@@@@@@@+.                  .+@@@+.   ",
"   .+@@+.          .+@@+.     .+@@@@@@+.  .+@@@@@@@@@@+. .+@@+.       .+@@@@@@@@@@+.   ..            .+@@@+.    ",
"   .+@@@+.        .+@@@+.    .+@@@@@@@@+.  .++++@@++++.  .+@@+.        .++++++++++.   .++.          .+@@@+.     ",
"    .+@@@+.      .+@@@+.    .+@@@+@@+@@@+.  ...+@@+...   .+@@+.         ..........   .+@@+.        .+@@@+.      ",
"     .+@@+.      .+@@+.     .+@@++@@++@@+.    .+@@+.     .+@@+.                      .+@@+.        .+@@+.       ",
"      .++.        .++.       .++..++..++.      .++.       .++.                        .++.          .++.        ",
"       ..          ..         ..  ..  ..        ..         ..                          ..            ..         ",
"   ........        ...        .........     .........     ..    ..      ..........     ........     .........   ",
"  .++++++++.      .+++.      .+++++++++.   .+++++++++.   .++.  .++.    .++++++++++.   .++++++++.   .+++++++++.  ",
" .+@@@@@@@@+.    .+@@@+.    .+@@@@@@@@@+. .+@@@@@@@@@+. .+@@+..+@@+.  .+@@@@@@@@@@+. .+@@@@@@@@+. .+@@@@@@@@@+. ",
".+@@@@@@@@@@+.   .+@@@@+.   .+@@@@@@@@@@+..+@@@@@@@@@@+..+@@+..+@@+.  .+@@@@@@@@@@+..+@@@@@@@@@+. .+@@@@@@@@@@+.",
".+@@++++++@@+.    .++@@+.    .++++++++@@+. .++++++++@@+..+@@+..+@@+.  .+@@++++++++. .+@@+++++++.   .++++++++@@+.",
".+@@++@@++@@+.     .+@@+.    .+@@@@@@@@@+. .+@@@@@@@@@+..+@@++++@@++. .+@@@@@@@@@+. .+@@@@@@@@@+.   .......+@@+.",
".+@@++@@++@@+.     .+@@+.   .+@@@@@@@@@+.  .+@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+.        .+@@+.",
".+@@++++++@@+.     .+@@+.   .+@@++++++++.  .++++++++@@+. .+@@@@@@@@@+. .++++++++@@+..+@@++++++@@+.        .+@@+.",
".+@@@@@@@@@@+.     .+@@+.   .+@@@@@@@@@@+..+@@@@@@@@@@+.  .+++++@@++. .+@@@@@@@@@@+..+@@@@@@@@@@+.        .+@@+.",
" .+@@@@@@@@+.      .+@@+.   .+@@@@@@@@@@+..+@@@@@@@@@+.    ....+@@+.  .+@@@@@@@@@+.  .+@@@@@@@@+.         .+@@+.",
"  .++++++++.        .++.     .++++++++++.  .+++++++++.         .++.    .+++++++++.    .++++++++.           .++. ",
"   ........          ..       ..........    .........           ..      .........      ........             ..  ",
"   ........      ........                                      ..                        ..          ........   ",
"  .++++++++.    .++++++++.        ..            ..            .++.      ..........      .++.        .++++++++.  ",
" .+@@@@@@@@+.  .+@@@@@@@@+.      .++.          .++.          .+@@+.    .++++++++++.    .+@@+.      .+@@@@@@@@+. ",
".+@@@@@@@@@@+..+@@@@@@@@@@+.    .+@@+.        .+@@+.        .+@@@+.   .+@@@@@@@@@@+.   .+@@@+.    .+@@@@@@@@@@+.",
".+@@++++++@@+..+@@++++++@@+.    .+@@+.        .+@@+.       .+@@@+.    .+@@@@@@@@@@+.    .+@@@+.   .+@@++++++@@+.",
".+@@@@@@@@@@+..+@@@@@@@@@@+.     .++.          .++.       .+@@@+.      .++++++++++.      .+@@@+.   .++.+@@@@@@+.",
".+@@@@@@@@@@+. .+@@@@@@@@@+.     .++.          .++.       .+@@@+.      .++++++++++.      .+@@@+.    ...+@@@@@+. ",
".+@@++++++@@+.  .+++++++@@+.    .+@@+.        .+@@+.       .+@@@+.    .+@@@@@@@@@@+.    .+@@@+.        .+++++.  ",
".+@@@@@@@@@@+. .+@@@@@@@@@+.    .+@@+.        .+@@+.        .+@@@+.   .+@@@@@@@@@@+.   .+@@@+.        .+@@+..   ",
" .+@@@@@@@@+.  .+@@@@@@@@+.      .++.         .+@@+.         .+@@+.    .++++++++++.    .+@@+.         .+@@+.    ",
"  .++++++++.    .++++++++.        ..           .++.           .++.      ..........      .++.           .++.     ",
"   ........      ........                       ..             ..                        ..             ..      ",
"   ........      ........     .........      .........    .........      .........     .........     .........  ",
"  .++++++++.    .++++++++.   .+++++++++.    .+++++++++.  .+++++++++.    .+++++++++.   .+++++++++.   .+++++++++. ",
" .+@@@@@@@@+.  .+@@@@@@@@+. .+@@@@@@@@@+.  .+@@@@@@@@@+..+@@@@@@@@@+.  .+@@@@@@@@@+. .+@@@@@@@@@+. .+@@@@@@@@@+.",
".+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+.",
".+@@++++++@@+..+@@++++++@@+..+@@++++++@@+..+@@++++++++. .+@@++++++@@+..+@@++++++++. .+@@++++++++. .+@@++++++++. ",
".+@@+@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@+.......  .+@@+....+@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@++@@@@@@+.",
".+@@+@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@+.......  .+@@+....+@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@++@@@@@@+.",
".+@@+@@+++@@+..+@@++++++@@+..+@@++++++@@+..+@@++++++++. .+@@++++++@@+..+@@++++++++. .+@@++++++++. .+@@++++++@@+.",
".+@@@@@@@@@@+..+@@+....+@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@+.......  .+@@@@@@@@@@+.",
" .+@@@@@@@@+. .+@@+.  .+@@+..+@@@@@@@@@+.  .+@@@@@@@@@+..+@@@@@@@@@+.  .+@@@@@@@@@+..+@@+.         .+@@@@@@@@@+.",
"  .++++++++.   .++.    .++.  .+++++++++.    .+++++++++.  .+++++++++.    .+++++++++.  .++.           .+++++++++. ",
"   ........     ..      ..    .........      .........    .........      .........    ..             .........  ",
"  ..      ..        ..                ..    ..      ..    ..            .........     ...     ..     ........   ",
" .++.    .++.      .++.              .++.  .++.    .++.  .++.          .+++++++++.   .+++.   .++.   .++++++++.  ",
".+@@+.  .+@@+.    .+@@+.            .+@@+..+@@+.  .+@@+..+@@+.        .+@@@@@@@@@+. .+@@@+. .+@@+. .+@@@@@@@@+. ",
".+@@+....+@@+.    .+@@+.            .+@@+..+@@+....+@@+..+@@+.        .+@@@@@@@@@@+..+@@@@+..+@@+..+@@@@@@@@@@+.",
".+@@++++++@@+.    .+@@+.      ..    .+@@+..+@@++++++@@+..+@@+.        .+@@++@@++@@+..+@@@@@+.+@@+..+@@++++++@@+.",
".+@@@@@@@@@@+.    .+@@+.     .++.   .+@@+..+@@@@@@@@@+. .+@@+.        .+@@++@@++@@+..+@@+@@@++@@+..+@@+....+@@+.",
".+@@@@@@@@@@+.    .+@@+.    .+@@+....+@@+..+@@@@@@@@@+. .+@@+.......  .+@@++@@++@@+..+@@++@@@+@@+..+@@+....+@@+.",
".+@@++++++@@+.    .+@@+.    .+@@++++++@@+..+@@++++++@@+..+@@++++++++. .+@@++@@++@@+..+@@+.+@@@@@+..+@@++++++@@+.",
".+@@+....+@@+.    .+@@+.    .+@@@@@@@@@@+..+@@+....+@@+..+@@@@@@@@@@+..+@@++@@++@@+..+@@+..+@@@@+..+@@@@@@@@@@+.",
".+@@+.  .+@@+.    .+@@+.     .+@@@@@@@@+. .+@@+.  .+@@+. .+@@@@@@@@@+..+@@++@@++@@+..+@@+. .+@@@+. .+@@@@@@@@+. ",
" .++.    .++.      .++.       .++++++++.   .++.    .++.   .+++++++++.  .++..++..++.  .++.   .+++.   .++++++++.  ",
"  ..      ..        ..         ........     ..      ..     .........    ..  ..  ..    ..     ...     ........   ",
"  .........      .......      .........      .........    ..........    ..      ..    ..      ..    ..  ..  ..  ",
" .+++++++++.    .+++++++.    .+++++++++.    .+++++++++.  .++++++++++.  .++.    .++.  .++.    .++.  .++..++..++. ",
".+@@@@@@@@@+.  .+@@@@@@@+.  .+@@@@@@@@@+.  .+@@@@@@@@@+..+@@@@@@@@@@+..+@@+.  .+@@+..+@@+.  .+@@+..+@@++@@++@@+.",
".+@@@@@@@@@@+..+@@@@@@@@@+. .+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@+.  .+@@+..+@@+.  .+@@+..+@@++@@++@@+.",
".+@@++++++@@+..+@@+++++@@+. .+@@++++++@@+..+@@++++++++.  .++++@@++++. .+@@+.  .+@@+..+@@+.  .+@@+..+@@++@@++@@+.",
".+@@++++++@@+..+@@+...+@@+. .+@@++++++@@+..+@@@@@@@@@+.   ...+@@+...  .+@@+.  .+@@+..+@@+.  .+@@+..+@@++@@++@@+.",
".+@@@@@@@@@@+..+@@+...+@@+. .+@@@@@@@@@+.  .+@@@@@@@@@+.    .+@@+.    .+@@+....+@@+..+@@+....+@@+..+@@++@@++@@+.",
".+@@@@@@@@@+. .+@@+++++@@+. .+@@@@@@@@@+.  .++++++++@@+.    .+@@+.    .+@@++++++@@+..+@@++++++@@+..+@@++@@++@@+.",
".+@@+++++++.  .+@@@@@@@@@@+..+@@+++++@@@+..+@@@@@@@@@@+.    .+@@+.    .+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+.",
".+@@+......    .+@@@@@@@@@+..+@@+....+@@+..+@@@@@@@@@+.     .+@@+.     .+@@@@@@@@+. .+@@@@@@@@@+. .+@@@@@@@@@+. ",
" .++.           .+++++++++.  .++.    .++.  .+++++++++.       .++.       .++++++++.   .+++++++++.   .+++++++++.  ",
"  ..             .........    ..      ..    .........         ..         ........     .........     .........   ",
"  ..      ..    ..      ..    ..........       ....        ..              ....           ..                    ",
" .++.    .++.  .++.    .++.  .++++++++++.     .++++.      .++.            .++++.        ..++..                  ",
".+@@+.  .+@@+..+@@+.  .+@@+..+@@@@@@@@@@+.   .+@@@@+.    .+@@+.          .+@@@@+.      .++@@++.                 ",
".+@@+....+@@+..+@@+....+@@+..+@@@@@@@@@@+.   .+@@@@+.    .+@@@+.         .+@@@@+.     .+@@@@@@+.                ",
".+@@++++++@@+..+@@++++++@@+. .++++++++@@+.   .+@@++.      .+@@@+.          .+@@+.     .+@@++@@+.                ",
" .+@@@@@@@@+. .+@@@@@@@@@@+. .+@@@@@@@@@+.   .+@@+.        .+@@@+.         .+@@+.      .++..++.                 ",
" .+@@@@@@@@+.  .+@@@@@@@@@+..+@@@@@@@@@+.    .+@@+.         .+@@@+.        .+@@+.       ..  ..      ..........  ",
".+@@++++++@@+.  .+++++++@@+..+@@++++++++.    .+@@+.          .+@@@+.       .+@@+.                  .++++++++++. ",
".+@@+....+@@+. .+@@@@@@@@@+..+@@@@@@@@@@+.   .+@@@@+.         .+@@@+.    .+@@@@+.                 .+@@@@@@@@@@+.",
".+@@+.  .+@@+. .+@@@@@@@@+. .+@@@@@@@@@@+.   .+@@@@+.          .+@@+.    .+@@@@+.                 .+@@@@@@@@@@+.",
" .++.    .++.   .++++++++.   .++++++++++.     .++++.            .++.      .++++.                   .++++++++++. ",
"  ..      ..     ........     ..........       ....              ..        ....                     ..........  ",
"    ..           ........     ..             .........            ..     ........        ......      .........  ",
"   .++.         .++++++++.   .++.           .+++++++++.          .++.   .++++++++.      .++++++.    .+++++++++. ",
"  .+@@+.       .+@@@@@@@@+. .+@@+......    .+@@@@@@@@@+.   ......+@@+. .+@@@@@@@@+.    .+@@@@@@+.  .+@@@@@@@@@+.",
"  .+@@@+.      .+@@@@@@@@@+..+@@+++++++.  .+@@@@@@@@@@+.  .+++++++@@+..+@@@@@@@@@@+.  .+@@@@@@@+. .+@@@@@@@@@@+.",
"   .+@@+.       .+++++++@@+..+@@@@@@@@@+. .+@@++++++++.  .+@@@@@@@@@+..+@@++++++@@+.  .+@@++++++. .+@@++++++@@+.",
"    .++.       .+@@@@@@@@@+..+@@@@@@@@@@+..+@@+.......  .+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+.",
"     ..       .+@@@@@@@@@@+..+@@++++++@@+..+@@+.......  .+@@++++++@@+..+@@@@@@@@@@+..+@@@@@@@@@@+. .+@@@@@@@@@+.",
"              .+@@++++++@@+..+@@++++++@@+..+@@++++++++. .+@@++++++@@+..+@@+++++++.   .++@@++++++.   .+++++++@@+.",
"              .+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@+.   .+@@+.....   .+@@@@@@@@@+.",
"               .+@@@@@@@@@+..+@@@@@@@@@+.  .+@@@@@@@@@+. .+@@@@@@@@@+. .+@@@@@@@@+.   .+@@+.       .+@@@@@@@@+. ",
"                .+++++++++.  .+++++++++.    .+++++++++.   .+++++++++.   .++++++++.     .++.         .++++++++.  ",
"                 .........    .........      .........     .........     ........       ..           ........   ",
"  ..                ..                ..    ..      ..        ..        .........     .........      ........   ",
" .++.              .++.              .++.  .++.    .++.      .++.      .+++++++++.   .+++++++++.    .++++++++.  ",
".+@@+......       .+@@+.            .+@@+..+@@+.  .+@@+.    .+@@+.    .+@@@@@@@@@+. .+@@@@@@@@@+.  .+@@@@@@@@+. ",
".+@@+++++++.      .+@@+.            .+@@+..+@@+....+@@+.    .+@@+.    .+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+.",
".+@@@@@@@@@+.      .++.       ..     .++. .+@@++++++@@+.    .+@@+.    .+@@++@@++@@+..+@@++++++@@+..+@@++++++@@+.",
".+@@@@@@@@@@+.    .+@@+.     .++.   .+@@+..+@@@@@@@@@@+.    .+@@+.    .+@@++@@++@@+..+@@+....+@@+..+@@+....+@@+.",
".+@@++++++@@+.    .+@@+.    .+@@+....+@@+..+@@@@@@@@@+.     .+@@+.    .+@@++@@++@@+..+@@+.  .+@@+..+@@+....+@@+.",
".+@@+....+@@+.    .+@@+.    .+@@++++++@@+..+@@++++@@+.      .+@@+.    .+@@++@@++@@+..+@@+.  .+@@+..+@@++++++@@+.",
".+@@+.  .+@@+.    .+@@+.    .+@@@@@@@@@@+..+@@+..+@@+.      .+@@+.    .+@@++@@++@@+..+@@+.  .+@@+..+@@@@@@@@@@+.",
".+@@+.  .+@@+.    .+@@+.     .+@@@@@@@@+. .+@@+..+@@+.      .+@@+.    .+@@++@@++@@+..+@@+.  .+@@+. .+@@@@@@@@+. ",
" .++.    .++.      .++.       .++++++++.   .++.  .++.        .++.      .++..++..++.  .++.    .++.   .++++++++.  ",
"  ..      ..        ..         ........     ..    ..          ..        ..  ..  ..    ..      ..     ........   ",
"  .........      .........     .........     .........      ..          ..      ..    ..      ..    ..  ..  ..  ",
" .+++++++++.    .+++++++++.   .+++++++++.   .+++++++++.    .++.        .++.    .++.  .++.    .++.  .++..++..++. ",
".+@@@@@@@@@+.  .+@@@@@@@@@+. .+@@@@@@@@@+. .+@@@@@@@@@+.  .+@@+.....  .+@@+.  .+@@+..+@@+.  .+@@+..+@@++@@++@@+.",
".+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+. .++@@++++++. .+@@+.  .+@@+..+@@+.  .+@@+..+@@++@@++@@+.",
".+@@++++++@@+..+@@++++++@@+..+@@++++++++. .+@@++++++++. .+@@@@@@@@@@+..+@@+.  .+@@+..+@@+.  .+@@+..+@@++@@++@@+.",
".+@@++++++@@+..+@@++++++@@+..+@@+.......  .+@@@@@@@@@+. .+@@@@@@@@@@+..+@@+.  .+@@+..+@@+.  .+@@+..+@@++@@++@@+.",
".+@@@@@@@@@@+..+@@@@@@@@@@+..+@@+.         .+@@@@@@@@@+. .++@@++++++. .+@@+....+@@+..+@@+....+@@+..+@@++@@++@@+.",
".+@@@@@@@@@+.  .+@@@@@@@@@+..+@@+.         .++++++++@@+.  .+@@++++++. .+@@++++++@@+..+@@++++++@@+..+@@++@@++@@+.",
".+@@+++++++.    .+++++++@@+..+@@+.        .+@@@@@@@@@@+.  .+@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+..+@@@@@@@@@@+.",
".+@@+......      ......+@@+..+@@+.        .+@@@@@@@@@+.    .+@@@@@@@+. .+@@@@@@@@+. .+@@@@@@@@@+. .+@@@@@@@@@+. ",
" .++.                  .++.  .++.          .+++++++++.      .+++++++.   .++++++++.   .+++++++++.   .+++++++++.  ",
"  ..                    ..    ..            .........        .......     ........     .........     .........   ",
"  ..      ..    ..      ..    ..........         ..           ..           ..            ..  .      .........   ",
" .++.    .++.  .++.    .++.  .++++++++++.       .++.         .++.         .++.          .++..+.    .+++++++++.  ",
".+@@+.  .+@@+..+@@+.  .+@@+..+@@@@@@@@@@+.     .+@@+.       .+@@+.       .+@@+.        .+@@++@+.  .+@@@@@@@@@@+.",
".+@@+....+@@+..+@@+....+@@+..+@@@@@@@@@@+.    .+@@@+.       .+@@+.       .+@@@+.      .+@@@@@@+.  .+@+@++++@+@+.",
".+@@++++++@@+..+@@++++++@@+. .++++++++@@+.    .+@@+.        .+@@+.        .+@@+.      .+@++@@+.   .+@+@++++@+@+.",
" .+@@@@@@@@+. .+@@@@@@@@@@+. .+@@@@@@@@@+.   .+@@@+.        .+@@+.        .+@@@+.      .+..++.    .+@+@@@@@@+@+.",
" .+@@@@@@@@+.  .+@@@@@@@@@+..+@@@@@@@@@+.    .+@@@+.        .+@@+.        .+@@@+.       .  ..     .+@++++++++@+.",
".+@@++++++@@+.  .+++++++@@+..+@@++++++++.     .+@@+.        .+@@+.        .+@@+.                  .+@+@@@@@@+@+.",
".+@@+....+@@+. .+@@@@@@@@@+..+@@@@@@@@@@+.    .+@@@+.       .+@@+.       .+@@@+.                  .+@+@++@@@+@+.",
".+@@+.  .+@@+. .+@@@@@@@@+. .+@@@@@@@@@@+.     .+@@+.       .+@@+.       .+@@+.                    .+@@@@@@@@@+.",
" .++.    .++.   .++++++++.   .++++++++++.       .++.         .++.         .++.                      .+++++++++. ",
"  ..      ..     ........     ..........         ..           ..           ..                        .........  "};
