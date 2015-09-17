//
//  utils.c
//  Wavetable
//
//  Created by Hosack, Matthew on 9/16/15.
//  Copyright (c) 2015 Hosack, Matthew. All rights reserved.
//

#include "utils.h"

void time_now(synth_time_t *t)
{
    gettimeofday(t, NULL);
}

double elapsed_time_ms(synth_time_t start, synth_time_t end)
{
    return ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
}

double elapsed_time(synth_time_t start, synth_time_t end)
{
    return elapsed_time_ms(start, end) / 1000.0;
}
