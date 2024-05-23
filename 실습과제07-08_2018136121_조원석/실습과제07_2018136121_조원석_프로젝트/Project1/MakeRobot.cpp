#include "Robot.h"
#include <gl/glut.h>
#include <gl/freeglut.h>
#include <windows.h>
static Mesh obj3D;	// Mesh ��ü
static Robot robot; // Robot ��ü
static bool bRobotRun = true;
static bool bMyRun = false;
//double rotate_y = 0;
//double rotate_x = 0;
//double zoom = 0.5;

void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix(); //������ ��ȯ����� Ǫ��(����) �Ѵ�.
	glTranslatef(0.0, -1.0, 0.0); //y������ -1��ŭ �̵�
	glBegin(GL_QUADS);
	glVertex3f(0.6, 0.0, 0.6);
	glVertex3f(0.6, 0.0, -0.6);
	glVertex3f(-0.6, 0.0, -0.6);
	glVertex3f(-0.6, 0.0, 0.6);
	glEnd(); //�簢�� �׸��� ����
	glPopMatrix();
}

void display() {
	glClearColor(0.99, 0.97, 0.97, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	robot.draw();
	glPopMatrix();
	/*
	// 3��и� ���鵵
	glViewport(0, 0, 300, 300);
	glPushMatrix();
	robot.draw();
	DrawScene();
	glPopMatrix();

	// 4��и� ���� ���鵵
	glViewport(300, 0, 300, 300);
	glPushMatrix();
	gluLookAt(0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
	DrawScene();
	robot.draw();
	glPopMatrix();
	
	// 2��и� ��鵵
	glViewport(0, 300, 300, 300);
	glPushMatrix();
	gluLookAt(0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0);
	DrawScene();
	robot.draw();
	glPopMatrix();
	
	// 1��и� ���Ÿ� ���鵵
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

static int PrevX, PrevY; // ���� X, Y ��ǥ
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
	else if (key == 'i') {				// �ʱ�ȭ
		printf("��ü �ʱ�ȭ(i)\n");
		glMatrixMode(GL_MODELVIEW);
		robot.reset();
		glLoadIdentity();
	}
	else if (key == 'w') {				// ����ȭ
		printf("����ȭ(w)\n");
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_POINT);
	}
	else if (key == 's') {				// ����ȭ �ǵ�����
		printf("����ȭ �ǵ�����(s)\n");
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_LINE);
	}
	else if (key == 'z' || key == 'Z') {	// z : �۾�����, Z : Ŀ����
		printf("ũ�� �����ϱ�(%c)\n", key);
		robot.resize(key == 'z');
	}
	else if (key == 'q') exit(0); // ������
	glutPostRedisplay();
}

void initRendering() {
	// ���� ó��
	GLfloat light_specular[] = { 0.8, 0.5, 0.8, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.5, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.8, 0.5, 0.8, 1.0 };
	GLfloat light_position[] = { 0.8, 0.5, 0.8, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	// Mesh�� ����
	GLfloat mat_specular[] = { 0.5, 1.0, 0.5, 1.0 };
	GLfloat mat_shininess[] = { 70.0 };
	GLfloat mat_color[] = { 0.5, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_shininess);

	glEnable(GL_LIGHTING);			// ���� ��� ����
	glEnable(GL_LIGHT0);			// ���� ��� ����
	glEnable(GL_NORMALIZE);			// ����ȭ

	glEnable(GL_DEPTH_TEST);		// depth �˻� (z-���� ���)
	glShadeModel(GL_SMOOTH); 
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);  // GLUT �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("RobotWorld");

	// �ݹ� ����
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);
	//glutMouseWheelFunc(mouseWheel);
	initRendering();			// ���� ����
	//keyboard('i', 0, 0);
	//keyboard('l', 0, 0);		
	
	glutMainLoop(); // GLUT ����
	return 0;
}