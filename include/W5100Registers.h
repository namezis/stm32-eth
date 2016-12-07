/*
 * Stm32 Eth - Ethernet connectivity for Stm32
 * Copyright (C) 2016  offa
 *
 * This file is part of Stm32 Eth.
 *
 * Stm32 Eth is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Stm32 Eth is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Stm32 Eth.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "W5100Register.h"
#include <gsl/span>

namespace eth
{

    namespace w5100
    {

        constexpr auto mode = makeRegister<uint8_t>(0x0000);
        constexpr auto transmitMemorySize = makeRegister<uint8_t>(0x001b);
        constexpr auto receiveMemorySize = makeRegister<uint8_t>(0x001a);

        constexpr auto gatewayAddress = makeRegister<gsl::span<const uint8_t>>(0x0001);
        constexpr auto subnetMask = makeRegister<gsl::span<const uint8_t>>(0x0005);
        constexpr auto sourceMacAddress = makeRegister<gsl::span<const uint8_t>>(0x0009);
        constexpr auto sourceIpAddress = makeRegister<gsl::span<const uint8_t>>(0x000f);



        constexpr auto socketMode(SocketHandle s)
        {
            return makeSocketRegister<uint8_t>(s, 0x0000);
        }

        constexpr auto socketSourcePort(SocketHandle s)
        {
            return makeSocketRegister<uint16_t>(s, 0x0004);
        }

        constexpr auto socketInterrupt(SocketHandle s)
        {
            return makeSocketRegister<uint8_t>(s, 0x0002);
        }

        constexpr auto socketCommand(SocketHandle s)
        {
            return makeSocketRegister<uint8_t>(s, 0x0001);
        }

        constexpr auto socketStatus(SocketHandle s)
        {
            return makeSocketRegister<uint8_t>(s, 0x0003);
        }

        constexpr auto socketTransmitFreeSize(SocketHandle s)
        {
            return makeSocketRegister<uint16_t>(s, 0x0020);
        }

        constexpr auto socketReceiveFreeSize(SocketHandle s)
        {
            return makeSocketRegister<uint16_t>(s, 0x0026);
        }

        constexpr auto socketTransmitWritePointer(SocketHandle s)
        {
            return makeSocketRegister<uint16_t>(s, 0x0024);
        }

        constexpr auto socketReceiveReadPointer(SocketHandle s)
        {
            return makeSocketRegister<uint16_t>(s, 0x0028);
        }

        constexpr auto socketDestIpAddress(SocketHandle s)
        {
            return makeSocketRegister<gsl::span<const uint8_t>>(s, 0x000c);
        }

        constexpr auto socketDestPort(SocketHandle s)
        {
            return makeSocketRegister<uint16_t>(s, 0x0010);
        }

    }

}
