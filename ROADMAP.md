# Orion Browser Roadmap

## 0.2 — shared Vela/Aster recovery shell
- use UN_Vela 0.3 API instead of a separate HTTP/text engine
- select `VELA_PROFILE_LITE` so JavaScript stays disabled
- share HTML/CSS/layout/history/scroll behavior with the full browser
- retain a tiny shell ABI for rescue environments
- validate Vela API compatibility before forwarding calls

## Next
- expose an optional compact painter/control surface for rescue UI
- define explicit memory ceilings for low-RAM targets
- add host capability reporting for HTTP/TLS/resources
- add recovery-focused keyboard navigation
