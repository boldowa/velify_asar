/**
 * for generate pre-compiled header
 */
#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>

/**
 * put macros
 */
extern bool vdebug;
#define putdebug(fmt, ...) if(vdebug) fprintf(stderr, "[DEBUG] " fmt "\n", ##__VA_ARGS__)
#define putinfo(fmt, ...)             fprintf(stderr, "[INFO ] " fmt "\n", ##__VA_ARGS__)
#define putwarn(fmt, ...)             fprintf(stderr, "[WARN ] " fmt "\n", ##__VA_ARGS__)
#define puterror(fmt, ...)            fprintf(stderr, "[ERROR] " fmt "\n", ##__VA_ARGS__)
#define putfatal(fmt, ...)            fprintf(stderr, "[FATAL] " fmt "\n", ##__VA_ARGS__)

