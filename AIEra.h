#ifndef AI_ERA_H
#define AI_ERA_H

#include "raylib.h"
#include <string>

// Abstraction: Encapsulates all sociotechnical & technical data of an AI era
class AIEra {
private:
    std::string name;
    std::string years;
    std::string climate;      // "AI Summer" or "AI Winter"
    std::string paramScale;   // e.g., "Hundreds" up to "100 Trillion"
    std::string summary;
    std::string quote;
    int treeDepth;            // Used for recursive visual scaling
    Color themeColor;

public:
    AIEra(std::string n, std::string y, std::string c, std::string p, 
          std::string s, std::string q, int depth, Color col);

    void drawVisuals(int screenWidth, int screenHeight) const;
    void printTerminalDetails() const;
    int getTreeDepth() const;
    Color getThemeColor() const;
};

#endif