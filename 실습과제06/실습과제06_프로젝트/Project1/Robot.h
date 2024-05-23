#pragma once
#include "Mesh.h"

class Robot {
public:
	// 로봇의 부품
	Mesh Head, Body, RightArm, RightHand, LeftArm, LeftHand;
	Mesh RightLeg, RightFoot, LeftLeg, LeftFoot;
	
	float scale;			// 모델의 스케일

	Robot() { // 로봇 readAse 로딩 구현
		scale = 100;		// 좌표값이 -100 ~ 100 범위
		
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
	void resize(bool flag = true) { // z 구현 : 크기 다시 설정하기
		if (flag) scale *= 1.05f;
		else scale *= 0.95;
	}
	void draw() { // 로봇 조립해서 그리기
		Body.draw(0.5, 0.8, 0.8, scale, true);

		glPushMatrix(); // 몸통 좌표계 저장
		glTranslated(0.0, 0.45, -0.07);
		glScalef(1.1f, 1.1f, 1.1f);
		Head.draw(0.8, 0.7, 0.7, scale);
		glPopMatrix(); // 몸통 좌표계로 돌아가기

		glPushMatrix(); // 몸통 좌표계 저장
		glTranslated(-0.25, 0.32, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		RightArm.draw(0.4, 0.4, 0.8, scale);

		glPushMatrix(); // 오른어깨 좌표계 저장
		glTranslated(-0.05, -0.3, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		RightHand.draw(0.8, 0.8, 0.8, scale);
		glPopMatrix(); // 오른어깨 좌표계로 돌아가기
		glPopMatrix(); // 몸통 좌표계로 돌아가기

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