# Orion Browser

Orion Browser is the lightweight fallback/recovery browser for UN_Orion.

It is intentionally **not** the same product as UN_Vela:

- **UN_Vela** is the primary browser and uses Aster Engine.
- **Orion Browser** stays small, text-oriented and independent from Aster.

The purpose of keeping Orion Browser is resilience: if the higher-level HTML engine is incomplete or broken, UN_Orion should still have a tiny HTTP client capable of displaying readable text and checking local/router services.

## Current design

`HTTP -> legacy text normalization -> Orion Browser text viewport`

Planned uses:
- rescue/recovery environment
- router/OpenWrt administration pages when text is sufficient
- diagnostics for HTTP services
- low-memory mode

## Layout

- `include/orion_browser.h` — small browser ABI
- `src/orion_browser.c` — browser shell/reference implementation
