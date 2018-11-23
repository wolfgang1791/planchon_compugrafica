#include <stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include <gl/glut.h>
#include <iostream>

#define l 0.5f
#define lado 4

#define lista_f 1
#define lista_c1 2
#define lista_c2 3
#define lista_p 4

#define lista_fa 5
#define lista_pa 6
#define lista_c1a 7
#define lista_c2a 8


#define qr 0.0009765625/2

static int fondo =1;
static int puertas=4;
static int contorno1 = 2;
static int contorno2=3;

static GLfloat theta[] = {0.0,0.0,0.0};
static GLfloat alfa[] = {0.0,0.0,0.0};
static GLfloat sigma[] = {0.0,0.0,0.0};
static GLfloat o[] = {0.0,0.0,0.0};

static GLfloat triangulo_2[] = {0.0,0.0,1.0};
static GLfloat triangulo_1[] = {1.0,0.0,1.0};

static GLfloat bola[] = {1.0,0.0,0.0};
static GLfloat alambres[] = {1.0,1.0,1.0};

//static GLfloat plataforma[] = {1.0,1.0,1.0};
// eje es el ángulo a rotar
static int dir=1;

GLdouble angulo=0, incremento_angulo=1;
static GLfloat angulo_girar = 0.01;
static GLfloat ejex = 0.01;
static GLfloat ejez = 0.01;


void cuadrado(GLfloat t1[],GLfloat t2[]){

         glBegin(GL_TRIANGLES);
            glPointSize(8);
            glColor3f(t1[0],t1[1],t1[2]);
            glVertex3f(0,0,0);
            glVertex3f(0.5,0,0);
            glVertex3f(0,0,-0.5);
            glVertex3f(0,0,0);

         glEnd();

         glBegin(GL_TRIANGLES);
            glColor3f(t2[0],t2[1],t2[2]);
            glVertex3f(0.5,0,0);
            glVertex3f(0,0,-0.5);
            glVertex3f(0.5,0,-0.5);
            glVertex3f(0.5,0,0);
         glEnd();

}
void cuadrado_a(GLfloat t1[],GLfloat t2[]){

         glBegin(GL_LINE_STRIP);
            glColor3f(t1[0],t1[1],t1[2]);
            glVertex3f(0,0,0);
            glVertex3f(0.5,0,0);
            glVertex3f(0,0,-0.5);
            glVertex3f(0,0,0);

         glEnd();

         glBegin(GL_LINE_STRIP);
            glColor3f(t2[0],t2[1],t2[2]);
            glVertex3f(0.5,0,0);
            glVertex3f(0,0,-0.5);
            glVertex3f(0.5,0,-0.5);
            glVertex3f(0.5,0,0);
         glEnd();

}

void cuadrado_(GLfloat a,GLfloat b,GLfloat c){
         glBegin(GL_TRIANGLES);
            glColor3f(a,b,c);
            glVertex3f(0,0,0);
            glVertex3f(0.5,0,0);
            glVertex3f(0,0,-0.5);
            glVertex3f(0,0,0);
         glEnd();

         glBegin(GL_TRIANGLES);
            glColor3f(c,a,b);
            glVertex3f(0.5,0,0);
            glVertex3f(0,0,-0.5);
            glVertex3f(0.5,0,-0.5);
            glVertex3f(0.5,0,0);
         glEnd();
}


//base 2d hecha de triangulos
void triangulo(){

      int i;

      glNewList(lista_f,GL_COMPILE);
      for(i = 0;i<lado*lado;i++){

         if(i%lado == 0 && i != 0){
            glTranslated(-0.5*(lado-1),0,0);
            glTranslated(0,0,-0.5);
         }
         else if(i != 0){
            glTranslated(0.5,0,0);
         }


         glBegin(GL_TRIANGLES);
            glPointSize(8);
            glColor3f(triangulo_1[0],triangulo_1[1],triangulo_1[2]);
            glVertex3f(0,0,0);
            glVertex3f(0.5,0,0);
            glVertex3f(0,0,-0.5);
            glVertex3f(0,0,0);

         glEnd();

         glBegin(GL_TRIANGLES);
            glColor3f(triangulo_2[0],triangulo_2[1],triangulo_2[2]);
            glVertex3f(0.5,0,0);
            glVertex3f(0,0,-0.5);
            glVertex3f(0.5,0,-0.5);
            glVertex3f(0.5,0,0);
         glEnd();
      }
      glEndList();
      glTranslated(-((lado*0.5/2)-0.5),0.5,(((lado*0.5/2))-0.5));
}


void grosor_armario(){
    int i;
    for(i=0;i<10;i++){
        glTranslated(0,0.01,0);
        cuadrado_(1.0,1.0,0.0);
        //glTranslated(0,-0.01,0);
    }
    for(i=0;i<10;i++){
     //   glTranslated(0,0.01,0);
     //   cuadrado_();
        glTranslated(0,-0.01,0);
    }

}

void fondo_armario(GLfloat t1[],GLfloat t2[]){

      int i;

      glNewList(lista_f,GL_COMPILE);
      for(i = 0;i<lado*lado;i++){

         if(i%lado == 0 && i != 0){
            glTranslated(-0.5*(lado-1),0,0);
            glTranslated(0,0,-0.5);
         }
         else if(i != 0){
            glTranslated(0.5,0,0);
         }

        cuadrado(t1,t2);
        grosor_armario();
      }
      glEndList();
     // glTranslated(-((lado*0.5/2)-0.5),0.5,(((lado*0.5/2))-0.5));
}

void fondo_armario_a(GLfloat t1[],GLfloat t2[]){

      int i;

      glNewList(lista_fa,GL_COMPILE);
      for(i = 0;i<lado*lado;i++){

         if(i%lado == 0 && i != 0){
            glTranslated(-0.5*(lado-1),0,0);
            glTranslated(0,0,-0.5);
         }
         else if(i != 0){
            glTranslated(0.5,0,0);
         }

        cuadrado_a(t1,t2);
        grosor_armario();
      }
      glEndList();
     // glTranslated(-((lado*0.5/2)-0.5),0.5,(((lado*0.5/2))-0.5));
}

void grosor_puerta(){
    int i;
    for(i=0;i<10;i++){
        glTranslated(0,0.01,0);
        cuadrado_(1.0,0.0,1.0);
    }
    for(i=0;i<10;i++){
        glTranslated(0,-0.01,0);
    }
}

void puerta_armario(GLfloat t1[],GLfloat t2[]){

      int i;

      glNewList(lista_p,GL_COMPILE);
      for(i = 0;i<lado*2;i++){

         if(i%lado == 0 && i != 0){
            glTranslated(-0.5*(lado-1),0,0);
            glTranslated(0,0,-0.5);
         }
         else if(i != 0){
            glTranslated(0.5,0,0);
         }

            cuadrado(t1,t2);
            grosor_puerta();
      }
      glEndList();

}

void puerta_armario_a(GLfloat t1[],GLfloat t2[]){

      int i;

      glNewList(lista_pa,GL_COMPILE);
      for(i = 0;i<lado*2;i++){

         if(i%lado == 0 && i != 0){
            glTranslated(-0.5*(lado-1),0,0);
            glTranslated(0,0,-0.5);
         }
         else if(i != 0){
            glTranslated(0.5,0,0);
         }

            cuadrado_a(t1,t2);
            grosor_puerta();
      }
      glEndList();

}

void grosor_contorno(){
    int i;
    for(i=0;i<10;i++){
       glTranslated(0,-0.01,0);
        cuadrado_(0.0,0.1,0.0);
    }
    for(i=0;i<10;i++){
       glTranslated(0,0.01,0);
    }
}

void un_contorno(GLfloat t1[],GLfloat t2[]){
    int i;
    bool flag0=false,flag1=false,flag2=false,flag3=false;
    bool FLAG=true;
    for(i = 0;i<lado*lado;i++){

          if(i%lado!=0 || i==0){
            cuadrado(t1,t2);
                if(flag1){
                        grosor_contorno();

                   glTranslated(0,0,-0.5);
                   cuadrado(t1,t2);

                   grosor_contorno();
                }
                if(flag2){
                   grosor_contorno();

                   glTranslated(0,0,-0.5);
                   cuadrado(t1,t2);

                   grosor_contorno();
                }
                if(flag3){
                   grosor_contorno();
                   glTranslated(0,0,-0.5);
                   cuadrado(t1,t2);

                   grosor_contorno();
                }
                if(FLAG){
                     //   grosor_contorno();
                    glTranslated(0,0,0.5);
                }
          }
          else{
            flag0=true;
          }
            if(flag0){
                switch(i){
                    case 4 : glRotatef(90,1.0,0.0,0.0);
                             glTranslated(0,-0.5,0);

                             flag1=true;
                             flag2=false;flag3=false;FLAG=false;
                             break;
                    case  8: glRotatef(-90,1.0,0.0,0.0);
                             glTranslated(0,0.5,0);

                             flag2=true;
                             flag1=false;flag3=false;FLAG=false;
                             break;
                    case 12: glRotatef(-90,1.0,0.0,0.0);
                             glTranslated(0,0.5,0);

                             flag3=true;
                             flag2=false;flag1=false;FLAG=false;
                             break;
                }
                flag0=false;
            }


      }
}

void un_contorno_a(GLfloat t1[],GLfloat t2[]){
    int i;
    bool flag0=false,flag1=false,flag2=false,flag3=false;
    bool FLAG=true;
    for(i = 0;i<lado*lado;i++){

          if(i%lado!=0 || i==0){
            cuadrado_a(t1,t2);
                if(flag1){
                        grosor_contorno();

                   glTranslated(0,0,-0.5);
                   cuadrado_a(t1,t2);
                   grosor_contorno();
                }
                if(flag2){
                        grosor_contorno();

                   glTranslated(0,0,-0.5);
                   cuadrado_a(t1,t2);

                   grosor_contorno();
                }
                if(flag3){
                    grosor_contorno();

                   glTranslated(0,0,-0.5);
                   cuadrado_a(t1,t2);

                   grosor_contorno();
                }
                if(FLAG){
                        grosor_contorno();
                    glTranslated(0,0,0.5);
                }
          }
          else{
            flag0=true;
          }
            if(flag0){
                switch(i){
                    case 4 : glRotatef(90,1.0,0.0,0.0);
                             glTranslated(0,-0.5,0);

                             flag1=true;
                             flag2=false;flag3=false;FLAG=false;
                             break;
                    case  8: glRotatef(-90,1.0,0.0,0.0);
                             glTranslated(0,0.5,0);

                             flag2=true;
                             flag1=false;flag3=false;FLAG=false;
                             break;
                    case 12: glRotatef(-90,1.0,0.0,0.0);
                             glTranslated(0,0.5,0);

                             flag3=true;
                             flag2=false;flag1=false;FLAG=false;
                             break;
                }
                flag0=false;
            }


      }
}


void contorno_armario(GLfloat t1[],GLfloat t2[]){

      int j;

      for(j=0;j<2;j++){
        if(j==0)
            glNewList(lista_c1,GL_COMPILE);
        else
            glNewList(lista_c2,GL_COMPILE);

        un_contorno(t1,t2);
        glEndList();
      }


}

void contorno_armario_a(GLfloat t1[],GLfloat t2[]){

      int j;

      for(j=0;j<2;j++){
        if(j==0)
            glNewList(lista_c1a,GL_COMPILE);
        else
            glNewList(lista_c2a,GL_COMPILE);

        un_contorno_a(t1,t2);
        glEndList();
      }


}
//plataforma bajo la base de triangulos
void crear_listas(GLfloat t1[],GLfloat t2[]){
    fondo_armario(t1,t2);
    contorno_armario(t1,t2);
    puerta_armario(t1,t2);

    fondo_armario_a(t1,t2);
    contorno_armario_a(t1,t2);
    puerta_armario_a(t1,t2);
}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 //composicion de rotaciones

 glRotatef(theta[0],1.0,0.0,0.0);
 glRotatef(theta[1],0.0,1.0,0.0);
 glRotatef(theta[2],0.0,0.0,1.0);

    theta[0] = 20; // 20 90 80
    theta[2] = 120;

 glRotatef(alfa[0],1.0,0.0,0.0);
 glRotatef(alfa[1],0.0,1.0,0.0);
 glRotatef(alfa[2],0.0,0.0,1.0);

 glPushMatrix();
 glTranslated(-(0.5*lado)/2,-0.5,(0.5*lado)/2);
 glCallList(fondo); // lista con el fondo
 glPopMatrix();
 glPushMatrix();
 glRotatef(90,0.0,0.0,1.0);
 glTranslated(-0.5,-1,-0.5);
 glCallList(contorno1); //lista con el primer contorno
 glPopMatrix();
 glPushMatrix();
 glRotatef(90,0.0,0.0,1.0);
 glTranslated(qr,-1,-0.5);
 glCallList(contorno2); // lista con el segundo contorno
 glPopMatrix();
 glPushMatrix();
 glRotatef(180,0.0,0.0,1.0);
 glTranslated(-(0.5*lado)/2,-0.5,(0.5*lado)/2);
   glRotatef(sigma[0],1.0,0.0,0.0);
   glRotatef(sigma[1],0.0,1.0,0.0);
   glRotatef(sigma[2],0.0,0.0,1.0);
 glCallList(puertas); // lista con las puertas
 glPopMatrix();
 glPushMatrix();
 glRotatef(180,1.0,0.0,0.0);
 glTranslated(-(0.5*lado)/2,-0.5,(0.5*lado)/2);//-(0.5*lado)/256
   glRotatef(o[0],1.0,0.0,0.0);
   glRotatef(o[1],0.0,1.0,0.0);
   glRotatef(o[2],0.0,0.0,1.0);
 glCallList(puertas);
 glPopMatrix();



 glFlush();

 glutSwapBuffers();
}

void girar_caja ()
{
 alfa[0] += (dir)*0.1;
 if(alfa[0]>360) alfa[0] -= 360.0;
 display();
}

void girar_puertas()
{
  // while(sigma[0] > -90 && o[0]>-90){
     sigma[0]-=5; // -45
     o[0]-=5;
     display();
     std::cout<<sigma[0]<<" "<<o[0]<<"\n";
   //}
}

void girar_puertas_()
{
  //while(sigma[0] < 0 && o[0]<0){
     sigma[0]+=5; // -45
     o[0]+=5;
     display();
     std::cout<<sigma[0]<<" "<<o[0]<<"\n";
  //}
}

void teclado(unsigned char tecla,int x,int y)
{

switch(tecla){
    case 'a' : girar_caja(); break;
    case 'w' : girar_puertas();break;
    case 's' : girar_puertas_();break;
    case 'd' : break;
    case 'f' : exit(0) ; break;
    }
}
// control de ventana (recuerde el volumen de visualización)
// modifique dicho volumen según su conveniencia
void myReshape(int w, int h)
{
 glViewport(0,0,w,h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 if(w <=h)
glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,
 2.0*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
 else
glOrtho(-2.0*(GLfloat)w/(GLfloat)h,
 2.0*(GLfloat)w/(GLfloat)h, -2.0,2.0,-10.0,10.0);
 glMatrixMode(GL_MODELVIEW);
}
void menu_principal(int opcion)
{
    switch(opcion){
    //case 1: int i=0;break;
    case 4: exit( -1 );
    }
}
//cambio de colores para la esfera

//cambio de colores para el tablero
void menu_color_tablero(int opcion)
{
switch(opcion){
case 1:
        std::cout<<1;
        triangulo_1[0]=0.0;triangulo_1[1]=1.0;triangulo_1[2]=0.0;
        triangulo_2[0]=1.0;triangulo_2[1]=0.0;triangulo_2[2]=0.0;
        crear_listas(triangulo_1,triangulo_2);
        display();
        break;
case 2: std::cout<<2;
        triangulo_1[0]=1.0;triangulo_1[1]=1.0;triangulo_1[2]=1.0;
        triangulo_2[0]=0.0;triangulo_2[1]=1.0;triangulo_2[2]=1.0;
        crear_listas(triangulo_1,triangulo_2);
        display();
        break;
case 3: std::cout<<3;
        triangulo_1[0]=1.0;triangulo_1[1]=0.0;triangulo_1[2]=1.0;
        triangulo_2[0]=0.0;triangulo_2[1]=0.0;triangulo_2[2]=1.0;
        crear_listas(triangulo_1,triangulo_2);
        display();
        break;
}
}

void menu_alambre_solido(int opcion)
{
    switch(opcion){
    case 1: fondo = lista_f;
            contorno1 = lista_c1;
            contorno2 = lista_c2;
            puertas=lista_p;
            display();
            break;
    case 2: fondo = lista_fa;
            contorno1 = lista_c1a;
            contorno2 = lista_c2a;
            puertas=lista_pa;
            display();
            break;
    }
}

void menu_dir(int opcion)
{
    switch(opcion){
    case 1: girar_puertas();
            display();
            break;
    case 2: girar_puertas_();
            display();
            break;
    }
}

void menu_dir_(int opcion)
{
    switch(opcion){
    case 1: if(dir<0)
                dir=dir*(-1);
            display();
            break;
    case 2: if(dir>0)
                dir=dir*(-1);
            display();
            break;
    }
}


int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(500,500);
 glutCreateWindow("mi objeto bajo rotaciones");
 int submenu_tablero=glutCreateMenu(menu_color_tablero);
 glutAddMenuEntry("Rojo/Verde",1);
 glutAddMenuEntry("Blanco/Turquesa",2);
 glutAddMenuEntry("Original",3);
 int submenu_alambre_solido=glutCreateMenu(menu_alambre_solido);
 glutAddMenuEntry("solido",1);
 glutAddMenuEntry("alambrico",2);
 int submenu_direccion=glutCreateMenu(menu_dir);
 glutAddMenuEntry("abrir",1);
 glutAddMenuEntry("cerrar",2);
 int submenu_direccion_=glutCreateMenu(menu_dir_);
 glutAddMenuEntry("horario",1);
 glutAddMenuEntry("antihorario",2);
 int menu=glutCreateMenu(menu_principal);
 glutAddSubMenu("tablero",submenu_tablero);
 glutAddSubMenu("alambrico/solido",submenu_alambre_solido);
 glutAddSubMenu("direccion",submenu_direccion_);
 glutAddSubMenu("abrir/cerrar",submenu_direccion);
 glutAddMenuEntry("Esc",4);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 glutReshapeFunc(myReshape);
 // invocamos a display() para dibujar nuestra escena
 glutDisplayFunc(display);
 crear_listas(triangulo_1,triangulo_2);
 //glutIdleFunc(girar_objeto_geometrico);
 glutIdleFunc(girar_caja);
 glutKeyboardFunc(teclado);
 /*glutMouseFunc(mouse);*/
 glEnable(GL_DEPTH_TEST);
 glutMainLoop();
}
