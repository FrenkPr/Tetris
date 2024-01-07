#include "raylib.h"

#define TETROMINO_SIZE 4

const int lTetromino0[] =
    {
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
};

const int lTetromino90[] =
    {
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int lTetromino180[] =
    {
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int lTetromino270[] =
    {
        0,
        0,
        1,
        0,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int jTetromino0[] =
    {
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int jTetromino90[] =
    {
        1,
        0,
        0,
        0,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int jTetromino180[] =
    {
        0,
        1,
        1,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int jTetromino270[] =
    {
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
};

const int oTetromino[] =
    {
        1,
        1,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int sTetromino0[] =
    {
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int sTetromino90[] =
    {
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
};

const int sTetromino180[] =
    {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        0,
        1,
        1,
        0,
        0,
};

const int sTetromino270[] =
    {
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
};

const int tTetromino0[] =
    {
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int tTetromino90[] =
    {
        0,
        1,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int tTetromino180[] =
    {
        0,
        1,
        0,
        0,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int tTetromino270[] =
    {
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int iTetromino0[] =
    {
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
};

const int iTetromino90[] =
    {
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int iTetromino180[] =
    {
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
};

const int iTetromino270[] =
    {
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int zTetromino0[] =
    {
        0,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
};

const int zTetromino90[] =
    {
        0,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
};

const int zTetromino180[] =
    {
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
};

const int zTetromino270[] =
    {
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
};

const Color colorTypes[8] =
    {
        {255, 255, 85, 255},
        {85, 43, 158, 255},
        {56, 255, 85, 255},
        {255, 255, 63, 255},
        {255, 42, 85, 255},
        {255, 100, 85, 255},
        {97, 5, 85, 255},
        {85, 45, 63, 255},
};

const int *tetrominoTypes[7][4] =
    {
        {zTetromino0, zTetromino90, zTetromino180, zTetromino270},
        {sTetromino0, sTetromino90, sTetromino180, sTetromino270},
        {tTetromino0, tTetromino90, tTetromino180, tTetromino270},
        {oTetromino, oTetromino, oTetromino, oTetromino},
        {iTetromino0, iTetromino90, iTetromino180, iTetromino270},
        {jTetromino0, jTetromino90, jTetromino180, jTetromino270},
        {lTetromino0, lTetromino90, lTetromino180, lTetromino270},
};

extern int stageStartOffsetX;
extern int stageStartOffsetY;

const int tetrominoStartX = STAGE_WIDTH / 2;
const int tetrominoStartY = 0;

int currentTetrominoX = 0;
int currentTetrominoY = 0;

int currentTetrominoType = 0;
int currentRotation = 0;

int isTetrominoActive = 1;

float moveTetrominoDownTimer = 1.f;
const float moveTetrominoDownInputKeyTimer = 0.1f;
const float moveTetrominoLaterallyTimer = 0.15f;

float timeToMoveTetrominoDownAutomatically = 0.0f;
float timeToMoveTetrominoDownInputKey = 0.0f;

float timeToMoveTetrominoLaterally = 0.0f;

int currentColorIndex = 0;

extern int stage[];
extern const int *tetrominoTypes[7][4];

extern void DeleteLines();
extern int GameOverCheck();
extern void OnGameOver();

int CheckCollision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino)
{
    for (int y = 0; y < TETROMINO_SIZE; y++)
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if (tetromino[offset] == 1)
            {
                const int offset_stage = (y + tetrominoStartY) * STAGE_WIDTH + (x + tetrominoStartX);

                if (stage[offset_stage] != 0)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void BlockTetrominoOnGround()
{
    if (isTetrominoActive)
    {
        for (int y = 0; y < TETROMINO_SIZE; y++)
        {
            for (int x = 0; x < TETROMINO_SIZE; x++)
            {
                const int offset = y * TETROMINO_SIZE + x;

                const int *tetromino = tetrominoTypes[currentTetrominoType][currentRotation];

                if (tetromino[offset] == 1)
                {
                    const int offset_stage = (y + currentTetrominoY) * STAGE_WIDTH + (x + currentTetrominoX);

                    stage[offset_stage] = currentColorIndex + 1;
                }
            }
        }
    }

    if (GameOverCheck())
    {
        OnGameOver();
    }

    if (HasStageLinesToDelete() || HasBlinkStageLinesToDelete())
    {
        timeToBlinkLine -= GetFrameTime();

        if (currentNumBlinks > 0)
        {
            isTetrominoActive = 0;

            if (timeToBlinkLine <= 0)
            {
                BlinkLines();
            }
        }

        else
        {
            DeleteLines();
        }
    }

    currentTetrominoX = tetrominoStartX;
    currentTetrominoY = tetrominoStartY;

    currentTetrominoType = GetRandomValue(0, 6);
    currentRotation = 0;
    currentColorIndex = GetRandomValue(0, 7);
}

void RotateTetromino()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        const int lastRotation = currentRotation;

        currentRotation++;

        if (currentRotation > 3)
        {
            currentRotation = 0;
        }

        if (CheckCollision(currentTetrominoX, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]))
        {
            currentRotation = lastRotation;
        }
    }
}

void UpdateTetromino()
{
    if (!isTetrominoActive)
    {
        BlockTetrominoOnGround();
        return;
    }

    timeToMoveTetrominoDownAutomatically -= GetFrameTime();

    // moves the tetromino laterally
    if (IsKeyDown(KEY_LEFT) && (IsKeyDown(KEY_RIGHT)))
    {
    }

    else
    {
        if (IsKeyDown(KEY_RIGHT))
        {
            timeToMoveTetrominoLaterally -= GetFrameTime();

            // No need to check overflow, wall is your protector
            if (!CheckCollision(currentTetrominoX + 1, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]) && timeToMoveTetrominoLaterally <= 0)
            {
                currentTetrominoX++;
                timeToMoveTetrominoLaterally = moveTetrominoLaterallyTimer;
            }
        }

        else if (IsKeyDown(KEY_LEFT))
        {
            timeToMoveTetrominoLaterally -= GetFrameTime();

            // No need to check overflow, wall is your protector
            if (!CheckCollision(currentTetrominoX - 1, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]) && timeToMoveTetrominoLaterally <= 0)
            {
                currentTetrominoX--;
                timeToMoveTetrominoLaterally = moveTetrominoLaterallyTimer;
            }
        }

        else
        {
            timeToMoveTetrominoLaterally = 0;
        }
    }
    // end moves the tetromino laterally

    // moves the tetromino down
    if (IsKeyDown(KEY_DOWN))
    {
        timeToMoveTetrominoDownInputKey -= GetFrameTime();
    }

    else
    {
        timeToMoveTetrominoDownInputKey = 0;
    }

    if (timeToMoveTetrominoDownAutomatically <= 0 || (IsKeyDown(KEY_DOWN) && timeToMoveTetrominoDownInputKey <= 0))
    {
        if (!CheckCollision(currentTetrominoX, currentTetrominoY + 1, tetrominoTypes[currentTetrominoType][currentRotation]))
        {
            currentTetrominoY++;
            timeToMoveTetrominoDownAutomatically = moveTetrominoDownTimer;
            timeToMoveTetrominoDownInputKey = moveTetrominoDownInputKeyTimer;
        }

        else
        {
            BlockTetrominoOnGround();
        }
    }
}

void DrawTetromino(const Color tetrominoColor, const int *tetromino)
{
    if (!isTetrominoActive)
    {
        return;
    }

    for (int y = 0; y < TETROMINO_SIZE; y++)
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if (tetromino[offset] == 1)
            {
                DrawRectangle((x + currentTetrominoX) * TILE_SIZE + stageStartOffsetX, (y + currentTetrominoY) * TILE_SIZE + stageStartOffsetY, TILE_SIZE, TILE_SIZE, tetrominoColor);
            }
        }
    }
}