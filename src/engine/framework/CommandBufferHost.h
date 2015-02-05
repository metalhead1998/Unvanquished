/*
===========================================================================
Daemon BSD Source Code
Copyright (c) 2013-2015, Daemon Developers
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Daemon developers nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL DAEMON DEVELOPERS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
===========================================================================
*/

#ifndef FRAMEWORK_COMMAND_BUFFER_HOST_H_
#define FRAMEWORK_COMMAND_BUFFER_HOST_H_

#include "../../common/IPC/CommandBuffer.h"
#include "../../common/Serialize.h"

namespace IPC {

    class CommandBufferHost {
        public:
            CommandBufferHost(std::string name);

            void Syscall(int index, Util::Reader& reader, IPC::Channel& channel);
            void Close();

        private:
            std::string name;
            Log::Logger logs;
            size_t read[2];
            IPC::CommandBufferData buffers[2];

            virtual void HandleCommandBufferSyscall(int major, int minor, Util::Reader& reader) = 0;

            void Init(IPC::SharedMemory mem0, IPC::SharedMemory mem1);

            void Consume(int i);
            Util::Reader ConsumeOne(int i);
    };
}

#endif // FRAMEWORK_COMMAND_BUFFER_HOST_H_
