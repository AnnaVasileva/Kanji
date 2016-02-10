#ifndef DRAWSMOOTHCYLINDERPART_H_INCLUDED
#define DRAWSMOOTHCYLINDERPART_H_INCLUDED

void drawSmoothCylinderPart ( float x, float y, float z, float r, float h , float a1, float a2)
{
    int n = 32;

    float alpha = a1;;
    float dalpha = (a2-a1)/n;

    for( int i=0; i<n; i++)
    {
        float dx1 = r*cos(alpha);
        float dy1 = r*sin(alpha);

        float dx2 = r*cos(alpha+dalpha);
        float dy2 = r*sin(alpha+dalpha);

        float r2 = r - 0.5;
        float adx1 = r2*cos(alpha);
        float ady1 = r2*sin(alpha);

        float adx2 = r2*cos(alpha+dalpha);
        float ady2 = r2*sin(alpha+dalpha);

        // Рисуване на парче от горната основа
        glBegin( GL_POLYGON );
            glNormal3f( 0, 0, 1 );
            glVertex3f( x+dx1, y+dy1, z +h);
            glVertex3f( x+dx2, y+dy2, z +h);
            glVertex3f( x+adx2, y+ady2,     z+h );
            glVertex3f( x+adx1, y+ady1,     z+h );
        glEnd();


        glBegin( GL_POLYGON );
            glNormal3f( -cos(alpha), -sin(alpha), 0 );
            glVertex3f( x+adx1, y+ady1, z+h );
            glVertex3f( x+adx1, y+ady1, z );
            glNormal3f( -cos(alpha+dalpha), -sin(alpha+dalpha), 0 );
            glVertex3f( x+adx2, y+ady2, z );
            glVertex3f( x+adx2, y+ady2, z+h );
        glEnd();

        glBegin (GL_POLYGON);
            glVertex3f(x+adx2, y+ady2, z );
            glVertex3f(x+dx2, y+dy2, z);
            glVertex3f( x+dx2, y+dy2, z+h);
            glVertex3f(x+adx2, y+ady2, z+h );
        glEnd();
        alpha += dalpha;
    }
}


#endif // DRAWSMOOTHCYLINDERPART_H_INCLUDED
