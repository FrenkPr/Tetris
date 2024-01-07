#include <string.h>
#include "raylib.h"

struct TextObjectInfo
{
    const char *textID;
    int x;
    int y;
    int fontSize;
    char text[1000];
    Color textColor;
    int isActive;
} typedef TextObjectInfo;

TextObjectInfo textObjects[1000];
int currentTextObjectInsertIndex = 0;

void InitTextMngr()
{
    memset(textObjects, 0, sizeof(textObjects));
    currentTextObjectInsertIndex = 0;
}

int GetTextObjectIndex(const char *textID)
{
    for (int i = 0; i < currentTextObjectInsertIndex; i++)
    {
        if (strcmp(textObjects[i].textID, textID) == 0)
        {
            return i;
        }
    }

    return -1;
}

int TextObjectExists(const char *textID)
{
    if(GetTextObjectIndex(textID) != -1)
    {
        return 1;
    }

    return 0;
}

void AddTextObject(const char *textID, int x, int y, int fontSize, char text[1000], Color textColor)
{
    if(TextObjectExists(textID))
    {
        return;
    }

    textObjects[currentTextObjectInsertIndex].textID = textID;
    textObjects[currentTextObjectInsertIndex].x = x;
    textObjects[currentTextObjectInsertIndex].y = y;
    textObjects[currentTextObjectInsertIndex].fontSize = fontSize;
    strcpy_s(textObjects[currentTextObjectInsertIndex].text, sizeof(textObjects[currentTextObjectInsertIndex].text), text);
    textObjects[currentTextObjectInsertIndex].textColor = textColor;
    textObjects[currentTextObjectInsertIndex].isActive = 1;

    currentTextObjectInsertIndex++;
}

void setText(const char *textID, char newText[1000])
{
    int textObjIndex = GetTextObjectIndex(textID);

    if (textObjIndex == -1)
    {
        return;
    }

    strcpy_s(textObjects[textObjIndex].text, sizeof(textObjects[textObjIndex].text), newText);
}

void SetTextVisibility(const char *textID, int value)
{
    int textObjIndex = GetTextObjectIndex(textID);

    if (textObjIndex == -1)
    {
        return;
    }

    textObjects[textObjIndex].isActive = value;
}

void DrawTexts()
{
    for (int i = 0; i < currentTextObjectInsertIndex; i++)
    {
        if (textObjects[i].isActive)
        {
            DrawText(textObjects[i].text, textObjects[i].x, textObjects[i].y, textObjects[i].fontSize, textObjects[i].textColor);
        }
    }
}