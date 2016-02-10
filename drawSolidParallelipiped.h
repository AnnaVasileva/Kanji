#ifndef DRAWSOLIDPARALLELIPIPED_H_INCLUDED
#define DRAWSOLIDPARALLELIPIPED_H_INCLUDED

void drawSolidParallelipiped (float x,float y,float z,float a, float b, float c)
{
    a = a/2;
    b = b/2;
    c = c/2;
    // Рисуване на стена откъм -X
    glBegin( GL_POLYGON );
        glNormal3f(-1.0, 0.0, 0.0);
        glVertex3f(x-a, y-b, z-c);
        glVertex3f(x-a, y-b, z+c);
        glVertex3f(x-a, y+b, z+c);
        glVertex3f(x-a, y+b, z-c);
    glEnd();

    // Рисуване на стена откъм +Z
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, +1.0);
        glVertex3f(x-a, y-b, z+c);
        glVertex3f(x-a, y+b, z+c);
        glVertex3f(x+a, y+b, z+c);
        glVertex3f(x+a, y-b, z+c);
    glEnd();
}

#endif // DRAWSOLIDPARALLELIPIPED_H_INCLUDED
