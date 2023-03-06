#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

struct punto
{ int x,y;};

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(400, 533), "Doodle jump");
    app.setFramerateLimit(60);

    Texture t1,t2,t3;
    t1.loadFromFile("immagini/sfondo.png");
    t2.loadFromFile("immagini/piattaforma.png");
    t3.loadFromFile("immagini/personaggio.png");

    Sprite sfondo(t1), sPlat(t2), sPers(t3);

    punto piattaforme[20];

    for (int i=0;i<10;i++)
      {
       piattaforme[i].x=rand()%400;
       piattaforme[i].y=rand()%533;
      }

    int x=100,y=100,h=200;
    float dx=0,dy=0;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;

    dy+=0.2;
    y+=dy;
    if (y>500)  dy=-10;

    if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      piattaforme[i].y=plat[i].y-dy;
      if (piattaforme[i].y>533) {piattaforme[i].y=0; piattaforme[i].x=rand()%400;}
    }

    for (int i=0;i<10;i++)
     if ((x+50>piattaforme[i].x) && (x+20<piattaforme[i].x+68)
      && (y+70>piattaforme[i].y) && (y+70<piattaforme[i].y+14) && (dy>0))  dy=-10;

    personaggio.setPosition(x,y);

    app.draw(sfondo);
    app.draw(personaggio);
    for (int i=0;i<10;i++)
    {
    piattaforma.setPosition(plat[i].x,plat[i].y);
    app.draw(piattaforma);
    }

    app.display();
}

    return 0;
}
