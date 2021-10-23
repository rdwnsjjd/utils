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


#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "errno.h"

#include "../inc/vector.h"

#define DEFAULT_VEC_CAP     32

typedef struct vector{
    GenType*        _array;
    size_t          _capacity;
    size_t          _size;
}
_Vector;


Vector vec_new(size_t capacity) {

    if (capacity == 0) {
        capacity = DEFAULT_VEC_CAP;
    }

    _Vector* vec = (_Vector*) malloc(sizeof(_Vector));
    soft_assert_ret_id(vec != INVALID_HNDL, "Allocation failed (%s)!", strerror(errno));
    
    vec->_array = (GenType*) malloc(sizeof(GenType) * capacity);
    soft_assert_ret_id(vec->_array != INVALID_HNDL, "Allocation failed (%s)!", strerror(errno));

    vec->_capacity = capacity;
    vec->_size     = 0;
    
    return (Vector)vec;
}


Result _vec_reallocation(_Vector** vector) {

    size_t reallocation_size = sizeof(GenType) * ((*vector)->_capacity + (*vector)->_capacity);
    
    (*vector)->_array = (GenType*) realloc(*vector, reallocation_size);
    soft_assert_ret_err((*vector)->_array != INVALID_HNDL, "Reallocation failed (%s)!", strerror(errno));

    (*vector)->_capacity = reallocation_size;
    return ok(reallocation_size);
}


Result vec_push(Vector vec, GenType value) {

    _Vector* vector = (_Vector*) vec;
    soft_assert_ret(
        vec != 0 || vector != INVALID_HNDL, 
        err(EK_Allcf, 0), 
        "Invalid Argument (the given vector is null)!"
    );

    if (vector->_capacity == vector->_size) {
        soft_assert_res_ret_err(_vec_reallocation(&vector), "Internal array reallocation failed!");
    }
    
    *(vector->_array + vector->_size) = value;
    vector->_size++;
    
    return ok(value);
}


Result vec_pop(Vector vec) {

    _Vector* vector = (_Vector*) vec;
    soft_assert_ret(
        vec != 0 || vector != INVALID_HNDL, 
        err(EK_Allcf, 0), 
        "Invalid Argument (the given vector is null)!"
    );
    soft_assert_ret_err( 
        vector->_size != 0,
        "Empty target (the given vector is empty)!"
    );
    
    return ok(vector->_array[--(vector->_size)]);
}


Result vec_get(Vector vec, size_t idx) {

    _Vector* vector = (_Vector*) vec;
    soft_assert_ret(
        vec != 0 || vector != INVALID_HNDL, 
        err(EK_Allcf, 0), 
        "Invalid Argument (the given vector is null)!"
    );
    soft_assert_ret_err( 
        vector->_size >= idx,
        "Empty target (the given vector is empty)!"
    );
    
    return ok(vector->_array[idx]);
}


Bool vec_is_empty(Vector vec) {

    _Vector* vector = (_Vector*) vec;
    soft_assert(
        vec != 0 || vector != INVALID_HNDL,
        "Invalid Argument (the given vector is null)!"
    );
    
    return vector->_size == 0L;
}


Bool vec_clear(Vector vec) {

    _Vector* vector = (_Vector*) vec;
    soft_assert(
        vec != 0 || vector != INVALID_HNDL,
        "Invalid Argument (the given vector is null)!"
    );

    vector->_size = 0L;
    return True;
}


Bool vec_reset(Vector vec, size_t capacity) {

    _Vector* vector = (_Vector*) vec;
    soft_assert(
        vec != 0 || vector != INVALID_HNDL,
        "Invalid Argument (the given vector is null)!"
    );

    vector->_size = 0L;
    vector->_capacity = capacity;
    return True;
}


Bool vec_set_capacity(Vector vec, size_t capacity) {

    _Vector* vector = (_Vector*) vec;
    soft_assert(
        vec != 0 || vector != INVALID_HNDL,
        "Invalid Argument (the given vector is null)!"
    );

    vector->_capacity = capacity;
    return True;
}


GenType* vec_to_array(Vector vec) {

    _Vector* vector = (_Vector*) vec;
    soft_assert_ret_ptr(
        vec != 0 || vector != INVALID_HNDL,
        "Invalid Argument (the given vector is null)!"
    );

    GenType* arr = (GenType*) malloc(vector->_size * sizeof(GenType));
    if (arr == INVALID_HNDL) {
        printf("[   ERROR   ] Allocation failed (%s)!", strerror(errno));
        return INVALID_HNDL;
    }

    return arr;
}


Bool vec_print(Vector vec) {

    _Vector* vector = (_Vector*) vec;
    soft_assert(
        vec != 0 || vector != INVALID_HNDL,
        "Invalid Argument (the given vector is null)!"
    );

    printf("[");
    for (size_t i = 0; i < vector->_size - 1; i++) {
        printf("%d, ", vector->_array[i].i32);
    }
    printf("%d", vector->_array[vector->_size].i32);
    printf("]\n");
    

    return True;
}


Vector vec_from_array(GenType* arr, size_t size) {

    debug_wrn("Do not use this function yet!");
    
    soft_assert_ret_ptr(
        arr != INVALID_HNDL,
        "Invalid Argument (the given array is null)!"
    );

    Vector vec = vec_new(DEFAULT_VEC_CAP);
    // soft_assert_ret_ptr(vec != 0, "Creating new vector failed!";
    
    for (size_t idx = 0; idx < size; idx++) {
        soft_assert_res_ret_ptr(vec_push(vec, (GenType)arr[idx]), "Pushing into vector failed!");
    }
    
    return vec;
}


Bool vec_destroy(Vector* vec) {

    _Vector* vector = (_Vector*) *vec;
    if (vec == 0 || vector == INVALID_HNDL) {
        printf("[   ERROR   ] Invalid argument (given vector is INVALID_HNDL)!\n");
        return False;
    }

    free(vector->_array);
    free(vector);
    *vec = 0;

    return True;
}