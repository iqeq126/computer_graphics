#include "Robot.h"
#include <gl/glut.h>

static Mesh obj3D;	// Mesh 객체
static Robot robot; // Robot 객체
// static bool bRobotRun = false; // 로봇 실행 여부

void display() {
	glClearColor(0.99, 0.97, 0.97, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	robot.draw();
	obj3D.draw(80.0f, true);
	glutSwapBuffers();
	glFlush();
}

static int PrevX, PrevY; // 이전 X, Y 좌표
void mouseClick(int button, int state, int x, int y) {
	printf("mouseClick : (%d, %d)\n",x, y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		PrevX = x;
		PrevY = y;
	}
}
void mouseMotion(GLint x, GLint y) {
	printf("mouseMotion : (%d, %d)\n", x, y);
	glMatrixMode(GL_MODELVIEW);
	glRotated(x - PrevX, 0, 1, 0);
	glRotated(y - PrevY, 1, 0, 0);
	PrevX = x;
	PrevY = y;
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
	/*
	if (key == 'l') {
		printf("파일 실행(ㅣ)\n");
		char* filename = glFileDlg(FILTER_ASE);
		if (filename != NULL)
			obj3D.readAse(filename);
//			obj3D.readAse("S_body.ase");
	}
	else*/if (key == 'i') {				// 초기화
		printf("객체 초기화(i)\n");
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	else if (key == 'w') {				// 투명화
		printf("투명화(w)\n");
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_POINT);
	}
	else if (key == 's') {				// 투명화 되돌리기
		printf("투명화 되돌리기(s)\n");
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_LINE);
	}
	else if (key == 'z' || key == 'Z') {	// z : 작아지기, Z : 커지기
		printf("크기 조절하기(z)\n");
		robot.resize(key == 'z');
	}
	else if (key == 'q') exit(0); // 나가기
	glutPostRedisplay();
}

void initRendering() {
	// 조명 처리
	GLfloat light_specular[] = { 0.8, 0.5, 0.8, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.5, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.8, 0.5, 0.8, 1.0 };
	GLfloat light_position[] = { 0.8, 0.5, 0.8, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	// Mesh의 재질
	GLfloat mat_specular[] = { 0.5, 1.0, 0.5, 1.0 };
	GLfloat mat_shininess[] = { 70.0 };
	GLfloat mat_color[] = { 0.5, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_shininess);

	glEnable(GL_LIGHTING);			// 조명 사용 설정
	glEnable(GL_LIGHT0);			// 조명 사용 설정
	glEnable(GL_NORMALIZE);			// 정규화

	glEnable(GL_DEPTH_TEST);		// depth 검사 (z-버퍼 사용)
	glShadeModel(GL_SMOOTH); 
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);  // GLUT 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("RobotWorld");

	// 콜백 설정
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);

	initRendering();			// 조명값 설정
	//keyboard('s', 0, 0);
	//keyboard('l', 0, 0);		
	
	glutMainLoop(); // GLUT 루프
	return 0;
}