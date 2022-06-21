#pragma once
#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

namespace ImGui
{
    void AddShadow(ImVec2 rectPos, ImVec2 rectSize, float sigma, int rings, int spacingBetweenRings, int samplesPerCornerSide, int spacingBetweenSamples, ImColor shadowColor, ImVec2 shadowOffset = ImVec2(0, 0));
}
