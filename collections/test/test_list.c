#include "../../../common/defs.h"
#include "../inc/list.h"


int main () {

    List list = list_new();

    list_append(list , gen_type("3"));
    list_append(list , gen_type("1"));
    list_append(list , gen_type("2"));
    list_append(list , gen_type("5"));
    list_append(list , gen_type("4"));

    return 0;
}