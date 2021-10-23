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


#ifndef __UTILS_COLLECTIONS_INC_VECTOR_H
#define __UTILS_COLLECTIONS_INC_VECTOR_H

#include <stdio.h>
#include "../../../common/inc.h"

// #define USE_GEN_TYPE
typedef long long Vector;

/* capacity zero for default */
Vector   vec_new(size_t capacity);

Vector   vec_from_array(GenType* arr, size_t size);

Result   vec_pop(Vector vec);

Result   vec_push(Vector vec, GenType value);

Result   vec_get(Vector vec, size_t idx);

GenType* vec_to_array(Vector vec);

Bool     vec_is_empty(Vector vec);

Bool     vec_clear(Vector vec);

Bool     vec_print(Vector vec);

Bool     vec_reset(Vector vec, size_t capacity);

Bool     vec_set_capacity(Vector vec, size_t capacity);

Bool     vec_destroy(Vector* vec);

#endif // __UTILS_COLLECTIONS_INC_VECTOR_H