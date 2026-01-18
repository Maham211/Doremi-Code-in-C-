#include <graphics.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

int main() {
    initwindow(1000, 700, "Night Scene with Doremi and Stars");

    int activePage = 0, visualPage = 1;

    // Random star positions
    const int numStars = 60;
    int starX[numStars], starY[numStars];
    for (int i = 0; i < numStars; i++) {
        starX[i] = rand() % 1000;
        starY[i] = rand() % 300;
    }

    for (int frame = 0; !kbhit(); frame++) {
        // Switch pages to avoid flicker
        setactivepage(activePage);
        setvisualpage(visualPage);
        cleardevice();

        // ===== BACKGROUND (Night Sky) =====
        setfillstyle(SOLID_FILL, COLOR(0, 0, 40));
        bar(0, 0, 1000, 700);

        // ===== STAR ANIMATION (in BACK) =====
        setcolor(WHITE);
        for (int s = 0; s < numStars; s++) {
            int twinkle = (rand() % 15 < 2) ? BLACK : WHITE; // small flicker
            putpixel(starX[s], starY[s], twinkle);
        }

        // ===== Buildings =====
        int bx = 0;
        int bw = 100;
        for (int i = 0; i < 9; i++) {
            int height = 100 + (i % 3) * 40;
            setfillstyle(SOLID_FILL, DARKGRAY);
            bar(bx, height, bx + bw, 479);

            setfillstyle(SOLID_FILL, YELLOW);
            for (int y = height + 30; y < 460; y += 40) {
                bar(bx + 20, y, bx + 40, y + 20);
                bar(bx + 60, y, bx + 80, y + 20);
            }

            bx += 112; // equal spacing between buildings
        }

        // ===== Ground =====
        setfillstyle(SOLID_FILL, WHITE);
        bar(0, 480, 1000, 700);

        // ===== Doremi Character =====
        int dx = 120, dy = 200;

        // Bow
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(240 + dx, 90 + dy, 45, 60);
        fillellipse(360 + dx, 90 + dy, 45, 60);

        // Hood
        setfillstyle(SOLID_FILL, COLOR(255, 204, 51));
        fillellipse(300 + dx, 200 + dy, 110, 100);
        setfillstyle(SOLID_FILL, WHITE);
        fillellipse(300 + dx, 210 + dy, 95, 90);
        setcolor(BLACK);
        ellipse(300 + dx, 210 + dy, 0, 360, 95, 90);

        // Eyes
        setfillstyle(SOLID_FILL, WHITE);
        fillellipse(260 + dx, 185 + dy, 22, 28);
        fillellipse(330 + dx, 185 + dy, 22, 28);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(260 + dx, 190 + dy, 10, 16);
        fillellipse(330 + dx, 190 + dy, 10, 16);
        setfillstyle(SOLID_FILL, WHITE);
        fillellipse(255 + dx, 180 + dy, 4, 5);
        fillellipse(325 + dx, 180 + dy, 4, 5);

        // Nose & Mouth
        setfillstyle(SOLID_FILL, COLOR(255, 105, 180));
        fillellipse(300 + dx, 220 + dy, 6, 4);
        setcolor(BLACK);
        arc(300 + dx, 240 + dy, 60, 120, 30);
        arc(300 + dx, 240 + dy, 190, -7, 13);

        // Collar
        setfillstyle(SOLID_FILL, COLOR(0, 0, 60));
        bar(230 + dx, 275 + dy, 370 + dx, 298 + dy);
        rectangle(230 + dx, 275 + dy, 370 + dx, 298 + dy);

        // Bell
        setfillstyle(SOLID_FILL, COLOR(255, 215, 0));
        fillellipse(300 + dx, 307 + dy, 15, 15);
        line(285 + dx, 300 + dy, 315 + dx, 300 + dy);
        fillellipse(300 + dx, 312 + dy, 2, 2);
        line(300 + dx, 314 + dy, 300 + dx, 320 + dy);

        // Pocket
        setfillstyle(SOLID_FILL, WHITE);
        ellipse(300 + dx, 320 + dy, 118, 421, 55, 45);
        arc(300 + dx, 320 + dy, 186, 355, 34);
        line(266 + dx, 323 + dy, 334 + dx, 323 + dy);
        floodfill(300 + dx, 330 + dy, BLACK);

        // Arms
        setcolor(BLACK);
        arc(277 + dx, 350 + dy, 120, 160, 80);
        circle(202 + dx, 340 + dy, 17);
        circle(400 + dx, 336 + dy, 17);
        arc(338 + dx, 346 + dy, 23, 70, 70);
        line(383 + dx, 340 + dy, 365 + dx, 330 + dy);
        line(219 + dx, 340 + dy, 235 + dx, 330 + dy);

        // Body
        line(235 + dx, 320 + dy, 235 + dx, 418 + dy);
        line(365 + dx, 320 + dy, 365 + dx, 418 + dy);

        // Feet
        line(295 + dx, 395 + dy, 309 + dx, 395 + dy);
        line(235 + dx, 416 + dy, 365 + dx, 416 + dy);
        arc(248 + dx, 444 + dy, 110, 190, 30);
        arc(351 + dx, 444 + dy, -11, 65, 30);
        line(302 + dx, 395 + dy, 302 + dx, 450 + dy);
        line(218 + dx, 450 + dy, 380 + dx, 450 + dy);

        // Dress
        setfillstyle(SOLID_FILL, COLOR(255, 204, 51));
        floodfill(239 + dx, 343 + dy, BLACK);

        // === Moon=
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        fillellipse(800, 80, 40, 40);  

        setfillstyle(SOLID_FILL, COLOR(0, 0, 40)); 
        fillellipse(815, 80, 40, 40);   

        delay(30);

        // Swap pages
        activePage = 1 - activePage;
        visualPage = 1 - visualPage;
    }

    getch();
    closegraph();
    return 0;
}
