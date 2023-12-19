# giant-gml matematik biblioteket

> Her kan man se koden til mit matematik bibliotek "giant-gml"(Giant Is A Notably Tiny Graphics Math Library)

## Mapper
- lib

Indeholder alle header(.h) filer til projektet. Alle typer bliver defineret her
<br>
- src

Denne mappe indeholder alle source(.c) filer. Funktionerne bliver defineret her

## Hvordan det bruges

Mappen inde i `lib` bliver sat inde i en include folder. Mappen inde i `src` bliver lagt ind sammen med resten af ".c" filerne i projektet man bruge biblioteket til.
<br><br>
### Demostration

```
#include "giant-gml/giant-gml.h"


int main(int argc, char** argv)
{
    mat4_t mat1 = MAT4_IDENTITY_INIT;
    mat4_t mat2 = MAT4_IDENTITY_INIT;

    vec3_t vec = {2.0f, 1.0f, 0.0f};
    vec[Z] = -3.0f;

    
    giant_mat4_translate(&mat1, (vec3_t){2.0f, 1.0f, 3.3f});
    giant_mat4_rotate(&mat2, (vec3_t){0.5f,1.0f,0.2f}, 45.0f)

    giant_mat4_mult(&mat1, mat2);
    // Typecasts vec3_t to vec4_t with W = 1 
    giant_mat4_mult_vec3(mat1, &vec)

    printf("Value of vec is\n");
    giant_vec3_print(vec);

    printf("\n");

    printf("Value of mat1 is\n");
    giant_mat4_print(mat1);

    printf("\n");

    printf("Last element in mat1 is\n");
    printf("%f\n", mat1[3][3]);

    return 0;
}
```

`OUTPUT`
```
Value of vec is
3.351594 1.931360 2.264214

Value of mat1 is
0.763869        -0.010990       0.645278        0.000000
0.238039        0.934156        -0.265877       0.000000
-0.599868       0.356696        0.716189        0.000000
-0.213787       2.089273        3.388102        1.000000

Last element in mat1 is
1.000000

```
