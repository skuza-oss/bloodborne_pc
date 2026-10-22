// SPDX-License-Identifier: GPL-2.0-or-later
// bbport: keys BBSC reads in the game window (F9 / Ctrl+F9, bloodborne_re.cpp "Lock keys").
#pragma once

namespace Core::Bbsc {

/// A key's press since the last call: 0 none, 1 alone, 2 with Ctrl. Only while the game's window has
/// the focus; Windows only (elsewhere always 0). `vk` is a Windows virtual-key code.
int KeyPressed(int vk);

} // namespace Core::Bbsc
