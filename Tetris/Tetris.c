#include "raylib.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "GridMngr.h"
#include "Tetromino.h"
#include "DrawTextMngr.h"

const int windowWidth = 600;
const int windowHeight = 700;

char scoreLbl[20] = "SCORE: ";
char scoreTxt[12] = "0";
// int score = 2147483646;
int score = 0;

int isGameOver = 0;
float gameOverCountDown = 3;

Music mainLoopMusic;
int isMainLoopMusicStopped = 0;

int GameOverCheck()
{
    int y = 0;

    for (int x = 1; x < STAGE_WIDTH - 1; x++)
    {
        const int offset = y * STAGE_WIDTH + x;

        if (stage[offset] != 0) // if the top of the grid is not filled
        {
            return 1;
        }
    }

    return 0;
}

void OnGameOver()
{
    gameOverCountDown -= GetFrameTime();

    if (gameOverCountDown <= 0 && !isGameOver)
    {
        SetTextVisibility("gameOverText", 1);
        isGameOver = 1;
    }
}

void InitGame()
{
    // variables init
    isTetrominoActive = 1;

    moveTetrominoDownTimer = 1.f;
    timeToMoveTetrominoDownAutomatically = 0.0f;

    score = 0;
    _itoa_s(score, scoreTxt, sizeof(scoreTxt), 10);

    memcpy_s(stage, sizeof(stage), stageOnStart, sizeof(stageOnStart));

    memset(blinkStage, 0, sizeof(blinkStage));
    stageStartOffsetX = (windowWidth / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2);
    stageStartOffsetY = (windowHeight / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2);

    currentTetrominoX = tetrominoStartX;
    currentTetrominoY = tetrominoStartY;

    currentTetrominoType = GetRandomValue(0, 6);
    currentRotation = 0;

    timeToMoveTetrominoDownAutomatically = moveTetrominoDownTimer;
    currentColorIndex = GetRandomValue(0, 7);

    time_t unixTime;

    time(&unixTime);
    SetRandomSeed(unixTime);

    InitTextMngr();

    AddTextObject("scoreText", 20, 20, 40, "SCORE: ", WHITE);
    AddTextObject("gameOverText", 110, 250, 60, "GAME OVER", RED);
    SetTextVisibility("gameOverText", 0);

    StopMusicStream(mainLoopMusic);
    PlayMusicStream(mainLoopMusic);

    isMainLoopMusicStopped = 0;
}

void LoadAudio()
{
    mainLoopMusic = LoadMusicStream("assets/tetris_main_loop.mp3");
}

int main(int argc, char **argv /*, char **environ*/)
{
    InitAudioDevice();
    LoadAudio();

    InitGame();

    InitWindow(windowWidth, windowHeight, "Tetris");

    // sets Vsync
    SetTargetFPS(60);

    // TraceLog(LOG_INFO, "Number of arguments : %d", argc);

    // for (int i = 0; i < argc; i++)
    // {
    //     TraceLog(LOG_INFO, "Argument : %d = %s", i, argv[i]);
    // }

    // while (*environ != 0)
    // {
    //     TraceLog(LOG_INFO, "Argument : %s", *environ);
    //     environ++;
    // }

    while (!WindowShouldClose())
    {
        if (isGameOver)
        {
            if (IsKeyPressed(KEY_R))
            {
                InitGame();

                isGameOver = 0;
                gameOverCountDown = 3;
            }

            BeginDrawing();
            ClearBackground(BLUE);

            DrawStage();
            DrawTetromino(colorTypes[currentColorIndex], tetrominoTypes[currentTetrominoType][currentRotation]);

            DrawTexts();

            EndDrawing();

            continue;
        }

        if(IsKeyPressed(KEY_P))
        {
            isMainLoopMusicStopped = !isMainLoopMusicStopped;

            if(isMainLoopMusicStopped)
            {
                StopMusicStream(mainLoopMusic);
            }

            else
            {
                PlayMusicStream(mainLoopMusic);
            }
        }


        UpdateMusicStream(mainLoopMusic); // Update mainLoopMusic buffer with new stream data

        strcpy_s(scoreLbl, sizeof(scoreLbl), "SCORE: ");
        strcat_s(scoreLbl, sizeof(scoreLbl), scoreTxt);

        setText("scoreText", scoreLbl);

        RotateTetromino();
        UpdateTetromino();

        BeginDrawing();
        ClearBackground(BLUE);

        DrawStage();
        DrawTetromino(colorTypes[currentColorIndex], tetrominoTypes[currentTetrominoType][currentRotation]);

        DrawTexts();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}