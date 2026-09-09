# Vela Lite integration

Orion Browser 0.2 is a shell, not a second rendering engine. Consumers link the shell with UN_Vela 0.3/Aster 0.3 and a host carrier. Initialization checks Vela API 1.2+ and selects `VELA_PROFILE_LITE`.

The shell deliberately leaves JavaScript disabled. HTML, CSS layout, URL resolution, history and scrolling stay shared with the full browser. Network, TLS and binary resource support are capabilities of the carrier rather than code duplicated in this repository.
