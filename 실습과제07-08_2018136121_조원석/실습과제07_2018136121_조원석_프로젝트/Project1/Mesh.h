#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <gl/glut.h>
#include <iostream>
#include "gllc.h"
using namespace std;

struct Vertex { // Vertex: x, y, z의 위치값
    float x, y, z;
};
struct Face { // Face: vertex 3개의 인덱스
    int vi[3];
};
struct Normal { // Normal: face와 세 정점의 법선벡터
    float norFace[3];
    float norV1[3], norV2[3], norV3[3];
};

class Mesh { // Mesh 클래스
    int nVtx = 0; // Vertex 개수
    Vertex* vertex = NULL; // Vertex 리스트
    int nFace = 0; // Face 개수
    Face* face = NULL; // Face 리스트
    Normal* normal = NULL; // Normal 리스트

public:
    Mesh() {}
    ~Mesh() { clearAse(); }
    void clearAse() { // -> vertex, face, normal 리스트의 동적 할당 해제
        if (nVtx != 0) // Vertex가 남아있을 때
            delete[] vertex;
        if (nFace != 0) { // Face가 남아있을 때
            delete[] face;
            delete[] normal;
        }
        nVtx = nFace = 0;   // 초기화
    }
    void readAse(const char* fileName) { // ASE file load
        FILE* fp; // 객체 선택 파일 포인터
        char line[256], str[40]; // 한 라인과 문자열 버퍼
        float _x, _y, _z; // 객체 정점 정보
        int num = 0;  // 읽어올 정점 개수

        if ((fp = fopen(fileName, "r")) == NULL) { // 파일 열기 오류 탐지
            cout << "File is Not Found" << endl;
            return;
        }
        while (fgets(line, 256, fp) != NULL) {
            sscanf(line, "%s", str);
            if (strcmp(str, "*MESH") == 0) { // "MESH"라는 문자가 나올 때까지 계속
                fgets(line, 256, fp); // *TIMEVALUE
                fgets(line, 256, fp); // *MESH NUMVERTEX
                sscanf(line, "%s%d", str, &nVtx);
                fgets(line, 256, fp); // *MESH NUMFACES
                sscanf(line, "%s %d", str, &nFace);

                vertex = new Vertex[nVtx]; // vertex 리스트 동적할당
                face = new Face[nFace]; // face 리스트 동적할당
                normal = new Normal[nFace]; // normal 리스트 동적할당

                fgets(line, 256, fp); // *MESH_VERTEX_LIST
                sscanf(line, "%s", str);
                if (strcmp(str, "*MESH_VERTEX_LIST") == 0) { // *MESH_VERTEX_LIST와 같을 때
                    for (int i = 0; i < nVtx; i++) { // vertex의 x, y, z좌표
                        fgets(line, 256, fp); // 각 정점 정보 읽기
                        sscanf(line, "%s%d%f%f%f", str, &num, &_x, &_y, &_z);
                        vertex[i].x = _x;
                        vertex[i].y = _z;
                        vertex[i].z = _y;
                    }
                }
                fgets(line, 256, fp); // Read the Line '}'
                fgets(line, 256, fp); // Read the Line *MESH_VERTEX_LIST
                sscanf(line, "%s", str);
                if (strcmp(str, "*MESH_FACE_LIST") == 0) {
                    for (int i = 0; i < nFace; i++) { // face의 vertex 인덱스 데이터
                        fgets(line, 256, fp); // Read the Line *MESH_VERTEX_LIST
                        sscanf(line, "%s%s%s%d%s%d%s%d%s%d%s%d%s%d%s",
                            str, str, str,
                            &(face[i].vi[0]), str,
                            &(face[i].vi[1]), str,
                            &(face[i].vi[2]), str,
                            &num, str, &num, str, &num, str);
                    }
                }
                fgets(line, 256, fp); // Read the Line '}'
                fgets(line, 256, fp); // Read the Line *MESH_NUMCVERTEX
                sscanf(line, "%s", str);
                if (strcmp(str, "*MESH_NUMCVERTEX") == 0) { // 내용이 *MESH_NUMCVERTEX와 같을 때
                    fgets(line, 256, fp); // 다시 *MESH_NORMALS를 위한 라인을 읽어오기 위해 사용
                    sscanf(line, "%s", str);
                }
                if (strcmp(str, "*MESH_NORMALS") == 0) { // normal 의 법선벡터 데이터 출력
                    for (int i = 0; i < nFace; i++) {
                        float* nF = normal[i].norFace;
                        float* nV1 = normal[i].norV1;
                        float* nV2 = normal[i].norV2;
                        float* nV3 = normal[i].norV3;

                        fgets(line, 256, fp); // Read the Line *MESH_FACENORMAL
                        sscanf(line, "%s%d%f%f%f", str, &num, nF, nF + 1, nF + 2);
                        fgets(line, 256, fp); // Read the Line *MESH_VERTEXNORMAL 1
                        sscanf(line, "%s%d%f%f%f", str, &num, nV1, nV1 + 1, nV1 + 2);
                        fgets(line, 256, fp); // Read the Line *MESH_VERTEXNORMAL 2
                        sscanf(line, "%s%d%f%f%f", str, &num, nV2, nV2 + 1, nV2 + 2);
                        fgets(line, 256, fp); // Read the Line *MESH_VERTEXNORMAL 3
                        sscanf(line, "%s%d%f%f%f", str, &num, nV3, nV3 + 1, nV3 + 2);
                    }
                }
                break;
            }
        }
        fclose(fp);
    }
    void draw(float scale = 1.0f, bool bCoord = false) { // 객체를 그리기
        glBegin(GL_TRIANGLES); // 객체 그리기 시작
        for (int i = 0; i < nFace; i++) {
            // 객체 생성 : face
            Vertex* v1 = &vertex[face[i].vi[0]];
            Vertex* v2 = &vertex[face[i].vi[1]];
            Vertex* v3 = &vertex[face[i].vi[2]];
            // 법선 벡터 정보 얻어와서 그리기 : normal
            glNormal3fv(normal[i].norV1);
            glVertex3f(v1->x / scale, v1->y / scale, v1->z / scale);
            glNormal3fv(normal[i].norV2);
            glVertex3f(v2->x / scale, v2->y / scale, v2->z / scale);
            glNormal3fv(normal[i].norV3);
            glVertex3f(v3->x / scale, v3->y / scale, v3->z / scale);
        }
        glEnd(); // 객체 그리기 끝
        if (bCoord) // bCoord가 활성화되어있을 때
            glDrawCoord(1.0); // 객체를 그림
    }
    // 객체에 색 지정하기
    void setColor(float r, float g, float b, float a) {
        float color[4] = { r, g, b, a };
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    }
    // 색을 지정해서 객체를 그리기
    void draw(float r, float g, float b, float scale = 1.0f, bool bCoord = false) { //
        setColor(r, g, b, 1.0);
        draw(scale, bCoord);
    }
};

