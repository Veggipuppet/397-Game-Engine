#include "Vector3.h"

class Camera{
	public:
		Camera();
		Camera(const Camera &new_cam);
		~Camera(){};

	

	private:
		void MoveTo(Vector3 new_pos, Vector3 new_rot);
		void UpdateLookAt();

		Vector3 camera_pos;
		Vector3 camera_rot;
		float camera_mov_spd;
		float camera_rot_spd;
		Vector3 camera_look_at;
};