/**
 * Copyright (C) 2021 rdwn
 * 
 * This file is part of utils.
 * 
 * utils is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * utils is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with utils.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __UTILS_COLLECTIONS_INC_SSTACK_H
#define __UTILS_COLLECTIONS_INC_SSTACK_H

#include "../common/inc.h"

typedef UInt64 SStack;

Result sstack_push(SStack sstack, GenType data);

Result sstack_pop(SStack sstack);

Result sstack_peek(SStack sstack);

#endif // __UTILS_COLLECTIONS_INC_SSTACK_H