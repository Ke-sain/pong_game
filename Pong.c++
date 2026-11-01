#include "raylib.h"
#include <cmath>

 struct Player {
    float papan_y;
};
struct Bola {
    float posx;
    float posy;
    float angle;
};

bool paused = false;
int main() {
    InitWindow(800, 450, "Ping Pong");
    SetTargetFPS(120);
    Player Player1 = {100};
    Player Player2 = {100};
    Bola Bola = {400,225,(float)(rand()%26) + 30};
    float kecepatan = 300.0f;
    float kecepatanbola = 300.0f;
   class data {
    private:
        int score = 0 ; 
    public:
        void changescore (int s){
            score += s ;
        };
        int getscore (){
            return score ;
        };
        void setscoretozero (){
            score = 0;
        }
   };
    data p1 ;
    data p2 ;
    
    while (!WindowShouldClose()) {
       while (paused == false)
       {
     float rad = Bola.angle* PI /180;
       float dt = GetFrameTime();
       float Vx = cos(rad) * kecepatanbola * dt;
       float Vy = sin(rad) * kecepatanbola * dt;
       Bola.posx += Vx; 
       Bola.posy += Vy;
        Rectangle papan1 = {40,Player1.papan_y,20,100};
        Rectangle papan2 = {740,Player2.papan_y,20,100};
       if (Bola.posx > 810 ){
            p1.changescore(1);
            Bola.posx = 400;
            Bola.posy = 225;
            Bola.angle =(float) (rand()%26)+30;
       }
       if( Bola.posx  < -10 ){
            p2.changescore(1);
            Bola.posx = 400;
            Bola.posy = 225;
            Bola.angle = (float)(rand()&26)+30;
       }
       if(CheckCollisionCircleRec({Bola.posx,Bola.posy},10,papan1)){
        Bola.angle = 180- Bola.angle;
        Bola.posx = papan1.x+ papan1.width + 10;
       }
       if (CheckCollisionCircleRec({Bola.posx,Bola.posy},10,papan2)){
        Bola.angle = 180- Bola.angle;
        Bola.posx = papan2.x -10 ;
       }
        if (Bola.posy- 10 <= 0){
            Bola.angle = -Bola.angle;
            Bola.posy = 11;
       }
       if (Bola.posy+10 >= 450){
            Bola.angle = -Bola.angle;
            Bola.posy = 440;
       }
       if (IsKeyPressed(KEY_F1)){
            paused = true;
       }
       if (IsKeyDown(KEY_UP)){
            Player2.papan_y -= kecepatan*dt;
        }
    if (IsKeyDown(KEY_DOWN)){
            Player2.papan_y += kecepatan*dt;
        }
    if (Player1.papan_y <0){
            Player1.papan_y = 0;
        }
    if (Player1.papan_y > 350){
            Player1.papan_y = 350;
        }
     if (IsKeyDown(KEY_W)){
            Player1.papan_y -= kecepatan*dt;
        }
    if (IsKeyDown(KEY_S)){
            Player1.papan_y += kecepatan*dt;
        }
    if (Player2.papan_y <0){
            Player2.papan_y = 0;
        }
    if (Player2.papan_y > 350){
            Player2.papan_y = 350;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle (40,Player1.papan_y,20,100,WHITE);
        DrawRectangle (740,Player2.papan_y,20,100,WHITE);
        DrawCircle (Bola.posx, Bola.posy, 10, WHITE);
        DrawText(TextFormat("SKOR 1: %i",p1.getscore()), 40, 410, 15, GREEN);
        DrawText(TextFormat("SKOR 2: %i",p2.getscore()), 700, 410, 15, GREEN);
        DrawFPS(10, 10);
        EndDrawing();
    }
    if(IsKeyPressed(KEY_F1)){
        paused = !paused;
    }
    if(IsKeyPressed(KEY_R)){
       Player1.papan_y = 100;
         Player2.papan_y = 100;
        Bola.posx = 400;
        Bola.posy = 225;
        Bola.angle =(float) (rand()%26)+30;
        paused = !paused;
        p1.setscoretozero();
        p2.setscoretozero();
    }
    BeginDrawing();
    DrawText("Paused",275,175,50,WHITE);
    DrawText("Hold F1 to continue", 275, 300, 20, WHITE);
    DrawText("Hold R to reset",275,350,20,WHITE );
    EndDrawing();
       }
       
    CloseWindow();
    return 0;
}
