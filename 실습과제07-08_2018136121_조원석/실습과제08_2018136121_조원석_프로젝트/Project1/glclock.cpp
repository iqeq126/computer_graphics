#include <gl/glut.h>
#include "gllc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_line() {
	glBegin(GL_LINES);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
}

void draw_plate() {
	for (int i = 0; i < 60; i++) {
		glPushMatrix();

		glRotatef(i * 6.0f, 0.0f, 0.0f, -1.0f);
		glTranslatef(0.75f, 0.0f, 0.0f);
		if (i % 5 == 0)
			glScalef(2.0f, 1.0f , 1.0f);
		glColor3f(0.0, 0.5, 0.0);
		draw_line();
		glPopMatrix();
	}
}

void draw_arm(float angle, float length) {
	glPushMatrix();
	glRotatef(-angle, 0.0f, 0.0f, 1.0f);
	glScalef(10 * length, 1.0f, 1.0f);
	glColor3f(0.0, 0.0, 0.0);
	draw_line();
	glPopMatrix();
}

void display() {
	struct tm* nowtime;
}