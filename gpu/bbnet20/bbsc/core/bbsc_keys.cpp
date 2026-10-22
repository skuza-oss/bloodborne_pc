// SPDX-License-Identifier: GPL-2.0-or-later
// bbport: keys BBSC reads in the game window (bbsc_keys.h). Its own file: bloodborne_re.cpp keeps
// <windows.h> out.
#include "core/bbsc_keys.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <array>
#endif

namespace Core::Bbsc {

int KeyPressed(int vk) {
#ifdef _WIN32
    static std::array<bool, 256> was_down{};
    if (vk <= 0 || vk >= 256) {
        return 0;
    }
    const bool down = (GetAsyncKeyState(vk) & 0x8000) != 0;
    const bool pressed = down && !was_down[vk];
    was_down[vk] = down;
    if (!pressed) {
        return 0;
    }
    DWORD pid = 0;
    GetWindowThreadProcessId(GetForegroundWindow(), &pid);
    if (pid != GetCurrentProcessId()) {
        return 0; // pressed in another window
    }
    return (GetAsyncKeyState(VK_CONTROL) & 0x8000) != 0 ? 2 : 1;
#else
    (void)vk;
    return 0;
#endif
}

} // namespace Core::Bbsc
