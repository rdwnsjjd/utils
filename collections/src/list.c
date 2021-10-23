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


#include <stdlib.h>

#include "../inc/list.h"
#include "../../../common/inc.h"

Idx GB_index_value = 0;

typedef struct list_node {
    Size              index;
    GenType           data;
    struct list_node* next;
    struct list_node* prev;
}
_ListNode;

typedef struct {
    _ListNode*      first;
    _ListNode*      last;
    Size            size;
}
_List;


List list_new() {
    _List* list = (_List*) malloc(sizeof(_List));
    soft_assert_ret_int(list != INVALID_HNDL, "Allocation failed!");

    list->size  = 0; 
    list->first = INVALID_HNDL;
    list->last  = INVALID_HNDL;

    return (List) list;
}


_ListNode* _list_node_new(Size index, GenType data) {
    _ListNode* node = (_ListNode*) malloc(sizeof(_ListNode));
    soft_assert_ret_ptr(node != INVALID_HNDL, "Allocation failed!");

    node->index = index;
    node->data  = data;
    node->next  = INVALID_HNDL;
    node->prev  = INVALID_HNDL;

    return node;
}


Result list_insert(
    List    list, 
    Size    index,
    GenType data
) {
    _List* _list = (_List*) list;
    soft_assert_ret_err(list  != 0,            "Invalid argument (list is null)!");
    soft_assert_ret_err(_list != INVALID_HNDL, "Invalid argument (list is null)!");
    soft_assert_ret_err(index <= _list->size,  "Invalid argument (index is bigger than current list size)!");

    if (_list->size == 0) {
        _list->first = _list_node_new(0, data);
        soft_assert_ret_err(
            _list->first != INVALID_HNDL, 
            "Creating new list node failed!"
        );
        _list->last        = _list->first;
        _list->first->next = INVALID_HNDL;
        _list->first->prev = INVALID_HNDL;
    }

    else if (index == _list->size) {
        _ListNode* current_node = _list_node_new(_list->size, data);
        soft_assert_ret_err(
            current_node != INVALID_HNDL, 
            "Creating new list node failed!"
        );
        current_node->next = INVALID_HNDL;
        current_node->prev = _list->last;
        _list->last->next  = current_node;
        _list->last        = current_node;
    }
    
    else {
        // if (_list->size >= 2 * index) {
            _ListNode* tmp = _list->first;
            for (Size idx = 0; idx < _list->size; idx++) {

                if (idx == index) {

                    _ListNode* prev_node    = tmp->prev;
                    _ListNode* current_node = _list_node_new(index, data);
                    soft_assert_ret_err(
                        current_node != INVALID_HNDL, 
                        "Creating new list node failed!"
                    );

                    if (prev_node != INVALID_HNDL) 
                        prev_node->next = current_node;
                    else
                        _list->first    = current_node;
                    
                    current_node->next = tmp;
                    current_node->prev = prev_node;
                    tmp->prev          = current_node;
                    break;
                }
                tmp = tmp->next;
            }
        // }
        // else {
        //     _ListNode* tmp = _list->last;
        //     for (Size idx  = _list->size - 1; idx >= 0; idx--) {

        //         if (index == idx) {
        //             _ListNode* prev_node    = tmp->prev;
        //             _ListNode* current_node = _list_node_new(index, data);
        //             soft_assert_ret_err(
        //                 current_node != INVALID_HNDL, 
        //                 "Creating new list node failed!"
        //             );
        //             current_node->next = tmp;
        //             current_node->prev = prev_node;
        //             prev_node->next    = current_node;
        //             break;
        //         }
        //         tmp = tmp->prev;
        //     }
        // }
    }

    _list->size++;
    return ok(data);
}



Result list_append(
    List list, 
    GenType data
) {
    _List* _list = (_List*) list;
    soft_assert_ret_err(list  != 0,            "Invalid argument (list is null)!");
    soft_assert_ret_err(_list != INVALID_HNDL, "Invalid argument (list is null)!");

    soft_assert_res_ret_err(list_insert(list, _list->size, data), "Insertion failed!");
    return ok(data);
}


Result list_get(
    List list, 
    Size index
) {
    _List* _list = (_List*) list;
    soft_assert_ret_err(list  != 0,            "Invalid argument (list is null)!");
    soft_assert_ret_err(_list != INVALID_HNDL, "Invalid argument (list is null)!");
    soft_assert_ret_err(index <= _list->size , "Invalid argument (index is bigger than current list size)!");

    _ListNode* cur = _list->first;
    for (Size idx = 0; idx < _list->size; idx++) {
        
        if (idx == index) {
            return ok(cur->data);
        }
        cur = cur->next;
    }
    return err(EK_Not_Found, 0);
}


Size list_get_size(List list) {
    _List* _list = (_List*) list;
    soft_assert_ret_id(list  != 0,            "Invalid argument (list is null)!");
    soft_assert_ret_id(_list != INVALID_HNDL, "Invalid argument (list is null)!");
    return _list->size;
}


Result list_get_head(
    List list
) {
    _List* _list = (_List*) list;
    soft_assert_ret_err(list  != 0,            "Invalid argument (list is null)!");
    soft_assert_ret_err(_list != INVALID_HNDL, "Invalid argument (list is null)!");
 
    GB_index_value = 0;
    return ok(_list->first->data);
}


Result list_get_next(
    List list
) {
    _List* _list = (_List*) list;
    soft_assert_ret_err(list  != 0,            "Invalid argument (list is null)!");
    soft_assert_ret_err(_list != INVALID_HNDL, "Invalid argument (list is null)!");
 
    return list_get(list, GB_index_value++);
}