# Orion Browser

Orion Browser is the lightweight recovery shell for UN_Orion.

Since 0.2.0 it **does not carry a second browser engine**. It is a thin adapter over the same UN_Vela 0.3 + Aster runtime used by the full browser, but selects `VELA_PROFILE_LITE` immediately after initialization.

## Why a Lite shell

The shared core means fixes to HTML parsing, CSS layout, URL resolution, history and scrolling are inherited instead of being reimplemented here. The Lite profile keeps the recovery path conservative:

- JavaScript is disabled.
- The shell itself owns no image decoder or network stack.
- Network/TLS/resource capabilities remain supplied by the host carrier.
- HTML/CSS/layout/history/scroll come from UN_Vela/Aster.
- ABI compatibility is checked before the shell forwards calls.

This preserves the original recovery goal without maintaining a divergent HTTP/text browser.

## Runtime path

`Orion Browser shell -> UN_Vela 0.3 Lite profile -> Aster 0.3 -> host carrier`

On UN_Orion the carrier can remain very small. On hosted Windows/Linux/macOS builds the same Vela runtime can use the platform HTTPS carrier.

## Compatibility

The shell requires UN_Vela API major 1, minor 2 or newer within API major 1. `include/orion_vela_bridge.h` is a small ABI declaration bridge; it deliberately does not vendor another copy of UN_Vela or Aster.

## Layout

- `include/orion_browser.h` — recovery-shell API
- `include/orion_vela_bridge.h` — minimal UN_Vela 0.3 ABI bridge
- `src/orion_browser.c` — Lite-profile adapter
- `tests/lite_smoke.c` — ABI/profile forwarding smoke test
