#include "AIEra.h"
#include <iostream>
#include <cmath>

// Helper recursive function to represent growing model complexity & abstraction
void drawRecursiveBranches(float x, float y, float length, float angle, int depth, Color col) {
    if (depth <= 0) return; // Base case

    float endX = x + cosf(angle * DEG2RAD) * length;
    float endY = y - sinf(angle * DEG2RAD) * length;

    DrawLineEx({x, y}, {endX, endY}, (float)depth * 1.5f, col);

    // Recursive calls for left and right branches
    drawRecursiveBranches(endX, endY, length * 0.72f, angle - 28.0f, depth - 1, col);
    drawRecursiveBranches(endX, endY, length * 0.72f, angle + 28.0f, depth - 1, col);
}

AIEra::AIEra(std::string n, std::string y, std::string c, std::string p, 
             std::string s, std::string q, int depth, Color col)
    : name(n), years(y), climate(c), paramScale(p), summary(s), quote(q), treeDepth(depth), themeColor(col) {}

void AIEra::drawVisuals(int screenWidth, int screenHeight) const {
    // Draw recursive tree representing parameter/compute growth
    drawRecursiveBranches(screenWidth / 2.0f, screenHeight - 80.0f, 95.0f, 90.0f, treeDepth, themeColor);

    // Draw UI Text
    DrawText(name.c_str(), 40, 40, 36, WHITE);
    DrawText(("Period: " + years + "  |  Climate: " + climate).c_str(), 40, 85, 22, themeColor);
    DrawText(("Parameter Scale: " + paramScale).c_str(), 40, 115, 20, LIGHTGRAY);
    DrawText(summary.c_str(), 40, 155, 18, RAYWHITE);

    // Controls hint at bottom
    DrawText("Press [LEFT / RIGHT] Arrows to travel through time | Press [T] to print full research in Terminal", 
             40, screenHeight - 35, 18, GRAY);
}

void AIEra::printTerminalDetails() const {
    std::cout << "\n========================================\n";
    std::cout << "ERA: " << name << " (" << years << ")\n";
    std::cout << "CLIMATE: " << climate << " | PARAMETERS: " << paramScale << "\n";
    std::cout << "NOTES: " << summary << "\n";
    std::cout << "HISTORICAL QUOTE: " << quote << "\n";
    std::cout << "========================================\n";
}

int AIEra::getTreeDepth() const { return treeDepth; }
Color AIEra::getThemeColor() const { return themeColor; }