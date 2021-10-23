#include "../inc/vector.h"

#define GEN_TYPE    int

int main() {
    // Vector vector = vec_new(0);
    // vec_push(vector, (GenType)"43");
    // vec_push(vector, (GenType)"12");
    // vec_push(vector, (GenType)"2134");
    // vec_push(vector, (GenType)"3");
    // vec_push(vector, (GenType)"7655");
    // vec_push(vector, (GenType)"4231321");

    GenType arr[7] = {2, 5, 2, 5, 7, 22, gen_type(7342)};
    Vector vector = vec_from_array((GenType*)arr, 7);

    // match_res(vec_get(vector, 3),
    //     Str a = data.str;,
    //     printf("Error");
    // )

    Result a = vec_pop(vector);
    soft_assert_res_ret_int(a, "Poping data failed!");
    Int32 s = res_get_data(a).i32;
    

    Bool b = vec_is_empty(vector);

    Result c = vec_pop(vector);
    soft_assert_res_ret_int(c, "Poping data failed!");

    // // int** arr = (char**)vec_to_array(vector);
    // vec_print(vector);

    vec_clear(vector);
    b = vec_is_empty(vector);
    // vec_reset(vector, 8);
    // b = vec_is_empty(vector);
    // vec_destroy(&vector);
    // b = vec_is_empty(vector);

    printf("salam\n");
}