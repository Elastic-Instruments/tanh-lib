#pragma once

// Types of the XY touch path: the fingers on a pad (detail::XYPad) and which one drives it.

#include <tanh/core/AbiNamespace.h>

#include <cstddef>
#include <cstdint>

namespace thl::inline THL_ABI_NAMESPACE::modulation {

/// Identifies one finger for its lifetime (a JUCE mouse source index, a UITouch
/// pointer, a React Native touch identifier).
using TouchId = uint64_t;

/// Fingers tracked at once per pad.
inline constexpr uint32_t k_xy_pad_max_touches = 16;

/// Which of several fingers on one pad drives it.
enum class MonoPriority : uint8_t {
    Last,  ///< the most recent touch; releasing it falls back to the newest remaining one
    First  ///< the oldest touch; later touches only take over when it is released
};

}  // namespace thl::inline THL_ABI_NAMESPACE::modulation
