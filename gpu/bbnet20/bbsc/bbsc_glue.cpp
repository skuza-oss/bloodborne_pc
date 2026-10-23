// SPDX-License-Identifier: GPL-2.0-or-later
// bbport online module: what BBSC (shadps4/core/bloodborne_re.cpp, GPL-2.0+)
// needs from shadPS4's UI. Its loading screen is a line in the port's overlay; its animated title
// card (off by default in BBSC too) is not ported.
#include <cstdio>
#include <string_view>

#include "bbgpu.h"

#include "imgui/bbsc_intro_layer.h"
#include "imgui/bbsc_loading_layer.h"

namespace Core::Bbsc {

void ShowLoadingScreen(LoadingScreenKind kind) {
    // The port's overlay line (BBSC draws its own loading screen in shadPS4's ImGui layer).
    bbgpu_overlay_banner(kind == LoadingScreenKind::Summon ? "Joining the host's world..."
                                                           : "Following the host...");
}

void HideLoadingScreen() {
    bbgpu_overlay_banner(nullptr);
}

void ShowPlayerMarkers(const PlayerMarker* markers, int count) {
    BbGpuMarker out[8];
    const int n = count < 0 ? 0 : count > 8 ? 8 : count;
    for (int i = 0; i < n; ++i) {
        out[i].x = markers[i].x;
        out[i].y = markers[i].y;
        std::snprintf(out[i].text, sizeof(out[i].text), "%s", markers[i].text);
    }
    bbgpu_overlay_markers(out, n);
}

void StartIntro(std::string_view) {}

} // namespace Core::Bbsc
