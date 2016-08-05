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

#include "Byte.h"
#include <CppUTest/TestHarness.h>

using namespace eth;

TEST_GROUP(ByteTest)
{
    void setup() override
    {
    }

    void teardown() override
    {
    }
};

TEST(ByteTest, getByteUint8)
{
    constexpr uint8_t value = 0xab;
    CHECK_EQUAL(0xab, byte::get<0>(value));
}

TEST(ByteTest, getByteUint16)
{
    constexpr uint16_t value = 0xabcd;
    CHECK_EQUAL(0xcd, byte::get<0>(value));
    CHECK_EQUAL(0xab, byte::get<1>(value));
}

TEST(ByteTest, getByteUint32)
{
    constexpr uint32_t value = 0xabcdef01;
    CHECK_EQUAL(0x01, byte::get<0>(value));
    CHECK_EQUAL(0xef, byte::get<1>(value));
    CHECK_EQUAL(0xcd, byte::get<2>(value));
    CHECK_EQUAL(0xab, byte::get<3>(value));
}
