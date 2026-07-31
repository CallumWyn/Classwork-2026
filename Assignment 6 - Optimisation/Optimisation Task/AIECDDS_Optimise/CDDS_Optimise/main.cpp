#include "raylib.h"
#include "raymath.h"
#include <random>
#include <time.h>
#include "Critter.h"
#include <stdlib.h>
#include <iostream>
#include "Quadtree.h"


// FILE 1

int main(int argc, char* argv[]){
    // Initialization
    float* timer = new float(1);
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "CDDS Optimization - sample project");
    //SetTargetFPS(60);
    srand(time(NULL)); 

    Quadtree quadtree(screenWidth / 2, screenHeight / 2, screenWidth, screenHeight, 8);

    
    float* highestFPS = new float(0);

    //----------------------------------create some critters----------------------------------------------------
    const int* CRITTER_COUNT = new int(50);
    Critter critters[1000];

    const int* MAX_VELOCITY = new int(80);

    Vector2* velocity = new Vector2();

    *velocity = // create a random direction vector for the velocity
    {
        -(float)100 + (rand() % 200),
        -(float)100 + (rand() % 200)
    };
    *velocity = Vector2Scale(Vector2Normalize(*velocity), *MAX_VELOCITY); // normalize and scale by a random speed



    for (int i = 0; i < *CRITTER_COUNT; i++){     
        

        *velocity = // create a random direction vector for the velocity
        { 
            -(float)100 + (rand() % 200), 
            -(float)100 + (rand() % 200) 
        }; 
        *velocity = Vector2Scale(Vector2Normalize(*velocity), *MAX_VELOCITY); // normalize and scale by a random speed

        critters[i].Init( // create a critter in a random location
            { 
                (float)(5 + rand() % (screenWidth - 10)), 
                (float)(5 + (rand() % (screenHeight - 10))) 
            },
            *velocity,
            12, 
            "res/10.png"
        );
        quadtree.Insert(critters[i]);
    }

    //-----------------------------------create destroyer--------------------------------------------------------
    Critter* destroyer = new Critter();
    *velocity = 
    { 
        -(float)100 + (rand() % 200), 
        -(float)100 + (rand() % 200) 
    };
    *velocity = Vector2Scale(Vector2Normalize(*velocity), *MAX_VELOCITY);
    destroyer->Init(Vector2{ (float)(screenWidth >> 1), (float)(screenHeight >> 1) }, *velocity, 20, "res/9.png");
    Vector2 nextSpawnPos = destroyer->GetPosition();
    
    system("cls");

    //--------------------------------------Main game loop------------------------------------------------
    while (!WindowShouldClose()) { // Detect window close button or ESC key

        if (GetFPS() > *highestFPS) {
            *highestFPS = GetFPS();
            std::cout << "Highest FPS: " << *highestFPS << '\n';
        }

        // update time
        float delta = GetFrameTime();
        //---------------------------------------------------destroyer-----------------------------------
        // update the destroyer by check against screen bounds
        destroyer->Update(delta);
        if (destroyer->GetX() < 0) {
            destroyer->SetX(0);
            destroyer->SetVelocity(Vector2{ -destroyer->GetVelocity().x, destroyer->GetVelocity().y });
        }
        if (destroyer->GetX() > screenWidth) {
            destroyer->SetX(screenWidth);
            destroyer->SetVelocity(Vector2{ -destroyer->GetVelocity().x, destroyer->GetVelocity().y });
        }
        if (destroyer->GetY() < 0) {
            destroyer->SetY(0);
            destroyer->SetVelocity(Vector2{ destroyer->GetVelocity().x, -destroyer->GetVelocity().y });
        }
        if (destroyer->GetY() > screenHeight) {
            destroyer->SetY(screenHeight);
            destroyer->SetVelocity(Vector2{ destroyer->GetVelocity().x, -destroyer->GetVelocity().y });
        }

        //------------------------------------------------------------critters--------------------------
        // update the critters - (dirty flags will be cleared during update)
        for (int i = 0; i < *CRITTER_COUNT; i++){
                critters[i].Update(delta);
                // check each critter against screen bounds
                if (critters[i].GetX() < 0) {
                    critters[i].SetX(0);
                    critters[i].SetVelocity(Vector2{ -critters[i].GetVelocity().x, critters[i].GetVelocity().y });
                }
                if (critters[i].GetX() > screenWidth) {
                    critters[i].SetX(screenWidth);
                    critters[i].SetVelocity(Vector2{ -critters[i].GetVelocity().x, critters[i].GetVelocity().y });
                }
                if (critters[i].GetY() < 0) {
                    critters[i].SetY(0);
                    critters[i].SetVelocity(Vector2{ critters[i].GetVelocity().x, -critters[i].GetVelocity().y });
                }
                if (critters[i].GetY() > screenHeight) {
                    critters[i].SetY(screenHeight);
                    critters[i].SetVelocity(Vector2{ critters[i].GetVelocity().x, -critters[i].GetVelocity().y });
                }
            
            // kill any critter touching the destroyer
            // simple circle-to-circle collision check
            float dist = Vector2Distance(critters[i].GetPosition(), destroyer->GetPosition());
            if (dist < critters[i].GetRadius() + destroyer->GetRadius()) {
                // This looks the same from here, but I removed the unload_texture method from the destroy function, so it doesn't take as many resources
                // Instead, it just turns the m_isLoaded bool to false, effectively disabling the object by stopping all of the functions in it.
                critters[i].Destroy();
                
            }
        }

        //-------------------------------------------------------collision check--------------------------   
        // 
        // 
        // THIS IS WHAT WE NEED A QUAD TREE
        // 
        // check for critter-on-critter collisions


        quadtree.Update(critters, *CRITTER_COUNT);
        quadtree.checkQuads();
        // quadtree.debugCheck();

        
        

        //for (int i = 0; i < *CRITTER_COUNT; i++) {
        //    for (int j = 0; j < *CRITTER_COUNT; j++) {
        //        if (i == j || critters[i].IsDirty()) continue; // note: the other critter (j) could be dirty - that's OK    
        //        // check every critter against every other critter
        //        float dist = Vector2Distance(critters[i].GetPosition(), critters[j].GetPosition());
        //        if (dist < critters[i].GetRadius() + critters[j].GetRadius()) {// <-- collision!.. do math to get critters bouncing
        //            Vector2 normal = Vector2Normalize(Vector2Subtract(critters[j].GetPosition(), critters[i].GetPosition()));
        //            critters[i].SetVelocity(Vector2Scale(normal, -*MAX_VELOCITY)); // not even close to real physics, but fine for our needs
        //            critters[i].SetDirty(); // set the critter to *dirty* so we know not to process any more collisions on it
        //            // we still want to check for collisions in the case where 1 critter is dirty - so we need a check 
        //            // to make sure the other critter is clean before we do the collision response
        //            if (!critters[j].IsDirty()) {
        //                critters[j].SetVelocity(Vector2Scale(normal, *MAX_VELOCITY));
        //                critters[j].SetDirty();
        //            }
        //            break;
        //        }
        //    }
        //    
        //}

        //-------------------------------------------------------respawn check--------------------------   
        // find any dead critters and spit them out (respawn) 
        *timer -= delta;
        if (*timer <= 0) {
            *timer = 1;
            for (int i = 0; i < *CRITTER_COUNT; i++) {
                if (critters[i].IsDead()) {
                    Vector2 normal = Vector2Normalize(destroyer->GetVelocity());
                    // get a position behind the destroyer, and far enough away that the critter won't bump into it again
                    Vector2 pos = destroyer->GetPosition();
                    pos = Vector2Add(pos, Vector2Scale(normal, -50));
                    // I made a new function called ReInit, which does everything Init does except it doesn't load a texture
                    critters[i].ReInit(
                        pos,
                        Vector2Scale(normal, -*MAX_VELOCITY),
                        12
                    );
                    break;
                }
            }
            nextSpawnPos = destroyer->GetPosition();
        }



        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(DARKGRAY);
        for (int i = 0; i < *CRITTER_COUNT; i++) { critters[i].Draw(); } // draw the critters
        destroyer->Draw(); // draw the destroyer
        // (if you're wondering why it looks a little odd when sometimes critters are destroyed when they're not quite touching the 
        // destroyer, it's because the origin is at the top-left. ...you could fix that!)

        DrawFPS(10, 10);

        //DrawText(" -- data -- ", 200, 10, 40, LIGHTGRAY);

        EndDrawing();
    }

    //---------------------------------------De-Initialization-------------------------------------------
    for (int i = 0; i < *CRITTER_COUNT; i++) { critters[i].Destroy(); } // destroy items after exit the main loop
    destroyer->Destroy();

    delete timer;
    delete highestFPS;
    delete CRITTER_COUNT;
    delete MAX_VELOCITY;
    delete velocity;
    delete destroyer;

    timer = nullptr;
    highestFPS = nullptr;
    CRITTER_COUNT = nullptr;
    MAX_VELOCITY = nullptr;
    velocity = nullptr;
    destroyer = nullptr;

    CloseWindow(); // Close window and OpenGL context

    return 0;
}

//std::cout << time;
//auto startTime = std::chrono::high_resolution_clock::now();


//for(int i = 0; i < 1000; i++){
//    int b = i;
//    Critter c;
//    c.Init(
//        {
//            (float)(5 + rand() % (screenWidth - 10)),
//            (float)(5 + (rand() % (screenHeight - 10)))
//        },
//        *velocity,
//        12,
//        "res/10.png"
//    );

//    //std::cout << c.GetX() << " : " << c.GetY() << "\n";

//    bool a = quadtree.AABB(screenWidth / 4, screenHeight / 4, screenWidth / 4, screenHeight / 4, c);
//    //std::cout << a << "\n";

//    //std::cout << c.GetX() << " : " << c.GetY() << "\n";
//}
//

//auto endTime = std::chrono::high_resolution_clock::now();

//auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);


//std::cout << duration.count();