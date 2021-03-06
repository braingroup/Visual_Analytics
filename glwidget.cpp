#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{

}

void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 1);
}
void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, -0.5, 0);
        glColor3f(0,1,0);
        glVertex3f( 0.5, -0.5, 0);
        glColor3f(0,0,1);
        glVertex3f( 0.0,  0.5, 0);
    glEnd();
}
void GLWidget::resize(int w, int h){

}
