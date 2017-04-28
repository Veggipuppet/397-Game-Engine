#include "Graphics.h"
#include <string>
#include "Vector3.h"


int Graphics::screen_width;
int Graphics::screen_height;
double Graphics::elapsed_time_second;
int Graphics::fps;

Camera* Graphics::cam;
GameTime* Graphics::game_time;

ParticleEmmitter particleSystem;




void OpenGL::CreateGameWindow(int width, int height, char* window_name, int* argc, char* argv[]){
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	screen_width = width;
	screen_height = height;
	glutInitWindowSize(screen_width, screen_height);
	glutCreateWindow(window_name);

	Initialize();

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(OpenGLKeyboardDownFunc);
	glutKeyboardUpFunc(OpenGLKeyboardUpFunc);
	glutWarpPointer(width / 2, height / 2);
	glutPassiveMotionFunc(OpenGLPassiveMouseFunc);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutReshapeFunc(Reshape);

	glutMainLoop();
}

void OpenGL::Initialize(){
	// set background (sky colour)
	glClearColor(97.0 / 255.0, 140.0 / 255.0, 185.0 / 255.0, 1.0);
	particleSystem.createParticles();
}

void OpenGL::Display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	elapsed_time_second = game_time->GetElapsedTimeSecond();
	fps = game_time->GetFps();
	cam->SetCameraSpdWithDT(elapsed_time_second);
	cam->CheckCamera();
	CallLookAt();
	/*
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex3i(0, 0, 10);
		glVertex3i(10, 0, 10);
		glVertex3i(10, 10, 10);
		glVertex3i(0, 10, 10);
	glEnd();*/
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3i(100, -10, 100);
	glVertex3i(100, -10, -100);
	glVertex3i(-100, -10, -100);
	glVertex3i(-100, -10, 100);
	glEnd();
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	glVertex3i(0, 0, 10);
 
	glEnd();

	particleSystem.updateParticles();
	particleSystem.DrawParticles(particleSystem);

	//glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void OpenGL::Reshape(int width, int height){
	float ratio;

	screen_width = width;
	screen_height = height;

	// prevent divide by zero
	if (screen_height == 0) screen_height = 1;
	ratio = 1.0f * screen_width / screen_height;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, screen_width, screen_height);
	gluPerspective(45.0, ratio, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
}

void OpenGL::CallLookAt(){
	glLoadIdentity();
	gluLookAt(cam->GetCameraPos().x, cam->GetCameraPos().y, cam->GetCameraPos().z,
		cam->GetCameraLookAt().x, cam->GetCameraLookAt().y, cam->GetCameraLookAt().z,
		0, 1, 0);

}

Graphics* GraphicsFactory::Create(char* type){
	std::string type_str = type;
	if (type_str == "OpenGL"){
		return new OpenGL;
	}
	else if(type_str == "DirectX"){
		return new DirectX;
	}
	else{
		return NULL;
	}
}