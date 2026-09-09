#ifndef ORION_VELA_BRIDGE_H
#define ORION_VELA_BRIDGE_H

#include <stdint.h>

#define ORION_VELA_REQUIRED_API_MAJOR 1u
#define ORION_VELA_REQUIRED_API_MINOR 2u
#define ORION_VELA_PROFILE_LITE 0u

void vela_init(int viewport_width);
uint32_t vela_api_version(void);
void vela_set_features(uint32_t features);
void vela_set_viewport_size(int viewport_width,int viewport_height);
void vela_input_char(char c);
void vela_backspace(void);
int vela_go(void);
int vela_load_url(const char *url);
int vela_back(void);
int vela_forward(void);
int vela_reload(void);
int vela_can_back(void);
int vela_can_forward(void);
void vela_scroll_by(int delta_y);
int vela_scroll(void);
const char *vela_url(void);
const char *vela_status(void);
const char *vela_title(void);

static inline int orion_vela_api_compatible(uint32_t api){
    uint32_t major=api>>16,minor=api&0xffffu;
    return major==ORION_VELA_REQUIRED_API_MAJOR&&minor>=ORION_VELA_REQUIRED_API_MINOR;
}

#endif
