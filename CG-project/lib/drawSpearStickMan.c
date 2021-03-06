#include <GL/glut.h>

void drawSpearStickMan(float x, float y,
    float handX, float handY, float spearX, float spearY,
    float angle, float displacement, float color[]) {

    // body
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50 + y);
        glVertex2f(x -2, 150 + y);
        glVertex2f(x + 3, 150 + y);
        glVertex2f(x + 3, 50 + y);
    glEnd();

    // hands
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 120 + y);
        glVertex2f((x + handX) - 37 + displacement, 75 + y + handY);
        glVertex2f((x + handX) - 32 + displacement, 75 + y + handY);
        glVertex2f(x + 3, 120 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 120 + y);
        glVertex2f(x + 32 - displacement, 75 + y);
        glVertex2f(x + 37 - displacement, 75 + y);
        glVertex2f(x + 3, 120 + y);
    glEnd();

    // legs
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50 + y);
        glVertex2f(x - 37 + displacement, 0 + y);
        glVertex2f(x - 32 + displacement, 0 + y);
        glVertex2f(x + 3, 50 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50 + y);
        glVertex2f(x + 32 - displacement, 0 + y);
        glVertex2f(x + 37 - displacement, 0 + y);
        glVertex2f(x + 3, 50 + y);
    glEnd();

    // spear
    glPushMatrix();

    glTranslatef((x + handX - spearX) - 30, y + 75 + handY + spearY, 0.0);

    glRotatef(angle, 0.0, 0.0,1.0);

    if(displacement < 37)
        glTranslatef(0 - ((x + handX - spearX) - 30), 0 - (y + 75 + displacement + handY + spearY), 0.0);
    else
        glTranslatef(0 - ((x + handX - spearX) - 10), 0 - (y + 75 + displacement + handY + spearY), 0.0);

    // glTranslatef(0 - (x - 30), 0 - (y + 75 + displacement), 0.0);

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f((x + handX - spearX - 30) - 2 + displacement, y + 20 + handY + spearY);
        glVertex2f((x + handX - spearX - 30) + 2 + displacement, y + 20 + handY + spearY);
        glVertex2f((x + handX - spearX - 30) + 2 + displacement, 150 + y + handY + spearY);
        glVertex2f((x + handX - spearX - 30) - 2 + displacement, 150 + y + handY + spearY);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f((x + handX - spearX - 30) + 5 + displacement, 150 + y + handY + spearY);
        glVertex2f((x + handX - spearX - 30) + displacement, 180 + y + handY + spearY);
        glVertex2f((x + handX - spearX - 30) - 5 + displacement, 150 + y + handY + spearY);
    glEnd();

    glPopMatrix();

    glColor3f(color[0], color[1], color[2]);
    // face
    drawFilledCircle(x, 150 + y, 25);
}