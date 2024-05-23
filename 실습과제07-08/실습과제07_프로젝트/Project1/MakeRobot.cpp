#include "Robot.h"
#include <gl/glut.h>
#include <gl/freeglut.h>
#include <windows.h>
static Mesh obj3D;	// Mesh 객체
static Robot robot; // Robot 객체
static bool bRobotRun = true;
static bool bMyRun = false;
//double rotate_y = 0;
//double rotate_x = 0;
//double zoom = 0.5;

void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix(); //현재의 변환행렬을 푸쉬(저장) 한다.
	glTranslatef(0.0, -1.0, 0.0); //y축으로 -1만큼 이동
	glBegin(GL_QUADS);
	glVertex3f(0.6, 0.0, 0.6);
	glVertex3f(0.6, 0.0, -0.6);
	glVertex3f(-0.6, 0.0, -0.6);
	glVertex3f(-0.6, 0.0, 0.6);
	glEnd(); //사각형 그리기 종료
	glPopMatrix();
}

void display() {
	glClearColor(0.99, 0.97, 0.97, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	robot.draw();
	glPopMatrix();
	/*
	// 3사분면 정면도
	glViewport(0, 0, 300, 300);
	glPushMatrix();
	robot.draw();
	DrawScene();
	glPopMatrix();

	// 4사분면 옆면 측면도
	glViewport(300, 0, 300, 300);
	glPushMatrix();
	gluLookAt(0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
	DrawScene();
	robot.draw();
	glPopMatrix();
	
	// 2사분면 평면도
	glViewport(0, 300, 300, 300);
	glPushMatrix();
	gluLookAt(0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0);
	DrawScene();
	robot.draw();
	glPopMatrix();
	
	// 1사분면 원거리 측면도
	glViewport(300, 300, 300, 300);
	glPushMatrix();
	gluLookAt(0.1, -0.1, 0.0, -5.0, 5.0, -5.0, 1.0, 1.0, 1.0); 
	DrawScene();
	robot.draw();
	glPopMatrix();
	*/
	if (bRobotRun == true) 
		robot.run();
	if (bMyRun == true)
		robot.myRun();
	Sleep(20);
	glutPostRedisplay();
	//obj3D.draw(80.0f, true);
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
/*
void mouseWheel(int wheel, int direction, int x, int y)
{
	wheel = 0;
	if (direction == -1)
	{
		printf("zoom : %lf\n", zoom);
		zoom -= 0.5;
	}
	else if (direction == +1)
	{
		printf("zoom : %lf\n", zoom);
		zoom += 0.5;
	}

	if (PrevX <= 300 && PrevY <= 300) {

	}
	else if (PrevX > 300 && PrevY <= 300) {
		//mouseWheel();
	}
	else if (PrevX <= 300 && PrevY > 300) {

	}
	else if (PrevX > 300 && PrevY > 300) {
		//mouseWheel();
	}
	glutPostRedisplay();
}*/
void keyboard(unsigned char key, int x, int y) {
	if (key == 'o') {
		printf("run on/off : %s\n", bRobotRun ? "on": "off");
		bRobotRun = !bRobotRun;
		if (bRobotRun == true && bMyRun == true)
			bMyRun = false;
	}
	else if (key == 'p') {
		printf("myrun on/off : %s\n", bMyRun ? "on" : "off");
		bMyRun = !bMyRun;
		if (bRobotRun == true && bMyRun == true)
			bRobotRun = false;
	}
	else if (key == 'i') {				// 초기화
		printf("객체 초기화(i)\n");
		glMatrixMode(GL_MODELVIEW);
		robot.reset();
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
		printf("크기 조절하기(%c)\n", key);
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
	//glutMouseWheelFunc(mouseWheel);
	initRendering();			// 조명값 설정
	//keyboard('i', 0, 0);
	//keyboard('l', 0, 0);		
	
	glutMainLoop(); // GLUT 루프
	return 0;
}