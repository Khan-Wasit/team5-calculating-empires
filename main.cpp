/*
 * Project: Calculating Empires - AI Climates & Scaling Explorer
 * Citations:
 * - Crawford, K., & Joler, V. (2023). Calculating Empires: A Genealogy of Technology and Power Since 1500.
 *   (Data points: Symbolic AI, Expert Systems, Machine Learning, Generative AI, AI Winters/Summers, Parameter scales).
 * - Turing, A. M. (1950). Computing Machinery and Intelligence. (Quote referenced in diagram).
 * - Lighthill, J. (1973). Artificial Intelligence: A General Survey. (Lighthill Report quote referenced in diagram).
 */

#include "raylib.h"
#include "AIEra.h"
#include <vector>
#include <iostream>

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "Calculating Empires: Evolution of AI");
    SetTargetFPS(60);

    // Data taken directly from the Calculating Empires AI column
    std::vector<AIEra> timeline = {
        AIEra("1. Symbolic AI (1st AI Summer)", "1956 - 1973", "AI Summer", "Hundreds - Thousands",
              "Dartmouth Workshop, Perceptron, ELIZA, & early logic-based microworlds.",
              "\"Within a generation... the problem of creating 'artificial intelligence' will substantially be solved.\" - Marvin Minsky (1967)",
              2, GOLD),

        AIEra("2. The 1st AI Winter", "1974 - 1980", "AI Winter", "Thousands",
              "DARPA funding cuts and the Lighthill Report expose limits of early symbolic reasoning.",
              "\"In no part of the field have the discoveries made so far produced the major impact that was then promised.\" - James Lighthill (1973)",
              1, SKYBLUE),

        AIEra("3. Expert Systems (2nd Summer & Winter)", "1980 - 1993", "AI Summer -> Winter", "100 Thousand - 1 Million",
              "Rise of rule-based knowledge systems & LISP machines, followed by the 1987 LISP market collapse.",
              "Focus shifted to narrow domain rules, proving fragile and expensive to maintain.",
              3, ORANGE),

        AIEra("4. Machine Learning (3rd AI Spring)", "1993 - 2011", "AI Spring", "1 Million - 100 Million",
              "Shift from hand-coded rules to statistical learning: Deep Blue vs Kasparov, DARPA Grand Challenge.",
              "Algorithms begin learning patterns directly from data rather than explicit human rules.",
              5, GREEN),

        AIEra("5. Generative AI & LLMs (3rd AI Summer)", "2012 - Present", "AI Summer", "Billion - 100 Trillion",
              "ImageNet breakthrough, Transformers, GANs, & Multimodal LLMs requiring massive compute & labor.",
              "Raises critical questions of energy efficiency, data scraping, and corporate consolidation.",
              8, RED)
    };

    int currentIndex = 0;
    std::cout << "Welcome to the Calculating Empires AI Timeline Explorer!\n";
    std::cout << "Use Left/Right arrow keys in the window to explore eras.\n";
    timeline[currentIndex].printTerminalDetails();

    while (!WindowShouldClose()) {
        // Navigation input
        if (IsKeyPressed(KEY_RIGHT)) {
            currentIndex = (currentIndex + 1) % timeline.size();
            timeline[currentIndex].printTerminalDetails();
        }
        if (IsKeyPressed(KEY_LEFT)) {
            currentIndex = (currentIndex - 1 + timeline.size()) % timeline.size();
            timeline[currentIndex].printTerminalDetails();
        }
        if (IsKeyPressed(KEY_T)) {
            timeline[currentIndex].printTerminalDetails();
        }

        // Render
        BeginDrawing();
        ClearBackground({20, 22, 28, 255}); // Dark slate background

        timeline[currentIndex].drawVisuals(screenWidth, screenHeight);

        // Progress bar at top
        float progress = (float)(currentIndex + 1) / timeline.size();
        DrawRectangle(0, 0, (int)(screenWidth * progress), 8, timeline[currentIndex].getThemeColor());

        EndDrawing();
    }

    CloseWindow();
    return 0;
}