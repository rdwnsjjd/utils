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


#ifndef __UTILS_COLLECTIONS_INC_LIST_H
#define __UTILS_COLLECTIONS_INC_LIST_H

#include "../../../common/inc.h"

typedef Size List;

List   list_new();

Size   list_get_size(List list);

Result list_get_head(List list);

Result list_get_next(List list);


Result list_insert(
    List    list, 
    Size    index,
    GenType data
);


Result list_append(
    List    list, 
    GenType data
);


Result list_get(
    List list, 
    Size index
);


#define list_foreach(list_)    for(Result res = ok(1);;) { res = list_get_next(lexer->list); if (!res.is_ok) break; 
#define list_foreach_end()     }

#endif // __UTILS_COLLECTIONS_INC_LIST_H