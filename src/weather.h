#ifndef WEATHER_H
#define WEATHER_H

#include <stdint.h>
#include <stdbool.h>
#include <time.h>

// Define the type for a weather effect
typedef struct {
    void (*init)(void);
    void (*update)(double deltaTime);
    void (*draw)(void);
    bool (*is_done)(void);
} WeatherEffect;

// Define the type for a weather system
typedef struct {
    WeatherEffect *effect;
    size_t num_effects;
    size_t current_effect;
    clock_t start_time;
    clock_t duration;
} WeatherSystem;

// Define the type for a rain effect
typedef struct {
    double intensity;
    double speed;
    double direction;
    uint32_t color;
} RainEffect;

// Define the type for a thunder effect
typedef struct {
    double frequency;
    double volume;
    double pan;
    double pitch;
} ThunderEffect;

// Initialize a rain effect
void rain_effect_init(RainEffect *effect, double intensity, double speed, double direction, uint32_t color);

// Update a rain effect
void rain_effect_update(RainEffect *effect, double deltaTime);

// Draw a rain effect
void rain_effect_draw(RainEffect *effect);

// Check if a rain effect is done
bool rain_effect_is_done(RainEffect *effect);

// Initialize a thunder effect
void thunder_effect_init(ThunderEffect *effect, double frequency, double volume, double pan, double pitch);

// Update a thunder effect
void thunder_effect_update(ThunderEffect *effect, double deltaTime);

// Draw a thunder effect
void thunder_effect_draw(ThunderEffect *effect);

// Check if a thunder effect is done
bool thunder_effect_is_done(ThunderEffect *effect);

// Initialize a weather system with rain and thunder effects
void weather_system_init(WeatherSystem *system, RainEffect rain, ThunderEffect thunder, clock_t duration);

// Update the weather system
void weather_system_update(WeatherSystem *system, double deltaTime);

// Draw the weather system
void weather_system_draw(WeatherSystem *system);

// Check if the weather system is done
bool weather_system_is_done(WeatherSystem *system);

#endif // WEATHER_H
