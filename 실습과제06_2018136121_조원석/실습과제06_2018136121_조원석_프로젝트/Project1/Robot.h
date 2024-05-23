#pragma once
#include "Mesh.h"

class Robot {
public:
	// �κ��� ��ǰ
	Mesh Head, Body, RightArm, RightHand, LeftArm, LeftHand;
	Mesh RightLeg, RightFoot, LeftLeg, LeftFoot;
	
	float scale;			// ���� ������

	Robot() { // �κ� readAse �ε� ����
		scale = 100;		// ��ǥ���� -100 ~ 100 ����
		
		printf("Loading Robot Models....\n");
		Head.readAse("s_Head.ASE");				printf("loading Head..........OK.\n");
		Body.readAse("S_Body.ASE");				printf("loading Body...........OK.\n");
		RightArm.readAse("S_RightArm.ASE");		printf("loading RightArm.......OK.\n");
		RightHand.readAse("S_RightHand.ASE");	printf("loading RightHand......OK.\n");
		LeftArm.readAse("S_LeftArm.ASE");		printf("loading LeftArm........OK.\n");
		LeftHand.readAse("S_LeftHand.ASE");		printf("loading LeftHand.......OK.\n");
		RightLeg.readAse("S_RightLeg.ASE");		printf("loading RightLeg.......OK.\n");
		RightFoot.readAse("S_RightFoot.ASE");	printf("loading RightFoot......OK.\n");
		LeftLeg.readAse("S_LeftLeg.ASE");		printf("loading LeftLeg........OK.\n");
		LeftFoot.readAse("S_LeftFoot.ASE");		printf("loading LeftFoot.......OK.\n");
	}
	void resize(bool flag = true) { // z ���� : ũ�� �ٽ� �����ϱ�
		if (flag) scale *= 1.05f;
		else scale *= 0.95;
	}
	void draw() { // �κ� �����ؼ� �׸���
		Body.draw(0.5, 0.8, 0.8, scale, true);

		glPushMatrix(); // ���� ��ǥ�� ����
		glTranslated(0.0, 0.45, -0.07);
		glScalef(1.1f, 1.1f, 1.1f);
		Head.draw(0.8, 0.7, 0.7, scale);
		glPopMatrix(); // ���� ��ǥ��� ���ư���

		glPushMatrix(); // ���� ��ǥ�� ����
		glTranslated(-0.25, 0.32, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		RightArm.draw(0.4, 0.4, 0.8, scale);

		glPushMatrix(); // ������� ��ǥ�� ����
		glTranslated(-0.05, -0.3, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		RightHand.draw(0.8, 0.8, 0.8, scale);
		glPopMatrix(); // ������� ��ǥ��� ���ư���
		glPopMatrix(); // ���� ��ǥ��� ���ư���

		glPushMatrix();
		glTranslated(0.25, 0.32, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		LeftArm.draw(0.4, 0.4, 0.8, scale);

		glPushMatrix();
		glTranslated(0.05, -0.3, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		LeftHand.draw(0.8, 0.8, 0.8, scale);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.1, -0.05, -0.02);
		glScalef(1.0f, 1.0f, 1.0f);
		RightLeg.draw(0.4, 0.4, 0.8, scale);

		glPushMatrix();
		glTranslated(0.0, -0.45, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		RightFoot.draw(0.8, 0.8, 0.8, scale);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.1, -0.05, -0.02);
		glScalef(1.0f, 1.0f, 1.0f);
		LeftLeg.draw(0.4, 0.4, 0.8, scale);

		glPushMatrix();
		glTranslated(0.0, -0.45, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		LeftFoot.draw(0.8, 0.8, 0.8, scale);
		glPopMatrix();
		glPopMatrix();
	}
};