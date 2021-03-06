//
//  envelopes.h
//  Wavetable
//
//  Created by Hosack, Matthew on 9/15/15.
//  Copyright (c) 2015 Hosack, Matthew. All rights reserved.
//

#ifndef __ENVELOPES_H__
#define __ENVELOPES_H__

#include "types.h"

typedef struct {
    double attack_t;    /* attack time (5ms - 15sec) */
    double decay_t;     /* decay time (5ms - 15sec)  */
    double sustain_g;   /* gain of sustain (0-1)   */
    double release_t;   /* release time (5ms 15sec)  */
    unsigned int type;  /* linear or exponential */
}envelope_s;

/* The four states of an envelope.
 * 1. Attack - The initial ascent of amplitude
 * 2. Decay - The descent from 1.0 to the sustain level
 * 3. Sustain - The amplitude is held at this level for a period of time
 * 4. Release - The amplitude descends to 0.0 here
 */
enum
{
    ENVELOPE_STATE_ATTACK = 0,
    ENVELOPE_STATE_DECAY,
    ENVELOPE_STATE_SUSTAIN,
    ENVELOPE_STATE_RELEASE,
    ENVELOPE_STATE_DEAD
};

/* The transitions from the attack, decay, sustain,
 * and release states can be linear or exponential.
 * Since human ear's loudness model is exponential,
 * it is advised to use exponential
 */
enum
{
    ENVELOPE_TYPE_LINEAR = 0,
    ENVELOPE_TYPE_EXPONENTIAL
};

envelope_s *env_new(const double attack
                    ,const double decay
                    ,const double sustain
                    ,const double release
                    ,const unsigned int type);
void env_destroy(envelope_s *e);

/* Testing out replacements
 * Use double precisions instead of calculating time diffs internally
 * Note manager can do this time calculation and leave the envelope functions
 * simpler and easier to  test
 */
double envelope_gain(const envelope_s env, const double tsec);
unsigned int envelope_get_state(const envelope_s env, const double tsec);

#endif /* __ENVELOPES_H__ */
