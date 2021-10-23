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


#include "../inc/sstack.h"


typedef struct _sstack{
    GenType             data[DEFAULT_STACK_SIZE];
    Size                len;
}
_SStack;


Void sstack_init(SStack sstack) {
    _SStack* _sstack = (_SStack*) sstack;
    // _sstack->data = {0};
    _sstack->len  = 0;
}


Result sstack_push(SStack sstack, GenType data) {
    _SStack* _sstack = (_SStack*) sstack;
    soft_assert_ret_err(sstack       != 0, "Invalid argument (sstack is null)!");
    soft_assert_ret_err(_sstack      != INVALID_HNDL, "Invalid argument (sstack is null)!");
    soft_assert_wrn(    _sstack->len != DEFAULT_STACK_SIZE, "Invalid argument (sstack is full)!");

    _sstack->len++;
    _sstack->data[_sstack->len - 1] = data;
    return ok(_sstack->len);
}


Result sstack_pop(SStack sstack) {
    _SStack* _sstack = (_SStack*) sstack;
    soft_assert_ret_err(sstack       != 0, "Invalid argument (sstack is null)!");
    soft_assert_ret_err(_sstack      != INVALID_HNDL, "Invalid argument (sstack is null)!");
    soft_assert_ret_err(_sstack->len != 0, "Invalid argument (sstack is free)!");

    GenType top = _sstack->data[_sstack->len - 1];
    _sstack->len--;
    return ok(top);
}


Result sstack_peek(SStack sstack) {
    _SStack* _sstack = (_SStack*) sstack;
    soft_assert_ret_err(sstack       != 0, "Invalid argument (sstack is null)!");
    soft_assert_ret_err(_sstack      != INVALID_HNDL, "Invalid argument (sstack is null)!");
    soft_assert_ret_err(_sstack->len != 0, "Invalid argument (sstack is free)!");

    return ok(_sstack->data[_sstack->len - 1]);
}