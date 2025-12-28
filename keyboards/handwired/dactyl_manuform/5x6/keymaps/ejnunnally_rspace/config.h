/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define QUICK_TAP_TERM 0
#define TAPPING_TERM 100

#define MK_3_SPEED
#define MK_C_OFFSET_UNMOD 16
#define MK_C_INTERVAL_UNMOD 16
#define MK_C_OFFSET_0 1
#define MK_C_INTERVAL_0 32
#define MK_C_OFFSET_1 8
#define MK_C_INTERVAL_1 16
#define MK_C_OFFSET_2 16
#define MK_C_INTERVAL_2 16
#define MK_W_OFFSET_UNMOD 1
#define MK_W_INTERVAL_UNMOD 40
#define MK_W_OFFSET_0 1
#define MK_W_INTERVAL_0 360
#define MK_W_OFFSET_1 1
#define MK_W_INTERVAL_1 120
#define MK_W_OFFSET_2 1
#define MK_W_INTERVAL_2 20

// enables bootloader keys
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0
#define BOOTMAGIC_ROW_RIGHT 6
#define BOOTMAGIC_COLUMN_RIGHT 5

// enables handedness
#define EE_HANDS
