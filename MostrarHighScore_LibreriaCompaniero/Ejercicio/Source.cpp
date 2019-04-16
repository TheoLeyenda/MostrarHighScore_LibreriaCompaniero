#include "../raylib/include/raylib.h"
#include "../include/Score.h"
#include "../include/ScoreManager.h"
#include <stdlib.h>
#include <time.h>
#define TAM 5
#define TAM_NOMBRE 125
int main()
{
	srand(time(NULL));
	ScoreManager *sm = new ScoreManager();
	Score *score = new Score();

	string nombres[TAM]{"Theo Leyenda", "Rozameel trozo", "Debora meeltrozo", "pene-lopè","JORGE EL CURIOSO"};
	int puntajes[TAM];
	for (int i = 0; i < TAM; i++) {
		puntajes[i] = rand() % 2000 + 100;
	}
	for (int i = 0; i < TAM; i++) {
		score->scorePlayer = nombres[i];
		score->scoreValue = puntajes[i];
		sm->AddScore(*score);
	}
	
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		int X_Nombre = 200;
		int X_Puntaje = X_Nombre + 200;
		string nombre;
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		/*
		DrawText("High Score", 250, 0, 48, BLUE);
		DrawText(HS->GetPlayerScore(0).nombre, X_Puntaje, 48, 32, BLUE);
		DrawText(FormatText("%i", HS->GetPlayerScore(0).GetPuntaje()), X_Nombre, 48, 32, BLUE);
		for (int i = 1; i < TAM; i++) {
			DrawText(HS->GetPlayerScore(i).nombre, X_Puntaje, ((i + 1) * 48), 32, BLUE);
			DrawText(FormatText("%i", HS->GetPlayerScore(i).GetPuntaje()), X_Nombre, ((i + 1) * 48), 32, BLUE);
		}
		*/
		DrawText("High Score", 250, 0, 48, BLUE);
		nombre = sm->getScoreBoard()[0].scorePlayer;
		DrawText(nombre.c_str(), X_Puntaje, 48, 32, BLUE);
		DrawText(FormatText("%i", sm->getScoreBoard()[0].scoreValue), X_Nombre, 48, 32, BLUE);
		for (int i = 1; i < TAM; i++) {
			nombre = sm->getScoreBoard()[i].scorePlayer;
			DrawText(nombre.c_str(), X_Puntaje, ((i + 1) * 48), 32, BLUE);
			DrawText(FormatText("%i", sm->getScoreBoard()[i].scoreValue), X_Nombre, ((i + 1) * 48), 32, BLUE);
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	delete score;
	delete sm;
	return 0;
}