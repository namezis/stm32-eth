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

#include <stm32f4xx_hal.h>
#include <diag/Trace.h>
#include "Socket.h"
#include "w5100/Device.h"
#include "SpiWriter.h"

void spiClockEnable()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_SPI2_CLK_ENABLE();
}


int main()
{
    HAL_Init();
    spiClockEnable();

    eth::SpiWriter writer;

    eth::w5100::Device device(writer);
    device.setGatewayAddress({192, 168, 1, 1});
    device.setIpAddress({192, 168, 1, 8});
    device.setSubnetMask({255, 255, 255, 0});
    device.setMacAddress({0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef});

    eth::Socket socket(eth::makeHandle<0>(), device);
    constexpr uint16_t port = 5000;

    trace_puts("Server: 192.168.1.8:5000");

    while(true)
    {
        if( socket.open(eth::Protocol::tcp, port, 0) != eth::Socket::Status::ok )
        {
            trace_puts("socket() failed");
        }
        else
        {
            trace_puts("socket() ok");
        }


        if( socket.listen() != eth::Socket::Status::ok )
        {
            trace_puts("listen() failed");
        }
        else
        {
            trace_puts("listen() ok");
        }


        socket.accept();
        trace_puts("accept() done");


        while(true)
        {
            if( socket.getStatus() == eth::SocketStatus::established )
            {
                std::array<uint8_t, 20> buffer;

                const auto received = socket.receive(buffer);
                trace_printf("receive(): %d\n", received);

                if( received > 0 )
                {
                    std::array<uint8_t, 9> resp{{ 'r', 'e', 'c', 'e', 'i', 'v', 'e', 'd', '\n' }};
                    const auto n = socket.send(resp);

                    if( n != resp )
                    {
                        trace_printf("send() failed (%d)\n", n);
                    }
                    else
                    {
                        trace_printf("send() ok (%d / %d)\n", n, resp.size());
                    }
                }
            }

        }

    }

    return 0;
}


extern "C" void SysTick_Handler(void)
{
    HAL_IncTick();
}


