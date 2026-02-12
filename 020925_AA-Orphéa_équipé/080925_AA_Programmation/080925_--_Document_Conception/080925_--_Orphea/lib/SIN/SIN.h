/***************************************************************
 * @file        SIN.h
 * @author      Lorenzo S. & Quentin P. & William L-C
 * @version     1
 * @date        2026-01-24
 * @brief       Gestion des signaux sinusoïdaux.
 * @details     SAE S5-S6 BUG GEII FA ESE
 * @copyright   (c) Lorenzo S. & Quentin P. & William L-C - Tous droits réservés
 ***************************************************************/

#ifndef SIN_H
#define SIN_H

#include <stdint.h>

// --- Paramètres de la table DDS ---
#define SINE_TABLE_SIZE 1024         // Nombre de points (2^10)
#define SINE_TABLE_BITS 10           // log2(SINE_TABLE_SIZE)
#define SINE_TABLE_SHIFT (32 - SINE_TABLE_BITS) // 22 (Bits à décaler pour l'indexation)

// Facteur d'échelle maximum pour l'amplitude 16-bit
#define SCALE_FACTOR 32767.0f 

// Déclaration de la table (accessible en lecture seule)
extern const int16_t sineTable[SINE_TABLE_SIZE];

#endif // SINE_TABLE_H