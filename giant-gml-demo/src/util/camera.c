
#include "camera.h"

camera_t camera;

void camera_init(int winWidth, int winHeight)
{
    camera.getView = camera_getView;
    camera.getPerspective = camera_getPerspective;
    camera.updateCamera = camera_updateCamera;
    camera.updateDirection = camera_updateDirection;
    camera.moveForward = camera_moveForward;
    camera.moveBack = camera_moveBack;
    camera.moveRight = camera_moveRight;
    camera.moveLeft = camera_moveLeft;

    camera.winWidth = winWidth;
    camera.winHeight = winHeight;

    // Camera stating point
    camera.pos[X] = 0.0f;
    camera.pos[Y] = 0.0f;
    camera.pos[Z] = 0.0f;

    // Camera starting direction(cannot be zero)
    camera.target[X] = 0.0f;
    camera.target[Y] = 0.0f;
    camera.target[Z] = -1.0f;

    camera.up[X] = 0.0f;
    camera.up[Y] = 1.0f;
    camera.up[Z] = 0.0f;

    // Scalar to prevent camera from moving/rotating too fast
    camera.camSpeed = 0.01f;
    camera.camSens = 0.1f;
    camera.fov = 110.0f;

    camera.yaw = -90.0f;
    camera.pitch = 0.0f;

    // Sets mouse coordinates to center of screen to prevent sudden camera flick
    // on start
    camera.lastX = camera.winWidth/2;
    camera.lastY = camera.winHeight/2;

}

// Pointer to LookAt matrix
mat4_t* camera_getView(void)
{
    return &camera.view;
}

// Pointer to perspective matrix
mat4_t* camera_getPerspective(void)
{
    return &camera.perspective;
}

// Calculates new camera position and re-generates LookAt matrix
void camera_updateCamera(void)
{
    giant_mat4_identity_init(&camera.view);
    giant_mat4_identity_init(&camera.perspective);

    giant_mat4_lookat(&camera.view, camera.pos, camera.target);

    // 0.5f = near z/near plane, 1000.0f = far plane
    // 1920.0f/1080.0f = aspec ratio
    //giant_mat4_perspective(&camera.perspective, 0.5f, 1000.0f, 1920.0f/1080.0f);
    giant_mat4_perspective_fov(&camera.perspective, 0.5f, 1000.0f, ((float)camera.winWidth/camera.winHeight), camera.fov);
}

// Changes camera direction from current mouse window coordinates
void camera_updateDirection(double x, double y)
{
    camera.yaw += (x - camera.lastX) * camera.camSens;
    camera.pitch += (camera.lastY - y) * camera.camSens;
    camera.lastX = x;
    camera.lastY = y;

    // Limit pitch to +-89 degrees
    if(camera.pitch > 89.0f)
        camera.pitch = 89.0f;
    if(camera.pitch < -89.0f)
        camera.pitch = -89.0f;

    camera.target[X] = cos(camera.yaw * DEG2RAD) * cos(camera.pitch * DEG2RAD);
    camera.target[Y] = sin(camera.pitch * DEG2RAD);
    camera.target[Z] = sin(camera.yaw * DEG2RAD) * cos(camera.pitch * DEG2RAD);

    camera.updateCamera();
}

void camera_moveForward(void)
{
    giant_vec3_init(&camera.buffer);
    giant_vec3_normalize(&camera.buffer);
    giant_vec3_scale_to(camera.target, (camera.camSpeed * camera.deltaTime), &camera.buffer);
    giant_vec3_add(&camera.pos, camera.buffer);
}

void camera_moveBack(void)
{
    giant_vec3_init(&camera.buffer);
    giant_vec3_normalize(&camera.buffer);
    giant_vec3_scale_to(camera.target, (camera.camSpeed * camera.deltaTime), &camera.buffer);
    giant_vec3_sub(&camera.pos, camera.buffer);
}

void camera_moveRight(void)
{
    giant_vec3_init(&camera.buffer);
    giant_vec3_cross_to(camera.target, camera.up, &camera.buffer);
    giant_vec3_normalize(&camera.buffer);
    giant_vec3_scale(&camera.buffer, (camera.camSpeed * camera.deltaTime));
    giant_vec3_add(&camera.pos, camera.buffer);
}

void camera_moveLeft(void)
{
    giant_vec3_init(&camera.buffer);
    giant_vec3_cross_to(camera.target, camera.up, &camera.buffer);
    giant_vec3_normalize(&camera.buffer);
    giant_vec3_scale(&camera.buffer, (camera.camSpeed * camera.deltaTime));
    giant_vec3_sub(&camera.pos, camera.buffer);
}
