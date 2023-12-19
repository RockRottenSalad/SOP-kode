#ifndef CAMERA_H
#define CAMERA_H

/*
 * CAMERA.H
 *
 * Defines the camera struct
 * The struct contains function pointers to all camera functions
 * This struct called giant_mat4 functions to generate the perspective matrix and LookAt matrix
 * References to these matrices can be acquired through the corresponding functions 
 *
 */

#include "giant-gml/giant-gml.h"

typedef void (*camFunc_ptr)(void);
typedef mat4_t* (*camFuncGetMat4_ptr)(void);
typedef void (*camFuncTurn_ptr)(double, double);

typedef struct
{
    // LookAt/Camera transforamtion matrix
    mat4_t view;
    // Perspective projection matrix
    mat4_t perspective;

    // Camera position
    vec3_t pos;
    // Camera direction
    vec3_t target;
    vec3_t center;
    vec3_t up;
    vec3_t buffer;

    float yaw, pitch;

    float camSpeed, camSens, fov, deltaTime;
    camFuncGetMat4_ptr getView;
    camFuncGetMat4_ptr getPerspective;
    camFunc_ptr updateCamera;
    camFuncTurn_ptr updateDirection;

    camFunc_ptr moveForward, moveBack, moveRight, moveLeft;

    // Mouse pos
    double lastX, lastY;

    // Window dimensions
    int winWidth, winHeight;
} camera_t;

extern camera_t camera;

void camera_init(int winWidth, int winHeight);

// Pointer to LookAt matrix
mat4_t* camera_getView(void);

// Pointer to perspective matrix
mat4_t* camera_getPerspective(void);

// Calculates new camera position and re-generates LookAt matrix
void camera_updateCamera(void);

// Changes camera direction from current mouse window coordinates
void camera_updateDirection(double x, double y);

void camera_moveForward(void);
void camera_moveBack(void);
void camera_moveRight(void);
void camera_moveLeft(void);

#endif
