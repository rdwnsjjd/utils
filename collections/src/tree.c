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

#include "../inc/tree.h"

typedef struct _tree_node {
    Id                  id;
    Size                child_num;
    Size                row_num;
    GenType             data;
    struct _tree_node*  parent;
    struct _tree_node*  childs[];
}
_TreeNode;

typedef struct {
    _TreeNode*          root;
    Size                height;
}
_Tree;


Tree tree_new() {

    _Tree* tree = (_Tree*) malloc(sizeof(_Tree));
    soft_assert_ret_ptr(tree != INVALID_HNDL, "Allocation failed!");

    tree->root   = INVALID_HNDL;
    tree->height = 0;

    return (Tree)tree;
}


Result tree_insert(
    Tree    tree,
    GenType data,
    Idx     index
) {
    _Tree* _tree = (_Tree*) tree;

    soft_assert_ret_err(tree  != INVALID_ID,   "Invalid argument (tree is null)!");
    soft_assert_ret_err(_tree != INVALID_HNDL, "Invalid argument (tree is null)!");
}


// Result tree_insert_to(
//     Tree    tree,
//     GenType data,
//     Idx     index
// ) {
//     _Tree* _tree = (_Tree*) tree;

//     soft_assert_ret_err(tree  != INVALID_ID,   "Invalid argument (tree is null)!");
//     soft_assert_ret_err(_tree != INVALID_HNDL, "Invalid argument (tree is null)!");
// }