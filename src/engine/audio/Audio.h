/*
===========================================================================

daemon gpl source code
copyright (c) 2013 unvanquished developers

this file is part of the daemon gpl source code (daemon source code).

daemon source code is free software: you can redistribute it and/or modify
it under the terms of the gnu general public license as published by
the free software foundation, either version 3 of the license, or
(at your option) any later version.

daemon source code is distributed in the hope that it will be useful,
but without any warranty; without even the implied warranty of
merchantability or fitness for a particular purpose.  see the
gnu general public license for more details.

you should have received a copy of the gnu general public license
along with daemon source code.  if not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#ifndef AUDIO_AUDIO_H_
#define AUDIO_AUDIO_H_

#include "../../common/String.h"

namespace Audio {

    // An interface to the sound system that mimics the previous sound system's behavior

    bool Init();
    void Shutdown();
    void Update();

    sfxHandle_t RegisterSFX(Str::StringRef filename);

    void StartSound(int entityNum, const vec3_t origin, sfxHandle_t sfx);
    void StartLocalSound(int entityNum);

    void AddEntityLoopingSound(int entityNum, sfxHandle_t sfx);
    void ClearAllLoopingSounds();
    void ClearLoopingSoundsForEntity(int entityNum);

    void StartMusic(Str::StringRef leadingSound, Str::StringRef loopSound);
    void StopMusic();

    void StreamData(int streamNum, const void* data, int numSamples, int rate, int width, float volume, int entityNum);

    void UpdateListener(int entityNum, const vec3_t orientation[3]);
    void UpdateEntityPosition(int entityNum, const vec3_t position);
    void UpdateEntityVelocity(int entityNum, const vec3_t velocity);

    void SetReverb(int slotNum, std::string name, float ratio);

    void StartCapture(int rate);
    int AvailableCaptureSamples();
    void GetCapturedData(int numSamples, void* buffer);
    void StopCapture();
}

#endif //AUDIO_AUDIO_H_