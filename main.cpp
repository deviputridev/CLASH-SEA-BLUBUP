#include <windows.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <mmsystem.h>

class Sea
{
public:
    void *img;
    int imgWidth, imgHeight;

    Sea()
    {
        imgWidth = getmaxx();
        imgHeight = getmaxy();
        img = malloc(imagesize(0, 0, imgWidth, imgHeight));
        readimagefile("img/sea.gif", 0, 0, imgWidth, imgHeight);
        getimage(0, 0, imgWidth, imgHeight, img);
    }

    void draw()
    {
        putimage(0, 0, img, COPY_PUT);
    }
};

class FighterJet
{
public:
    int x, y, dx, dy;
    int imgWidth, imgHeight;
    void *colorImg;
    void *maskImg;

    FighterJet(int startX, int startY, int startDx, int startDy)
    {
        x = startX;
        y = startY;
        dx = startDx;
        dy = startDy;
        imgWidth = 146;
        imgHeight = 62;

        colorImg = malloc(imagesize(0, 0, imgWidth, imgHeight));
        maskImg = malloc(imagesize(0, 0, imgWidth, imgHeight));

        readimagefile("img/jetbw.gif", 0, 0, imgWidth, imgHeight);
        getimage(0, 0, imgWidth, imgHeight, maskImg);

        readimagefile("img/jet.gif", 0, 0, imgWidth, imgHeight);
        getimage(0, 0, imgWidth, imgHeight, colorImg);
    }

    void draw()
    {
        putimage(x, y, maskImg, AND_PUT);
        putimage(x, y, colorImg, OR_PUT);
    }

    void move()
    {
        x += dx;
        y += dy;
        if (y < 0 || y > 300)
        {
            dy = -dy;
            y += dy;
        }
    }

    bool isOutOfWindow(int maxX)
    {
        return x > maxX;
    }

    int getGunX()
    {
        return x + 20;
    }

    int getGunY()
    {
        return y + 20;
    }
};

struct Tbuffer
{
    void *img;
    void *mask;
};

class Bullet
{
public:
    int x, y, speed;
    int imgWidth, imgHeight;

    Tbuffer drop[8];
    Tbuffer parasut[8];
    int indexBullet = -1;

    void *colorBullet3;
    void *maskBullet3;

    Bullet(int startX, int startY, int bulletSpeed)
    {
        x = startX;
        y = startY;
        speed = bulletSpeed;
        imgWidth = 90;
        imgHeight = 90;

        readimagefile("img/rubydrop.gif", 0, 0, imgWidth * 8, imgHeight);
        for (int i = 0; i < 8; i++)
        {
            drop[i].img = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, drop[i].img);
        }

        readimagefile("img/rubydrop-bw.gif", 0, 0, imgWidth * 8, imgHeight);
        for (int i = 0; i < 8; i++)
        {
            drop[i].mask = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, drop[i].mask);
        }

        readimagefile("img/rubypar.gif", 0, 0, imgWidth * 8, imgHeight);
        for (int i = 0; i < 8; i++)
        {
            parasut[i].img = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, parasut[i].img);
        }

        readimagefile("img/rubypar-bw.gif", 0, 0, imgWidth * 8, imgHeight);
        for (int i = 0; i < 8; i++)
        {
            parasut[i].mask = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, parasut[i].mask);
        }

        colorBullet3 = malloc(imagesize(x, y, x + imgWidth, y + imgHeight));
        maskBullet3 = malloc(imagesize(x, y, x + imgWidth, y + imgHeight));

        readimagefile("img/diebw.gif", x, y, x + imgWidth, y + imgHeight);
        getimage(x, y, x + imgWidth, y + imgHeight, maskBullet3);

        readimagefile("img/die.gif", x, y, x + imgWidth, y + imgHeight);
        getimage(x, y, x + imgWidth, y + imgHeight, colorBullet3);
    }

    void draw(int maxY)
    {
        if (y >= 0 && y <= maxY / 3)
        {
            indexBullet = (indexBullet + 1) % 8;
            putimage(x, y, drop[indexBullet].mask, AND_PUT);
            putimage(x, y, drop[indexBullet].img, OR_PUT);
        }
        else if (y > maxY / 3 && y <= maxY / 2 + 100)
        {
            indexBullet = (indexBullet + 1) % 8;
            putimage(x, y, parasut[indexBullet].mask, AND_PUT);
            putimage(x, y, parasut[indexBullet].img, OR_PUT);
        }
        else if (y > maxY / 2 + 100)
        {
            putimage(x, y, maskBullet3, AND_PUT);
            putimage(x, y, colorBullet3, OR_PUT);
        }
    }

    void move()
    {
        y += speed;
    }
};

class Kapal
{
public:
    int x, y, width, height;
    void *colorShip;
    void *maskShip;
    int imgWidth, imgHeight;

    Kapal(int startX, int startY)
    {
        x = startX;
        y = startY;
        width = 150;
        height = 150;
        imgWidth = 485;
        imgHeight = 495;

        colorShip = malloc(imagesize(x, y, x + width, y + height));
        maskShip = malloc(imagesize(x, y, x + width, y + height));

        readimagefile("img/shipbw.gif", x, y, x + width, y + height);
        getimage(x, y, x + width, y + height, maskShip);

        readimagefile("img/ship.gif", x, y, x + width, y + height);
        getimage(x, y, x + width, y + height, colorShip);
    }

    void draw()
    {
        putimage(x, y, maskShip, AND_PUT);
        putimage(x, y, colorShip, OR_PUT);
    }

    void move(int newX, int maxX)
    {
        if (newX >= 0 && newX + width <= maxX)
        {
            x = newX;
        }
    }
};

class Fish
{
public:
    int x, y, radius, dx;
    Tbuffer frames[5];
    Tbuffer mirror[5];
    int imgWidth, imgHeight;
    int indexFish = -1;

    Fish(int startX, int startY, int r, int speed)
    {
        x = startX;
        y = startY;
        radius = r;
        dx = speed;
        imgWidth = 60;
        imgHeight = 60;

        readimagefile("img/fish.gif", 0, 0, imgWidth * 5, imgHeight);
        for (int i = 0; i < 5; i++)
        {
            frames[i].img = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, frames[i].img);
        }

        readimagefile("img/fishbw.gif", 0, 0, imgWidth * 5, imgHeight);
        for (int i = 0; i < 5; i++)
        {
            frames[i].mask = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, frames[i].mask);
        }

        readimagefile("img/fishmirror.gif", 0, 0, imgWidth * 5, imgHeight);
        for (int i = 0; i < 5; i++)
        {
            mirror[i].img = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, mirror[i].img);
        }

        readimagefile("img/fishbw-mirror.gif", 0, 0, imgWidth * 5, imgHeight);
        for (int i = 0; i < 5; i++)
        {
            mirror[i].mask = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, mirror[i].mask);
        }
    }

    void move(int maxX)
    {
        x += dx;
        if (x < 0 || x >= maxX - 100)
        {
            dx = -dx;
        }
    }

    void reloadImages()
    {
        imgWidth += radius;
        imgHeight += radius;

        readimagefile("img/fish.gif", 0, 0, imgWidth * 5, imgHeight);
        for (int i = 0; i < 5; i++)
        {
            frames[i].img = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, frames[i].img);
        }

        readimagefile("img/fishbw.gif", 0, 0, imgWidth * 5, imgHeight);
        for (int i = 0; i < 5; i++)
        {
            frames[i].mask = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, frames[i].mask);
        }

        readimagefile("img/fishmirror.gif", 0, 0, imgWidth * 5, imgHeight);
        for (int i = 0; i < 5; i++)
        {
            mirror[i].img = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, mirror[i].img);
        }

        readimagefile("img/fishbw-mirror.gif", 0, 0, imgWidth * 5, imgHeight);
        for (int i = 0; i < 5; i++)
        {
            mirror[i].mask = malloc(imagesize(0, 0, imgWidth, imgHeight));
            getimage(i * imgWidth, 0, (i + 1) * imgWidth, imgHeight, mirror[i].mask);
        }
    }

    void grow()
    {
        radius += 2;
        if (radius > 20)
            radius = 20;
        reloadImages();
    }

    void draw()
    {
        indexFish = (indexFish + 1) % 5;
        if (dx >= 0)
        {
            putimage(x, y, frames[indexFish].mask, AND_PUT);
            putimage(x, y, frames[indexFish].img, OR_PUT);
        }
        else
        {
            putimage(x, y, mirror[indexFish].mask, AND_PUT);
            putimage(x, y, mirror[indexFish].img, OR_PUT);
        }
    }
};

bool checkCollision(int x1, int y1, int w1, int h1, int x2, int y2, int r2)
{
    int closestX = std::max(x1, std::min(x2, x1 + w1));
    int closestY = std::max(y1, std::min(y2, y1 + h1));
    int dx = x2 - closestX;
    int dy = y2 - closestY;
    return (dx * dx + dy * dy) <= (r2 * r2);
}

bool showWelcomeScreen()
{
    void *img = nullptr;
    int width = 800, height = 800;
    initwindow(width, height, "Clash Sea - Welcome");

    readimagefile("img/gui.gif", 0, 0, width, height);
    img = malloc(imagesize(0, 0, width, height));
    getimage(0, 0, width, height, img);

    while (true)
    {
        putimage(0, 0, img, COPY_PUT);

        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int mx = mousex();
            int my = mousey();
            clearmouseclick(WM_LBUTTONDOWN);

            if (mx >= 300 && mx <= 500 && my >= 320 && my <= 390)
            {
                mciSendString("close click", NULL, 0, NULL);
                mciSendString("open \"click.wav\" type waveaudio alias click", NULL, 0, NULL);
                mciSendString("play click from 0", NULL, 0, NULL);

                closegraph();
                return true;
            }

            if (mx >= 300 && mx <= 500 && my >= 430 && my <= 500)
            {
                mciSendString("close click", NULL, 0, NULL);
                mciSendString("open \"click.wav\" type waveaudio alias click", NULL, 0, NULL);
                mciSendString("play click from 0", NULL, 0, NULL);

                closegraph();
                return false;
            }
        }

        delay(30);
        swapbuffers();
    }
}

void showHowToPlayScreen()
{
    int width = 800, height = 800;
    void *img = nullptr;
    initwindow(width, height, "How to Play");

    readimagefile("img/howtoplay.gif", 0, 0, width, height);
    img = malloc(imagesize(0, 0, width, height));
    getimage(0, 0, width, height, img);

    while (true)
    {
        putimage(0, 0, img, COPY_PUT);

        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int mx = mousex();
            int my = mousey();
            clearmouseclick(WM_LBUTTONDOWN);

            if (mx >= 320 && mx <= 500 && my >= 620 && my <= 675)
            {
                mciSendString("close click", NULL, 0, NULL);
                mciSendString("open \"click.wav\" type waveaudio alias click", NULL, 0, NULL);
                mciSendString("play click from 0", NULL, 0, NULL);
                
                closegraph();
                break;
            }
        }
        delay(30);
        swapbuffers();
    }
}

void showGameOverScreen(int playerScore, int fishScore)
{
    int width = 800, height = 800;
    initwindow(width, height, "Game Over");

    readimagefile("img/gameover.gif", 0, 0, width, height);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(WHITE);

    char scoreBuf[100];
    snprintf(scoreBuf, sizeof(scoreBuf), "Player Score: %d", playerScore);
    outtextxy(200, 350, scoreBuf);

    snprintf(scoreBuf, sizeof(scoreBuf), "Fish Score : %d", fishScore);
    outtextxy(200, 400, scoreBuf);

    outtextxy(360, 520, "EXIT");

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int mx = mousex();
            int my = mousey();
            clearmouseclick(WM_LBUTTONDOWN);
            if (mx >= 300 && mx <= 500 && my >= 500 && my <= 550)
                break;
        }
        delay(30);
    }

    swapbuffers();
    closegraph();
}

void runGame()
{
    initwindow(800, 800, "Clash Sea");

    int maxX = getmaxx(), maxY = getmaxy();
    srand(time(0));

    Sea sea;
    Kapal kapal(maxX / 2, maxY / 2 - 50);

    FighterJet jets[3] = {
        FighterJet(0, 0, 5 + rand() % 5, 1 + rand() % 3),
        FighterJet(0, 0, 5 + rand() % 5, 1 + rand() % 3),
        FighterJet(0, 0, 5 + rand() % 5, 1 + rand() % 3),
    };

    FighterJet straightJets[2] = {
        FighterJet(0, maxY / 6, 5, 0),
        FighterJet(0, maxY / 3, 5, 0)};

    std::vector<Bullet> bullets;
    std::vector<Fish> fishes;

    for (int i = 0; i < 6; i++)
    {
        fishes.push_back(Fish(rand() % maxX, maxY - 120 - rand() % 120, 15, 3 + rand() % 3));
    }

    int frameCounter = 0, shootInterval = 100;
    int playerScore = 0, fishScore = 0;
    bool gameOver = false;

    while (!kbhit() && !gameOver)
    {
        cleardevice();

        sea.draw();

        for (int i = 0; i < 3; i++)
        {
            jets[i].draw();
            jets[i].move();
            if (jets[i].isOutOfWindow(maxX))
            {
                jets[i].x = 0;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            straightJets[i].draw();
            straightJets[i].move();
            if (straightJets[i].isOutOfWindow(maxX))
            {
                straightJets[i].x = 0;
            }
        }

        if (frameCounter % shootInterval == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                bullets.push_back(Bullet(jets[i].getGunX(), jets[i].getGunY(), 5));
            }
            bullets.push_back(Bullet(straightJets[0].getGunX(), straightJets[0].getGunY(), 5));
        }

        for (int i = 0; i < bullets.size(); i++)
        {
            bullets[i].move();
            bullets[i].draw(maxY);
        }

        for (int i = 0; i < fishes.size(); i++)
        {
            fishes[i].move(maxX);
            fishes[i].draw();
        }

        kapal.draw();

        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int mouseX = mousex();
            kapal.move(mouseX - kapal.width / 2, maxX);
            clearmouseclick(WM_LBUTTONDOWN);
        }

        for (int i = 0; i < bullets.size();)
        {
            if (bullets[i].y >= kapal.y && bullets[i].x >= kapal.x && bullets[i].x <= kapal.x + kapal.width)
            {
                playerScore++;

                mciSendString("close poin", NULL, 0, NULL);
                mciSendString("open \"poin.wav\" type waveaudio alias poin", NULL, 0, NULL);
                mciSendString("play poin from 0", NULL, 0, NULL);

                bullets.erase(bullets.begin() + i);
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < bullets.size();)
        {
            bool eaten = false;
            for (int j = 0; j < fishes.size(); j++)
            {
                if (checkCollision(fishes[j].x - fishes[j].radius, fishes[j].y - fishes[j].radius,
                                   fishes[j].radius * 2, fishes[j].radius * 2,
                                   bullets[i].x, bullets[i].y, 5))
                {
                    fishScore++;
                    fishes[j].grow();
                    bullets.erase(bullets.begin() + i);

                    mciSendString("close eat", NULL, 0, NULL);
                    mciSendString("open \"eat.wav\" type waveaudio alias eat", NULL, 0, NULL);
                    mciSendString("play eat from 0", NULL, 0, NULL);

                    eaten = true;
                    break;
                }
            }
            if (!eaten)
                i++;
        }

        setcolor(WHITE);
        char buf[100];
        snprintf(buf, sizeof(buf), "Player Score: %d | Fish Score: %d", playerScore, fishScore);
        outtextxy(300, 10, buf);

        if (fishScore >= 10)
            gameOver = true;

        delay(20);
        frameCounter++;
        swapbuffers();
    }

    closegraph();

    if (fishScore >= 10)
    {
        showGameOverScreen(playerScore, fishScore);
    }
}

int main()
{
    mciSendString("open \"sound.mp3\" type mpegvideo alias bgm", NULL, 0, NULL);
    mciSendString("play bgm repeat", NULL, 0, NULL);

    bool goToGame = showWelcomeScreen();
    if (!goToGame)
        showHowToPlayScreen();
    runGame();
    return 0;
}
