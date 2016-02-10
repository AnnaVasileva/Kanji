#include <cstdlib>
#include <GL/glfw.h>
#include <cmath>
#include "drawSmoothCylinderPart.h"
#include "drawSolidParallelipiped.h"

bool running()
{
    return( !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam( GLFW_OPENED) );
}

void init()
{
    int width, height;

    glfwInit();
    if( !glfwOpenWindow( 640, 480, 0, 0, 0, 0, 8, 0, GLFW_WINDOW ) ) return;

    glfwGetWindowSize( &width, &height );
    height = height > 0 ? height : 1;

    glViewport( 0, 0, width, height );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 65.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 10.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f );
}

void finit()
{
    glfwTerminate();
}
struct OKG_POINT
{
    float x;
    float y;
    float z;
} ;

OKG_POINT point( float x, float y, float z)
{
    OKG_POINT p;
    p.x = x;
    p.y = y;
    p.z = z;
    return( p );
}

OKG_POINT spherical( float alpha, float beta, float r )
{
    OKG_POINT p;
    p.x = r*cos(alpha)*cos(beta);
    p.y = r*sin(alpha)*cos(beta);
    p.z = r*sin(beta);
    return p;
}

int main()
{
    init();

    glEnable( GL_DEPTH_TEST );
    glEnable( GL_LIGHTING );
    glEnable( GL_COLOR_MATERIAL );
    glEnable( GL_LIGHT0 );

    glEnable(GL_SMOOTH);
	glShadeModel(GL_SMOOTH);

    while( running() )
    {
        glClear( GL_COLOR_BUFFER_BIT+GL_DEPTH_BUFFER_BIT );

        glColor3ub( 200, 51, 51 );

        drawSolidParallelipiped (0.0, 1.5/3, 0.0/3, 13/3, 1.0/3, 4.0/3);

        drawSolidParallelipiped (0.0, 3.5/3, 0.0, 11/3, 1.0/3, 4.0/3);
        drawSolidParallelipiped (0.0, 6.5/3, 0.0, 11/3, 1.0/3, 4.0/3);

        drawSolidParallelipiped (-4.0/3, -2.0/3, 0.0,
                                  1.0/3, 4.0/3, 4.0/3);
        drawSolidParallelipiped (4.0/3, -2.0/3, 0.0,
                                  1.0/3, 4.0/3, 4.0/3);

        drawSolidParallelipiped (0.0, -0.5/3, 0.0,
                                 9.0/3, 1.0/3, 4.0/3);
        drawSolidParallelipiped (0.0, -3.5/3, 0.0,
                                 9.0/3, 1.0/3, 4.0/3);

        drawSolidParallelipiped (1.5/3, 5.0/3, 0.0,
                                 1.0/3, 4.0/3, 4.0/3);
        drawSolidParallelipiped (4.5/3, 5.0/3, 0.0,
                                 1.0/3, 4.0/3, 4.0/3);
        drawSolidParallelipiped (-1.5/3, 5.0/3, 0.0,
                                 1.0/3, 4.0/3, 4.0/3);
        drawSolidParallelipiped (-4.5/3, 5.0/3, 0.0,
                                 1.0/3, 4.0/3, 4.0/3);

        drawSolidParallelipiped (-9/3, 0.0, 0.0,
                                 1.5/3, 13/3, 4.0/3);

        drawSolidParallelipiped (-9/3, 0.0, 0.0,
                                 4.3/3, 1.4/3, 4.0/3);
        drawSolidParallelipiped (-9/3, 5.3/3, 0.0,
                                 5.0/3, 1.4/3, 4.0/3);

        drawSolidParallelipiped (-0.5/3, -7.0/3, 0.0,
                                 1.5/3, 6.0/3, 4.0/3);

        drawSmoothCylinderPart(-3.2, 0.81, -0.665, 4,
                               4/3, 5, 5.7);
        drawSmoothCylinderPart(2.4,1.3,-0.67,4,
                               4/3.0,4, 4.7);

        drawSmoothCylinderPart(-0.3,1.5,-0.67,4,
                               4/3.0,5,5.5);

        drawSmoothCylinderPart(-4.5,5.5,-0.67,8,
                               4/3.0,4.8,5.05);

        glfwSwapBuffers();
            }

    finit();
    return 0;
}



