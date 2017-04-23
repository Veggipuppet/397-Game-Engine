#include "Camera.h"

Camera::Camera(){
	camera_mov_spd = 10.0;
	camera_rot_spd = 5.0;

	MoveTo(Vector3(), Vector3());
}

void Camera::MoveTo(Vector3 new_pos, Vector3 new_rot){
	camera_pos = new_pos;
	camera_rot = new_rot;
	UpdateLookAt();
}

void Camera::UpdateLookAt(){


}