#include "../important/main.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

static RainEffect rain_effect;
static ThunderEffect thunder_effect;
static WeatherSystem weather_system;

void rain_effect_init(double intensity, double speed, double direction, uint32_t color) {
    rain_effect.intensity = intensity;
    rain_effect.speed = speed;
    rain_effect.direction = direction;
    rain_effect.color = color;
}

void rain_effect_update(double delta_time) {
    // Update rain effect here
}

void rain_effect_draw() {
    // Draw rain effect here
}

bool rain_effect_is_done() {
    return false;
}

void thunder_effect_init(double frequency, double volume, double pan, double pitch) {
    thunder_effect.frequency = frequency;
    thunder_effect.volume = volume;
    thunder_effect.pan = pan;
    thunder_effect.pitch = pitch;
}

void thunder_effect_update(double delta_time) {
    // Update thunder effect here
}

void thunder_effect_draw() {
    // Draw thunder effect here
}

bool thunder_effect_is_done() {
    return false;
}

void weather_system_init(RainEffect rain, ThunderEffect thunder, clock_t duration) {
    rain_effect_init(rain.intensity, rain.speed, rain.direction, rain.color);
    thunder_effect_init(thunder.frequency, thunder.volume, thunder.pan, thunder.pitch);
    weather_system.effect = malloc(sizeof(RainEffect) + sizeof(ThunderEffect));
    weather_system.num_effects = 2;
    weather_system.current_effect = 0;
    weather_system.start_time = clock();
    weather_system.duration = duration;
    memcpy(weather_system.effect, &rain_effect, sizeof(RainEffect));
    memcpy(weather_system.effect + sizeof(RainEffect), &thunder_effect, sizeof(ThunderEffect));
}

void weather_system_update(double delta_time) {
    clock_t current_time = clock();
    double elapsed_time = (current_time - weather_system.start_time) / (double)CLOCKS_PER_SEC;
    if (elapsed_time > weather_system.duration) {
        // Weather system is done, reset it
        weather_system.current_effect = 0;
        elapsed_time = 0;
    }
    while (elapsed_time > 0) {
        WeatherEffect *effect = weather_system.effect + weather_system.current_effect;
        if (effect->is_done) {
            // Move to the next effect
            weather_system.current_effect = (weather_system.current_effect + 1) % weather_system.num_effects;
            effect = weather_system.effect + weather_system.current_effect;
        }
        effect->update(delta_time);
        elapsed_time -= effect->is_done() ? 0 : delta_time;
    }
}

void weather_system_draw() {
    WeatherEffect *effect = weather_system.effect + weather_system.current_effect;
    effect->draw();
}

bool weather_system_is_done() {
    return clock() - weather_system.start_time > weather_system.duration * CLOCKS_PER_SEC;
}
