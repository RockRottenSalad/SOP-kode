
#include "gfx/window.h"
// vao.h also includes vbo and ebo
#include "gfx/vao.h"
#include "gfx/shader.h"
#include "util/camera.h"
#include "util/eventhandler.h"
#include "giant-gml/giant-gml.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

float vertex[] = 
{
    0.5f, 0.5f, 0.5f, // top far right (0)
    0.5f, -0.5f, 0.5f, // bottom far right (1)
                    //
    0.5f, 0.5f, -0.5f, // top close right (2)
    0.5f, -0.5f, -0.5f, // bottom close right (3)

    -0.5, 0.5f, 0.5f, // top far left (4)
    -0.5f, -0.5f, 0.5f, // bottom far left (5)
                    //
    -0.5f, 0.5f, -0.5f, // top close left (6)
    -0.5f, -0.5f, -0.5f // bottom close left (7)
};

int n = 24;

int len = 36;

unsigned int indices[] = 
{
    0, 1, 2,
    2, 3, 1, // RIGHT PLANE

    3, 1, 7,
    7, 5, 1, // BOTTOM PLANE

    1, 0, 5,
    5, 0, 4, // BACK PLANE

    4, 6, 0,
    0, 2, 6, // TOP PLANE

    6, 7, 2,
    2, 3, 7, // FRONT PLANE

    7, 6, 5,
    5, 4, 6 // LEFT PLANE
};

float colors[][3] = 
{
  {1.0, 0.0, 0.0},
  {0.0, 1.0, 0.0},
  {0.0, 0.0, 1.0},

  {1.0, 1.0, 0.0},
  {0.0, 1.0, 1.0},
  {1.0, 0.0, 1.0},
  {1.0, 1.0, 1.0}
};

vec3_t vectors[] = 
{
  {2.0, 3.0, 1.0},
  {-2.0, 6.0, -4.0},
  {1.0, 2.0, -2.0},
  {3.0, 4.0, -3.0}
};

vec3_t rotate_vectors[] = 
{
  {0.5, 0.7, 0.2},
  {1.0, 0.0, 0.5},
  {0.1, 0.2, 0.7},
  {0.2, 0.4, 0.0}
};

float rotate_angle[] = 
{
  32.0f,
  160.0f,
  76.0f,
  90.0f
};

int main(int argc, char** argv)
{

    // # WINDOW
    window_init("GIANT-GML test", (ivec2_t){WINDOW_HEIGHT, WINDOW_WIDTH} );
    glfwSetCursorPosCallback(window.ptr, mouse_callback);
    glfwSetInputMode(window.ptr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // # CAMERA
    camera_init(WINDOW_WIDTH, WINDOW_HEIGHT);

    // # VAO, VBO, EBO
    VAO_init();
    vao.bind();

    VBO_init();
    vbo.bind();
    vbo.configure(vertex, n);

    vao.configure( ((struct Attribute) {
            .attribute = 0,
            .vertices = 3,
            .totalVertices = 3,
            .offset = 0
            }));

    EBO_init();
    ebo.bind();
    ebo.configure(indices, len);

    // # SHADER
    shader_init();
    vec3_t colortmp;
    giant_vec3_init(&colortmp);

    // # IDENTITY MATRIX AND FIRST PERSPECTIVE/VIEW MATRIX CALC
    mat4_t model = MAT4_IDENTITY_INIT;
    mat4_t model_rotate = MAT4_IDENTITY_INIT;

    glEnable(GL_DEPTH_TEST);
    // # START OF MAIN LOOP
    window.deltaB = window.deltaA = (float)glfwGetTime();
    //GLenum err;
    while(!glfwWindowShouldClose(window.ptr))
    {
        window.events();
        window.deltaB = (float)glfwGetTime();
        window.deltaTime = window.deltaB - window.deltaA;
        camera.deltaTime = window.deltaTime;
       // err = glGetError();
        //if(err != GL_NO_ERROR)
          //  printf("ERROR CODE: %d\n", err);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        camera.updateCamera();
        if(window.deltaTime >= 1.0 / 60.0)
        {
          for(unsigned int n = 0; n < 5; n++)
          {
            giant_mat4_identity_init(&model);
            giant_mat4_identity_init(&model_rotate);
            giant_mat4_translate(&model, vectors[n]);
            giant_mat4_rotate(&model_rotate, rotate_vectors[n], rotate_angle[n]);
            giant_mat4_mult(&model, model_rotate);

            shader.setTransFunc(&model, camera.getView(), camera.getPerspective());
            for(unsigned int i = 0; i < 7; i++)
            {
              giant_vec3_copy(colors[i], &colortmp);
              shader.set_color(colortmp);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,
                    (void*)((sizeof(unsigned int)) * (6*i) ));
            }
          }

            glfwSwapBuffers(window.ptr);
            window.deltaA = window.deltaB;
        }

        glfwPollEvents();
        keyboard_callback(window.ptr);
    }
    window.destroy();

    // # POST WINDOW EXIT CLEANUP
    shader.delete();
    vao.delete();
    vbo.delete();
    
    return 0;
}

